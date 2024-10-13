/**
 * @file rulkov_map.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the c functions
 * @version 0.1
 * @date 2024-07-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef RULKOV_MAP_H
#define RULKOV_MAP_H

#include "../constants.h"
#include "model.h"

typedef struct _RulkovMap
{
    float x;
    float y;
    float o;
    float a;
    float B;
    float m;
    Model *model;
} RulkovMap;

/**
 * @brief This function initialices the model.
 *
 * @param start_time time to start
 * @param time_increment incremet of the time (time step)
 * @param initial_x initial value of slow variable
 * @param o value of the external bias current (or regime control)
 * @param a value of the a control map parameter
 * @param B value of the synaptic impulses
 * @param m parameter of small values
 * @return Returns the model initialized.
 */
RulkovMap *rulkovmap_new_y(double start_time, double time_increment, int elements_in_model, float initial_x, float o, float a, float B, float m);

/**
 * @brief This function initialices the model.
 *
 * @param start_time time to start
 * @param time_increment incremet of the time (time step)
 * @param initial_x initial value of slow variable
 * @param initial_y initial value of slow variable
 * @param o value of the external bias current (or regime control)
 * @param a value of the a control map parameter
 * @param B value of the synaptic impulses
 * @param m parameter of small values
 * @return Returns the model initialized.
 */
RulkovMap *rulkovmap_new(double start_time, double time_increment, int elements_in_model, float initial_x, float initial_y, float o, float a, float B, float m);

/**
 * @brief This iterates and simulates the model
 * @param target_time the target time
 * @param calculate function to calculate
 *
 */
void rulkovmap_objective_loop(RulkovMap *model, double target_time);

/**
 * @brief This iterates and simulates the model
 * @param iterations number of iterations
 * @param calculate function to calculate
 *
 */
void rulkovmap_iterations_loop(RulkovMap *model, int iterations);

/**
 * @brief This function allocates the memory of the array
 * @param filename the name of the file
 *
 */
void rulkovmap_write_on_file(RulkovMap *rulkovmap, const char *filename);

/**
 * @brief This function frees the memory of the rulkovmap model
 *
 */
void rulkovmap_free(RulkovMap *rulkovmap);

#endif /* RULKOV_MAP_H */