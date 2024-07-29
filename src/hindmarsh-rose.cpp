#include "../include/hindmarsh-rose.h"



HindmarshRose::HindmarshRose(int iterations, const char *filename)
{

    this->outfile.open(filename);
    
    this->perpetual=false;
    this->iterations=iterations;

}

HindmarshRose::HindmarshRose(const char *filename)
{
    this->outfile.open(filename);
    this->perpetual=true;

}


void HindmarshRose::calculate_stationary_yz(float x)
{

}

void HindmarshRose::calculate_stationary_z(float x, float y)
{

}

void HindmarshRose::calculate_stationary_y(float x, float z)
{

}

void HindmarshRose::calculate(float x, float y, float z)
{

}

void HindmarshRose::write_vector()
{

    std::vector<float>::iterator y_iterator = this->y_vector->begin();
    std::vector<float>::iterator z_iterator = this->z_vector->begin();
    for(std::vector<float>::iterator x_iterator = this->x_vector->begin(); x_iterator != this->x_vector->end(); ++x_iterator, ++y_iterator, ++z_iterator)
    {


    }

}
