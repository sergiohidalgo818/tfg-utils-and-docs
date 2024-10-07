/**
 * @file Model.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the model class
 * @version 0.1
 * @date 2024-07-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MODEL_H
#define MODEL_H

#include <fstream>
#include "../constants.h"

/**
 * @class Model
 * @brief This class implements the base class model.
 *
 * @param data_rows number of data rows
 * @param data_cols number of data colummns
 * @param time the value of the time
 * @param time_increment the value of the time increment
 * @param outfile outfile to print the data
 * @param data values of data
 * @param perpetual indicates that the model will execute perpetually
 * @param elements_in_model number of elements in model
 *
 */
class Model
{

public:
    int data_rows;
    int data_cols;
    double time;
    double time_increment;
    std::ofstream outfile;
    float **data;
    bool perpetual;
    int elements_in_model;
public:
    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param elements_in_model number of elements in model
     *
     * @return Returns the model initialized.
     */
    Model(double time_increment, const char *filename, int elements_in_model);

    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param start_time time of starting
     * @param elements_in_model number of elements in model

     * @return Returns the model initialized.
     */
    Model(double time_increment, const char *filename, int elements_in_model, double start_time);

    /**
     * @brief This function calculates t + t_increment on the model.
     * 
     * @param index indicates where to store the variables in the array
     */
    virtual void calculate(int index) {}

    /**
     * @brief This function loops t + t_increment until it reaches the target.
     *
     * @param target_time time to reach
     */
    void objective_loop(double target_time);

    /**
     * @brief This function loops t + t_increment N times.
     *
     * @param iterations the N times
     */
    void iterations_loop(int iterations);

    /**
     * @brief This function writes the data on file.
     *
     */
    void write_data();

    /**
     * @brief This function allocates an array.
     *
     */
    void allocate_array(double start_time, double target_time);

    /**
     * @brief This function allocates an array.
     *
     */
    void allocate_array(int iterations);

    /**
     * @brief This function frees the data the data on file.
     *
     */
    void free();
};

#endif /* MODEL_H */