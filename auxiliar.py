#! /usr/bin/python
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches


def holtWinters(data, alpha=0.1,beta=0.5,gamma=0.95,p=12):
    L0=[data[0]]
    T0=[data[0]]
    S0=[gamma+(data[0]*(1-gamma)) for i in range (p)]
    
    L=lambda alpha,yt,st,lt,tt: alpha*(yt/st)+(1-alpha)*(lt-tt)
    
    T=lambda beta,lt2,lt1,Tt1 : beta*(lt2-lt1)+(1-beta)*Tt1
    
    S=lambda gamma,yt,lt,st_p : gamma*(yt/lt) + (1-gamma)*(st_p)
    
    Ye=lambda l,t,s: (l+t)*s    
    y=[]
    j=0
    for i in range (len(data)):
        l=L(alpha,data[i],S0[j],L0[i],T0[i])
        t=T(beta,l,L0[i],T0[i])
        s=S(gamma,data[i],L0[i],S0[j])
        L0.append(l)
        T0.append(t)
        S0.append(s)
        tmp=Ye(l,t,s)
        y.append(tmp)
        j+=1
    data=np.array(data)
    y=np.array(y)
    error= ((y-data)**2)
    return y


        
def graficar(data,y):

    plt.grid()
    plt.plot(data,color="blue")
    plt.plot(y,color="red")
    plt.title("Monthly sales of Tasty Cola")
    plt.xlabel("Meses")
    plt.ylabel("Estamaciones")
    red_patch = mpatches.Patch(color='red', label=u'Evolución Diferencial')
    red_patch1 = mpatches.Patch(color='blue', label='Datos Reales')
    plt.legend(handles=[red_patch,red_patch1])
    plt.savefig("figura2.png")
    return 
