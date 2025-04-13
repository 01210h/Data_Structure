//w1. array based list
//연속된 메모리 구조->즉각적인 접근 가능(인덱스)
//한계점 : 크기를 미리 정해야하고 한 번 정하면 바꿀 수 없음
#include<iostream>
#include<string>
using namespace std;

class list{
private:
    int* arr;
    int N;
    int capacity;
public:
    list(int capacity);
    int size();
    int at(int idx);
    void set(int idx,int value);
    void insert(int idx,int value);
    void erase(int idx);
    void print();
    bool empty();
};
list::list(int capacity):N(0),capacity(capacity){
    arr=new int [capacity];//동적 할당. 힙 영역에 메모리 공간 만둘기~~
}
int list::size(){
    return N;
}
int list::at(int idx){
    return arr[idx];//원소 반환
}
void list::set(int idx,int value){
    if(empty()){
        cout<<"0\n";
        return;
    }
    if(idx<0||idx>=capacity){
        cout<<"-1\n";
        return;
    }
    arr[idx]=value;
}
void list::insert(int idx,int value){
    if(idx<0||idx>=capacity){
        cout<<"-1\n";
        return;
    }
    for(int i=N-1;i>=idx;i--){//뒤로 한 칸씩 미는 shifting 연산. 맨 뒷 쪽부터 옮기는 게 핵심.
        //이유는 idx부터 순차적으로 옮겨버리면, idx값으로 모두 채워져버림
        arr[i+1]=arr[i];
    }
    arr[idx]=value;
    N++;
}
void list::erase(int idx){
    if(empty()){
        cout<<"0\n";
        return;
    }
    if(idx<0||idx>=capacity||idx>=N){
        cout<<"-1\n";
        return;
    }
    for(int i=idx;i<N-1;i++){
        arr[i]=arr[i+1];//앞으로 땡겨서 값을 없애버림. idx 쪽부터 옮기는 게 핵심.
        //이유는 insert 때와는 반대로 뒷쪽부터 옮기면, arr[N-1]값으로 모두 채워져버림
    }
    N--;
}
void list::print(){
    if(empty()){
        cout<<"0\n";
        return;
    }
    for(int i=0;i<size();i++){
            cout<<arr[i]<<" ";
    }
}
bool list::empty(){
    return N==0;
}

int main(){
    int test,n1,n2,S;
    string str;
    cout<<"테스트 몇 번 해볼래용~? :";
    cin>>test;
    cout<<"사이즈 입력해용~ : ";
    cin>>S;
    list L(S);

    for(int i=0;i<test;i++){
        cin>>str;
        if(str=="print_odd"){
            L.print();
        }else if(str=="insert"){
            cin>>n1>>n2;
            L.insert(n1,n2);
        }else if(str=="size"){
            cout<<L.size()<<"\n";
        }else if(str=="erase"){
            cin>>n1;
            L.erase(n1);
        }else if(str=="set"){
            cin>>n1>>n2;
            L.set(n1,n2);
        }else if(str=="at"){
            cin>>n1;
            L.at(n1);
        }
    }
    return 0;
}
