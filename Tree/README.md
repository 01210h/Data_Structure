<h2>Basic Tree</h2>
<hr>

```cpp
#include<iostream>
#include<vector>
using namespace std;
class tree;
class Node{
private:
    int data;
    Node* parent;
    vector<Node*> childList;//자식들의 노드 주소를 갖고있음
    friend class tree;//friend 클래스를 추가하여 tree에서 접근 가능하도록 함.
public:
    Node(int data, Node* parent){
        this->data=data;
        this->parent=parent;
    }
};

class tree{
private:
    Node* root;//루트는 하나
    vector<Node*> nodeList;//벡터를 생성. Node* 즉, 노드의 주소를 저장. 이름은 nodeList
    int find(int data,vector<Node*>& list);//data를 갖는 노드의 인덱스를 찾음

public:
    tree(int data);
    void insertNode(int parData,int data);
    void deleteNode(int data);
    void printParent(int data);
    void printChild(int data);

};
tree::tree(int data):root(new Node(data, nullptr)){//생성자 함수
    nodeList.push_back(root);//생성한 루트를 푸쉬백으로 일단 전체 노드 주소록에 저장
}
int tree::find(int data,vector<Node*>& list){//data값을 가진 노드를 찾는 메소드
    for(int i=0;i<list.size();i++){//vector기능 사이즈만큼 순회
        if(list[i]->data==data){//노드의 data비교해서 찾으면 인덱스 리턴
            return i;
        }
    }
    return -1;//못 찾으면 -1 리턴
}
void tree::insertNode(int parData,int data){//삽입 메소드
    if(find(data,nodeList)!=-1){//이미 저장되어있으면
        return;//리턴 (삽입하지 않음)
    }
    int idx=find(parData,nodeList);//부모의 데이터 인덱스 저장
    if(idx==-1){//부모 데이터가 저장되어있지 않으면 리턴(삽입 못함)
        return;
    }
    Node* parNode=nodeList[idx];//찾은 인덱스로 부모 인덱스 가리키는 포인터 생성. 벡터가 주소저장하는 벡터이므로 & 안씀. 벡터 요소 주소는 필요가 없음
    Node* newNode=new Node(data,parNode);//새로운 동적 노드 설정. 부모 가리킴
    parNode->childList.push_back(newNode);//부모의 자식목록에 추가
    nodeList.push_back(newNode);//전체 노드 목록에도 추가
}
void tree::deleteNode(int data){
    int idx=find(data, nodeList);//지우려는 노드 찾기
    if(idx==-1){//노드가 존재하지 않으면 리턴
        return;
    }
    Node* delNode=nodeList[idx];//지우려는 노드 주소를 저장하는 포인터 생성
    if(delNode==root){
        return;//루트는 삭제하면 안 되므로 루트면 리턴
    }
    Node* parNode=delNode->parent;//삭제하려는 노드의 부모 노드 주소를 저장하는 포인터 생성
    for(int i=0;i<delNode->childList.size();i++){//삭제하려는 노드의 자식의 갯수만큼 반복
        parNode->childList.push_back(delNode->childList[i]);//부모노드의 자식에 삽입
        delNode->childList[i]->parent=parNode;//부모 변경
    }

    vector<Node*>&child=parNode->childList;//부모의 자식 목록 받는 참조자 생성(참조자가 더 편리)
    child.erase(child.begin()+find(data,child));//vector 기능? 부모노드의 자식목록에서 삭제
    delete nodeList[idx];//메모리 해제 (집 제거)
    nodeList.erase(nodeList.begin()+idx);//전체 노드에서 삭제+자동당기기(집주소 제거)
}
void tree::printParent(int data){//부모 출력
    int idx=find(data,nodeList);//인덱스 찾기
    if(idx==-1){
        return;
    }
    Node* curNode=nodeList[idx];//찾은 인덱스 이용해서 노드 포인터 생성
    cout<<curNode->parent->data<<endl;//그 노드의 부모의 데이터 출력
}
void tree::printChild(int data){//아이들 출력
    int idx=find(data,nodeList);//데이터를 가진 인덱스 찾기
    if(idx==-1){
        return;
    }
    vector<Node*>& child=nodeList[idx]->childList;//벡터 받는 참조자 생성(참조자가 더 편리)
    for(int i=0;i<child.size();i++){//자식 갯수만큼 반복
        cout<<child[i]->data<<" ";//자식 데이터 출력
    }
    cout<<endl;
}
```
<pre>
  오랜만에 하나하나 보니 부족한 점이 많이 보임. 
  포인터로 객체의 함수, 변수에 접근 시 -> 이용, 참조자일 시 . 이용
  delete 는 힙영역에서 할당된 메모리를 해제.(집 허물기)
  벡터 erase 기능 사용시 지우려는 것의 주소까지 삭제. (집주소 삭제)
  
</pre>

<h2>Iterator Tree</h2>
<hr>

```cpp
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
```
