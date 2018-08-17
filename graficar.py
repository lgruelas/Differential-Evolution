#! /usr/bin/python
# -*- coding: utf-8 -*-

#really good parameters are [0.666681,0.499999,8.44622e-07]

import auxiliar
import numpy as np
import os
import subprocess


def run_cpp():
    print("building differential evolution...")
    os.system('rm -f outfile')
    os.system('g++ -std=c++11 main.cpp Ind.cpp -o outfile')
    print("done")
    print("excecuting differential evolution...")
    return [float(i) for i in subprocess.check_output(['./outfile']).strip().split() if ord(i.decode('utf-8')[0]) < 58]

if __name__ == '__main__':
    a = run_cpp()
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

    if auxiliar.graficar(data, y):
        print("Image is saved as figura2.png in current directory")
