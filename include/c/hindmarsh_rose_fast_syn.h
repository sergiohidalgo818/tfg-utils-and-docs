/**
 * @file hindmarsh_rose_fast_syn.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the c functions
 * @version 0.1
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef HINDMARSH_ROSE_FAST_SYN_H
#define HINDMARSH_ROSE_FAST_SYN_H

#include "../constants.h"
#include "hindmarsh_rose.h"

typedef struct _HindmarshRoseFastSyn
{
  float Vspre;
  float gfast;
  float Esyn;
  float Sfast;
  float Vfast;
  HindmarshRose *hr_model;
} HindmarshRoseFastSyn;

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
 * @param gfast value of the g fast constant
 * @param Sfast value of the S fast constant
 * @param Esyn value of the E constant
 * @param Vfast value of the V fast constant
 * 
 * @return Returns the array of values.
 */
HindmarshRoseFastSyn *hindmarshrosefastsyn_new_yz(double start_time, double time_increment, int elements_in_model, float initial_x, float e, float m, float S, float v, float gfast, float Sfast, float Esyn, float Vfast);

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
 * @param gfast value of the g fast constant
 * @param Sfast value of the S fast constant
 * @param Esyn value of the E constant
 * @param Vfast value of the V fast constant
 * 
 * @return Returns the array of values.
 */
HindmarshRoseFastSyn *hindmarshrosefastsyn_new_y_or_z(double start_time, double time_increment, int elements_in_model, float initial_x, float initial_yz, float e, float m, float S, float v, StationaryMode mode, float gfast, float Sfast, float Esyn, float Vfast);

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
 * @param gfast value of the g fast constant
 * @param Sfast value of the S fast constant
 * @param Esyn value of the E constant
 * @param Vfast value of the V fast constant
 * 
 * @return Returns the array of values.
 */
HindmarshRoseFastSyn *hindmarshrosefastsyn_new(double start_time, double time_increment, int elements_in_model, float initial_x, float initial_y, float initial_z, float e, float m, float S, float v, float gfast, float Sfast, float Esyn, float Vfast);

/**
 * @brief This function calculates t + t_increment on the model.
 *
 * @param index indicates where to store the variables in the array
 * @param Vspre value of the other neuron
 */
void hindmarshrosefastsyn_calculate(HindmarshRoseFastSyn *hindmarshrosefastsyn, int index, float Vspre);

/**
 * @brief This function allocates the memory of the data array
 * @param iterations The number of iterations
 *
 */
void hindmarshrosefastsyn_allocate_array_iterations(HindmarshRoseFastSyn *hindmarshrosefastsyn, int iterations);


/**
 * @brief This function allocates the memory of the data array
 * @param target_time The number of iterations
 *
 */
void hindmarshrosefastsyn_allocate_array_time(HindmarshRoseFastSyn *hindmarshrosefastsyn, double target_time);

/**
 * @brief This function writes on file
 * @param filename The file name
 *
 */
void hindmarshrosefastsyn_write_on_file(HindmarshRoseFastSyn *hindmarshrose, const char *filename, int save_every);

/**
 * @brief This function frees the memory of the hindmarshrose model
 *
 */
void hindmarshrosefastsyn_free(HindmarshRoseFastSyn *hindmarshrose);



#endif /* HINDMARSH_ROSE_FAST_SYN_H */