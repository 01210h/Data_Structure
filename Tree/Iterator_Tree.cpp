#include<iostream>
#include<list>
#include<string>
using namespace std;

class Tree;
class Node{
private:
    int data;
    list<Node*> childList;
    Node* parent;
    friend class Tree;
public:
    Node(int data,Node* parent):data(data),parent(parent){};
};
class Tree{
private:
    Node* root;
    list<Node*> allList;
public:
    Tree(int num);
    list<Node*>::iterator find(int v,list<Node*>& node);
    void Insert(int x,int v);
    void Delete(int v);
    void Parent(int v);
    void Children(int v);
    void Ancestors(int v);

    bool empty(list<Node*>& node);
};
Tree::Tree(int num):root(new Node(num, nullptr)){
    allList.push_back(root);
}
list<Node*>::iterator Tree::find(int val,list<Node*>& node){
    list<Node*>::iterator it=node.begin(); //탐색하려는 노드의 시작점 지정
    while(it!=node.end()){
        if((*it)->data==val){
            break;
        }
        it++;
    }
    return it;
}
bool Tree::empty(list<Node*>& node){
    return node.size()==0;
}
void Tree::Insert(int x,int v){
    if(v<1||v>10001||x<1||x>10001){//유효값인지 판단
        cout<<"-1\n";
        return;
    }
    list<Node*>::iterator key1=find(x,allList);//부모
    list<Node*>::iterator key2=find(v,allList);//자식
    if(key1==allList.end()||key2!=allList.end()){
        cout<<"-1\n";
        return;
    }
    Node* par=*(key1);
    Node* new_node=new Node(v,par);
    par->childList.push_back(new_node);
    allList.push_back(new_node);
}
void Tree::Delete(int v){
    list<Node*>::iterator key1=find(v,allList);
    if(key1==allList.end()||*(key1)==root){
        cout<<"-1\n";
        return;
    }
    Node* del=*(key1);//삭제하려는 노드
    Node* par=del->parent;
    par->childList.erase(find(v,par->childList));
    for(Node* view:del->childList){
        par->childList.push_back(view);
        view->parent=par;
    }
    allList.erase(key1);
    delete del;
}
void Tree::Parent(int v){
    list<Node*>::iterator key1=find(v,allList);
    if(key1==allList.end()){
        cout<<"-1\n";
        return;
    }
    Node* view=*(key1);
    if(view==root){
        cout<<"0\n";
        return;
    }
    cout<<view->parent->data<<"\n";
}
void Tree::Children(int v){
    list<Node*>::iterator key1=find(v,allList);
    if(key1==allList.end()){
        cout<<"-1\n";
        return;
    }
    Node* view=*(key1);
    if(empty(view->childList)){
        cout<<"0\n";
        return;
    }
    for(Node* cursor:view->childList){
        cout<<cursor->data<<" ";
    }
    cout<<"\n";
}
void Tree::Ancestors(int v){
    list<Node*>::iterator key1=find(v,allList);
    if(key1==allList.end()){
        cout<<"-1\n";
        return;
    }
    Node* view=*(key1);
    if(view==root){
        cout<<"0\n";
        return;
    }
    int N{0};
    while(view!=root){
        N++;
        view=view->parent;
    }
    cout<<N<<"\n";
}
int main(){
    int test,n1,n2;
    string str;
    cin>>test;
    Tree tree(1);
    for(int i=0;i<test;i++){
        cin>>str;
        if(str=="Insert"){
            cin>>n1>>n2;
            tree.Insert(n1,n2);
        }else if(str=="Parent"){
            cin>>n1;
            tree.Parent(n1);
        }else if(str=="Children"){
            cin>>n1;
            tree.Children(n1);
        }else if(str=="Ancestors"){
            cin>>n1;
            tree.Ancestors(n1);
        }else if(str=="Delete"){
            cin>>n1;
            tree.Delete(n1);
        }
    }
}
