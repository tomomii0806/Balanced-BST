/*
 * Tomomi Nakamura
 * Balanced BST
 * file @ bintree.cpp
 */

#include "bintree.h"
#include <stack>    //Being used for stack
#include <iomanip>  //Being used for setw();


// ------------------------------------ constructor -----------------------------------------------

// Description

// constructor: constructor to initialize 'BinTree'
// preconditions:
// postconditions: settting root = NULL and size = 0
//

// --------------------------------------------------------------------------------------------
BinTree::BinTree() {
    size = 0;
    root = NULL;
}

// ------------------------------------ copy constructor -----------------------------------------------

// Description

// copy constructor: copy constructor to initialize 'BinTree'
// preconditions:  'bt' is a BinTree to copy its all NodeDatas to 'this'
// postconditions: calling copyTree which create a copy of bt, and set the result of copyTree as root
//                 settting root  and setting size same as size of 'bt'
//

// --------------------------------------------------------------------------------------------
BinTree::BinTree(const BinTree &bt) {

    root = copyTree(bt.root);

     size = bt.size;

}

// ------------------------------------ copyTree -----------------------------------------------

// Description

// copyTree:       function create a copy of BinTree whose root if specified as 'curr' in parameter
// preconditions:  'curr' is a node of BinTree to copy
// postconditions: recusively create child nodes first and new 'node' points those children
//                 return 'node'

// --------------------------------------------------------------------------------------------
BinTree::Node *BinTree::copyTree(BinTree::Node *curr) {
    if (curr == NULL)
    {
        return NULL;
    }

    Node* node = new Node();
    node->data = curr->data;
    node->left = copyTree(curr->left);
    node->right = copyTree(curr->right);
    return node;
}

// ------------------------------------ destructor -----------------------------------------------

// Description

// destructor:     function delete the BinTree
// preconditions:
// postconditions: call function makeEmpty()

// --------------------------------------------------------------------------------------------
BinTree::~BinTree() {
    makeEmpty();
}

// ------------------------------------ isEmpty() -----------------------------------------------

// Description

// isEmpty():      function check if the BinTree is empty
// preconditions:
// postconditions: return true is empty, if not return false

// --------------------------------------------------------------------------------------------
bool BinTree::isEmpty() const {
    return root == NULL ? true : false;
}

// ------------------------------------ makeEmpty -----------------------------------------------

// Description

// makeEmpty:      function delete BinTree without memory leak
// preconditions:
// postconditions: call private method makeEmpty(Node*) to delete all child nodes
//                 set root = NULL and size = 0

// --------------------------------------------------------------------------------------------
void BinTree::makeEmpty() {
    makeEmpty(root);
    root = NULL;
    size = 0;
}

// ------------------------------------ makeEmpty -----------------------------------------------

// Description

// makeEmpty:      private function delete BinTree without memory leak
// preconditions:  'curr' points to a node to delete
// postconditions: recusively delete child nodes first. if curr is NULL, skip deleting

// --------------------------------------------------------------------------------------------
void BinTree::makeEmpty(BinTree::Node *&curr) {
    if (curr != NULL)
    {
        makeEmpty(curr->left);
        makeEmpty(curr->right);

        curr->data = NULL;
        delete curr->data;

        delete curr;
        curr = NULL;
    }

}

// ------------------------------------ operator = -----------------------------------------------

// Description

// operator=:      function to overload assignment operator= for BinTree
// preconditions:  'bt' is a BinTree to copy its all NodeDatas to 'this'
// postconditions: delete all nodes before copying 'bt'
//                 call copyTree to recusively create child nodes first and new 'node' points those children
//                 update size to the size of 'bt'
//                 return *this

// ----------------------------------------------------------------------------------------------
BinTree &BinTree::operator=(const BinTree &bt) {

    if (!isEmpty())
    {
        makeEmpty();
    }
    root = copyTree(bt.root);
    size = bt.size;
    return *this;
}

// ------------------------------------ operator == -----------------------------------------------

// Description

// operator==:     function to overload assignment operator== for BinTree
// preconditions:  'bt' is a BinTree to compare if its NodeDatas matche to the ones of 'this'
// postconditions: call function checkEqualsTo to check if two BinTrees are the same
//                 return true is they are same, if not return false
//

// ----------------------------------------------------------------------------------------------
bool BinTree::operator==(const BinTree &bt) const {
    bool isEqual = true;
    checkEqualTo(root, bt.root, isEqual);
    return isEqual;
}

// ------------------------------------ operator != -----------------------------------------------

// Description

// operator!=:     function to overload assignment operator!= for BinTree
// preconditions:  'bt' is a BinTree to compare if its NodeDatas matche to the ones of 'this'
// postconditions: call function checkEqualsTo to check if two BinTrees are the same
//                 return false is they are same, if not return true
//

// ----------------------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree &bt) const {
    bool isEqual = true;
    checkEqualTo(root, bt.root, isEqual);
    return isEqual ? false : true;
}

