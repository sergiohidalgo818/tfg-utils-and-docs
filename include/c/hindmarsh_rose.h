/**
 * @file hindmarsh_rose.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the c functions
 * @version 0.1
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef HINDMARSH_ROSE_H
#define HINDMARSH_ROSE_H

#include "../constants.h"
#include "model.h"


/**
 * @enum StationaryMode
 * @brief enum for the stationary variable.
 */
typedef enum
{
  Y_STATIONARY = 1,
  Z_STATIONARY = 2 
} StationaryMode;

typedef struct _HindmarshRose 
{
    float x;
    float y;
    float z;
    float e;
    float m;
    float S;
    float v;
    StationaryMode mode;
    Model *model;
}HindmarshRose;

/**
 * @brief This function simulates the hindmarsh rose model, z and y are stationary.
 *
 * @param time_increment incremet of the time (time step)
 * @param start_time the t  e when the model starts
 * @param elements_in_model number of elements in the model
 * @param initial_x value x
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant
 * @param S value of the S constant
 * @param v value of the v constant
 *
 * @return Returns the array of values.
 */
HindmarshRose *hindmarshrose_new_yz( double start_time, double time_increment, int elements_in_model,float initial_x, float e, float m, float S, float v);

/**
 * @brief This function simulates the hindmarsh rose model, z and y are stationary.
 *
 * @param time_increment incremet of the time (time step)
 * @param start_time the t  e when the model starts
 * @param elements_in_model number of elements in the model
 * @param initial_x value x
 * @param initial_yz value of y or z
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant
 * @param S value of the S constant
 * @param v value of the v constant
 *
 * @return Returns the array of values.
 */
HindmarshRose *hindmarshrose_new_y_or_z( double start_time,double time_increment, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, float v, StationaryMode mode);



/**
 * @brief This function simulates the hindmarsh rose model
 *
 * @param start_time the time when the model starts
 * @param time_increment incremet of the time (time step)
 * @param initial_x value x
 * @param initial_y the value y
 * @param initial_z the value z
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant
 * @param S value of the S constant
 * @param v value of the v constant
 *
 * @return Returns the array of values.
 */
HindmarshRose *hindmarshrose_new( double start_time, double time_increment,  int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S, float v);


/**
 * @brief This iterates and simulates the model
 * @param target_time the target time
 *
 */
void hindmarshrose_objective_loop(HindmarshRose *model, double target_time);


/**
 * @brief This iterates and simulates the model
 * @param iterations number of iterations
 *
 */
void hindmarshrose_iterations_loop(HindmarshRose *model, int iterations);


/**
 * @brief This function allocates the memory of the array
 * @param filename the name of the file
 *
 */
void hindmarshrose_write_on_file(HindmarshRose *hindmarshrose, const char* filename, int save_every);

/**
 * @brief This function frees the memory of the hindmarshrose model
 *
 */
void hindmarshrose_free(HindmarshRose *hindmarshrose);


#endif /* HINDMARSH_ROSE_H */