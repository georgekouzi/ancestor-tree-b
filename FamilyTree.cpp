#include <iostream>
#include "FamilyTree.hpp"
#include <cmath>
#include <string>

using namespace std;
using namespace family;

 
Node* Tree:: serch(string c,Node *root){ 
       if(root==NULL)
         return NULL;
     
    if(root->name == c)
        return root;
    Node * dl=serch(c,root->father);
     if(dl!= NULL)
        return dl;    
    else
    return serch(c,root->mother);

     

}

Tree& Tree::addFather(string child,string father){
    
    Node * findchild=serch(child,this->t);
    if (findchild== NULL) {
       throw invalid_argument("This child didnt in the tree");
    }
    else{
        if(findchild->father== NULL) {
             Node * n= new Node(father,child,statusNode((findchild->num)+1,'m'),(findchild->num)+1,'m');
          findchild->father =n;

        }
        else{
            throw invalid_argument("This child have dad already");
        }
    }
    return *this;
}
Tree& Tree::addMother(string child,string mother) {
    Node * findchild=serch(child,this->t);
    if (findchild== NULL) {
       throw invalid_argument("This child didnt in the tree");
    
    }
    else{
        if(findchild->mother== NULL) {
             Node * n= new Node(mother,child,statusNode(findchild->num+1,'w'),(findchild->num)+1,'w');    
          findchild->mother =n;
        }
        else{
            
            throw invalid_argument("This child have dad already");
        }
    }

    return *this;
}


string Tree::statusNode(int n,char g){

string ans="";

 if(n==1){
    if(g=='m')
    return "father";
    else
    return "mother";
}
else{
int f =n-2;
while(f>0){
ans+="great-";
f--;
} 
if(g=='w')
ans+="grandmother";
else
ans+="grandfather";
}
    return ans;
}

string family::Tree::relation(string s){

Node* n = serch(s, this->t);

if(n==NULL){
return "unrelated";
}
if(n==this->t)
return t->status;
else
return n->status;
}

Node* Tree::findStatus(string s1,Node*n){
   if(n == NULL)
        return NULL;
    if(n->status == s1 && n->onOff==true)
        return n; 
    Node * dl=findStatus(s1,n->mother);
     if(dl!= NULL)
        return dl;    
    else
    return findStatus(s1,n->father);
}


string Tree::find(string s1){
Node* n = findStatus(s1, this->t);
if(n==NULL){
    throw invalid_argument("This child have dad already");

}
 else if(n==this->t){
return this->t->name;
}
 else
return n->name;




// else
// return sameStatus(n,true,s1);
 }


string Tree:: sameStatus(Node*n,bool ans, string s){
string str="";
str+=n->name;
n->onOff=false;
int loop=(pow(2,n->num)/2)-1;
while(loop!=0){
Node* n = findStatus(s,this->t);
if (n!=NULL){
str+=","+n->name;
n->onOff=false;
}
loop--;
}
if(ans){
ternOn(this->t);
}
return str;
}


void Tree::ternOn(Node*root){
              if(root->father!=NULL && root->mother!=NULL){
                    root->father->onOff=true; 
                    root->mother->onOff=true; 
                    ternOn(root->father);
                    ternOn(root->mother);
              }
        if(root->father!=NULL&&root->mother==NULL){
                    root->father->onOff=true; 
                     ternOn(root->father);
              }
         if(root->mother!=NULL&&root->father==NULL){
                    root->mother->onOff=true; 
                    ternOn(root->mother);


       }

}




void Tree::display(){
printfamily(this->t);
ternOn(this->t);

}

void Tree:: printfamily(Node *root ){
    
    
    if(root->num==0){
  cout<<root->status+": "+root->name<<endl;
    
    } 
              if(root->father!=NULL && root->mother!=NULL && root->father->onOff==true&&root->mother->onOff==true){
      
               cout<<root->father->status+": "+sameStatus(root->father,false,root->father->status)<<endl;
                cout<<root->mother->status+": "+sameStatus(root->mother,false,root->mother->status)<<endl;
             
            printfamily(root->father);
             printfamily(root->mother);
                }
             
              if(root->father!=NULL&&root->mother==NULL&& root->father->onOff==true){
            cout<< root->father->status+": "+sameStatus(root->father,false,root->father->status)<<endl;
                     printfamily(root->father);

              }

              if(root->mother!=NULL&&root->father==NULL&&root->mother->onOff==true ){
           cout<< root->mother->status+": "+sameStatus(root->mother,false,root->mother->status)<<endl;
                       printfamily(root->mother);

               }
            
       
        }   
             



void Tree::remove(string name){

Node * findNode=serch(name,this->t);

if (findNode== NULL) {
    throw invalid_argument(name+" didnt in the tree");
    }

else if (findNode->num==0) {

    throw invalid_argument(" you try to remove the root ");

    }
    
 else{

 Node* childNode =serch(findNode->child,this->t);

 if(findNode->gender=='m'){

 delete(childNode->father);
 childNode->father=NULL;
}
 else{
  delete(childNode->mother);
 childNode->mother=NULL;
 }
}
}




  










