#include<iostream>
using namespace std;
class list;

class Node{
private:
    int data;
    Node* next;
    friend class list;
public:
    Node(int num):data(num),next(nullptr){}
};

class list{
private:
    int N;
    int round;
    int result;
    Node* front;
    Node* rear;
    Node* BOOM;
    int capacity;
    int inha;
    int* game;
public:
    list(int P);
    bool empty();
    void insert();
    void moving(int n);
    void remove();
    void G();
};
int main(){
    int test,people;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>people;
        list arr(people);
        arr.insert();
        arr.G();
    }
    return 0;
}
list::list(int P):result(0),round(0),BOOM(nullptr),N(0),inha(0),capacity(P),front(nullptr),rear(nullptr){}
bool list::empty(){return N==0;}
void list::insert(){//초기 환경 구축
    for(int i=capacity;i>0;i--){//사람 수만큼 반복
        Node* new_node=new Node (i);//새로운 노드 동적할당
        if(empty()){//비어있으면
            front=rear=new_node;
        }else{
            new_node->next=front;
            front=new_node;//사람 수만큼 자리 배치
        }
        N++;
    }
    rear->next=front; //순회할 수 있도록 이어주기!!
    BOOM=front;//폭탄은 처음에 front에 위치함
}
void list::G(){
    game=new int [capacity-1];//동적 배열 생성
    for(int j=0;j<capacity-1;j++){
        cin>>game[j];//값 넣기
    }
    cin>>inha;//인하의 좌석 번호 받기
    for(int j=0;j<capacity-1;j++){
        moving(game[j]);//배열의 값만큼 움직이기
        remove();//제거하기
    }
    if(result==0){//인하가 끝까지 살아남음
        cout<<"-1\n";
    }else{//인하가 탈락했으므로 탈락 라운드 출력
        cout<<result<<"\n";
    }
}
void list::moving(int n){//폭탄 돌리기
    for(int i=0;i<n-1;i++){
        BOOM=BOOM->next;//탈락자 전 노드를 알기위해 한번 덜 감.
    }
}
void list::remove(){
    round++;
    Node* prev=BOOM;//연결을 위해 폭탄 전 노드
    BOOM=BOOM->next;//폭탄 넘겨주기
    Node* erase_node=BOOM;
    prev->next=BOOM->next;//잇기
    BOOM=BOOM->next;//탈락자 다음에게 폭탄 전달
    if(erase_node->data==inha){
        result=round;
        delete erase_node;
        N--;
        return;
    }
    delete erase_node;
    N--;
}
