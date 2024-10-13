#include <iostream>
#include "4AT.h"

using namespace std;

int main()
{
    FourAryTree T;
    int perintah,parentInfo;
    infotype data;

    perintah = 1;
    cout<<"Masukan data root: ";
    cin>>data;
    T.insertRoot(data);
    while (perintah == 1){
        cout<<"Masukan data parent: ";
        cin>>parentInfo;
        cout<<"Masukan data children: ";
        for (size_t i = 0;i < 4;i++){
            cin>>data;
            T.insertChild(parentInfo,data,i);
        }
        cout<<"Input: ";
        cin>>perintah;
    }
    T.printAll();
    cout<<"Masukan simpul yang ingin dihapus: ";
    cin>>parentInfo;
    cin>>data;
    T.deleteChild(parentInfo,data);
    T.printAll();
    return 0;

    /*FourAryTree T;
    infotype data,rootInfo;
    cout<<"Masukan root: ";
    cin>>rootInfo;
    T.insertRoot(rootInfo);
    cout<<"Masukan children: ";
    for (size_t i = 0;i < 4;i++){
        cin>>data;
        T.insertChild(rootInfo,data,i);
    }
    address child = T.searchElm(2);
    cout<<child->info<<endl;*/
}
