//
//  dongMatrix.hpp
//  Algebra_compute
//
//  Created by 강동석 on 4/1/24.
//

#ifndef dongMatrix_hpp
#define dongMatrix_hpp

#include "dongVector.hpp"

namespace dong {
using namespace dong;

class Matrix{
    //메소드 정의에서만 호출하는 생성자
    Matrix(){}
    std::vector<dong::Vector> elements;
    //push_back
    void push_back(dong::Vector __x){elements.push_back(__x);}
    void push_back(std::initializer_list<double> vec){elements.push_back(Vector(vec));}
    void push_back(std::vector<double> __x){elements.push_back(Vector(__x));}
    
    //error if(a != b)
    static void size_no_match (size_t a, size_t b);
public:
    //row() size
    size_t row() const;
    //col() size
    size_t col() const;
    
    // 행렬의 행에 접근하는 함수
    Vector& operator[](size_t i);
    const Vector& operator[](size_t i) const;
    
    //iterator
    auto begin() -> decltype(elements.begin());
    auto end() -> decltype(elements.end());
    auto begin() const -> decltype(elements.begin());
    auto end() const -> decltype(elements.end());
    
    //생성자
    //복사생성자
    Matrix(const Matrix& other);
    
    //행렬 차원 입력받아서 영행렬 생성
    Matrix(size_t row, size_t cul);
    //2차원 리스트 입력받아서 생성
    Matrix(std::initializer_list<std::initializer_list<double>> list);
    //벡터를 요소로 갖는 리스트를 입력받아서 생성
    Matrix(std::initializer_list<Vector> list);
    
    
    //전치 행렬
    Matrix transpose() const;
    
    //스칼라 곱
    Matrix mul_scalar(const double& a)const;
    
    //행렬 곱 (this * other)
    Matrix matMul(const Matrix& other) const;
    
    //행렬 합
    Matrix add(const Matrix& other) const;
    
    //차
    Matrix subtract(const Matrix& other) const;
    
    //i행과 j열을 제외한 부분행렬
    Matrix submatrix(size_t row_i, size_t col_j) const;
    
    //행렬식
    double determinant() const;
    
    //역행렬
    Matrix invers() const;
};


inline Matrix matMul(const Matrix& left,const Matrix& right)  {
    return left.matMul(right);
}

inline Matrix operator*(const Matrix& left,const Matrix& right)  {
    return matMul(left,right);
}
inline Matrix matAdd(const Matrix& left,const Matrix& right)  {
    return left.add(right);
}

inline Matrix operator+(const Matrix& left,const Matrix& right)  {
    return matAdd(left,right);
}
inline Matrix matSubstract(const Matrix& left,const Matrix& right)  {
    return left.subtract(right);
}

inline Matrix operator-(const Matrix& left,const Matrix& right) {
    return matSubstract(left,right);
}



}

#endif /* dongMatrix_hpp */
