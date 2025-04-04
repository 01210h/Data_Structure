#include<iostream>
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
    Node* head;
    Node* tail;
    int N;
public:
    list();
    void deleteByValue(int x);
    void insert_front(int x);
};

list::list():N(0),head(nullptr),tail(nullptr){}
void list::deleteByValue(int x){
    if(head== nullptr){
        return;
    }
    if(head->data==x){
        Node* del=head;
        head=head->next;
        if(del==tail){
            tail= nullptr;
        }
        delete del;
        N--;
        return;
    }
    Node* cursor=head;
    while(cursor!= nullptr){
        if(cursor->next->data==x&&cursor->next!= nullptr){
            Node* erase_node=cursor->next;
            if(erase_node==tail){
                tail=cursor;
                cursor->next= nullptr;
            }else{
                cursor->next=erase_node->next;
            }
            delete erase_node;
            N--;
            return;
        }
        cursor=cursor->next;
    }
    cout<<"x isn't in list.\n";
}
void list::insert_front(int x){
    Node* new_node=new Node(x);
    if(N==0){
        head=tail=new_node;
    }else{
        new_node->next=head;
        head=new_node;
    }
    N++;
}