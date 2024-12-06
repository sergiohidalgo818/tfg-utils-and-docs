
import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
from math import e
def detect_points(data:np.ndarray, tol:int)->tuple:

    x_data:np.ndarray = data[0]
    time_data:np.ndarray = data[1]

    firsts_location:list = []
    lasts_location:list = []
    



    last_point_valley:bool=False
    spike_marked:bool=True
    spike:int=-1


    for i in  range (1, x_data.size):
        dx = 1
        t_act = time_data[i-1]
        x_act = x_data[i-1]

        t_next =  float(time_data[i])
        x_next = float(x_data[i])
        t_diff = float(t_next - t_act)
            
        dx = float(x_next- x_act)/t_diff

        if i == 1:
            prev_sign= np.sign([dx])[0]


        dx_sign = np.sign([dx])[0]

        if dx_sign!=prev_sign and x_act <= tol: # here is identified the LAST spike (at the end of the Burst Duration)
            if spike_marked:
                lasts_location.append(spike) 
                spike_marked=False

            last_point_valley=True
        
        elif dx_sign!=prev_sign and last_point_valley:
            firsts_location.append(i-1) # here is identified the FIRST spike (at the begining of the Burst Duration)
            last_point_valley=False

        elif dx_sign!=prev_sign:
            spike = i-1
            spike_marked=True   

        prev_sign = dx_sign
        t_act = t_next
        x_act = x_next


    return (firsts_location, lasts_location)

name_dir = "./data/executions_HR/c/"
name_file = "HR_regular_continue_c.csv"
time_end = 12500

