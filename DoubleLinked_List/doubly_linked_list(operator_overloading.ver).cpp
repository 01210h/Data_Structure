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
int main(){


    return 0;
}