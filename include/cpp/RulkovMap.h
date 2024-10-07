/**
 * @file RulkovMap.h
 * @author Sergio Hidalgo (sergio.hidalgo@estudiante.uam.es)
 * @brief Definition file for the Rulkov-Map model class
 * @version 0.1
 * @date 2024-10-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef RULKOVMAP_H
#define RULKOVMAP_H

#include "Model.h"

/**
 * @class RulkovMap
 * @brief This function initialices the model.
 *
 * @param x value of fast variable
 * @param y value of slow variable
 * @param o value of the external bias current (or regime control)
 * @param B value of the synaptic impulses
 * @param m parameter of small values
 * @param a value of the a control map parameter
 *
 */
class RulkovMap : public Model
{

public:

    float x;
    float y;
    float o;
    float B;
    float m;
    float a;

public:
    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x initial value of fast variable
     * @param o value of the external bias current (or regime control)
     * @param a value of the a control map parameter
     * @param B value of the synaptic impulses
     * @param m parameter of small values
     * @return Returns the model initialized.
     */
    RulkovMap(double time_increment, const char *filename, int elements_in_model, float initial_x, float o, float a, float B, float m);

    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_y initial value of slow variable
     * @param o value of the external bias current (or regime control)
     * @param a value of the a control map parameter
     * @param B value of the synaptic impulses
     * @param m parameter of small values
     * @return Returns the model initialized.
     */
    RulkovMap(double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y,  float o, float a, float B, float m);

    /**
     * @brief This function initialices the model.
     *
     * @param start_time time to start
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x initial value of fast variable
     * @param o value of the external bias current (or regime control)
     * @param a value of the a control map parameter
     * @param B value of the synaptic impulses
     * @param m parameter of small values
     * @return Returns the model initialized.
     */
    RulkovMap(double start_time, double time_increment, const char *filename, int elements_in_model, float initial_x, float o, float a, float B, float m);

    /**
     * @brief This function initialices the model.
     *
     * @param start_time time to start
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_y initial value of slow variable
     * @param o value of the external bias current (or regime control)
     * @param a value of the a control map parameter
     * @param B value of the synaptic impulses
     * @param m parameter of small values
     * @return Returns the model initialized.
     */
    RulkovMap(double start_time,double time_increment, const char *filename, int elements_in_model, float initial_x, float initial_y,  float o, float a, float B, float m);



    /**
     * @brief This function calculates t + t_increment on the model.
     * 
     * @param index indicates where to store the variables in the array
     */
    void calculate(int index);


private:

    /**
     * @brief This function calculates stationary_y.
     *
     */
    void calculate_stationary_y();

};

#endif /* RULKOVMAP_H */