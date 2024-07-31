#ifndef HINDMARSHROSE_H
#define HINDMARSHROSE_H

#include "Model.h"


/**
 * @class This class implements the model of hindmarsh-Rose.
 *
 * @param x value x
 * @param y the value y
 * @param z the value z
 * @param e value of the e constant (> 3.0  is chaotic)
 * @param m value of the m constant
 * @param S value of the S constant
 *
 */
class HindmarshRose : public Model
{

public:
    enum StationaryMode
    {
        Z_Stationary,
        Y_Stationary,
        ZY_Stationary,
        None_Stationary
    };

    float x;
    float y;
    float z;
    float e;
    float S;
    float m;
    HindmarshRose::StationaryMode mode;


public:
    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(double time_increment, const char *filename, float initial_x, float e, float m, float S);

    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param initial_x value of intial x
     * @param initial_y value of intial y
     * @param initial_z value of intial z
     * @param filename name of the file to write
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(double time_increment, const char *filename, float initial_x, float initial_y, float initial_z, float e, float m, float S);

    /**
     * @brief This function initialices the model.
     *
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param initial_yz value of initial y or value of initial z (depends on the mode)
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     * @param mode mode of the stationary values
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(double time_increment, const char *filename, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode);

    /**
     * @brief This function initialices the model.
     *
     * @param start_time time of starting
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(float start_time, double time_increment, const char *filename, float initial_x, float e, float m, float S);

    /**
     * @brief This function initialices the model.
     *
     * @param start_time time of starting
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param initial_y value of intial y
     * @param initial_z value of intial z
     * @param y value y
     * @param z value z
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(float start_time, double time_increment, const char *filename, float initial_x, float initial_y, float initial_z, float e, float m, float S);

    /**
     * @brief This function initialices the model.
     *
     * @param start_time time of starting
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param initial_x value of intial x
     * @param initial_yz value of initial y or value of initial z (depends on the mode)
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     * @param mode mode of the stationary values
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(float start_time, double time_increment, const char *filename, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode);

    /**
     * @brief This function calculates t + t_increment on the model.
     *
     */
    void calculate();

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

private:
    /**
     * @brief This function calculates stationary_z.
     *
     */
    void calculate_stationary_z();

    /**
     * @brief This function calculates stationary_y.
     *
     */
    void calculate_stationary_y();

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
};

#endif /* HINDMARSHROSE_H */