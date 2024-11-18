/**
 * @file main_syn_hr_cpp.cpp
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Main file for the execution of the Hindmarsh-Rose fast synaptic model in c++
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../../include/cpp/HindmarshRoseFastSyn.h"

#include <chrono>

int main()
{
    const char *filename = "./data/timings_syn_HR/speed_cpp.csv";
    float gsync1 = 0.241, gsync2 = 0.186;
    // float gsync1=0.02/1000000, gsync2=0.005/1000000;
    // float Sfast = 0.2, Esyn = -75, Vfast = -50;
    float Sfast=0.44, Esyn=-1.92, Vfast=-1.66;
    FILE *file;
    int i, first_loop = 5000, second_loop = 10000;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    HindmarshRose *regular_stationary = new HindmarshRose(0, 0.001, "./data/executions_HR_syn/cpp/HR_syn_regular_neuron1_cpp.csv",
                                                          ELEMENTS_HR, -1.3, 3.0, M_VAL, 4.0);

    HindmarshRose *chaotic_stationary = new HindmarshRose(0, 0.001, "./data/executions_HR_syn/cpp/HR_syn_regular_neuron2_cpp.csv",
                                                           ELEMENTS_HR, -1.3, 3.281, M_VAL, 4.0);

    regular_stationary->objective_loop(5000);
    chaotic_stationary->objective_loop(5000);

    HindmarshRoseFastSyn *regular_model = new HindmarshRoseFastSyn(0, 0.001, "./data/executions_HR_syn/cpp/HR_syn_regular_neuron1_cpp.csv",
                                                                   ELEMENTS_HR, regular_stationary->x, regular_stationary->y, regular_stationary->z,
                                                                   3.0, M_VAL, 4.0, gsync1, Sfast, Esyn, Vfast);

    HindmarshRoseFastSyn *regular_model2 = new HindmarshRoseFastSyn(0, 0.001, "./data/executions_HR_syn/cpp/HR_syn_regular_neuron2_cpp.csv",
                                                                    ELEMENTS_HR, regular_stationary->x, regular_stationary->y, regular_stationary->z,
                                                                    3.0, M_VAL, 4.0, gsync2, Sfast, Esyn, Vfast);

    HindmarshRoseFastSyn *chaotic_model = new HindmarshRoseFastSyn(0, 0.001, "./data/executions_HR_syn/cpp/HR_syn_chaotic_neuron1_cpp.csv",
                                                                   ELEMENTS_HR, chaotic_stationary->x, chaotic_stationary->y, chaotic_stationary->z,
                                                                   3.281, M_VAL, 4.0, gsync1, Sfast, Esyn, Vfast);

    HindmarshRoseFastSyn *chaotic_model2 = new HindmarshRoseFastSyn(0, 0.001, "./data/executions_HR_syn/cpp/HR_syn_chaotic_neuron2_cpp.csv",
                                                                    ELEMENTS_HR, chaotic_stationary->x, chaotic_stationary->y, chaotic_stationary->z,
                                                                    3.281, M_VAL, 4.0, gsync2, Sfast, Esyn, Vfast);

    regular_model->allocate_array(0, first_loop);
    regular_model2->allocate_array(0, first_loop);
    i = 0;
    while ((first_loop - regular_model->time) > DECIMAL_PRECISION)
    {
        regular_model->Vspre = regular_model2->x;
        regular_model2->Vspre = regular_model->x;
        regular_model->calculate(i);
        regular_model2->calculate(i);
        i++;
    }

    std::chrono::steady_clock::time_point end_function = std::chrono::steady_clock::now();

    chaotic_model->allocate_array(0, first_loop);
    chaotic_model2->allocate_array(0, first_loop);

    i = 0;
    while ((first_loop - chaotic_model->time) > DECIMAL_PRECISION)
    {
        chaotic_model->Vspre = chaotic_model2->x;
        chaotic_model2->Vspre = chaotic_model->x;
        chaotic_model->calculate(i);
        chaotic_model2->calculate(i);
        i++;
    }

    HindmarshRoseFastSyn *regular_model_continue = new HindmarshRoseFastSyn(regular_model->time, 0.001, "./data/executions_HR_syn/cpp/HR_syn_regular_neuron1_continue_cpp.csv",
                                                                            ELEMENTS_HR, regular_model->x, regular_model->y, regular_model->z, 3.0,
                                                                            M_VAL, 4.0, gsync1, Sfast, Esyn, Vfast);

    HindmarshRoseFastSyn *regular_model2_continue = new HindmarshRoseFastSyn(regular_model2->time, 0.001, "./data/executions_HR_syn/cpp/HR_syn_regular_neuron2_continue_cpp.csv",
                                                                             ELEMENTS_HR, regular_model2->x, regular_model2->y, regular_model2->z, 3.0,
                                                                             M_VAL, 4.0, gsync2, Sfast, Esyn, Vfast);

    HindmarshRoseFastSyn *chaotic_model_continue = new HindmarshRoseFastSyn(chaotic_model->time, 0.001, "./data/executions_HR_syn/cpp/HR_syn_chaotic_neuron1_continue_cpp.csv",
                                                                            ELEMENTS_HR, chaotic_model->x, chaotic_model->y, chaotic_model->z, 3.281,
                                                                            M_VAL, 4.0, gsync1, Sfast, Esyn, Vfast);

    HindmarshRoseFastSyn *chaotic_model2_continue = new HindmarshRoseFastSyn(chaotic_model2->time, 0.001, "./data/executions_HR_syn/cpp/HR_syn_chaotic_neuron2_continue_cpp.csv",
                                                                             ELEMENTS_HR, chaotic_model2->x, chaotic_model2->y, chaotic_model2->z, 3.281,
                                                                             M_VAL, 4.0, gsync2, Sfast, Esyn, Vfast);

    regular_model_continue->allocate_array(regular_model->time, second_loop);
    regular_model2_continue->allocate_array(regular_model2->time, second_loop);
    chaotic_model_continue->allocate_array(chaotic_model->time, second_loop);
    chaotic_model2_continue->allocate_array(chaotic_model2->time, second_loop);

    i = 0;
    while ((second_loop - regular_model_continue->time) > DECIMAL_PRECISION)
    {
        regular_model_continue->Vspre = regular_model2_continue->x;
        regular_model2_continue->Vspre = regular_model_continue->x;

        chaotic_model_continue->Vspre = chaotic_model2_continue->x;
        chaotic_model2_continue->Vspre = chaotic_model_continue->x;

        regular_model_continue->calculate(i);
        regular_model2_continue->calculate(i);

        chaotic_model_continue->calculate(i);
        chaotic_model2_continue->calculate(i);
        i++;
    }

    std::chrono::steady_clock::time_point end_all_functions = std::chrono::steady_clock::now();

    regular_model->write_data();
    regular_model2->write_data();

    regular_model_continue->write_data();
    regular_model2_continue->write_data();

    chaotic_model->write_data();
    chaotic_model2->write_data();

    chaotic_model_continue->write_data();
    chaotic_model2_continue->write_data();

    std::chrono::steady_clock::time_point end_writing_operations = std::chrono::steady_clock::now();

    regular_stationary->free();
    chaotic_stationary->free();

    regular_model->free();
    regular_model2->free();

    regular_model_continue->free();
    regular_model2_continue->free();

    chaotic_model->free();
    chaotic_model2->free();

    chaotic_model_continue->free();
    chaotic_model2_continue->free();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::ofstream outfile;

    if (!(file = fopen(filename, "r")))
    {
        outfile.open(filename);
        outfile << "function_time;all_functions_time;writing_operations;program_after_writing;frees;total_program\n";
    }
    else
    {
        fclose(file);
        outfile.open(filename, std::ios_base::app);
    }

    outfile << std::chrono::duration<double>(end_function - start).count() << ";";
    outfile << std::chrono::duration<double>(end_all_functions - start).count() << ";";
    outfile << std::chrono::duration<double>(end_writing_operations - end_all_functions).count() << ";";
    outfile << std::chrono::duration<double>(end_writing_operations - start).count() << ";";
    outfile << std::chrono::duration<double>(end - end_writing_operations).count() << ";";
    outfile << std::chrono::duration<double>(end - start).count() << "\n";
}
