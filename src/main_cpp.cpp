#include "../include/HindmarshRose.h"

#include <chrono>

int main()
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
  
    HindmarshRose *regular_model = new HindmarshRose(0.001, "./data/HidmarshRoseRegular_cpp.dat", 3.0, 0.0021, 4.0);
    regular_model->objective_loop_stationary_yz(-1.3, 5000.0);
    
    std::chrono::steady_clock::time_point end_function = std::chrono::steady_clock::now();

    HindmarshRose *chaotic_model = new HindmarshRose(0.001, "./data/HidmarshRoseChaotic_cpp.dat", 3.281, 0.0021, 4.0);

    chaotic_model->objective_loop_stationary_yz(-1.3, 5000.0);

    HindmarshRose *regular_model_continue = new HindmarshRose(regular_model->time, 0.001, "./data/HidmarshRoseRegularContinue_cpp.dat", 3.0, 0.0021, 4.0);
    HindmarshRose *chaotic_model_continue = new HindmarshRose(chaotic_model->time, 0.001, "./data/HidmarshRoseChaoticContinue_cpp.dat", 3.281, 0.0021, 4.0);

    regular_model_continue->objective_loop(regular_model->x, regular_model->y, regular_model->z, 10000.0);

    chaotic_model_continue->objective_loop(chaotic_model->x, chaotic_model->y, chaotic_model->z, 10000.0);
    std::chrono::steady_clock::time_point end_all_functions = std::chrono::steady_clock::now();

    regular_model->write_vector();
    chaotic_model->write_vector();

    regular_model_continue->write_vector();
    chaotic_model_continue->write_vector();
    std::chrono::steady_clock::time_point end_writing_operations = std::chrono::steady_clock::now();

    regular_model->free();
    chaotic_model->free();

    regular_model_continue->free();
    chaotic_model_continue->free();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::ofstream outfile;

    outfile.open("./measures/timing_HR/speed_cpp.txt");

    outfile << "function_time,all_functions_time,writing_operations,program_after_writing,frees,total_program\n";

    outfile << std::chrono::duration<double>(end_function - start).count() << ",";
    outfile << std::chrono::duration<double>(end_all_functions - start).count() << ",";
    outfile << std::chrono::duration<double>(end_writing_operations - end_all_functions).count() << ",";
    outfile << std::chrono::duration<double>(end_writing_operations - start).count() << ",";
    outfile << std::chrono::duration<double>(end - end_writing_operations).count() << ",";
    outfile << std::chrono::duration<double>(end - start).count() << "\n";
}
