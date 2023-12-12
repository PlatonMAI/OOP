import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import os
from random import randint
# import math
# from scipy.integrate import odeint

colors = ['r', 'g', 'b']
start_distance = 20
step_distance = 10

def plot(data):
    global ax1, pointers
    pointers = []
    for i in range(1, len(data) - 1):
        entity = [int(i) for i in data[i].split(" ")]
        pointers.append(ax1.plot(entity[1], entity[2], colors[ entity[0] ] + 'o')[0])

def onPress(event):
    global I, DATA, QUANTITY_FIGHTS, fig, plt, ax1, pointers

    for pointer in pointers:
        pointer.remove()

    if (event.key == "left"):
        I = (I - 1) % (QUANTITY_FIGHTS + 1)
    elif (event.key == "right"):
        I = (I + 1) % (QUANTITY_FIGHTS + 1)
    plot(DATA[I])
    
    if I == 0:
        plt.title("Начальная генерация")
    else:
        plt.title(f"Состояние после {I} сражения\n(дистанция была {start_distance + (I - 1) * step_distance})")

    fig.canvas.draw()

fig = plt.figure()

ax1 = fig.add_subplot()
ax1.axis('equal')
plt.gca().set_adjustable("box")
ax1.set(xlim=[0, 100], ylim=[0, 100])
plt.title("Начальная генерация")
ax1.plot(-1, -1, 'ro', label = 'Outlaw')
ax1.plot(-1, -1, 'go', label = 'Knight')
ax1.plot(-1, -1, 'bo', label = 'Elf')
plt.legend(bbox_to_anchor=(1, 1))

pointers = []
with open("npc.txt") as file:
    data = file.read().split("\n")
plot(data)

QUANTITY_FIGHTS = len(os.listdir('txt'))
DATA = [data]
for i in range(QUANTITY_FIGHTS):
    with open(f"txt/npc{i + 1}") as file:
        DATA.append(file.read().split("\n"))

I = 0
fig.canvas.mpl_connect('key_press_event', onPress)

def onClick(event):
    global targetPoint
    if targetPoint[0] == -1:
        targetPoint[0] = event.xdata
        targetPoint[1] = event.ydata
        print("Выбрана точка", targetPoint)
    else:
        print("Расстояние: ", int(((event.xdata - targetPoint[0]) ** 2 + (event.ydata - targetPoint[1]) ** 2) ** 0.5))
        targetPoint = [-1, -1]

targetPoint = [-1, -1]
fig.canvas.mpl_connect('button_press_event', onClick)

plt.show()