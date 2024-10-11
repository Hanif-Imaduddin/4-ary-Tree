#ifndef 4AT_H_INCLUDED
#define 4AT_H_INCLUDED

typedef int infotype;
typedef struct elmFourAT* address;

struct elmFourAT{
    infotype info;
    address children[4];
    elmFourAT(infotype);
};

bool isLeaf(elmFourAT);

struct FourAryTree{
    address root;

    FourAryTree();

    void traversePreorder(address,address,infotype);
    void traverseDelete(address);
    void traversePrint(address);
    address searchElm(infotype info);
    void insertRoot(infotype);
    void insertChild(infotype,infotype,int);
    void deleteChild(infotype,infotype);
    void printAll();
    void deleteAll();
};

void createNewTree;

#endif // 4AT_H_INCLUDED
