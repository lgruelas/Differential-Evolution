#! /usr/bin/python
# -*- coding: utf-8 -*-

#really good parameters are [0.666681,0.499999,8.44622e-07]

import auxiliar
import numpy as np
import os
import subprocess

print("building differential evolution...")
os.system('rm -f outfile')
os.system('g++ -std=c++11 main.cpp Ind.cpp -o outfile')
print("done")
print("excecuting differential evolution...")
a = [float(i) for i in subprocess.check_output(['./outfile']).strip().split() if ord(i.decode('utf-8')[0]) < 58]
print("done")
data = []
print("reading data...")
with open('data2.csv', 'r') as archivo:
    for i in archivo:
        j=i.strip().split()
        data.append(np.float(j[0]))
print("done")

print("applying Holt-Winters with values from differential evolution...")
y=auxiliar.holtWinters(data, a[1], a[2], a[3])
print("done")
auxiliar.graficar(data, y)