// ------------------------------------ checkEqualTo -----------------------------------------------

// Description

// checkEqualTo:    function to to compare if two BinTrees are the same
// preconditions:  'n1' and 'n2' are BinTrees to compare if their NodeDatas matche one another
// postconditions: create stack 'st' to iteratively check all nodes by in-order traversal
//                 return false if any node's data is different, if not then return true
//

// ----------------------------------------------------------------------------------------------
void BinTree::checkEqualTo(BinTree::Node* n1, BinTree::Node *n2, bool& isEqual) const {

    if ((n1 == NULL && n2 == NULL) || !isEqual)
    {
        return;
    }
    if ((n1 == NULL && n2 != NULL)|| (n1 != NULL && n2 == NULL) || (n1->data != n2->data) )
    {
         isEqual = false;
         return;
    }
        checkEqualTo(n1->left, n2->left, isEqual);
        checkEqualTo(n1->right, n2->right, isEqual);


    /*stack<BinTree::Node*> st;

    while ((n1 != NULL || n2 != NULL || !st.empty()))
    {

        if (n1 != NULL && n2 != NULL)
        {
            if (n1->data != n2->data)
            {
                return false;
            }
            st.push(n1);
            n1 = n1->left;
            n2 = n2->left;

        }
        else if (n1 == NULL && n2 == NULL)
        {
            n1 = st.top();
            n2 = st.top();
            st.pop();
            if (n1->data != n2->data)
            {
                return false;
            }
            n1 = n1->right;
            n2 = n2->right;
        }
        else if ((n1 != NULL && n2 == NULL) || (n1 == NULL && n2 != NULL) || n1->data != n2->data)
        {
            return false;
        }

    }
    return true;
     */
}

// ------------------------------------ insert -----------------------------------------------

// Description

// insert:    function to insert all nodes
// preconditions:  'newData' is NodeData to insert to BinTree
// postconditions: if root if null, create new Node and set it as root
//                 if not, call private method insert(NodeData*, Node*) to add 'newData' to proper position
//                 return true if insertion successed
//

// ----------------------------------------------------------------------------------------------
bool BinTree::insert(NodeData *newData) {

    if (isEmpty())
    {
        root = new Node();
        root->data = newData;
        size++;
        return true;
    }

    return insert(newData, root);
}

// ------------------------------------ insert -----------------------------------------------

// Description

// insert:          private function to insert all nodes
// preconditions:  'newData' is NodeData to insert to BinTree, 'curr' points to the current node
// postconditions: if newData is already in BinTree, return false.
//                 if curr.right or curr.left is null, insert a new Node with newData, and return true
//                 if newData is smaller or bigger than data which curr points to, move curr left or right
//

// ----------------------------------------------------------------------------------------------
bool BinTree::insert(NodeData *newData, BinTree::Node* curr) {

    if (*newData == *curr->data)
    {
        return false;
    }
    else if (*newData < *curr->data)
    {
        if (curr->left == NULL)
        {
            curr->left = new Node();
            curr->left->data = newData;
            size++;
            return true;
        }
        return insert(newData, curr->left);
    }
    else if (*newData > *curr->data)
    {
        if (curr->right == NULL)
        {
            curr->right = new Node();
            curr->right->data = newData;
            size++;
            return true;
        }
        return insert(newData, curr->right);
    }
    return false;
}

// ------------------------------------ retrive -----------------------------------------------

// Description

// retrive:        function to retrive specified node
// preconditions:  'nodeToBeDound' is NodeData to to be found from BinTree, 'foundObj' points a node in BinTree
//                  which was found to be to the current node
// postconditions: is root is null, return false. if not, call private method retrive
//

// ----------------------------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData &nodeTobeFound, NodeData* &foundObj) const {
    if (root == NULL)
    {
        return false;
    }

    return retrieve(nodeTobeFound, foundObj, root);
}

// ------------------------------------ retrive -----------------------------------------------

// Description

// retrive:        private function to retrive specified node
// preconditions:  'nodeToBeDound' is NodeData to to be found from BinTree, 'foundObj' points a node in BinTree
//                  which was found to be to the current node
// postconditions: is root is null, return false. if not, call private method retrive
//

// ----------------------------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData &nodeTobeFound, NodeData *&foundObj, BinTree::Node *curr) const {


    if (curr == NULL) {
        return false;
    } else if (nodeTobeFound == *curr->data) {
        foundObj = curr->data;
        return true;
    } else if (*curr->data > nodeTobeFound) {
        return retrieve(nodeTobeFound, foundObj, curr->left);
    } else if (*curr->data < nodeTobeFound) {
        return retrieve(nodeTobeFound, foundObj, curr->right);
    }
    return false;
}

// ------------------------------------ diplaySideway -----------------------------------------------

// Description

// displaySideway:   function to display all nodes in BinTree sideways
// preconditions:
// postconditions: if root is not null, call private method sideways()
//

