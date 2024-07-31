#include "../include/HindmarshRose.h"


HindmarshRose::HindmarshRose(double time_increment, const char *filename, float e, float m, float S) : Model(time_increment, filename)
{
    this->e = e;
    this->m = m;
    this->S = S;

    this->outfile << "x,y,z,time\n";
}

HindmarshRose::HindmarshRose( float start_time, double time_increment, const char *filename, float e, float m, float S) : Model(time_increment, filename, start_time)
{
    this->e = e;
    this->m = m;
    this->S = S;

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

    this->save(); //TO-DO: is the use of vectors the factor that slow down cpp

    this->x = aux_x;
    this->y = aux_y;
    this->z = aux_z;

    time = time + time_increment;
}

void HindmarshRose::objective_loop(float x, float y, float z, double target_time)
{
    this->x = x;
    this->y = y;
    this->z = z;
    
    while (this->time < target_time)
    {
        this->calculate();
    }
}

void HindmarshRose::objective_loop_stationary_z(float x, float y, double target_time)
{

    this->x = x;
    this->y = y;

    this->calculate_stationary_z();
    
    while (this->time < target_time)
    {
        this->calculate();
    }
}

void HindmarshRose::objective_loop_stationary_y(float x, float z, double target_time)
{

    
    this->x = x;
    this->z = z;

    this->calculate_stationary_y();

    while (this->time < target_time)
    {
        this->calculate();
    }
}

void HindmarshRose::objective_loop_stationary_yz(float x, double target_time)
{

    this->x = x;

    this->calculate_stationary_y();
    this->calculate_stationary_z();

    while (this->time < target_time)
    {
        this->calculate();
    }
}

void HindmarshRose::iterations_loop(float x, float y, float z, int iterations)
{

    this->x = x;
    this->y = y;
    this->z = z;


    for (int i = 0; i < iterations; i++)
    {
        this->calculate();
    }
}

void HindmarshRose::iterations_loop_stationary_z(float x, float y, int iterations)
{

    this->x = x;
    this->y = y;

    this->calculate_stationary_z();

    for (int i = 0; i < iterations; i++)
    {
        this->calculate_stationary_z();
    }
}

void HindmarshRose::iterations_loop_stationary_y(float x, float z, int iterations)
{
    this->x = x;
    this->z = z;

    this->calculate_stationary_y();

    for (int i = 0; i < iterations; i++)
    {
        this->calculate();
    }
}

void HindmarshRose::iterations_loop_stationary_yz(float x, int iterations)
{
    this->x = x;

    this->calculate_stationary_y();
    this->calculate_stationary_z();


    for (int i = 0; i < iterations; i++)
    {
        this->calculate();
    }
}


void HindmarshRose::save()
{
    std::vector<float>elements{this->x, this->y, this->z, static_cast<float>(this->time)};

    this->data->push_back(elements);
}