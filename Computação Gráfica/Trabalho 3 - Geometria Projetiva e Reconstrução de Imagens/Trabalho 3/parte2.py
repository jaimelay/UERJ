# Alunos: Jaime Lay e Leonardo Andrade

from skimage import io
import matplotlib.pyplot as plt
import numpy as np

img_path = './Placa_Estacionamento_Marcas.png'
#img_path = './Placa_Pare_Marcas.png'
height = 700
width = 350

def main(h, w, img):
    height = h
    width = w
    img_path = img

    global points, clicks_amount, image, fig, ax

    points = []
    clicks_amount = 0
    
    image = io.imread(img_path)
    fig, ax = plt.subplots(figsize = (7, 7))
    cid = fig.canvas.mpl_connect('button_press_event', on_click)
    ax.cla()
    ax.imshow(image)
    plt.show()

def reconstruct():
    new_image = np.zeros((height, width, 3), dtype = 'uint8')
    
    new_image2 = np.zeros((height, width, 3), dtype = 'uint8')
    
    T = least_squares_perspective(points[0], points[1], points[2], points[3])
    print("T = ", T)
    print("SHAPES = ", image.shape, new_image.shape)
    print("POINTS = ", points)

    print(np.matmul(T, new_image[0][0]))
    # T = np.transpose(T)

    row, col, _ = new_image.shape
    for i in range(row):
        for j in range(col):
            first_point_x = int(points[0][1])
            first_point_y = int(points[0][0])

            second_point_x = int(points[1][1])
            second_point_y = int(points[1][0])

            third_point_x = int(points[2][1])
            third_point_y = int(points[2][0])

            fourth_point_x = int(points[3][1])
            fourth_point_y = int(points[3][0])

            pixel_old_image = normalize(np.matmul(T, [j, i, 1]))
            x = int(pixel_old_image[1])
            y = int(pixel_old_image[0])

            v = y - first_point_y
            u = x - first_point_x

            new_image2[i][j] = image[y][x]
            # new_image[i][j] = image[x][y] * ((1 - u) * ((1 - v) * image[first_point_x][first_point_y] + v * image[fourth_point_x][fourth_point_y]) + u * ((1 - v) * image[second_point_x][second_point_y] + v * image[third_point_x][third_point_y]))

    ax.imshow(new_image2, interpolation="bilinear")
    plt.show()

def normalize(pontos):
    pT = np.transpose(pontos)
    t = pT[-1:]
    return pT/t

def least_squares_perspective(Tp0, Tp1, Tp2, Tp3):
    Tp0 = np.transpose(Tp0)
    Tp1 = np.transpose(Tp1)
    Tp2 = np.transpose(Tp2)
    Tp3 = np.transpose(Tp3)

    p0 = np.array([0, 0, 1])
    p1 = np.array([0, height, 1])
    p2 = np.array([width, height, 1])
    p3 = np.array([width, 0, 1])

    p0 = np.transpose(p0)
    p1 = np.transpose(p1)
    p2 = np.transpose(p2)
    p3 = np.transpose(p3)

    L = np.array([Tp0[0], Tp0[1], Tp1[0], Tp1[1], Tp2[0], Tp2[1], Tp3[0], Tp3[1]])
    L = np.transpose(L)

    A = np.array([
        [p0[0], p0[1], 1, 0, 0, 0, -(p0[0] * Tp0[0]), -(p0[1] * Tp0[0])],
        [0, 0, 0, p0[0], p0[1], 1, -(p0[0] * Tp0[1]), -(p0[1] * Tp0[1])],
        [p1[0], p1[1], 1, 0, 0, 0, -(p1[0] * Tp1[0]), -(p1[1] * Tp1[0])],
        [0, 0, 0, p1[0], p1[1], 1, -(p1[0] * Tp1[1]), -(p1[1] * Tp1[1])],
        [p2[0], p2[1], 1, 0, 0, 0, -(p2[0] * Tp2[0]), -(p2[1] * Tp2[0])],
        [0, 0, 0, p2[0], p2[1], 1, -(p2[0] * Tp2[1]), -(p2[1] * Tp2[1])],
        [p3[0], p3[1], 1, 0, 0, 0, -(p3[0] * Tp3[0]), -(p3[1] * Tp3[0])],
        [0, 0, 0, p3[0], p3[1], 1, -(p3[0] * Tp3[1]), -(p3[1] * Tp3[1])],
    ])

    At = np.transpose(A)
    AtA = np.matmul(At, A)
    AtAi = np.linalg.inv(AtA)
    AtAiAt = np.matmul(AtAi, At)
    X = np.matmul(AtAiAt, L)

    T = np.array([
        [X[0], X[1], X[2]],
        [X[3], X[4], X[5]],
        [X[6], X[7], 1]
    ])

    return T

def on_click(event):
    global clicks_amount, points
    print(event)
    if event.xdata != None and event.ydata != None and event.button == 1:
        clicks_amount = clicks_amount + 1
        points.append([event.ydata, event.xdata, 1])
        if (clicks_amount == 4):
            print("4 vezes", points)
            reconstruct()
            clicks_amount = 0
            del points[:]

main(height, width, img_path)