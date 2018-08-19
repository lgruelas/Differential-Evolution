#! /usr/bin/python
# -*- coding: utf-8 -*-

#Copyright (C) 2018  Luis Germán Ruelas Luna gruelas@cieco.unam.mx

#This file is part or Differential-Evolution

#Differential-Evolution is free software; you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation; either version 3 of the License, or
#(at your option) any later version.

#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.

#You should have received a copy of the GNU General Public License
#along with this program; if not, write to the Free Software
#Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA




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
