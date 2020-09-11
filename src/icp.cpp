#include <iostream>
#include <array>
#include <vector>
#include <Eigen/Dense>

std::vector<std::array<int,2>> nearestNeighborIndics(const Eigen::MatrixX3d &P,const Eigen::MatrixX3d &Q){
    // P and Q stand for matrixs
    // p and q stand for points
    // name your variable properly 
    // to reduce mistaken's occurence
    std::vector<std::array<int,2>> pairs;
    double p_x,p_y,q_x,q_y,dist_t,dist=100;
    std::array<int,2> arr={0,0};
    for (int i=0;i<P.rows()-1;i++){
        for(int j=0;j<Q.rows()-1;j++){
            p_x=P.row(i)[0];
            p_y=P.row(i)[1];
            q_x=Q.row(j)[0];
            q_y=Q.row(j)[1];
            
            dist_t=pow(pow((p_x-q_x),2)+pow((p_y-q_y),2),0.5);
            // std::cout<<dist_t<<std::endl;
            if(dist_t<dist){
                dist=dist_t;
                arr={i,j};
            }
        }
        // std::cout<<arr[0]<<","<<arr[1]<<std::endl;
        pairs.push_back(arr);
        dist=100;
    }
    
    return pairs;
}

