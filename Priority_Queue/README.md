<h1>우선순위 큐</h1>
<h2>정렬되지 않은 리스트를 이용한 우선순위 큐(Selection-Sort)</h2>
<pre>
  1. 삽입단계
    정렬 없이 그냥 넣으므로 
    O(1)*n = O(n) time 소요
  
   2. 제거단계
      우선순위가 가장 작은 값을 찾아야하므로 순회해야한다.
      1+2+...+n = n(n-1)/2 = O(n^2)time 소요
     
   따라서 O(n^2)+O(n) = O(n^2)time 
</pre>
```cpp
#include<iostream>
#include<list>
#include<vector>
using namespace std;
//시퀀스 맨 뒤에 원소 삽입 O(n) (삽입 원소 n 개라)
//삭제시 순회 O(n^2)

//field : comp(비교자 인스턴스 bool), elements(원소들을 저장하는 시퀀스)
//초반 : 시퀀스 elements 비어있는 상태

struct Compare{
    bool operator()(int lhs, int rhs){
        return lhs<rhs;//값이 더 작을 수록 우선순위가 높음
    }
};

class UnsortedSequencePQ{
public:
    UnsortedSequencePQ()=default;

    int size();
    bool empty();

    void push(int value);
    int top();
    void pop();

private:
    Compare comp;
    list<int> elements;//sequence
};

int UnsortedSequencePQ::size(){
    return elements.size();//sequence(list)'s size return
}
bool UnsortedSequencePQ::empty(){
    return size()==0;
}

void UnsortedSequencePQ::push(int value){
    elements.push_back(value);//시퀀스 맨 뒤에 삽입
}
int UnsortedSequencePQ::top(){
    if(empty()){
        return -1;
    }
    list<int>::iterator res,it;//순회를 하기 위한 반복자 생성
    res=it=elements.begin();//시작 지점 설정
    while(it!=elements.end()){//끝에 도달하면 while문 빠져나가도록
        if(comp(*it,*res)) {//비교해서 *it<*res 이면 true(우선순위 높으면)
            res = it;//우선순위 높은 걸로 교체
        }
        ++it;//다음 것과도 비교해야하므로 이동
    }
    return *res;//벡터와는 달리 리스트는 인덱스 접근이 불가하므로 역참조 이용하기(원소반환)
}
void UnsortedSequencePQ::pop(){
    if(empty()){
        cout<<"empty\n";
        return;
    }
    list<int>::iterator res,it;
    res=it=elements.begin();
    while(it!=elements.end()){
        if(comp(*it,*res)){//우선순위 높으면
            res=it;//높은 거 저장(즉, 여기선 가장 작은 값이 됨)
        }
        ++it;//이동
    }
    elements.erase(res);//우선순위 가장 작은 값 제거
}
```

<h2>정렬된 리스트를 이용한 우선순위 큐(Insertion-Sort)</h2>
<pre>
  1. 삽입단계
    삽입할 때 정렬된 순서에 맞는 자리에 넣어야하므로
    정렬 running time 소요
    1+2+...+n = n(n-1)/2 = O(n^2)time 소요

   2. 제거단계
      정렬되어있으므로, 시작부분에서 빼가면 됨.
      O(1) constant time * n번 = O(n) time 소요

   따라서 O(n^2)+O(n) = O(n^2)time 
</pre>
```cpp
#include<iostream>
#include<list>
#include<vector>
using namespace std;

//삽입 시 우선순위에 맞는 위치에 원소 삽입
//가장 우선순위가 높은 원소는 맨 앞에 위치함

struct Compare{
    bool operator()(int lhs, int rhs){
        return lhs<rhs;//값이 더 작을 수록 우선순위가 높음
    }
};

class SortedSequencePQ{
private:
    Compare comp;
    list<int>elements;

public:
    SortedSequencePQ()=default;
    int size();
    bool empty();
    void push(int value);
    int top();
    void pop();

};

int SortedSequencePQ::size(){
    return elements.size();
}
bool SortedSequencePQ::empty(){
    return size()==0;
}
void SortedSequencePQ::push(int value){
    list<int>::iterator it=elements.begin();
    while(it!=elements.end()&&comp(*it,value)){//끝에 도달하거나 *it가 value보다 작은 순간이 오면 while문 끝남
        it++;
    }
    elements.insert(it,value);
}
int SortedSequencePQ::top(){
    if(empty()) {
        return -1;
    }
        return elements.front();
}
void SortedSequencePQ::pop(){
    if(empty()){
        cout<<"empty\n";
        return;
    }
    elements.pop_front();
}
```
<h2>제자리 삽입 정렬(In-place Insertion-Sort)</h2>
<pre>
  외부의 자료구조 없이 입력 배열 자체의 일부를 우선순위 큐처럼 사용.
  원하는 것에 맞게 swap의 반복으로 정렬함.
  n+n-1+...+2 = O(n^2) time -> 처음에 n번 수행 시 우선순위가 가장 낮은 것이 맨 뒤에 확정적으로
  자리를 잡게 된다. 그래서 그 다음은 최대 n-1번의 swap ... 하게되는데, 마지막에 2번까지만 해도 정렬
  이 완성되므로, 1번은 생략이 가능하다.

   제거는 O(n) time
</pre>
