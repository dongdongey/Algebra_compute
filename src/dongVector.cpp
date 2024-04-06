//
//  dongVector.cpp
//  Algebra_compute
//
//  Created by 강동석 on 4/3/24.
//

#include "dongVector.hpp"
using namespace dong;



//벡터의 크기가 같아야하는 연산에서 가장 먼저 호출하는 함수 : 벡터의 크기가 다르면 에러 출력, 프로세스 종료
void Vector::size_error(const size_t other_size) const{
    if((other_size != this->size())){
        std::cerr << "no match Vector size" << std::endl;
        exit(1);
    }
}

//size()->벡터의 길이
const size_t Vector::size() const {return elements.size();}

// 벡터의 요소에 접근하는 함수
double& Vector::operator[](size_t i) {
    return elements[i];
}
const double& Vector::operator[](size_t i) const {
    return elements[i];
}

//iterator
auto Vector::begin() -> decltype(elements.begin()) { return elements.begin(); }
auto Vector::end() -> decltype(elements.end()) { return elements.end(); }
auto Vector::begin() const -> decltype(elements.begin()) { return elements.begin(); }
auto Vector::end() const -> decltype(elements.end()) { return elements.end(); }

// 생성자
Vector::Vector(const Vector &that){
    for(auto i : that){
        elements.push_back(i);
    }
}
Vector::Vector(size_t dimension) {
    for (size_t i = 0; i < dimension; i++) {
        elements.push_back(0.0);
    }
}
Vector::Vector(double arr[], size_t Dimention){
    for(size_t i = 0; i < Dimention; i++){
        elements[i] = arr[i];
    }
}
Vector::Vector(std::initializer_list<double> list){
    for (auto it : list){
        elements.push_back(it);
    }
}


//벡터의 크기
double Vector::magnitude(void) const {
    //result = sqrt(ret)
    double ret = 0;
    for (auto i : elements){
        ret += i*i;
    }
    return std::sqrt(ret);
}

// 벡터 덧셈
Vector Vector::operator+(const Vector& other) const {
    size_error(other.size());
    
    Vector result;
    auto it1 = elements.begin();
    auto it2 = other.begin();
    for (; it1 != elements.end() && it2 != elements.end();it1++,it2++) {
        result.push_back(*it1 + *it2);
    }
    return result;
}

// 벡터 뺄셈
Vector Vector::operator-(const Vector& other) const {
    size_error(other.size());
    Vector result;
    

    auto it1 = elements.begin();
    auto it2 = other.begin();
    for (; it1 != elements.end() && it2 != elements.end();it1++,it2++) {
        result.push_back(*it1 - *it2);
    }
    return result;
}

// 스칼라 곱셈
Vector Vector::operator*(double scalar) const {
    Vector result;
    
    for (auto i : elements) {
        result.push_back( i * scalar);
    }
    return result;
}

//내적
double Vector::dot(const Vector& other ) const {
    size_error(other.size());
    double result = 0.0;
    
    auto it1 = elements.begin();
    auto it2 = other.begin();
    for (; it1 != elements.end() && it2 != elements.end();it1++,it2++) {
        result += (*it1 * *it2);
    }
    return result;
}

//외적
Vector Vector::cross(const Vector& other ) const {
    size_error(other.size());
    
    if (!(size() == 3 || size() == 4)){
        std::cerr << "no match Vector size" << std::endl;
        exit(1);
    }
    Vector result(size());
    result[0] = elements[1]*other[2] - elements[2]*other[1];
    result[1] = elements[2]*other[0] - elements[0]*other[2];
    result[2] = elements[0]*other[1] - elements[1]*other[0];
    if(size() == 4) result[3] = 1;
    return result;
}


