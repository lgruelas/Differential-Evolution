#! /usr/bin/python
# -*- coding: utf-8 -*-

import auxiliar
import numpy as np
import os
import subprocess

a = [float(i) for i in subprocess.check_output([out]).strip().split() if ord(i[0]) < 58]
#a = [0.666681,0.499999,8.44622e-07]
data = []

with open('data2.csv', 'r') as archivo:
    for i in archivo:
        j=i.strip().split()
        data.append(np.float(j[0]))

y=auxiliar.holtWinters(data, a[0], a[1], a[2])
auxiliar.graficar(data, y)
