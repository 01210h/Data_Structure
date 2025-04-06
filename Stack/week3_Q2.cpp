#include<iostream>
#include<string>
using namespace std;
class Node{
private:
    int data;
    Node* next;
    friend class list;
public:
    Node(int num):next(nullptr),data(num){}
};

class list{
private:
    int N;
    bool result;
    Node* head;
    Node* tail;
public:
    list();
    bool empty();
    void push();
    void pop();
    bool getresult();
    int getN();
};
void game();
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        game();
    }
    return 0;
}
list::list():result(true),N(0),head(nullptr),tail(nullptr){}
bool list::empty(){return N==0;}
void game(){
    list arr;
    string str;
    cin>>str;
    int num=str.length();
    for(int i=0;i<num;i++){
        if(str[i]=='('){
            arr.push();
        }else{
            arr.pop();
        }
        if(!arr.getresult()){
            cout<<"NO\n";
            return;
        }
    }
    if(arr.getN()>=1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int list::getN(){
    return N;
}
bool list::getresult(){
    return result;
}
void list::push(){
    Node* new_node=new Node(0);
    if(empty()){
        head=tail=new_node;
    }else{
        new_node->next=head;
        head=new_node;
    }
    N++;
}
void list::pop(){
    if(empty()){
        result=false;
        return;
    }
    Node* erase_node=head;
    head=head->next;
    delete erase_node;
    N--;
}
