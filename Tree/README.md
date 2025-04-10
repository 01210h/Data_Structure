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
