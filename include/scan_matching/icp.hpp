#include <array>
#include <vector>
#include <Eigen/Dense>

// std::vector<std::array<int,2>> nearestNeighborIndics(
//     const Eigen::MatrixX3d &P, const Eigen::MatrixX3d &Q);

std::vector<std::array<int,2>> nearestNeighborIndics(
    Eigen::MatrixX3d p, Eigen::MatrixX3d q);