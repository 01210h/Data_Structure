#include<iostream>
using namespace std;

class ArrayList{
private:
    int arr[100];
    int size;
public:
    ArrayList();
    void push_back(int x);
    void insert(int idx,int x);
    void erase(int idx);
    void sort();
    void swap(int* a,int* b);
};
ArrayList::ArrayList():size(0){}
void ArrayList::push_back(int x){
    if(size==100){
        return;
    }else{
        arr[size]=x;
        size++;
    }
}
void ArrayList::insert(int idx,int x){
    if(idx<0||idx>size||idx>100||size==100){
        return;
    }
    for(int i=size-1;i>=idx;i--){
        arr[i+1]=arr[i];
    }
    arr[idx]=x;
    size++;
}
void ArrayList::erase(int idx){
    if(idx<0||idx>=size||size==100){
        return;
    }
    for(int i=idx;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}
void ArrayList::sort(){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void ArrayList::swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
