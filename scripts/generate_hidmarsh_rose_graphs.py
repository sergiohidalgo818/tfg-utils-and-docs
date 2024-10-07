import os

from generate_graphs import plot_speed_data, plot_model_data

if __name__=="__main__":
    
    plot_speed_data("./data/timings_HR", 'HR')

    folders = os.listdir("./data/executions_HR/")

    for folder in folders:
        files = os.listdir("./data/executions_HR/"+folder)
        for file in files:
            plot_model_data("./data/executions_HR/"+folder+ "/", file,'HR')
