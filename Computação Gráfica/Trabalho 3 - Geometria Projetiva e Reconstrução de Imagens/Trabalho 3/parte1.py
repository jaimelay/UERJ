# Alunos: Jaime Lay e Leonardo Andrade

import numpy as np
import matplotlib.pyplot as plt

global theta, delta, eixo, px, py, pz, po
theta = 0
delta = 0
eixo = "XY"
px = 0
py = 0
pz = 0

print("Para reiniciar a figura aperte a tecla 'esc'")

po = np.array([[1,1,1,1],[3,1,1,1],[3,3,1,1],[2,4,1,1],[1,3,1,1], # house: front points
               [1,1,4,1],[3,1,4,1],[3,3,4,1],[2,4,4,1],[1,3,4,1], # house: back points
               [1.7,1,1,1],[1.7,2.3,1,1],[2.3,2.3,1,1],[2.3,1,1,1]]) # house: door points

Tt = np.array([[1,0,0,-2.0],
              [0,1,0,-2.5],
              [0,0,1,-2.5],
              [0,0,0,1]])

l,c = po.shape
for i in range(l):
    po[i] = np.matmul(Tt, po[i])

pFront = np.array([po[0],po[1],po[2],po[3],po[4],po[0]])
pBack = np.array([po[5],po[6],po[7],po[8],po[9],po[5]])
pCeil = np.array([po[4],po[2],po[7],po[9],po[4]])
pFloor = np.array([po[0],po[1],po[6],po[5],po[0]])
pRoof = np.array([po[3],po[8]])
pDoor = np.array([po[10],po[11],po[12],po[13]])

pBack = np.transpose(pBack)
pFront = np.transpose(pFront)
pCeil = np.transpose(pCeil)
pFloor = np.transpose(pFloor)
pRoof = np.transpose(pRoof)
pDoor = np.transpose(pDoor)

def on_key(event):
    global py,px,pz,delta,theta, eixo
    if event.key == '1':
        eixo = "XY"
        create_fig()
        print("Projection Plane set to: " + str(eixo))
    elif event.key == '2':
        eixo = "ZX"
        create_fig()
        print("Projection Plane set to: " + str(eixo))
    elif event.key == '3':
        eixo = "ZY"
        create_fig()
        print("Projection Plane set to: " + str(eixo))
    elif event.key == 'up':
        theta = (theta + 5) 
        rotaciona()
        print("Rotation Angle X set to: " +str(theta))
    elif event.key == 'down':
        theta = (theta - 5)
        rotaciona()
        print("Rotation Angle X set to: " + str(theta))
    elif event.key == 'left':
        delta = (delta + 5) 
        rotaciona()
        print("Rotation Angle Y set to: " + str(delta))
    elif event.key == 'right':
        delta = (delta - 5)
        rotaciona()
        print("Rotation Angle Y set to: " + str(delta))
    elif event.key == 'X':
        px = px - 1
        rotaciona()
        print("Perspective X set to: " + str(px/100))
    elif event.key == 'x':
        px = px + 1
        rotaciona()
        print("Perspective X set to: " + str(px/100))
    elif event.key == 'Z':
        pz = pz - 1
        rotaciona()
        print("Perspective Z set to: " + str(pz/100))
    elif event.key == 'z':
        pz = pz + 1
        rotaciona()
        print("Perspective Z set to: " + str(pz/100))
    elif event.key == 'Y':
        py = py - 1
        rotaciona()
        print("Perspective Y set to: " + str(py/100))
    elif event.key == 'y':
        py = py + 1
        rotaciona()
        print("Perspective Y set to: " + str(py/100))
    elif event.key == 'escape':
        py = 0
        pz = 0
        px = 0
        eixo = "XY"
        delta = 0
        theta = 0
        reset()
        print("Variables reset")

def normalize(pontos):
    pT = np.transpose(pontos)
    t = pT[-1:]
    return pT/t
        
def init():
    global fig, ax
    fig, ax = plt.subplots(figsize = (7, 7))
    cid = fig.canvas.mpl_connect('key_press_event', on_key)

def anima(pBack,pFront,pCeil,pFloor,pRoof,pDoor):
    init()    
    configura_figura(pBack,pFront,pCeil,pFloor,pRoof,pDoor)
    
def rotaciona():
    theta_rad = (theta/180) * np.pi
    delta_rad = (delta/180) * np.pi
    pt = po.copy()
    P = np.array([[1,0,0,0],
                  [0,1,0,0],
                  [0,0,1,0],
                  [px/100,py/100,pz/100,1]])
    Rotx = np.array([[1,0,0,0],
                    [0,np.cos(theta_rad),-np.sin(theta_rad),0],
                    [0, np.sin(theta_rad), np.cos(theta_rad),0],
                    [0,0,0,1]])
    
    Roty = np.array([[np.cos(delta_rad),0,-np.sin(delta_rad),0],
                    [0,1,0,0],
                    [np.sin(delta_rad),0, np.cos(delta_rad),0],
                    [0,0,0,1]])
    
    l,c = pt.shape
    for i in range(l):
        pt[i] = np.matmul(Rotx, pt[i])
        pt[i] = np.matmul(Roty, pt[i])
        pt[i] = np.matmul( P, pt[i])
        pt[i] = normalize(pt[i]) 
        
    pFront = np.array([pt[0],pt[1],pt[2],pt[3],pt[4],pt[0]])
    pBack = np.array([pt[5],pt[6],pt[7],pt[8],pt[9],pt[5]])
    pCeil = np.array([pt[4],pt[2],pt[7],pt[9],pt[4]])
    pFloor = np.array([pt[0],pt[1],pt[6],pt[5],pt[0]])
    pRoof = np.array([pt[3],pt[8]])
    pDoor = np.array([pt[10],pt[11],pt[12],pt[13]])

    pBack = np.transpose(pBack)
    pFront = np.transpose(pFront)
    pCeil = np.transpose(pCeil)
    pFloor = np.transpose(pFloor)
    pRoof = np.transpose(pRoof)
    pDoor = np.transpose(pDoor)
    
    configura_figura(pBack, pFront, pCeil, pFloor, pRoof, pDoor)
    
