//
//  main.cpp
//  Algebra_compute
//
//  Created by 강동석 on 4/1/24.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "dongVector.hpp"
#include "dongMatrix.hpp"

void VectorFn(std::ifstream &input, std::ofstream &output);
void MatrixFn(std::ifstream &input, std::ofstream &output);

int main(int argc, const char * argv[]) {
    std::ifstream input;
    std::ofstream output;
    
    input.open("./iosources/input.txt");
    output.open("./iosources/output.txt");
    
    std::string type;
    input >> type;
    std::cout << type << std::endl;
    
    if (type == "vector"){
        VectorFn(input,output);
    }else if (type == "matrix"){
        MatrixFn(input,output);
    }else{
        std::cerr << "Unknown command: " << type << std::endl;
        exit(1);
    }
    
    input.close();
    output.close();
    return 0;
}

void VectorFn(std::ifstream &input, std::ofstream &output){
    std::string fn;
    input >> fn;
    
    std::cout << fn << std::endl;
    
    if(!(fn == "dot"||fn == "add"||fn == "sub"||fn == "cross"||fn =="mag")){
        std::cerr << "Unknown command: " << fn << std::endl;
        exit(1);
    }
    
    int dimension1;
    input >> dimension1;
    //std::cout << dimension1 << std::endl;
    
    std::vector<double> vec1;
    for (int i = 0; i < dimension1; i++){
        double temp;
        input >> temp;
        //std::cout << temp << ' ';
        vec1.push_back(temp);
    }
    //std::cout << std::endl;
    dong::Vector v1(vec1);
    
    if(fn=="mag"){
        double mag = v1.magnitude();
        
        output << mag << '\n';
        return;
    }
    
    int dimension2;
    input >> dimension2;
    //std::cout << dimension2 << std::endl;
    
    std::vector<double> vec2;
    for (int i = 0; i < dimension2; i++){
        double temp;
        input >> temp;
        //std::cout << temp << ' ';
        vec2.push_back(temp);
    }
    //std::cout << std::endl;
    dong::Vector v2(vec2);
    
    
    if (fn == "dot"){
        auto dotRet = v1*v2;
        output << dotRet << '\n';
    }else if(fn == "cross"){
        auto crossRet = v1%v2;
        for (auto i : crossRet){
            output << i <<' ';
        }
        output << '\n';
    }else if(fn == "sub"){
        auto crossRet = v1-v2;
        for (auto i : crossRet){
            output << i <<' ';
        }
        output << '\n';
    }else if(fn == "add"){
        auto crossRet = v1+v2;
        for (auto i : crossRet){
            output << i <<' ';
        }
        output << '\n';
    }
}

void MatrixFn(std::ifstream &input, std::ofstream &output){
    std::string fn;
    input >> fn;
    
    std::cout << fn << std::endl;
    
    if(!(fn == "mul"||fn == "add"||fn == "sub"||fn == "tran"||fn=="det"||fn == "inv")){
        std::cerr << "Unknown command: " << fn << std::endl;
        exit(1);
    }
    
    int row1, col1;
    input >> row1;
    input >> col1;
    //std::cout << row1 << ' ' << col1 << std::endl;
    dong::Matrix mat1(row1,col1);
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col1; j++){
            double temp;
            input >> temp;
            mat1[i][j] = temp;
        }
    }
    
    if(fn == "tran"){
        auto ret = mat1.transpose();
        for (int i = 0; i < ret.row(); i++){
            for (int j = 0; j < ret.col(); j++){
                output << ret[i][j] << ' ';
            }
            output << '\n';
        }
        return;
    }
    else if(fn == "det"){
        auto ret = mat1.determinant();
        output << ret << '\n';
        return;
    }else if (fn == "inv"){
        auto ret = mat1.invers();
        for (int i = 0; i < ret.row(); i++){
            for (int j = 0; j < ret.col(); j++){
                output << ret[i][j] << ' ';
            }
            output << '\n';
        }
        return;
    }
    
    int row2, col2;
    input >> row2;
    input >> col2;
    //std::cout << row2 << ' ' << col2 << std::endl;
    dong::Matrix mat2(row2,col2);
    for (int i = 0; i < row2; i++){
        for (int j = 0; j < col2; j++){
            double temp;
            input >> temp;
            mat2[i][j] = temp;
        }
    }
    
    if (fn == "mul"){
        auto ret = mat1*mat2;
        for (int i = 0; i < ret.row(); i++){
            for (int j = 0; j < ret.col(); j++){
                output << ret[i][j] << ' ';
            }
            output << '\n';
        }
    }else if (fn == "add"){
        auto ret = mat1+mat2;
        for (int i = 0; i < ret.row(); i++){
            for (int j = 0; j < ret.col(); j++){
                output << ret[i][j] << ' ';
            }
            output << '\n';
        }
    }else if (fn == "sub"){
        auto ret = mat1-mat2;
        for (int i = 0; i < ret.row(); i++){
            for (int j = 0; j < ret.col(); j++){
                output << ret[i][j] << ' ';
            }
            output << '\n';
        }
    }
    
}
