#include "4AT.h"
#include <iostream>

elmFourAT::elmFourAT(infotype data):info(data){
    for (size_t i = 0;i < 4;i++){
        children[i] = nullptr;
    }
}

bool isLeaf(elmFourAT p){
    for (size_t i = 0;i < 4;i++){
        if (p->children[i] != nullptr){
            return false;
        }
    }
    return true;
}

FourAryTree::FourAryTree():root(nullptr){}

void FourAryTree::traversePreorder(address p,address q,infotype info){
    if (info == p->info){
        q = p;
    }
    if q != nullptr{
        for (size_t i = 0;i < 4;i++){
            traversePreorder(p->children[i],q,info);
        }
    }
}

void FourAryTree::traverseDelete(address p){
    if (p != nullptr){
        for (size_t i = 0;i < 4;i++){
            traverseDelete(p->children[i]);
        }
        delete p;
    }
}

void FourAryTree::traversePrint(address p){
    if (p != nullptr){
        int n_child;
        n_child = 0;
        cout<<"Parent: "<<p->info<<endl;
        cout<<"Children: ";
        for (size_t i =0;i < 4;i++){
            if (p->children[i] != nullptr){
                cout<<p->children[i]->info<<" ";
                n_child++;
            }
        }
        if (n_child == 0){
            cout<<"Tidak mempunyai anak"<<endl;
        }
        for (size_t i = 0;i < 4;i++){
            traversePrint(p->children[i]);
        }
    }
}

address FourAryTree::searchElm(infotype info){
    if (this->root != nullptr){
        address p,q;
        p = this->root;
        q = nullptr;
        traversePreorder(p,q,info);
        return q;
    }else{
        return nullptr;
    }
}

void FourAryTree::insertChild(infotype parentInfo,infotype childInfo,int position){
    if (childInfo != -1){
        address child = new elmFourAT(childInfo);
        address parent = searchElm(parentInfo);
        if (parent != nullptr){
            parent->children[position] = child;
        }
    }
}



void FourAryTree::deleteChild(infotype parentInfo,infotype childInfo){
    address child = nullptr;
    address parent = searchElm(parentInfo);
    if (parent != nullptr){
        for (size_t i = 0 ;i < 4;i++){
            if (childInfo == parent->children[i]->info){
                child = parent->children[i];
                break;
            }
        }
        traverseDelete(child);
    }
}

void FourAryTree::printAll(){
    if (this->root != nullptr){
        int n_child = 0;
        cout<<"Root: "<<this->root->info<<endl;
        cout<<"Children: ";
        for (size_t i = 0;i < 4;i++){
            if (this->root->children[i] != nullptr){
                cout<<root->children[i]->info<<" ";
                n_child++;
            }
        }
        if (n_child == 0){
            cout<<"Tidak memiliki anak"<<endl;
        }
        for (size_t i = 0;i < 4;i++){
            traversePrint(this->root->children[i]);
        }
    }else{
        cout<<"Pohon kosong"<<endl;
    }
}
