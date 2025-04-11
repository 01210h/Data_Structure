#include<iostream>
#include<list>
using namespace std;

class Node{
private:
    int data;//int 를 저장하는 트리
    Node* parent;//부모 정해주기. 너 엄마 누긔야!!
    list<Node*> children;//자식 노드 리스트(노트 포인터 타입)
    friend class Tree;//Tree클래스에서 노드 접근할 수 있도록 friend 처리
public:
    Node(int data,Node* parent):data(data),parent(parent){}//생성자 함수 값 넣기
};

class Tree{
private:
    Node* root_node;//트리 당 루트 노드 하나.
    list<Node*>node_list;//모든 노드의 주소를 저장하는 리스트
public:
    Tree(int value);//생성자 함수
    int size();//트리 사이즈 리턴
    Node* root();//루트 노드의 주소 리턴
    list<Node*>::iterator find(list<Node*>& L, int value);//반복자
    //다른 위치로 이동할 수 있는 "위치 객체"->

    void insert(Node* pos, int value);//삽입
    void erase(Node* pos);//제거

};
Tree::Tree(int value):root_node(new Node(value,nullptr)){
    node_list.push_back(root_node);//루트 생성 및 전체 리스트에 삽입
}
int Tree::size(){
    return static_cast<int>(node_list.size());//리스트 기능
}
Node* Tree::root(){
    return root_node;//루트 노드 주소 반환
}
list<Node*>::iterator Tree::find(list<Node*>& L, int value){//반복자
    list<Node*>::iterator it=L.begin();//리스트의 첫 번째 원소 가리킴
    while(it!=L.end()){//끝까지 반복
        if((*it)->data==value){//*it-> 역참조 -> 리스트 속 값 참조.(node*객체)의 data 값이 같으면
            break;//while문 탈출
        }
        it++;//it 이동 (다음으로)
    }
    return it;//it 찾는 노드 위치를 가리키는 반복자 반환
}

void Tree::insert(Node* pos, int value){
    if(pos== nullptr){
        return;
    }
    Node* new_node=new Node(value,pos);//새로운 노드 할당
    pos->children.push_back(new_node);//자식노드에 집어넣음.
    node_list.push_back(new_node);//모든 노드 저장하는 곳에 삽입
}
void Tree::erase(Node* pos){
    if(pos== nullptr){//찾을 수 없는 노드면 리턴
        return;
    }
    if(pos==root_node){//지우려는 노드가 루트면 리턴
        cout<<"TryToRemoveRoot\n";
        return;
    }
    Node* parent_node=pos->parent;//지우려는 노드의 부모노드 주소저장
    parent_node->children.erase(find(parent_node->children,pos->data));//부모노드의 자식 중 지우려는 노드의 값을 가진 노드 찾아 지우기
    node_list.erase(find(node_list,pos->data));//전체 노드에서도 지우기

    for(Node* child:pos->children){//자식 노드들을 하나씩 꺼내서 child ptr로 접근
        parent_node->children.push_back(child);//부모 노드의 자식 노드에 삽입
        child->parent=parent_node;//부모 변경
    }
    delete pos;
}