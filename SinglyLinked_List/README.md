<h2>week2-Q2 | 커서 순환형 </h2>


```cpp
#include<iostream>
#include<string>
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
    Node* head;
    Node* tail;
    Node* cursor;
public:
    list(int size);
    bool empty();
    void insert_forward(int n);
    void insert(int x);
    void del();
    void forward(int k);
    void print();
};

int main(){
    int test,size,text,n;
    string str;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>size;//리스트 사이즈 받기
        list L(size);
        L.insert_forward(size);//노드 입력받기
        cin>>text;
        for(int j=0;j<text;j++){
            cin>>str;//명령 받기
            if(str=="Forward"){
                cin>>n;
                L.forward(n);
            }else if(str=="Insert"){
                cin>>n;
                L.insert(n);
            }else if(str=="Delete"){
                L.del();
            }else if(str=="Print"){
                L.print();
            }
        }
    }
    return 0;
}
bool list::empty(){return N==0;}
void list::insert_forward(int n){
    int num;
    for(int i=0;i<n;i++) {//원하는 노드 갯수만큼 반복생성
        cin>>num;
        Node* new_node =new Node(num);
        if (empty()) {//비었으면 초기상태
            head=tail=new_node;
            cursor=head;
            N++;
        }else{//비지 않았으면
            tail->next=new_node;
            tail=new_node;
            N++;
        }
    }
}
list::list(int size):N(0),head(nullptr),tail(nullptr),cursor(nullptr){
}
void list::insert(int x){//커서의 오른쪽 삽입
    if(empty()){
        return;
    }
    Node* new_node=new Node (x);
    if(cursor==tail){
        tail->next=new_node;
        tail=new_node;
        N++;
        return;
    }
    new_node->next=cursor->next;
    cursor->next=new_node;
    N++;
}
void list::del(){//커서가 가리키는 노드 삭제
    if(empty()||cursor==tail){
        return;
    }
    Node* view=head;
    Node* erase_node=cursor;
    if(cursor==head){
        head=cursor=cursor->next;
        delete erase_node;
        N--;
        return;
    }
    while(view->next!=cursor){//이런식으로도 조건이 되나?
        view=view->next;
    }
    view->next=cursor->next;
    cursor=cursor->next;
    delete erase_node;
    N--;
}
void list::forward(int k){//커서를 오른쪽으로 k칸 이동, 커서가 테일에 도달할 경우
    // 나머지 헤드에서 추가로 이동. 테일에서 헤드 옮길 때도 한 칸이동 소모됨.
    if(N<=1||empty()){
        return;
    }
    for(int i=0;i<k;i++){//N=4 a b c d
        if(cursor->next== nullptr){
            cursor=head;
        }else {
            cursor = cursor->next;
        }
    }
}
void list::print(){
    Node* view=head;
    while(view!= nullptr) {
        cout <<view->data<<" ";
        view=view->next;
    }
}

