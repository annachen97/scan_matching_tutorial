#include <Eigen/Dense>
#include <string> 
using namespace std;
Eigen::MatrixX3d readPointsFromCsv(std::string csv_file,Eigen::MatrixX3d input_points);
void writePointsToCsv(std::string csv_file_out,Eigen::MatrixX3d input_points);
