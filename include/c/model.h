/**
 * @file model.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the c functions
 * @version 0.1
 * @date 2024-10-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MODEL_H
#define MODEL_H

#include "../constants.h"

typedef struct _Model
{
    int data_rows;
    int data_cols;
    double time;
    double time_increment;
    float *data;
    void *model_type;
} Model;

/**
 * @brief This function creates a new model allocating memory for it
 * @param time_increment the increment of the time
 * @param elements_in_model the numer of elements in the model
 *
 */
Model *model_new(double start_time, double time_increment, int elements_in_model, void *model_type);

/**
 * @brief This iterates and simulates the model
 * @param target_time the target time
 * @param calculate function to calculate
 *
 */
void model_objective_loop(Model *model, double target_time, void (*calculate)(Model *, int));

/**
 * @brief This iterates and simulates the model
 * @param iterations number of iterations
 * @param calculate function to calculate
 *
 */
void model_iterations_loop(Model *model, int iterations, void (*calculate)(Model *, int));

/**
 * @brief This function allocates the memory of the array
 * @param target_time the time stop
 *
 */
void model_allocate_array_time(Model *model, double target_time);

/**
 * @brief This function allocates the memory of the array
 * @param iterations number of iterations
 *
 */
void model_allocate_array_iterations(Model *model, int iterations);

/**
 * @brief This function writes on a file
 * @param header_of_file the header of the file (name of the columns)
 * @param file_name the name of the file
 *
 */
void model_write_on_file(Model *model, const char *file_name, const char *header_of_file, int save_every);

/**
 * @brief This function frees the memory of the model
 *
 */
void model_free(Model *model);

#endif /* MODEL_H */