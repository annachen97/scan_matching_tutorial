#include <iostream>
#include <string> 
#include <Eigen/Dense>
#include <scan_matching/csv_reader.hpp>

int main(int argc, char const *argv[])
{
    
    std::string csv_file="/home/spie-lab-01/Desktop/scan_matching/data/rectangle_points10.csv";
    std::string csv_file_out="/home/spie-lab-01/Desktop/scan_matching/data/rectangle_points10_rotated.csv";
    Eigen::MatrixX3d input_points;
    input_points=readPointsFromCsv(csv_file,input_points);
    //std::cout<<input_points <<std::endl;
    
    writePointsToCsv(csv_file_out,input_points);
    return 0;
}
