#include <array>
#include <vector>
#include <Eigen/Dense>


// pass by reference makes you don't make a copy of the same variable

std::vector<std::array<int,2>> nearestNeighborIndics(
    const Eigen::MatrixX3d &p, const Eigen::MatrixX3d &q);