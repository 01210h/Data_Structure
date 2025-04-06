#include<iostream>
#include<string>
using namespace std;
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

public:
    list();
    void size();
    bool EMPTY();
    void empty();
    void top();
    void push(int x);
    void pop();
    void pop_all();

};
int main(){
    int test,text,num;
    string str;
    cin>>test;
    for(int i=0;i<test;i++){
        list arr;
        cin>>text;
        for(int j=0;j<text;j++) {
            cin >> str;
            if(str=="size"){
                arr.size();
            }else if(str=="push"){
                cin>>num;
                arr.push(num);
            }else if(str=="pop"){
                arr.pop();
            }else if(str=="empty"){
                arr.empty();
            }else if(str=="pop_all"){
                arr.pop_all();
            }
        }
    }
    return 0;
}
list::list():N(0),head(nullptr),tail(nullptr){}
void list::size(){cout<<N<<"\n";}
void list::empty(){
    if(N==0){
        cout<<"1\n";
    }else{
        cout<<"0\n";
    }
}
bool list::EMPTY(){return N==0;}
void list::top(){
    if(EMPTY()){
        cout<<"-1\n";
        return;
    }
    cout<<tail->data<<"\n";
}
void list::push(int x){
    Node* new_node=new Node(x);
    if(EMPTY()){
        head=tail=new_node;
        N++;
        return;
    }
    tail->next=new_node;
    tail=new_node;
    N++;
}
void list::pop(){
    if(EMPTY()){
        cout<<"-1\n";
        return;
    }
    Node* view=head;
    /*
    while(view->next->next!= nullptr){
        view=view->next;//삭제 전 노드
    }*/
    for(int i=0;i<N-2;i++){//h 2 3 4 t
        view=view->next;
    }
    Node* erase_node=tail;
    view->next= nullptr;
    tail=view;
    cout<<erase_node->data<<"\n";
    delete erase_node;
    N--;
}
void list::pop_all(){
    int n=N;
    int sum(0);
    if(EMPTY()){
        cout<<"-1\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(EMPTY()){
            cout<<"-1\n";
            return;
        }
        Node* view=head;
        for(int i=0;i<N-2;i++){//h 2 3 4 t
            view=view->next;
        }
        Node* erase_node=tail;
        view->next= nullptr;
        tail=view;
        sum+=erase_node->data;
        delete erase_node;
        N--;
    }
    cout<<sum<<"\n";
}