//
//  test.cpp
//  Algebra_compute
//
//  Created by 강동석 on 4/5/24.
//

#include <iostream>
#include "dongMatrix.hpp"
using namespace dong;
int main(){
    
    Matrix mat1({{2, 0, 0, 3}
                ,{0, 2, 0, 3}
                ,{0, 0, 2, 4}
                ,{0, 2, 2, 5}});
    
    auto ret = mat1.invers();
    for (int i = 0; i < ret.row(); i++){
        for (int j = 0; j < ret.col(); j++){
            std::cout << ret[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
