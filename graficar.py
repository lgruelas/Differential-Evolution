#! /usr/bin/python
# -*- coding: utf-8 -*-

import auxiliar
import numpy as np
import os

a = [0.666681,0.499999,8.44622e-07]

archivo=open("data2.csv","r")
data=[]
for i in archivo:
    j=i.split()
    data.append(np.float(j[0]))
    
    
y=auxiliar.holtWinters(data, a[0], a[1], a[2])
auxiliar.graficar(data,y)
