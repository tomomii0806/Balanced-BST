/*
 * Tomomi Nakamura
 * Balanced BST
 * file @ main.cpp
 */

#include "bintree.h"
//#include "bintree.cpp"
//#include "nodedata.h"
//#include "nodedata.cpp"
#include <fstream>
#include <iostream>
#include <cassert> // used for assert()


using namespace std;

const int ARRAYSIZE = 100;

//global function prototypes
void buildTree(BinTree&, ifstream&);      //
void initArray(NodeData*[]);             // initialize array to NULL

//
// ------------------------------------ Test1() -----------------------------------------------

// Description

// Tes1():   testing function insert, getHeight, displaySideway, and operator==
//

// ---------------------------------------------------------------------------------------
void Test1(){

    BinTree bt;
    NodeData* notND = new NodeData("not");
    NodeData* andND = new NodeData("and");
    NodeData* sssND = new NodeData("sss");
    NodeData* ttttND = new NodeData("tttt");
    NodeData* oooND = new NodeData("ooo");
    NodeData* yND = new NodeData("y");
    NodeData* eND = new NodeData("e");
    NodeData* mND = new NodeData("m");
    NodeData* tND = new NodeData("t");

    bt.insert(notND);
    bt.insert(andND);
    bt.insert(sssND);
    bt.insert(ttttND);
    bt.insert(oooND);
    bt.insert(yND);
    bt.insert(eND);
    bt.insert(mND);
    bt.insert(tND);

    //inserting same data
    assert(!bt.insert(sssND));

    NodeData And("andDDD");

    //cout << "Height: " << bt.getHeight(And) << endl;
    //cout << "Height: " << bt.getHeight(*notND) << endl;

    assert(bt.getHeight(*notND) == 4);
    assert(bt.getHeight(*andND) == 3);
    assert(bt.getHeight(*sssND) == 3);
    assert(bt.getHeight(*ttttND) == 2);
    assert(bt.getHeight(*oooND) == 1);
    assert(bt.getHeight(*yND) == 1);
    assert(bt.getHeight(*eND) == 2);
    assert(bt.getHeight(*mND) == 1);
    assert(bt.getHeight(*tND) == 1);
    //Data doesn't exist in BinTree
    assert(bt.getHeight(And) == 0);

    cout << "Display Test1() Tree" << endl;
    bt.displaySideways();

    NodeData y("y");
    NodeData* p = NULL;
    assert(!bt.retrieve(And, p));
    assert(p == NULL);
    assert(bt.retrieve(y, p));
    assert(*p == y);
}

// ------------------------------------ Test2() -----------------------------------------------

// Description

// Tes1():   testing operator =, ==, !=, and copy constructor
//

// ---------------------------------------------------------------------------------------
void Test2(){

    BinTree bt, btEmp;
    NodeData* notND = new NodeData("not");
    NodeData* andND = new NodeData("and");
    NodeData* sssND = new NodeData("sss");
    NodeData* ttttND = new NodeData("tttt");
    NodeData* oooND = new NodeData("ooo");
    NodeData* yND = new NodeData("y");
    NodeData* eND = new NodeData("e");
    NodeData* mND = new NodeData("m");
    NodeData* tND = new NodeData("t");

    bt.insert(notND);
    bt.insert(andND);
    bt.insert(sssND);
    bt.insert(ttttND);
    bt.insert(oooND);
    bt.insert(yND);
    bt.insert(eND);
    bt.insert(mND);
    bt.insert(tND);

    BinTree bt2 = bt;
    BinTree bt3(bt);

    //copy empty tree
    BinTree btEmp2 = btEmp;
    BinTree btEmp3(btEmp);
    assert(btEmp3 == btEmp2);
    btEmp2.displaySideways();
    cout << "Display Empty Tree" << endl;
    cout << btEmp << endl;

    NodeData* zND = new NodeData("z");
    NodeData* goodND = new NodeData("good");
    assert(bt2.insert(zND));
    assert(bt2.insert(goodND));

    assert(bt != bt2);
    assert(bt != btEmp);
    assert(bt == bt3);
}

// ------------------------------------ Test3() -----------------------------------------------

// Description

// Tes1():   testing arrayToBST and bstToArray
//

// ---------------------------------------------------------------------------------------
void Test3(){
    BinTree bt, bt3, btEmp;
    NodeData* k = new NodeData("k");
    NodeData* ok = new NodeData("ok");
    NodeData* d = new NodeData("d");
    NodeData* ht = new NodeData("ht");
    NodeData* fr = new NodeData("fr");
    NodeData* r = new NodeData("r");
    NodeData* u = new NodeData("u");
    NodeData* v = new NodeData("v");
    NodeData* fh = new NodeData("fh");

    bt.insert(k);
    bt.insert(ok);
    bt.insert(d);
    bt.insert(ht);
    bt.insert(fr);
    bt.insert(r);
    bt.insert(u);
    bt.insert(v);
    bt.insert(fh);

    BinTree bt2 = bt;
    NodeData* array[100];
    cout << "Before bstreeToArray" << endl;
    bt.displaySideways();
    bt.bstreeToArray(array);
    //bt is empty after bstToarray
    assert(bt == btEmp);
    bt.arrayToBSTree(array);
    cout << "After arrayToBSTree" << endl;
    bt.displaySideways();



}
int main() {

    Test1();
    Test2();
    Test3();

    cout << "Passed All Tests..." << endl;
}