if __name__=="__main__":

    if not os.path.exists("graphs/executions_DP"):
        os.makedirs("graphs/executions_DP")


    if not os.path.exists("data/executions_DP"):
        os.makedirs("data/executions_DP")


    # creation of normal figure and pointed figure

    df = pd.read_csv(name_dir+name_file, sep=";", decimal=".")

    # df = df[df['time'] < time_end]

    print("executing algorithm")

    (firsts_location, lasts_location) = detect_points(np.array([df['x'].to_list(),df['time'].to_list()]), -1.2)

    
    print("ploting " + name_file)

    name = name_file.split('.')[0]

    plt.figure( figsize=(24,6) )

    plt.plot( df["time"], df["x"]) 

    list_x = df['x'].to_list()
    list_t = df['time'].to_list()
    plt.xlim([ min(list_t), max(list_t)])

    plt.savefig("graphs/executions_DP/"+name+ '.png', bbox_inches='tight')

    plt.plot( [list_t[i] for i in firsts_location]  , [list_x[i] for i in firsts_location] , marker='.', ls='none', ms=10, color='r')
    plt.plot( [list_t[i] for i in lasts_location]  , [list_x[i] for i in lasts_location] , marker='.', ls='none', ms=10, color='g')

    

    plt.savefig("graphs/executions_DP/"+name+ '_pointed.png', bbox_inches='tight')
    plt.close()

    df_values = pd.DataFrame()

    all_times = list()  
    firsts = list()  
    lasts = list()  


    print("writting data")


    # this part is to keep all the data in a csv to posterior analyisis
    for i in range(max(len(firsts_location), len(lasts_location))):

        if i < len (firsts_location):
            actual_first = firsts_location[i]
        else:
            actual_first = None

        if i < len (lasts_location):
            actual_last = lasts_location[i]
        else:
            actual_last = None
        

        if actual_first != None and actual_last != None:

                
            if actual_first < actual_last:
                all_times.append(list_t[actual_first])
                all_times.append(list_t[actual_last])

                firsts.append(list_x[actual_first])
                firsts.append(None)

                lasts.append(None)
                lasts.append(list_x[actual_last])
        
            else:
                all_times.append(list_t[actual_last])
                all_times.append(list_t[actual_first])
                
                lasts.append(list_x[actual_last])
                lasts.append(None)

                firsts.append(None)
                firsts.append(list_x[actual_first])

        elif actual_first != None:
                all_times.append(list_t[actual_first])
                
                lasts.append(None)

                firsts.append(list_x[actual_first])

        else:
                all_times.append(list_t[actual_last])
                
                lasts.append(list_x[actual_last])
                
                firsts.append(None)



    print("analyzing data")

    # this could be calculated during the loop, but its interesting do it apart 

    df_values['time']=all_times
    df_values['first']=firsts
    df_values['last']=lasts

    df_values.set_index("time").to_csv("data/executions_DP/"+name_file, sep=";")


    df_firsts= df_values.drop("last", axis=1).dropna()
    df_lasts= df_values.drop("first", axis=1).dropna()



    df_analyzed_values = pd.DataFrame()

    periods = list()
    interbursts = list()
    bursts_durations = list()

    times_periods = list()
    times_interbursts = list()
    times_bursts = list()

    if df_firsts['time'].values[0] > df_lasts['time'].values[0]:
        # normal secuence first - last

        prev_first = None
        prev_last = None

        for i in range(max(len(df_firsts['first'].values), len(df_lasts['last'].values))):

            if i < len ( df_firsts['time'].values):
                time_first = df_firsts['time'].values[i]
            else:
                time_first = None

            if i < len (df_lasts['time'].values):
                time_last = df_lasts['time'].values[i]
            else:
                time_last = None
            

            if time_first != None and time_last != None:
                times_interbursts.append(time_last)

                interbursts.append(time_first-time_last)
                    
                if prev_first != None:
                        times_periods.append(prev_first)
                        times_bursts.append(prev_first)

                        periods.append(time_first-prev_first)
                        bursts_durations.append(time_last-prev_first)
                else:
                        
                        times_periods.append(None)
                        times_bursts.append(None)

                        bursts_durations.append(None)
                        periods.append(None)

            elif time_last != None :
                    times_periods.append(None)
                    times_interbursts.append(time_last)
                    times_bursts.append(prev_first)

                    bursts_durations.append(time_last-prev_first)

                    interbursts.append(None)

                    periods.append(None)

            if time_first != None:
                prev_first = time_first
            if time_last != None:
                prev_last = time_last
                    
    else:
        # secuence last - first

        prev_first = None
        prev_last = None

        for i in range(max(len(df_firsts['first'].values), len(df_lasts['last'].values))):

            if i < len (df_firsts['time'].values):
                time_first = df_firsts['time'].values[i]
            else:
                time_first = None

            if i < len (df_lasts['time'].values):
                time_last = df_lasts['time'].values[i]
            else:
                time_last = None
            


            if time_first != None and time_last != None:
                times_interbursts.append(time_last)

                bursts_durations.append(time_last-time_first)

                if prev_last != None:
                        interbursts.append(prev_last-time_first)
      
                else:
                        interbursts.append(None)

                if prev_first != None:
                        periods.append(time_first-prev_first)
                else:
                        periods.append(None)


            elif time_first != None :
                    times_interbursts.append(time_last)
                    interbursts.append(time_first-prev_last)

                    bursts_durations.append(None)

                    periods.append(time_first-prev_first)
            
            if time_first != None:
                prev_first = time_first
            if time_last != None:
                prev_last = time_last




    df_analyzed_values['time_period'] =times_periods
    df_analyzed_values['time_interburst'] =times_interbursts
    df_analyzed_values['time_burst'] =times_bursts
    df_analyzed_values['period_duration'] =periods
    df_analyzed_values['interburst_duration'] =interbursts
    df_analyzed_values['burst_duration'] =bursts_durations

    df_analyzed_values.to_csv("data/executions_DP/"+"analyzed_"+name_file, sep=";")

    # the distance extracted from the points its drawn in a graph
    print("ploting " + name_file)

    name = name_file.split('.')[0]

    plt.figure( figsize=(24,6) )

    plt.plot( df["time"], df["x"]) 

    list_x = df['x'].to_list()
    list_t = df['time'].to_list()
    plt.xlim([ min(list_t), max(list_t)])

    df_periods=df_analyzed_values.drop(["interburst_duration", "burst_duration", "time_interburst", "time_burst"], axis=1).dropna()
    df_interbursts=df_analyzed_values.drop(["period_duration", "burst_duration", "time_period", "time_burst"], axis=1).dropna()
    df_bursts=df_analyzed_values.drop(["period_duration", "interburst_duration", "time_period", "time_interburst"], axis=1).dropna()

    periods_list = [[time, period+time] for time, period in df_periods.values]
    interbursts_list =  [[time, interburst+time] for time, interburst in df_interbursts.values]
    bursts_list =  [[time, bursts+time] for time, bursts in df_bursts.values]


    for pair in periods_list:
        val=2.1
        if periods_list.index(pair) %2==0:
             val=2.2
        period_lines = plt.plot( pair, [val for i in pair], color='tab:orange')


    for pair in bursts_list:
        burst_lines=plt.plot( pair, [2 for i in pair], color='b')

    for pair in interbursts_list:
        interburst_lines= plt.plot( pair, [1.9 for i in pair], color='g')

    legend_elements = [Line2D([0], [0], color = 'tab:orange', markerfacecolor = 'tab:orange', marker = 'o', label='one',  markersize=8),
                   Line2D([0], [0], color = 'b', markerfacecolor = 'b',  marker='o', label='zero', markersize=8)]

    plt.legend(loc='lower left',handles=[period_lines[0], burst_lines[0], interburst_lines[0]], labels=['period', 'burst duration', 'interburst interval'])

    plt.savefig("graphs/executions_DP/"+name+ '_lines.png', bbox_inches='tight')
    plt.close()


    plt.figure(figsize =(10, 7))