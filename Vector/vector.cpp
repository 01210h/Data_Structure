#include<iostream>
using namespace std;
class arrayVector{
public:
    arrayVector();//생성자
    bool empty();//벡터가 비어있는지 확인
    int size();//벡터의 크기를 반환하는 함수
    int at(int idx);//인덱스의 원소 반환하는 함수
    void set(int idx,int data);//인덱스의 원소를 data로 변경하는 함수
    void erase(int idx);//인덱스에 저장된 원소를 삭제하는 함수
    void insert(int idx,int data);//인덱스의 위치에 데이터를 삽입하는 함수
private:
    int capacity;//벡터의 최대 크기
    int n;//벡터의 크기
    int* arr;//원소를 저장할 동적 배열
    void reserve(int size);//벡터의 최대크기를 size로 변경하는 함수
};
int main(){
    return 0;
}
arrayVector::arrayVector():capacity(1),n(0),arr(nullptr){
}
bool arrayVector::empty(){return n==0;}
int arrayVector::size(){return n;}
int arrayVector::at(int idx){
    return arr[idx];
}
void arrayVector::set(int idx,int data){
    arr[idx]=data;
}
void arrayVector::erase(int idx){
    if(empty()){
        return;
    }
    for(int i=n;i>=idx;i--){
        arr[i+1]=arr[i];
    }
    n--;
}
void arrayVector::insert(int idx,int data){
    if(n==capacity){
        reserve(2*capacity);
    }
    for(int i=n-1;i>=idx;i--){
        arr[i+1]=arr[i];
    }
    arr[idx]=data;
    n++;
}
void arrayVector::reserve(int size){
    int* arr2;
    arr2=new int [size];
    for(int i=0;i<n;i++){
        arr2[i]=arr[i];
    }
    delete[] arr;
    arr=arr2;
    capacity*=2;
}