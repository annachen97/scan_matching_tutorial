#include <iostream>
#include <array>
#include <vector>
#include <Eigen/Dense>
#include <scan_matching/csv_reader.hpp>
#include <scan_matching/icp.hpp>


int main(int argc, char const *argv[])
{
    std::string csv_file="/home/spie-lab-01/Desktop/scan_matching/data/rectangle_points10.csv";
    std::string csv_file_out="/home/spie-lab-01/Desktop/scan_matching/data/rectangle_points10_rotated.csv";
    Eigen::MatrixX3d p;
    Eigen::MatrixX3d q;
    std::array<int,2> pairs;
    p=readPointsFromCsv(csv_file,p);
    q=readPointsFromCsv(csv_file_out,p);
    std::cout<<p<<std::endl;
    std::cout<<q<<std::endl;
    pairs=nearestNeighborIndics(Eigen::MatrixX3d p,Eigen::MatrixX3d q);

    return 0;
}


