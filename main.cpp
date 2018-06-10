//
//  main.cpp
//  LinkedList
//
//  Created by Ruban Rengaraju on 6/6/18.
//  Copyright © 2018 Ruban Rengaraju. All rights reserved.
//

#include <iostream>
using namespace std;

class linkedList{
public:
    
    linkedList(){
        head = nullptr;
    }
    
    void addNode(string v){
        if(head == nullptr){
            Node* p = new Node;
            p->name = v;
            p->next = nullptr;
            head = p;
        }
        
        Node* p = head;
        while(p->next != nullptr){
            p = p->next;
        }
        Node* n = new Node;
        p->next = n;
        n->name = v;
        n->next = nullptr;

    }
    
    void searchNode(string v){
        if(head == nullptr){
            cout<< "Empty List!"<< endl;
            return;
        }
        Node* p = head;
        while(p != nullptr){
            if (p->name == v) {
                cout<< "Found "<<v<<"!"<< endl;;
                return;
            }
            p = p->next;
        }
        cout<< v <<" couldn't be found"<< endl;
        return;
    }
    
    
    void deleteFirstNode(string v){
        if(head == nullptr){
            cout<<"Empty list, can't delete "<<v<<"!"<<endl;
            return;
        }
        Node* p = head;
        if(p->name == v){
            head = nullptr;
            delete p;
            cout<< v<<" was found and deleted"<<endl;
            return;
        }
        while(p->next->name != v){
            p = p->next;
        }
        Node* n = p->next;
        if(p->next->next == nullptr){
            p->next = nullptr;
            delete n;
            cout<<v<<" was found and deleted"<<endl;
            return;
        }
        p->next = p->next->next;
        delete n;
        cout<<v<<" was found and deleted"<<endl;
        return;
    }
    
private:
    struct Node{
        string name;
        Node* next;
    };
    Node* head;
    
};

int main() {
    linkedList BE;
    int r;
    string x,y,z;
    cout<< "How many members do you want to add: ";
    cin>>r;
    if(r == 1){
        cout<<"First name: ";
        cin>>x;
        BE.addNode(x);
    }
    else
        if(r == 2){
            cout<<"First name: ";
            cin>>x;
            cout<<"Second name: ";
            cin>>y;
            BE.addNode(x);
            BE.addNode(y);
        }
    else
        if(r == 3){
            cout<<"First name: ";
            cin>>x;
            cout<<"Second name: ";
            cin>>y;
            cout<<"Third name: ";
            cin>>z;
            BE.addNode(x);
            BE.addNode(y);
            BE.addNode(z);
        }
    
    
    BE.searchNode("Bob");
    BE.deleteFirstNode("Bob");
}








