//
//  unionFind.cpp
//  Union_find or disjointed_set data structure implementation
//
//  Created by DENG ZISHI on 1/28/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(size_t i=a;i<b;i++)
#define SC(x) scanf("%d",&x)

using namespace std;

//union-find data structure or disjointed set Node
struct Node{
    int rank;
    int data;
    Node* parent;
    
    Node(int d):data(d){}
};

void makeSet(Node x){
    x.parent=&x;
    x.rank=0;
}

//find function with path compression
Node* find(Node x){
    if(x.parent!=&x) x.parent=find(*(x.parent));
    return x.parent;
}

void Union(Node x,Node y){
    Node* xRoot = find(x);
    Node* yRoot = find(y);
    
    if(xRoot==yRoot) return;
    if(xRoot->rank < yRoot->rank) xRoot->parent = yRoot;
    else if(xRoot->rank > yRoot->rank) yRoot->parent = xRoot;
    else{
        yRoot->parent = xRoot;
        xRoot->rank+=1;
    }
}

typedef vector<Node> Vnode;
Vnode vecNode;

int main(){
    int x;
    SC(x);
    FOR(i,0,x){
        Node k = Node(i);
        makeSet(k);
        vecNode.push_back(k);
    }
    return 0;
}
