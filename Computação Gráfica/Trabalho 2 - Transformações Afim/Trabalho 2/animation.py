# Trabalho 2 - Computação Gráfica
# Alunos: Jaime Lay e Leonardo Andrade
import numpy as np
import matplotlib.pyplot as plt
import control

def init():
    global fig, ax

    fig, ax = plt.subplots(figsize = (7, 7))
    cid = fig.canvas.mpl_connect('button_press_event', control.on_press)
    cid = fig.canvas.mpl_connect('key_press_event', control.on_key)

def createFigure(objectPoints, objectSize):
    ax.cla()
    ax.set_xlim([-objectSize, objectSize]), ax.set_ylim([-objectSize, objectSize])
    plt.axhline(linewidth = 1), plt.axvline(linewidth = 1)

    x_list = np.append(objectPoints[0,:], objectPoints[0,0])
    y_list = np.append(objectPoints[1,:], objectPoints[1,0])

    plt.plot(x_list, y_list, 'r', linewidth = 3)

def animate(object):
    po = np.transpose(object)

    Tt1 = np.array([[1, 0, -1.5 ],
                [0, 1, -1.5],
                [0, 0, 1]])

    Tt2 = np.array([[1, 0, 1.5 ],
                [0, 1, 1.5],
                [0, 0, 1]])

    init()

    global theta, end_loop, velocityRotationCenterSpace, objectSize, pontos, velocityRotationCenterObject
    theta = 0
    velocityRotationCenterSpace = 1
    velocityRotationCenterObject = 1
    end_loop = False
    objectSize = 10
    delta = 0
    pontos = po

    while end_loop == False:
        theta_rad = (theta / 180) * np.pi
        delta_rad = (delta / 180) * np.pi
                        
        Rot = np.array([[np.cos(delta_rad), -np.sin(delta_rad), 0],
                    [np.sin(delta_rad), np.cos(delta_rad), 0],
                    [0, 0, 1]])

        R = np.array([[np.cos(theta_rad), -np.sin(theta_rad), 0],
                    [np.sin(theta_rad), np.cos(theta_rad), 0],
                    [0, 0, 1]])
        

        Ttr = np.matmul(Rot, Tt1)
        Ttrt = np.matmul(Tt2 ,Ttr)
                
        pt = np.matmul (Ttrt, pontos)
        pt = np.matmul(R,pt)

        createFigure(pt, objectSize)
        plt.pause(0.01)
        delta = (delta + velocityRotationCenterObject) % 360
        theta = (theta + velocityRotationCenterSpace) % 360

    plt.show()