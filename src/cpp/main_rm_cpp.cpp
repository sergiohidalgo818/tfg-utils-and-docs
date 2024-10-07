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

#include "../../include/cpp/RulkovMap.h"

#include <chrono>

int main()
{
    const char *filename = "./data/timings_RM/speed_cpp.csv";
    FILE *file;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    RulkovMap *a_model = new RulkovMap(0.001, "./data/executions_RM/cpp/RM_a_cpp.csv", ELEMENTS_RM, -1, 0.14, 0, M_VAL, 4.5);

    a_model->objective_loop(2000.0);

    std::chrono::steady_clock::time_point end_function = std::chrono::steady_clock::now();

    RulkovMap *b_model = new RulkovMap(0.001, "./data/executions_RM/cpp/RM_b_cpp.csv", ELEMENTS_RM, -1, -0.1, 0, M_VAL, 6.0);

    b_model->objective_loop(2000.0);

    RulkovMap *c_model = new RulkovMap(0.001, "./data/executions_RM/cpp/RM_c_cpp.csv", ELEMENTS_RM, -1, 0.386, 0, M_VAL, 6.0);

    c_model->objective_loop(2000.0);

    RulkovMap *a_model_continue = new RulkovMap(0.001, "./data/executions_RM/cpp/RM_a_cpp_continue.csv", ELEMENTS_RM,  a_model->x, a_model->y, 0.14, 0, M_VAL, 4.5);
    RulkovMap *b_model_continue = new RulkovMap(0.001, "./data/executions_RM/cpp/RM_b_cpp_continue.csv", ELEMENTS_RM, b_model->x, b_model->y, -0.1, 0, M_VAL, 6.0);
    RulkovMap *c_model_continue = new RulkovMap(0.001, "./data/executions_RM/cpp/RM_b_cpp_continue.csv", ELEMENTS_RM, c_model->x, c_model->y, 0.386, 0, M_VAL, 6.0);

    a_model_continue->objective_loop(4000.0);
    b_model_continue->objective_loop(4000.0);
    c_model_continue->objective_loop(4000.0);

    std::chrono::steady_clock::time_point end_all_functions = std::chrono::steady_clock::now();

    a_model->write_data();
    b_model->write_data();
    c_model->write_data();   

    a_model_continue->write_data();
    b_model_continue->write_data();
    c_model_continue->write_data();


    std::chrono::steady_clock::time_point end_writing_operations = std::chrono::steady_clock::now();

    a_model->free();
    b_model->free();
    c_model->free();   

    a_model_continue->free();
    b_model_continue->free();
    c_model_continue->free();

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
