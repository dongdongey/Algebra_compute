# 행렬, 벡터 계산기

## 기본
 - 명령어를 입력받는 파일은 `./iosources/input.txt`
 - 출력 결과를 내는 파일은 `./iosources/output.txt`
 - 입력파일 규칙
```
["matrix" or "vector"]
[선형대수 연산]
[차원 1] {차원 2(행렬일 경우)}
[차원에 맞는 행렬이나 벡터의 요소...]
[차원 1] {차원 2(행렬일 경우)}
[차원에 맞는 행렬이나 벡터의 요소...]
```
명령어나 요소는 공백이나 개행으로 구분합니다.
   
## 연산 명령어
### vector
`mag` : 한 벡터의 크기를 계산합니다. (|v1|)   
`add` : 두 벡터의 합을 계산합니다. (v1 + v2)   
`sub` : 두 벡터의 차를 계산합니다. (v1 - v2)   
`dot` : 두 벡터의 내적을 계산합니다. (v1 \* v2)   
`cross` : 두 벡터의 외적을 계산합니다 (v1 % v2)   
### matrix
`tran` : 한 행렬을 전치 행렬을 구합니다. (A^T)   
`det` : 한 행렬의 행렬식을 계산합니다.   
`inv` : 한 행렬의 역행렬을 계산합니다.   
`add` : 두 행렬의 합을 계산합니다. (A + B)   
`sub` : 두 행렬의 차를 계산합니다. (A - B)   
`mul` : 두 행렬의 곱을 계산합니다. (A \* B)   

## 예시

input.txt
```
matrix
mul
4 4
1 0 0 1
0 1 0 1
0 0 1 1
0 0 0 1
4 1
3 2 1 1
```

output.txt
```
4 
3 
2 
1 
```
