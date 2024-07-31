import os
import pandas as pd
import matplotlib.pyplot as plt
import statistics

def plot_model_data(filename:str):
    if not os.path.exists("graphs/HR/"):
        os.makedirs("graphs/HR/")

    print("ploting " + filename)
    data_frame = pd.read_csv("./data/"+filename, sep=",")
    data_frame = data_frame[['x', 'time']]

    plt.figure( figsize=(12,6) )

    plt.plot( data_frame["time"], data_frame["x"]) 
    plt.xlim((data_frame['time'].min(), data_frame['time'].max()))
    plt.ylim((-1.5, 2.5))
    
    name = filename.split('/')[-1]

    name = name.split('.')
    plt.savefig("graphs/HR/"+name[0]+ '.png')


def plot_speed_data(path):

    if not os.path.exists("graphs/timing_HR/"):
        os.makedirs("graphs/timing_HR/")

    files = os.listdir(path)

    data_frames = list()
    print("ploting files in " + path)
    labels = list()
    for filename in files:
        labels.append(filename)

        data_frame = pd.read_csv(path + "/" + filename, sep=",")
        data_frames.append(data_frame)


    for col_name in data_frames[0].columns:
        
        data = list()
        for data_frame in data_frames:
            data.append(statistics.mean(data_frame[col_name].values))



        fig, ax = plt.subplots(1, 1) 
        
        plt.bar(labels,  data, width = 0.4) 

        ax.set_xlabel(col_name) 
        ax.set_ylabel("seconds")

        plt.savefig("graphs/timing_HR/"+col_name+ '.png')


if __name__=="__main__":
    
    plot_speed_data("./measures/timing_HR")

    files = os.listdir("./data")

    for file in files:
        pass
        plot_model_data(file)
