#include <Eigen/Dense>
#include <string> 
using namespace std;
Eigen::MatrixX2d readPointsFromCsv(std::string csv_file,Eigen::MatrixX2d input_points);
void writePointsToCsv(std::string csv_file_out,Eigen::MatrixX2d input_points);
