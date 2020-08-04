#include <iostream>
#include "scan_matching/csv_reader.hpp"
#include <fstream>
#include <sstream>
#include <string> 
#include <Eigen/Dense>
#include <vector>
#include <ios>
#include <iostream>
#include  <cmath>

using namespace std;
const double PI  =3.141592653589793238463;

Eigen::MatrixX3d readPointsFromCsv(std::string csv_file,Eigen::MatrixX3d input_points){
    std::fstream fin;
    fin.open(csv_file, std::ios::in);
    std::string line;
    double data_to_double;
    getline(fin, line);
    while (getline(fin, line))  //讀檔讀到跳行字元
	  {
      // cout<<line<<endl;
      std::stringstream lineStream(line);
      std::string data;
      std::vector<double> matrix;
      while (std::getline(lineStream, data,',')) //讀檔讀到逗號
      {
        
        data_to_double=stod(data);
        matrix.push_back(data_to_double); 
      }

      int pt_size = input_points.rows();
      input_points.conservativeResize(pt_size+1,3);  
      input_points.row(pt_size)<<matrix[0],matrix[1],1;
     
    }
    //cout<< input_points <<endl;
    fin.close();
    return input_points;
	}


void writePointsToCsv(std::string csv_file_out,Eigen::MatrixX3d input_points){
  std::fstream fout;
  std::string data;
  double tempx,tempy;
  double theta=30*PI/180,tx,ty; 
  fout.open(csv_file_out,std::ios::out);
  //std::cout<<"input_points rowsize: "<<input_points.rows()<<std::endl;
  // for(int i=0;i<input_points.rows();i++){
  //   tempx=input_points(i,0);
  //   tempy=input_points(i,1);
  //   input_points(i,0)=tempx*cos(30*PI/180)-tempy*sin(30*PI/180);
  //   input_points(i,1)=tempx*sin(30*PI/180)+tempy*cos(30*PI/180);
  //   fout<< input_points(i,0)<<","<<input_points(i,1)<<"\n";
  // }
  Eigen::Matrix3d rot;
  rot<< cos(theta), -sin(theta), tx,
        sin(theta),  cos(theta), ty,
        0,            0,          1;

  input_points=(rot*(input_points.transpose())).transpose();
  int rs;
  for(rs=0;rs<=input_points.rows()-1;rs++){
    fout<<input_points(rs,0)<<","<<input_points(rs,1)<<endl;
  }
  fout.close();
  fout.open(csv_file_out,std::ios::in);
  while(std::getline(fout,data))
  {
    cout<<data<<endl;
  }
  fout.close();
}