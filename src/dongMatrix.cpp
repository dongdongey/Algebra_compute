//
//  dongMatrix.cpp
//  Algebra_compute
//
//  Created by 강동석 on 4/2/24.
//

#include "dongMatrix.hpp"
using namespace dong;
//error if(a != b)
void Matrix::size_no_match (size_t a, size_t b){
    if(a != b){
        std::cerr << "size no match" << std::endl;
        exit(2);
    }
}
//row() size
size_t Matrix::row() const {return elements.size();}
//col() size
size_t Matrix::col() const {
    return elements.begin()->size();}

// 행렬의 행에 접근하는 함수
Vector& Matrix::operator[](size_t i) {
    return elements[i];
}
const Vector& Matrix::operator[](size_t i) const {
    return elements[i];
}

//iterator
auto Matrix::begin() -> decltype(elements.begin()) { return elements.begin(); }
auto Matrix::end() -> decltype(elements.end()) { return elements.end(); }
auto Matrix::begin() const -> decltype(elements.begin()) { return elements.begin(); }
auto Matrix::end() const -> decltype(elements.end()) { return elements.end(); }

//복사생성자
Matrix::Matrix(const Matrix& other){
    for(auto i : other){
        elements.push_back(Vector(i));
    }
}

//행렬 차원 입력받아서 영행렬 생성
Matrix::Matrix(size_t row, size_t cul){
    for(size_t i = 0; i < row; i++){
        std::vector<double> vec;
        for(size_t j = 0; j < cul; j++){
            vec.push_back(0.0);
        }
        elements.push_back(vec);
    }
}

//2차원 리스트 입력받아서 생성
Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) {
    size_t col = list.begin()->size();
    for (auto row_it = list.begin();row_it != list.end();++row_it) {
        //안쪽 리스트의 크기가 다른게 나오면 에러
        size_no_match(col, row_it->size());
        elements.push_back(*row_it);
    }
}

//벡터를 요소로 갖는 리스트를 입력받아서 생성
Matrix::Matrix(std::initializer_list<Vector> list) {
    size_t col = list.begin()->size();
    for (auto row_it = list.begin();row_it != list.end();row_it++) {
        //안쪽 벡터의 크기가 다른게 나오면 에러
        size_no_match(col, row_it->size());
        elements.push_back(*row_it);
    }
}

//전치 행렬
Matrix Matrix::transpose() const{
    Matrix result;
    
    for (size_t i = 0; i < this->col(); i++){
        std::vector<double> vec;
        for (size_t j = 0; j < this->row(); j++){
            vec.push_back(elements[j][i]);
        }
        result.push_back(vec);
    }
    
    
    return result;
}



//행렬 곱
Matrix Matrix::matMul(const Matrix& other) const {
    size_no_match(this->col(),other.row());
    
    Matrix result(this->row(),other.col());
    
    for (size_t i = 0; i < this->row(); i++) {
        for (size_t j = 0; j < other.col(); j++) {
            double sum = 0.0;
            for (size_t k = 0; k < other.row(); k++) {
                sum += elements[i][k] * other[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

//행렬 합
Matrix Matrix::add(const Matrix& other) const{
    Matrix result(row(),col());
    for (size_t i = 0; i < this->row(); i++) {
        for (size_t j = 0; j < this->col(); j++) {
            result[i][j] = elements[i][j] + other[i][j];
        }
    }
    return result;
}

//차
Matrix Matrix::subtract(const Matrix& other) const{
    size_no_match(this->row(), other.row());
    size_no_match(this->col(), other.col());
    Matrix result(row(),col());
    for (size_t i = 0; i < row(); i++) {
        for (size_t j = 0; j < col(); j++) {
            result[i][j] = elements[i][j] - other[i][j];
        }
    }
    return result;
}

//스칼라곱
Matrix Matrix::mul_scalar(const double& a) const{
    Matrix ret;
    for(auto i : *this){
        ret.push_back(a*i);
    }
    return ret;
}

//i행과 j열을 제외한 부분행렬
Matrix Matrix::submatrix(size_t row_i, size_t col_j) const{
    Matrix M;
    for(int i = 0; i < row(); i++){
        if(i == row_i)  continue;
        std::vector<double> row;
        for (int j = 0; j < col(); j++) {
            if(j != col_j) row.push_back(elements[i][j]);
        }
        M.push_back(row);
    }
    return M;
}

//행렬식
double Matrix::determinant() const{
    size_no_match(row(),col());
    //std::clog<< "determinant called" << std::endl;
    if(row()==0){
        return 1;
    }else if(row()==1){
        return elements[0][0];
    }else if (row()==2){
        double ret = (elements[0][0] * elements[1][1] - elements[1][0] * elements[0][1]);
        return ret;
    }else{
        const size_t i = 0;
        double ret = 0;
        for (size_t j = 0; j < this->row(); j++){
            if(elements[i][j]!=0.0){
                ret += pow(-1,i+j)*elements[i][j]*(this->submatrix(i, j)).determinant();
            }
        }
        return ret;
    }
}

//역행렬
Matrix Matrix::invers() const{
    
    size_no_match(row(),col());
    //std::clog<< "invers called" << std::endl;
    if(row()==1){
        return Matrix({1/elements[0][0]});
    }
    double det = this->determinant();
    //std::clog<< "det in invers called" << std::endl;
    if(det == 0){
        std::cerr << "det = 0" << std::endl;
        exit(3);
    }
    Matrix ret(row(), col());
    for(int i = 0; i < row(); i++){
        for(int j = 0; j < col(); j++){
            ret[i][j] = std::pow(-1,i+j)*((this->submatrix(i, j)).determinant());
            
        }
    }
    return ret.mul_scalar(1/det);
    
}
