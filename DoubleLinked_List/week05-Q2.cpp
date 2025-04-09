#include<iostream>
using namespace std;
class list;
class Node{
private:
    int data;
    Node* next;
    Node* prev;
    friend class list;
public:
    Node(int num):data(num),next(nullptr),prev(nullptr){}
};
class list{
private:
    Node* header;
    Node* trailer;
    int N;
public:
    list();
    bool empty();
    void push_back(int n);
    void pop_front();
    void odd(int n1,int n2);
    void even(int n1,int n2);
    ~list();
};
list::list():N(0),header(new Node(0)),trailer(new Node(0)){
    header->next=trailer;
    trailer->prev=header;
}
bool list::empty(){
    return N==0;
}
void list::push_back(int n){
    Node* new_node=new Node(n);
    if(empty()){
        header->next=new_node;
        new_node->next=trailer;
        new_node->prev=header;
        trailer->prev=new_node;
        N++;
        return;
    }
    new_node->next=trailer;
    trailer->prev->next=new_node;
    new_node->prev=trailer->prev;
    trailer->prev=new_node;
    N++;
}
void list::pop_front(){
    if(empty()){
        return;
    }
    Node* erase_node=header->next;
    header->next=erase_node->next;
    header->next->prev=header;
    delete erase_node;
    N--;
}
void list::odd(int n1,int n2){
    int n=0;
    Node* view=header->next;
    for(int i=0;i<n1;i++){//n번째 노드 도착
        view=view->next;
    }
    if(n1-n2<0){//
        n2=n1;
    }
    for(int i=0;i<n2;i++){
        view=view->prev;
        if((view->data)%2!=0){
            cout<<view->data<<" ";
            n++;
        }
    }
    if(n==0){
        cout<<"-1\n";
        return;
    }
    cout<<endl;
}
void list::even(int n1,int n2){
    int n=0;
    Node* view=header->next;
    for(int i=0;i<n1;i++){//n번째 노드 도착
        view=view->next;
    }
    if(n1+n2>=N){
        n2=N-1-n1;
    }
    for(int i=0;i<n2;i++){
        view=view->next;
        if((view->data)%2==0){
            cout<<view->data<<" ";
            n++;
        }
    }
    if(n==0){
        cout<<"-1\n";
        return;
    }
    cout<<endl;
}
list::~list(){
    while(!empty()){
        pop_front();
    }
    delete header;
    delete trailer;
}

int main(){
    int test,text,siz,n,n1,n2;
    cin>>test;
    for(int i=0;i<test;i++){
        list arr;
        cin>>siz>>text;
        for(int j=0;j<siz;j++){
            cin>>n;
            arr.push_back(n);
        }
        for(int j=0;j<text;j++){
            cin>>n1>>n2;
            if(n1%2==0){
                arr.even(n1,n2);
            }else{
                arr.odd(n1,n2);
            }
        }
    }

    return 0;
}