#include <iostream>
#include <array>
#include <vector>
#include <Eigen/Dense>
#include <scan_matching/csv_reader.hpp>
#include <scan_matching/icp.hpp>


// operation overloading for cout array in vector. (haven't finished)
ostream &operator << (ostream &out, std::vector<std::array<int,2>> &pairs)
{
    return out<<pairs;
}

int main(int argc, char const *argv[])
{
    std::string csv_file="/home/spie-lab-01/Desktop/scan_matching/data/rectangle_points10.csv";
    std::string csv_file_out="/home/spie-lab-01/Desktop/scan_matching/data/rectangle_points10_rotated.csv";
    Eigen::MatrixX3d P;
    Eigen::MatrixX3d Q;
    std::vector<std::array<int,2>> pairs;
    P=readPointsFromCsv(csv_file,P);
    Q=readPointsFromCsv(csv_file_out,Q);
    std::cout<<P<<std::endl;
    std::cout<<Q<<std::endl;
    std::cout<<"-------------------"<<std::endl;
    pairs=nearestNeighborIndics(P,Q);
    std::cout<<"pairs"<<std::endl;
    for (auto i:pairs)
    std::cout << "(" << i[0] << "," << i[1] << ")" << std::endl;

    return 0;
}