// ----------------------------------------------------------------------------------------------
void BinTree::displaySideways() const {
    if (root == NULL)
    {
        return;
    }
    cout << endl;
    sideways(root, 8);
}

// ------------------------------------ sideways -----------------------------------------------

// Description

// sideways:   private function to display all nodes in BinTree sideways
// preconditions:  'curr' points to current node in BinTree. 'h' keeps track of the node's height
//                  and is used to display some spaces by using setw()
// postconditions: if curr is not null, recursively displays nodes by in-order traversal
//

// ----------------------------------------------------------------------------------------------
void BinTree::sideways(BinTree::Node *curr, int h) const {

    if (curr == NULL)
    {
        return;
    }
    sideways(curr->right, h + 5);
    cout << setw(h) << *curr->data << endl;
    sideways(curr->left, h + 5);

}


// ------------------------------------ operator << -----------------------------------------------

// Description

// operator<<:     function to overload assignment operator<< for BinTree
// preconditions:  'bt' is a BinTree to output its all NodeDatas
// postconditions: using stack, iteratively chrck all nodes using in-order traversal.
//                 return output

// ----------------------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const BinTree& bt) {


    BinTree::Node* curr = bt.root;

    stack<BinTree::Node*> st;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr =  st.top();
            st.pop();

            output << *curr->data << " ";
            curr = curr->right;
        }
    }

    return output;
}

// ------------------------------------ getHeight -----------------------------------------------

// Description

// getheight:     function to get a height of specified node in BinTree
// preconditions:  'nodeToFind' is a node to be found in BinTree
// postconditions: using stack, iteratively find and point a node which contins data 'nodeToFind'
//                 Pass the node to private function to find get a height of the node.
//                 if the node wasnt found, return 0

// ----------------------------------------------------------------------------------------------
int BinTree::getHeight(const NodeData &nodeToFind) const{
    if (root == NULL)
    {
        return 0;
    }
    NodeData* node;
    if (!retrieve(nodeToFind, node))
    {
        return 0;
    }

    Node* curr = root;
    stack<Node*> st;
    while ((curr != NULL || !st.empty())) {


        if (curr != NULL) {
            if (curr != NULL && *curr->data == nodeToFind)
            {
                break;
            }
            st.push(curr);
            //st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();


            curr = curr->right;
        }

        /*if (curr != NULL && *curr->data == nodeToFind)
        {
            break;
        }*/
    }



    return getHeight(curr);
}

// ------------------------------------ getHeight -----------------------------------------------

// Description

// getheight:      private function to get a height of specified node in BinTree
// preconditions:  'curr' points to a node to get a height
// postconditions: recursively get a height of the node if the curr = null return 0 so that next height
//                 is returned as 1. if curr has two child nodes, compute with larger height

// ----------------------------------------------------------------------------------------------
int BinTree::getHeight(BinTree::Node *curr) const{


    if (curr == NULL)
    {
        return 0;
    }
    return max(getHeight(curr->left) + 1, getHeight(curr->right) + 1);


}


// ------------------------------------ bstreeToArray -----------------------------------------------

// Description

// bstreeToArray:  function to convert BinTree to array
// preconditions:  'ndArray' is an empty array to hold nodadatas from the tree
// postconditions: using stack, iteratively go through and insert a nodedat to ndArray

// ----------------------------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData *ndArray[]) {
    if (root == NULL)
    {
        return;
    }

    Node* curr = root;
    stack<Node*> st;
    int idx = 0;
    while ((curr != NULL || !st.empty())) {


        if (curr != NULL) {
            st.push(curr);
            //st.push(curr);
            curr = curr->left;
        } else {
            curr = st.top();
            st.pop();

            ndArray[idx] = curr->data;
            delete curr;
            idx++;

            curr = curr->right;
        }

    }
    root = NULL;
}

// ------------------------------------ arrayToBSTree -----------------------------------------------

// Description

// arrayToBSTree:  function to convert array to BSTree
// preconditions:  'arr' is an array which hold nodadatas
// postconditions: if root is null, call pivat functin to convert the array to BSTree
//                 if not, do nothing
// ----------------------------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData *arr[]) {

    if (root == NULL)
    {
        root = arrayToBSTree(arr, 0, size - 1);
    }
}

// ------------------------------------ arrayToBSTree -----------------------------------------------

// Description

// arrayToBSTree:  private function to convert array to BSTree
// preconditions:  'arr' is an array which hold nodadatas, l is the left index, r is the right index
// postconditions: if l is lower than r, create a new node with arr[mid] where mid is a midde index
//                 between l and r.
//                 set node right and left, and return node.
// ----------------------------------------------------------------------------------------------
BinTree::Node *BinTree::arrayToBSTree(NodeData *arr[], int l, int r) {

    if (l > r)
    {
        return NULL;
    }

    int mid = (l + r) / 2;
    Node* node = new Node();
    node->data = arr[mid];
    node->left = arrayToBSTree(arr, l, mid - 1);
    node->right = arrayToBSTree(arr, mid + 1, r);
    return node;
}






