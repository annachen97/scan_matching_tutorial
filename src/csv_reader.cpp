#include <iostream>
#include "scan_matching/csv_reader.hpp"
#include <fstream>
#include <sstream>
#include <string> 
#include <Eigen/Dense>
#include <vector>
#include <ios>
#include <iostream>

using namespace std;

Eigen::MatrixX2d readPointsFromCsv(std::string csv_file,Eigen::MatrixX2d input_points){
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
      input_points.conservativeResize(pt_size+1,2);  
      input_points.row(pt_size)<<matrix[0],matrix[1];
     
    }
    //cout<< input_points <<endl;
    fin.close();
    return input_points;
	}


void writePointsToCsv(std::string csv_file_out,Eigen::MatrixX2d input_points){
  std::fstream fout;
  std::string data;
  fout.open(csv_file_out,std::ios::out);
  //std::cout<<"input_points rowsize: "<<input_points.rows()<<std::endl;
  for(int i=0;i<input_points.rows();i++){
    fout<< input_points(i,0)<<","<<input_points(i,1)<<"\n";
  }
  fout.close();
  fout.open(csv_file_out,std::ios::in);
  while(std::getline(fout,data))
  {
    cout<<data<<endl;
  }
  fout.close();
}