#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <fstream>
#include <csignal>

class Model 
{

public:
    int iterations;
    double time;
    double time_increment;
    std::ofstream outfile;
    std::vector<std::vector<float>> *data;
    bool perpetual;


public:
    Model(double time_increment, const char *filename);
    Model(double time_increment, const char *filename, float start_time);
    
    void write_vector();
    void free();
};

#endif /* MODEL_H */