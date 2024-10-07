/**
 * @file main_cpp.cpp
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Main file for the execution of the Hindmarsh-Rose model in c++
 * @version 0.1
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../../include/cpp/HindmarshRose.h"

#include <chrono>

int main()
{
    const char *filename = "./data/timings_HR/speed_cpp.csv";
    FILE *file;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    HindmarshRose *regular_model = new HindmarshRose(0.001, "./data/executions_HR/cpp/HR_regular_cpp.csv", ELEMENTS_HR,-1.3, 3.0, 0.0021, 4.0);

    regular_model->objective_loop(5000.0);

    std::chrono::steady_clock::time_point end_function = std::chrono::steady_clock::now();

    HindmarshRose *chaotic_model = new HindmarshRose(0.001, "./data/executions_HR/cpp/HR_chaotic_cpp.csv", ELEMENTS_HR, -1.3, 3.281, 0.0021, 4.0);

    chaotic_model->objective_loop(5000.0);



    HindmarshRose *regular_model_continue = new HindmarshRose(regular_model->time, 0.001, "./data/executions_HR/cpp/HR_regular_continue_cpp.csv", ELEMENTS_HR, regular_model->x, regular_model->y, regular_model->z, 3.0, 0.0021, 4.0);
    HindmarshRose *chaotic_model_continue = new HindmarshRose(chaotic_model->time, 0.001, "./data/executions_HR/cpp/HR_chaotic_continue_cpp.csv", ELEMENTS_HR, chaotic_model->x, chaotic_model->y, chaotic_model->z, 3.281, 0.0021, 4.0);

    regular_model_continue->objective_loop(10000.0);

    chaotic_model_continue->objective_loop(10000.0);

    std::chrono::steady_clock::time_point end_all_functions = std::chrono::steady_clock::now();

    regular_model->write_data();
    chaotic_model->write_data();

    regular_model_continue->write_data();
    chaotic_model_continue->write_data();
    std::chrono::steady_clock::time_point end_writing_operations = std::chrono::steady_clock::now();

    regular_model->free();
    chaotic_model->free();

    regular_model_continue->free();
    chaotic_model_continue->free();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::ofstream outfile;



    if (!(file = fopen(filename, "r"))) {
        outfile.open(filename);
        outfile << "function_time,all_functions_time,writing_operations,program_after_writing,frees,total_program\n";
    } 
    else
    {
        fclose(file);
        outfile.open(filename,  std::ios_base::app);
    }
    

    outfile << std::chrono::duration<double>(end_function - start).count() << ",";
    outfile << std::chrono::duration<double>(end_all_functions - start).count() << ",";
    outfile << std::chrono::duration<double>(end_writing_operations - end_all_functions).count() << ",";
    outfile << std::chrono::duration<double>(end_writing_operations - start).count() << ",";
    outfile << std::chrono::duration<double>(end - end_writing_operations).count() << ",";
    outfile << std::chrono::duration<double>(end - start).count() << "\n";
}
