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
        X_Stationary,
        Y_Stationary,
        XY_Stationary,
        None_Stationar
    };

    float x;
    float y;
    float z;
    float e;
    float S;
    float m;

private:
    bool perpetual;

public:
    /**
     * @brief This function initialices the model.
     *
     * @param x value x
     * @param y the value y
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(double time_increment, const char *filename, float e, float m, float S);

    /**
     * @brief This function is the constructor of the models.
     *
     * @param x value x
     * @param y the value y
     * @param start_time time for the nodel to start
     * @param time_increment incremet of the time (time step)
     * @param filename name of the file to write
     * @param m value of the m constant
     * @param e value of the e constant (> 3.0  is chaotic)
     * @param S value of the S constant
     *
     * @return Returns the model initialized.
     */
    HindmarshRose(float start_time, double time_increment, const char *filename, float e, float m, float S);

    /**
     * @brief This function calculates t + t_increment on the model.
     *
     *
     */

    void calculate();

    /**
     * @brief This function loops t + t_increment until it reaches the target and
     *  calculates y and z in stationary mode.
     *
     * @param x value x
     * @param target_time time to reach
     */
    void objective_loop_stationary_yz(float x, double time);

    /**
     * @brief This function loops t + t_increment until it reaches the target
     * and calculates both z and y in stationary mode.
     *
     * @param x value x
     * @param y value y
     * @param target_time time to reach
     */
    void objective_loop_stationary_z(float x, float y, double target_time);

    /**
     * @brief This function loops t + t_increment until it reaches the target
     * and calculates z in stationary mode.
     *
     * @param x value x
     * @param z value z
     * @param target_time time to reach
     */
    void objective_loop_stationary_y(float x, float z, double target_time);

    /**
     * @brief This function loops t + t_increment until it reaches the target.
     *
     * @param x value x
     * @param z value z
     * @param target_time time to reach
     */
    void objective_loop(float x, float y, float z, double target_time);

    /**
     * @brief This function loops t + t_increment N times and
     *  calculates y and z in stationary mode.
     *
     * @param x value x
     * @param iterations the N times
     */
    void iterations_loop_stationary_yz(float x, int iterations);

    /**
     * @brief This function loops t + t_increment N times and
     *  calculates y and z in stationary mode.
     *
     * @param x value x
     * @param y value y
     * @param iterations the N times
     */
    void iterations_loop_stationary_z(float x, float y, int iterations);

    /**
     * @brief This function loops t + t_increment N times and
     *  calculates y in stationary mode.
     *
     * @param x value x
     * @param z value z
     * @param iterations the N times
     */
    void iterations_loop_stationary_y(float x, float z, int iterations);

    /**
     * @brief This function loops t + t_increment N times.
     *
     * @param x value x
     * @param z value z
     * @param iterations the N times
     */
    void iterations_loop(float x, float y, float z, int iterations);

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
     * @brief This function saves x,y,z and the actual time.
     *
     */
    void save();
};

#endif /* HINDMARSHROSE_H */