<h2>Basic Queue based singly linked list</h2>

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
    Node* front_index;
    Node* rear_index;
public:
    list();
    void size();
    void isEmpty();
    bool empty();
    void rear();
    void front();
    void enqueue(int value);
    void dequeue();
};

int main(){
    int test,num;
    string str;
    cin>>test;
    list arr;
    for(int i=0;i<test;i++){
        cin>>str;
        if(str=="isEmpty"){
            arr.isEmpty();
        }else if(str=="size"){
            arr.size();
        }else if(str=="dequeue"){
            arr.dequeue();
        }else if(str=="enqueue"){
            cin>>num;
            arr.enqueue(num);
        }else if(str=="front"){
            arr.front();
        }else if(str=="rear"){
            arr.rear();
        }
    }
    return 0;
}
list::list():N(0),front_index(nullptr),rear_index(nullptr){}
void list::size(){
    cout<<N<<"\n";
}
void list::isEmpty(){
    if(N==0){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }
}
bool list::empty(){
    return N==0;
}
void list::rear(){
    cout<<rear_index->data<<"\n";
}
void list::front(){
    cout<<front_index->data<<"\n";
}
void list::enqueue(int value){
    Node* new_node=new Node(value);
    if(empty()){
        front_index=rear_index=new_node;
    }else{
        rear_index->next=new_node;
        rear_index=new_node;
    }
    N++;
}
void list::dequeue(){
    if(empty()){
        cout<<"Empty\n";
        return;
    }else{
        Node* erase_node=front_index;
        cout<<erase_node->data<<"\n";
        front_index=front_index->next;
        delete erase_node;
    }
    N--;
}
```
