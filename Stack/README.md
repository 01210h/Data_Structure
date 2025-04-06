<h2>Basic Stack code (with. singly linked list)</h2>

```css
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
            }else if(str=="top"){
                arr.top();
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
    cout<<tail->data<<"\n";//테일 데이터 접근
}
void list::push(int x){
    Node* new_node=new Node(x);//새로운 노드 생성. 동적할당
    if(EMPTY()){
        head=tail=new_node;//처음에 비어있으면 헤드와 테일 모두 새로운 노드 가리킴
        N++;//갯수 늘리기
        return;
    }
    new_node->next=head;
    head=new_node;
    N++;
}
void list::pop(){
    if(EMPTY()){
        cout<<"-1\n";
        return;
    }
    Node* erase_node=head;
    head=head->next;
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
    Node* view=head;
    while(view!= nullptr){
        Node* erase_node=view;
        sum+=erase_node->data;
        delete erase_node;
        view=view->next;
        N--;
    }
    cout<<sum<<"\n";
    head= nullptr;
    tail= nullptr;
}

<h2>Parenthesis Check Stack code 괄호검사 (with. singly linked list)</h2>

```css
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
