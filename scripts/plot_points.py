#!/usr/bin/env python3
import matplotlib.pyplot as plt
import csv
x=[]
y=[]
x1=[]
y1=[]
with open('/home/spie-lab-01/Desktop/scan_matching/data/rectangle_points10_rotated.csv', newline='') as csvfile:

    rows = csv.reader(csvfile)
    for row in rows:
        x.append(float(row[0]))
        y.append(float(row[1]))


with open('/home/spie-lab-01/Desktop/scan_matching/data/rectangle_points10.csv', newline='') as csvfile:
    next(csvfile) #skip the first line writing x,y
    rows = csv.reader(csvfile)
    
    for row in rows:
        x1.append(float(row[0]))
        y1.append(float(row[1]))    

plt.scatter(x, y)
plt.scatter(x1, y1)
plt.show()