#include<iostream>
#include<string>
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
    int N;
    Node* header;
    Node* trailer;
public:
    list();
    bool empty();
    void print();
    void size();
    void erase_front();
    void erase_back();
    void insert_back(int n);
    void insert_front(int n);
    void erase(int idx);
    void insert(int idx,int value);
    void Print_Odd(int idx);
    ~list();
};
list::list():N(0),header(new Node (0)),trailer(new Node(0)){
    header->next=trailer;
    trailer->prev=header;
}
bool list::empty(){
    return N==0;
}
void list::print(){
    if(empty()){
        cout<<"empty\n";
        return;
    }
    Node* view=header->next;
    while(view!=trailer){
        cout<<view->data<<" ";
        view=view->next;
    }
    cout<<endl;
}
void list::size(){
    cout<<N<<endl;
}

void list::erase_front(){
    if(empty()){
        cout<<"-1\n";
        return;
    }
    Node* erase_node=header->next;
    header->next=erase_node->next;
    erase_node->next->prev=header;
    delete erase_node;
    N--;
}
void list::erase_back(){
    if(empty()){
        cout<<"-1\n";
        return;
    }
    Node* erase_node=trailer->prev;
    trailer->prev=erase_node->prev;
    erase_node->prev->next=trailer;
    delete erase_node;
    N--;
}
void list::insert_back(int n){
    Node* new_node=new Node(n);
    trailer->prev->next=new_node;
    new_node->next=trailer;
    new_node->prev=trailer->prev;
    trailer->prev=new_node;
    N++;
}
void list::insert_front(int n){
    Node* new_node=new Node(n);
    new_node->next=header->next;
    header->next->prev=new_node;
    header->next=new_node;
    new_node->prev=header;
    N++;
}

void list::erase(int idx){
    if(empty()||idx<0||idx>=N){
        cout<<"-1\n";
        return;
    }
    if(idx==0){
        erase_front();
        return;
    }
    if(idx==N-1){
        erase_back();
        return;
    }
    Node* erase_node=header->next;
    for(int i=0;i<idx;i++){//3이면 3번째에 도착.
        erase_node=erase_node->next;
    }
    erase_node->prev->next=erase_node->next;
    erase_node->next->prev=erase_node->prev;
    delete erase_node;
    N--;
}
void list::insert(int idx,int value){
    if(idx==0){
        insert_front(value);
        return;
    }
    if(idx==N){
        insert_back(value);
        return;
    }
    Node* view=header->next;
    for(int i=0;i<idx;i++){//idx번째 노드 접근
        view=view->next;
    }
    Node* new_node=new Node(value);
    view->prev->next=new_node;
    new_node->next=view;
    new_node->prev=view->prev;
    view->prev=new_node;
    N++;
}
void list::Print_Odd(int idx){
    int n(0);
    if(empty()||idx>=N||idx<0){
        cout<<"-1\n";
        return;
    }
    Node* view=header->next;
    for(int i=0;i<=idx;i++){
        view=view->next;
    }
    while(view!=trailer){
        if((view->data)%2!=0) {
            cout << view->data << " ";
            n++;
        }
        view=view->next;
    }
    if(n==0){
        cout<<"-1";
    }
    cout<<endl;
}
list::~list(){
    while(!empty()){
        erase_front();
    }
    delete header;
    delete trailer;
}
int main(){
    int text,num,num2;
    string str;
    list arr;
    cin>>text;
    for(int i=0;i<text;i++){
        cin>>str;
        if(str=="Print"){
            arr.print();
        }else if(str=="Print_Odd"){
            cin>>num;
            arr.Print_Odd(num);
        }else if(str=="Insert"){
            cin>>num>>num2;
            arr.insert(num,num2);
        }else if(str=="Erase"){
            cin>>num;
            arr.erase(num);
        }else if(str=="Size"){
            arr.size();
        }
    }
    return 0;
}