def configura_figura(pBack,pFront,pCeil,pFloor,pRoof,pDoor):
    global x_list1, x_list2, x_list3, x_list4, x_list5, x_list6
    global y_list1, y_list2, y_list3, y_list4, y_list5, y_list6
    global z_list1, z_list2, z_list3, z_list4, z_list5, z_list6
    x_list1 = np.append(pBack[0,:], pBack[0,0])
    y_list1 = np.append(pBack[1,:], pBack[1,0])
    z_list1 = np.append(pBack[2,:], pBack[2,0])
    
    x_list2 = np.append(pFront[0,:], pFront[0,0])
    y_list2 = np.append(pFront[1,:], pFront[1,0])
    z_list2 = np.append(pFront[2,:], pFront[2,0])

    
    x_list3 = np.append(pCeil[0,:], pCeil[0,0])
    y_list3 = np.append(pCeil[1,:], pCeil[1,0])
    z_list3 = np.append(pCeil[2,:], pCeil[2,0])
    
    x_list4 = np.append(pFloor[0,:], pFloor[0,0])
    y_list4 = np.append(pFloor[1,:], pFloor[1,0])
    z_list4 = np.append(pFloor[2,:], pFloor[2,0])

    x_list5 = np.append(pRoof[0,:], pRoof[0,0])
    y_list5 = np.append(pRoof[1,:], pRoof[1,0])
    z_list5 = np.append(pRoof[2,:], pRoof[2,0])

    x_list6 = np.append(pDoor[0,:], pDoor[0,0])
    y_list6 = np.append(pDoor[1,:], pDoor[1,0])
    z_list6 = np.append(pDoor[2,:], pDoor[2,0])
    
    create_fig()
    
def create_fig():
    global x_list1, x_list2, x_list3, x_list4, x_list5, x_list6
    global y_list1, y_list2, y_list3, y_list4, y_list5, y_list6
    global z_list1, z_list2, z_list3, z_list4, z_list5, z_list6
    
    ax.cla()
    ax.set_xlim([-5,5]), ax.set_ylim([-5, 5])

    plt.title("Projection Plane: " + eixo + "\nRotation: X = " + str(theta) + "; Y = " + str(delta) + "\nPerspective: X = " + str(px/100) + "; Y = " + str(py/100)+ "; Z = " + str(pz/100))

    if eixo == "XY":
        plt.plot(x_list1, y_list1, 'r', linewidth=3)
        plt.plot(x_list2, y_list2, 'r', linewidth=3)
        plt.plot(x_list3, y_list3, 'r', linewidth=3)
        plt.plot(x_list4, y_list4, 'r', linewidth=3)
        plt.plot(x_list5, y_list5, 'r', linewidth=3)
        plt.plot(x_list6, y_list6, 'r', linewidth=3)
    elif eixo == "ZX":
        plt.plot(z_list1, x_list1, 'r', linewidth=3)
        plt.plot(z_list2, x_list2, 'r', linewidth=3)
        plt.plot(z_list3, x_list3, 'r', linewidth=3)
        plt.plot(z_list4, x_list4, 'r', linewidth=3)
        plt.plot(z_list5, x_list5, 'r', linewidth=3)
        plt.plot(z_list6, x_list6, 'r', linewidth=3)
    elif eixo == "ZY":
        plt.plot(z_list1, y_list1, 'r', linewidth=3)
        plt.plot(z_list2, y_list2, 'r', linewidth=3)
        plt.plot(z_list3, y_list3, 'r', linewidth=3)
        plt.plot(z_list4, y_list4, 'r', linewidth=3)
        plt.plot(z_list5, y_list5, 'r', linewidth=3)
        plt.plot(z_list6, y_list6, 'r', linewidth=3)
    plt.pause(0.01)
 
def reset():
    pt = po.copy()
    pFront = np.array([pt[0],pt[1],pt[2],pt[3],pt[4],pt[0]])
    pBack = np.array([pt[5],pt[6],pt[7],pt[8],pt[9],pt[5]])
    pCeil = np.array([pt[4],pt[2],pt[7],pt[9],pt[4]])
    pFloor = np.array([pt[0],pt[1],pt[6],pt[5],pt[0]])
    pRoof = np.array([pt[3],pt[8]])
    pDoor = np.array([pt[10],pt[11],pt[12],pt[13]])

    pBack = np.transpose(pBack)
    pFront = np.transpose(pFront)
    pCeil = np.transpose(pCeil)
    pFloor = np.transpose(pFloor)
    pRoof = np.transpose(pRoof)
    pDoor = np.transpose(pDoor)
    configura_figura(pBack,pFront,pCeil,pFloor,pRoof,pDoor)

anima(pBack,pFront,pCeil,pFloor,pRoof,pDoor)
