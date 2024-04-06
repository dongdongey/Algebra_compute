//
//  dongVector.hpp
//  Algebra_compute
//
//  Created by 강동석 on 4/1/24.
//

#ifndef dongVector_hpp
#define dongVector_hpp

#include <vector>
#include <initializer_list>
#include <iterator>
#include <cmath>
#include <iostream>
#include <cstdlib>


namespace dong {


class Vector {
private:
    //메소드 정의에서만 호출하는 생성자
    Vector(){}
    std::vector<double> elements;
    //push_back()
    void push_back(double __x){elements.push_back(__x);}
    
    //벡터의 크기가 같아야하는 연산에서 가장 먼저 호출하는 함수 : 벡터의 크기가 다르면 에러 출력, 프로세스 종료
    void size_error(const size_t other_size) const;
    
    //동적할당 금지
    void* operator new(size_t size) = delete;
    void* operator new[](size_t size) = delete;
public:
    
    
    //size()->벡터의 길이
    const size_t size() const;
    
    // 벡터의 요소에 접근하는 함수
    double& operator[](size_t i);
    const double& operator[](size_t i) const;
    
    //iterator
    auto begin() -> decltype(elements.begin());
    auto end() -> decltype(elements.end());
    auto begin() const -> decltype(elements.begin());
    auto end() const -> decltype(elements.end());
    
    
    
    // 생성자
    Vector(const Vector& that);
    Vector(size_t dimension);
    Vector(double arr[], size_t Dimention);
    Vector(std::initializer_list<double> list);
    
    Vector(std::vector<double> container){
        for (auto i : container){
            elements.push_back(i);
        }
    }
    
    //=연산자
    Vector& operator=(Vector &other);
    
    //벡터의 크기
    double magnitude(void) const;
    // 벡터 덧셈
    Vector operator+(const Vector& other) const;
    // 벡터 뺄셈
    Vector operator-(const Vector& other) const;
    // 스칼라 곱셈
    Vector operator*(double scalar) const;
    
    //벡터 곱셈
    //내적
    double dot(const Vector& other ) const;
    double operator*(const Vector& other ) const {return this->dot(other);}
    
    //외적
    Vector cross(const Vector& other ) const;
    Vector operator%(const Vector& other ) const {
        return this->cross(other);
    }
};
inline Vector operator*(double scalar,Vector v){return v * scalar;}
}

#endif /* dongVector_hpp */
