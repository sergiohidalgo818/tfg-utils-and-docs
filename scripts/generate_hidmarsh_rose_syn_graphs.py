import os
import pandas as pd
import matplotlib.pyplot as plt

if __name__=="__main__":
    

    folders = os.listdir("./data/executions_HR_syn/")

    contents = [('regular', 'continue')]

    for folder in folders:
        all_files = os.listdir("./data/executions_HR_syn/"+folder)
        type_model='HR_syn'

        list1=['HR_syn_regular_neuron1_cpp.csv','HR_syn_regular_neuron2_cpp.csv']
        list2=['HR_syn_chaotic_neuron1_cpp.csv','HR_syn_chaotic_neuron2_cpp.csv']
        list3=['HR_syn_regular_neuron1_continue_cpp.csv','HR_syn_regular_neuron2_continue_cpp.csv']
        list4=['HR_syn_chaotic_neuron1_continue_cpp.csv','HR_syn_chaotic_neuron2_continue_cpp.csv']


        for files in [list1, list2, list3, list4]:
            plt.figure( figsize=(12,6) )

            for file in files:
                directory="./data/executions_HR_syn/"+folder+ "/"
                filename=file

                if not os.path.exists("graphs/executions_"+type_model+"/" + folder):
                    os.makedirs("graphs/executions_"+type_model+"/" + folder)

                if  os.path.exists(directory+filename):

                    data_frame = pd.read_csv(directory + filename, sep=";")
                    data_frame = data_frame[['x', 'time']]

                    plt.plot(data_frame["time"], data_frame["x"]) 
                    plt.xlim((data_frame['time'].min(), data_frame['time'].max()))
                    plt.ylim((-1.5, 2.5))

            if len(files)>0:
                print("ploting " + type_model+ "_" + filename)
                plt.savefig("graphs/executions_"+type_model+"/"  + folder + "/"+ filename+ '.png')
                plt.close()



            
