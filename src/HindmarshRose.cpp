#include "../include/HindmarshRose.h"

HindmarshRose::HindmarshRose(double time_increment, const char *filename, float initial_x, float e, float m, float S) : Model(time_increment, filename)
{
    this->x = initial_x;

    this->e = e;
    this->m = m;
    this->S = S;

    this->calculate_stationary_y();

    this->calculate_stationary_z();

    this->outfile << "x,y,z,time\n";
}

HindmarshRose::HindmarshRose(double time_increment, const char *filename, float initial_x, float initial_y, float initial_z, float e, float m, float S) : Model(time_increment, filename)
{
    this->x = initial_x;
    this->y = initial_y;
    this->z = initial_z;

    this->e = e;
    this->m = m;
    this->S = S;

    this->calculate_stationary_y();
    this->calculate_stationary_z();

    this->outfile << "x,y,z,time\n";
}

HindmarshRose::HindmarshRose(double time_increment, const char *filename, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode) : Model(time_increment, filename)
{
    this->x = x;

    this->e = e;
    this->m = m;
    this->S = S;

    if (HindmarshRose::StationaryMode::Y_Stationary == mode)
    {
        this->z = initial_yz;

        this->calculate_stationary_y();
    }
    else if (HindmarshRose::StationaryMode::Z_Stationary == mode)
    {
        this->y = initial_yz;
        this->calculate_stationary_z();
    }
    else
    {
        this->calculate_stationary_y();
        this->calculate_stationary_z();
    }

    this->outfile << "x,y,z,time\n";
}

HindmarshRose::HindmarshRose(float start_time, double time_increment, const char *filename, float initial_x, float e, float m, float S) : Model(time_increment, filename, start_time)
{
    this->x = initial_x;

    this->e = e;
    this->m = m;
    this->S = S;

    this->calculate_stationary_y();
    this->calculate_stationary_z();

    this->outfile << "x,y,z,time\n";
}

HindmarshRose::HindmarshRose(float start_time, double time_increment, const char *filename, float initial_x, float initial_y, float initial_z, float e, float m, float S) : Model(time_increment, filename, start_time)
{
    this->x = initial_x;
    this->y = initial_y;
    this->z = initial_z;

    this->e = e;
    this->m = m;
    this->S = S;

    this->calculate_stationary_y();
    this->calculate_stationary_z();

    this->outfile << "x,y,z,time\n";
}

HindmarshRose::HindmarshRose(float start_time, double time_increment, const char *filename, float initial_x, float initial_yz, float e, float m, float S, StationaryMode mode) : Model(time_increment, filename, start_time)
{
    this->x = x;

    this->e = e;
    this->m = m;
    this->S = S;

    if (HindmarshRose::StationaryMode::Y_Stationary == mode)
    {
        this->z = initial_yz;
        this->calculate_stationary_y();
    }
    else if (HindmarshRose::StationaryMode::Z_Stationary == mode)
    {
        this->y = initial_yz;
        this->calculate_stationary_z();
    }
    else
    {
        this->calculate_stationary_y();
        this->calculate_stationary_z();
    }

    this->outfile << "x,y,z,time\n";
}

void HindmarshRose::calculate_stationary_y()
{
    y = (time_increment * (1 - 5 * x * x)) / (time_increment - 1);
}

void HindmarshRose::calculate_stationary_z()
{
    z = (time_increment * m * S * (x + 1.6)) / (time_increment * m - 1);
}

void HindmarshRose::calculate()
{

    float aux_x, aux_y, aux_z;

    aux_x = x + time_increment * (y + 3 * x * x - x * x * x - z + e);
    aux_y = y + time_increment * (1 - 5 * x * x - y);
    aux_z = z + time_increment * m * (-z + S * (x + 1.6));

    this->x = aux_x;
    this->y = aux_y;
    this->z = aux_z;

    time = time + time_increment;
}

void HindmarshRose::objective_loop(double target_time)
{

    int counter = 0;

    this->allocate_array(this->time, target_time);

    while (this->time < target_time)
    {

        this->data[counter][0] = x;
        this->data[counter][1] = y;
        this->data[counter][2] = z;
        this->data[counter][3] = time;
        this->calculate();

        counter++;
    }
}

void HindmarshRose::iterations_loop(int iterations)
{

    this->x = x;
    this->y = y;
    this->z = z;

    this->allocate_array(iterations);

    for (int i = 0; i < iterations; i++)
    {

        this->data[iterations][0] = x;
        this->data[iterations][1] = y;
        this->data[iterations][2] = z;
        this->data[iterations][3] = time;
        this->calculate();
    }
}

void HindmarshRose::allocate_array(double start_time, double target_time)
{

    int i = 0;
    double time = target_time - this->time;
    this->data_rows = (long)((time / time_increment) + 1);

    this->data_cols = ElemsInModel;

    this->data = new double *[this->data_rows];

    for (i = 0; i < this->data_rows; i++)
    {
        this->data[i] = new double[this->data_cols];
    }
}

void HindmarshRose::allocate_array(int iterations)
{
    int i = 0;
    this->data_rows = iterations;
    this->data_cols = ElemsInModel;

    this->data = new double *[this->data_rows];

    for (i = 0; i < this->data_rows; i++)
    {
        this->data[i] = new double[this->data_cols];
    }
}