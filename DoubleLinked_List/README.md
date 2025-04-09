<h2>doubly linked list - basic.ver - week5-Q1</h2>
<hr>

```cpp
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
```
<hr>

<h2>doubly linked list - week5-Q2</h2>
<hr>

```cpp
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
```

<hr>
<h2>doubly linked list - operator overloading.ver</h2>

<hr>

```cpp
#include<iostream>
using namespace std;
class list;

class Node{
private:
    int data;
    Node* prev;
    Node* next;
    friend class list;
public:
    Node(int data):data(data) {
        prev = next = nullptr;
    }
};
class list{
public:
    class iterator{
    public:
        iterator();
        iterator(Node* node);

        iterator& operator++();
        iterator& operator--();
        int& operator*();
        bool operator==(const iterator& other)const;
        bool operator!=(const iterator& other)const;
    private:
        Node* ref;
        friend class list;
    };
    list();
    ~list();
    int size();
    bool empty();

    iterator begin();
    iterator end();
    void front();
    void back();
    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    iterator insert(iterator pos,int value);
    iterator erase(iterator pos);

private:
    int N;
    Node* header;
    Node* trailer;
};
list::iterator::iterator():ref(nullptr){}
list::iterator::iterator(Node* node):ref(nullptr){}

list::iterator& list::iterator::operator++(){
    ref=ref->next;
    return *this;
}
list::iterator& list::iterator::operator--(){
    ref=ref->prev;
    return *this;
}
int& list::iterator::operator*(){
    return ref->data;
}
bool list::iterator::operator==(const iterator& other)const{
    return ref==other.ref;
}
bool list::iterator::operator!=(const iterator& other)const{
    return ref!=other.ref;
}

list::list():N(0),header(new Node(0)),trailer(new Node(0)){
    header->next=trailer;
    trailer->prev=header;
}
list::~list(){
    while(!empty()){
        pop_front();
    }
    delete header;
    delete trailer;
}
int list::size(){
    return N;
}
bool list::empty(){
    return size()==0;
}

list::iterator list::begin(){
    return iterator(header->next);//list 맨 앞 노드로 생성자 함수 호출. 객체 생성. 그 만든
    //객체를 반환
}
list::iterator list::end(){
    return iterator(trailer);//이것도 마찬가지
}
void list::front(){
    if(empty()){
        cout<<"-1\n";
        return;
    }
    cout<<header->next->data<<"\n";//리스트 맨 앞 데이터 리턴
}
void list::back(){
    if(empty()){
        cout<<"-1\n";
        return;
    }
    cout<<trailer->prev->data<<"\n";//리스트 맨 뒤 데이터 리턴
}
void list::push_front(int value){
    insert(begin(),value);//현재 맨 앞 주소를 가진 새로운 객체와 값 전달
}
void list::pop_front(){
    if(empty()){
        cout<<"-1\n";
        return;
    }
    erase(begin());//현재 맨 앞 주소를 가진 객체 전달
}
void list::push_back(int value){
    insert(end(),value);//현재 trailer 주소를 가진 객체와 값 전달
}
void list::pop_back(){
    if(empty()){
        cout<<"-1\n";
        return;
    }
    erase(--end());//end()는 trailer, --end()는 trailer->prev
}
list::iterator list::insert(iterator pos,int value){
    Node* new_node=new Node(value);//새로운 노드 생성
    new_node->prev=pos.ref->prev;
    new_node->next=pos.ref;//pos 번째에 삽입 prev / new_node / pos
    pos.ref->prev->next=new_node;
    pos.ref->prev=new_node;
    ++N;//갯수 늘리기
    return iterator(new_node);//생성자 함수. 새로운 노드 주소를 가진 iterator 객체 리턴.
}
list::iterator list::erase(iterator pos){
    if(pos==end()){//지우려는 pos 가 trailer이면 지울 수 없기 때문에
        return end();//리턴을 트레일러?
    }
    Node* erase_node=pos.ref;
    Node* erase_next_node=erase_node->next;
    erase_node->prev->next=erase_node->next;
    erase_node->next->prev=erase_node->prev;
    delete erase_node;
    --N;
    return iterator(erase_next_node);
}
```
