#ifndef HINDMARSHROSE_H
#define HINDMARSHROSE_H
#include <vector>
#include <fstream>

class HindmarshRose
{

public:
    float x;
    float y;
    float z;
    int iterations;
    std::vector<float> *x_vector;
    std::vector<float> *y_vector;
    std::vector<float> *z_vector;
    std::ofstream outfile;


private:
    bool perpetual;

public:
    HindmarshRose(int iterations, const char *filename);
    HindmarshRose(const char *filename);
    void calculate_stationary_yz(float x);
    void calculate_stationary_z(float x, float y);
    void calculate_stationary_y(float x, float z);
    void calculate(float x, float y, float z);
    void write_vector();
};

#endif /* HINDMARSHROSE_H */