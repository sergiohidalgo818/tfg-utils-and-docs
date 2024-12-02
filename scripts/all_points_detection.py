
import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from math import e
def detect_points(data:np.ndarray)->tuple:

    x_data:np.ndarray = data[0]
    y_data:np.ndarray = data[1]
    z_data:np.ndarray = data[2]
    time_data:np.ndarray = data[3]

    sign_list:list = []
    d_location:list = []
    
    sign_flag = False

    for i in  range (1, x_data.size):
        dx = 1
        t_act = time_data[i-1]
        x_act = x_data[i-1]
        y_act = y_data[i-1]
        z_act = z_data[i-1]
        
        t_next =  float(time_data[i])
        x_next = float(x_data[i])
        t_diff = float(t_next - t_act)
            
        dx = float(x_next- x_act)/t_diff
        # dx = y_act + 3*(x_act**2) - x_act**3 - z_act + e


        t_act = t_next
        x_act = x_next
            

        if sign_flag:
            dx_sign = np.sign([dx])[0]
            sign_list.append(-dx_sign)
            sign_flag = False
        
        # if abs(dx) -0.3 <= 0:
        if abs(dx) -0.0001 <= 0:
            sign_flag = True
            d_location.append(i)
        
    return (d_location, sign_list)

name_dir = "./data/executions_HR/c/"
name_file = "HR_chaotic_continue_c.csv"
time_end = 12500

if __name__=="__main__":

    if not os.path.exists("graphs/executions_DP"):
        os.makedirs("graphs/executions_DP")

    df = pd.read_csv(name_dir+name_file, sep=";", decimal=".")

    df = df[df['time'] < time_end]


    print("executing algorithm")

    (d_location, sign_list) = detect_points(np.array([df['x'].to_list(), df['y'].to_list(), df['z'].to_list(),df['time'].to_list()]))

    
    print("ploting " + name_file)

    name = name_file.split('.')[0]

    plt.figure( figsize=(12,6) )

    plt.plot( df["time"], df["x"]) 

    list_x = df['x'].to_list()
    list_t = df['time'].to_list()

    plt.savefig("graphs/executions_DP/"+name+ '.png')


    plt.plot( [list_t[i] for i in d_location]  , [list_x[i] for i in d_location] , marker='.', ls='none', ms=10)

    


    plt.savefig("graphs/executions_DP/"+name+ '_pointed.png')
    plt.close()