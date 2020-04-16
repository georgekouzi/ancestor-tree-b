#include <string>
#include "node.hpp"
#include <iostream>

using namespace std;
namespace family{
class Tree{                               
public:
Node* t;
     Tree(string root){
        t=new Node(root);

     }
Node* getNode(){
  return this->t;
}
Node* serch(string c,Node*allNode);
Tree& addFather(string child,string father);
Tree& addMother(string child,string mother);
string statusNode(int n,char g);
string relation(string s);
Node* findStatus(string c,Node*allNode);
string find(string s1);
string sameStatus(Node*n,bool ans,string s );
void ternOn(Node*root);
void printfamily(Node *root);
void display();
void remove(string name); 
~Tree(){}
};
};