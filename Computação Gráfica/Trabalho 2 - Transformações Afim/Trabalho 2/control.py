# Trabalho 2 - Computação Gráfica
# Alunos: Jaime Lay e Leonardo Andrade
import animation
from matplotlib.backend_bases import MouseButton

def on_press(event):
    print('Você pressionou o botão do mouse:', event.button, event.xdata, event.ydata)
    if event.button == MouseButton.LEFT:
       animation.pontos = 1.5 * animation.pontos
    elif event.button == MouseButton.RIGHT:
        animation.pontos = 0.5 * animation.pontos

# Função que gerencia eventos do teclado
def on_key(event):
    print('Você pressionou a tecla: "', event.key, '"', event.xdata, event.ydata)
    if event.key == 'escape':
        animation.end_loop = True
    elif event.key == 'up':
        animation.velocityRotationCenterObject = animation.velocityRotationCenterObject + 1
    elif event.key == 'down':
        animation.velocityRotationCenterObject = animation.velocityRotationCenterObject - 1
    elif event.key == 'left':
        animation.velocityRotationCenterSpace = animation.velocityRotationCenterSpace + 1
    elif event.key == 'right':
        animation.velocityRotationCenterSpace = animation.velocityRotationCenterSpace - 1