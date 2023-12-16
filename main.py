#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
import os
import time
import threading

MAX_X = 100
MAX_Y = 100
MOBS = 50

colors = ['r', 'g', 'b']

def func():
    pointers = []
    while True:
        n = input()
        if "eof" in n:
            print("Я питон и я умираю")
            break

        if len(pointers) == MOBS:
            for pointer in pointers:
                pointer.remove()
        pointers = []

        for i in range(MOBS):
            mob = input()
            
            type, x, y, isAlive = [int(i) for i in mob.rstrip().split(" ")]
            if x < 0 or y < 0:
                print("ну пиздец блять")

            if isAlive:
                color = colors[type]
            else:
                color = "black"
            pointers.append( ax1.plot(x, y, color = color, marker = 'o')[0] )
        
        fig.canvas.draw()

def onPress(event):
    print(event.key)

fig = plt.figure()

ax1 = fig.add_subplot(1, 1, 1)
ax1.axis('equal')
plt.gca().set_adjustable("box")
ax1.set(xlim=[-1, 101], ylim=[-1, 101])
ax1.plot(-10, -10, 'ro', label = 'Outlaw')
ax1.plot(-10, -10, 'go', label = 'Knight')
ax1.plot(-10, -10, 'bo', label = 'Elf')
plt.legend(bbox_to_anchor=(1, 1))

fig.canvas.mpl_connect('key_press_event', onPress)

t = threading.Thread(target = func, daemon = True)
t.start()

plt.show()