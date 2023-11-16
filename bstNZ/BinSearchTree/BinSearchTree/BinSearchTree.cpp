//
// Created by Ali Kooshesh on 3/1/23.
// School Assignment Completed by: Natnael Zeweldi
//

#include <iostream>
#include "BinSearchTree.hpp"
#include <queue>
#include <algorithm>

BinSearchTree::BinSearchTree(): root{nullptr} {}

TreeNode *BinSearchTree::insert( TreeNode *root, int v ) {

    if( root == nullptr ) // base case: empty node to insert new one
        return new TreeNode( v );

    if( root->value() < v ) // find a position closest to v
        root->rightSubtree( insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( insert( root->leftSubtree(), v ) );

    return root;
}

void BinSearchTree::insert(int v) {
    // Insert v in the tree if it is not already a member.
    if( ! find(v) ) {
        root = insert(root, v);
    }
}

int BinSearchTree::size() {

    return size(root);
}

int BinSearchTree::size(TreeNode *root){
// counts and returns the number of nodes
// in the tree that is rooted at"root"
    if(root == nullptr)
        return 0;

    return 1 + size(root->leftSubtree()) + size(root->rightSubtree());

}

bool BinSearchTree::find(int v) {
    // Function has a recursive implementation.

    return find(root,v);
}

bool BinSearchTree::find(TreeNode* root, int target){
    if (root == nullptr) // base case: not found
        return false;

    if(root->value() == target) //target found true
        return true;

    if(root->value() > target) // search for target by traversing closest to where value may be
        return find(root->leftSubtree(), target);

    return find(root->rightSubtree(), target);
}

BinSearchTree::~BinSearchTree() {
    // This function should delete every node in the tree.
    // To do that, you will have to recursively traverse the tree, using
    // a post-order traversal.
    deleteNodes(root);
}

void BinSearchTree::deleteNodes(TreeNode *root){ // postorder traversal deleting the entirety of the trees nodse
    if(root!=nullptr){
        deleteNodes(root->leftSubtree());
        deleteNodes(root->rightSubtree());
        delete root;
    }
}

bool BinSearchTree::iterFind(int v) {

    return iterFind(root,v);
}

// iterative find function
bool BinSearchTree::iterFind(TreeNode *root, int target){
    if(root == nullptr){
        return false;
    }
    while(root!=nullptr) {
        if(root->value() == target){
            return true;
        }
// while root isn't nullptr search by comparing if root value is less than, greater than or equal to target
        if(root->value() < target)
        root = root->rightSubtree();
        else
        root = root->leftSubtree();

    }

    return false;
}

int BinSearchTree::maxDepth() {
    return maxDepth(root);
}

// recursive height function that always returns the greater of two heights
int BinSearchTree::maxDepth(TreeNode *root) {

    if(root==nullptr){
        return 0;
    }
    return 1 + std::max(maxDepth(root->rightSubtree()),maxDepth(root->leftSubtree()));
}

void BinSearchTree::inorderDump() {
    inorderDump(root);
}

// inorder traversal of a tree that goes from smallest value to the largest value
void BinSearchTree::inorderDump(TreeNode *root){
    if(root!=nullptr) {

        inorderDump(root->leftSubtree());

        std::cout << root->value() << std::endl;

        inorderDump(root->rightSubtree());
    }
}

/*
 prints the values in the tree, one per line, using a
 level-order traversal. You must write an iterative
 solution using a FCFS queue.
*/

void BinSearchTree::levelOrderDump(){
    levelOrderDump(root);
}

void BinSearchTree::levelOrderDump(TreeNode * root){ // done

   if(root==nullptr) // base case
       return;

   std::queue<TreeNode *> queue; // create queue (FCFS) call it queue
   TreeNode * curNode;
   queue.push(root); // add (enqueue) the root node to queue


   while (!queue.empty()) { // while queue is not empty do:

       curNode = queue.front(); // current node gets oldest node from queue
       std::cout << curNode->value() << std::endl;
       queue.pop(); // remove oldest node from the queue

       if (curNode->leftSubtree()!=nullptr) { // if the left subtree of current node is not empty add to queue
           queue.push(curNode->leftSubtree());
       }

       if (curNode->rightSubtree()!=nullptr) { // if the right subtree of current node is not empty add to queue
           queue.push(curNode->rightSubtree());
       }
   }
}

/*
 removes the node containing the value v from the tree,
 if it exists. It returns true if the value was in the
 tree and false otherwise. You can choose to write an
 iterative solution or a recursive solution for this function.
*/

bool BinSearchTree::remove( int v ){
    if(find(v)){

        deletes(root,v);
        return true;
    }
    else {

        return false;
    }
}

TreeNode* BinSearchTree::deletes(TreeNode * root,int target) { // done
    TreeNode *curNode; // temporary node for current position

    if (root == nullptr) { // base case
        return root;
    }
    else if (target < root->value()) { // check if target is less than or greater than root until you find target
        root->leftSubtree(deletes(root->leftSubtree(), target));
    }
    else if (target > root->value()) {
        root->rightSubtree(deletes(root->rightSubtree(), target));

    }
    else {
        // no children nodes, less work just delete root and assign it nullptr
        if (root->leftSubtree() == nullptr && root->rightSubtree() == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->rightSubtree() == nullptr) {
            curNode = root;
            root = root->leftSubtree(); // reattach left child
            delete curNode;

        }
        else if (root->leftSubtree() == nullptr) {
            curNode = root;
            root = root->rightSubtree(); // reattach right child
            delete curNode;
        }
        else { // inorder successor (smallest or leftmost value from the right of node)
            curNode = root->rightSubtree(); // move one node to the right
            int cNSize = size(curNode);
            // find left most node (minimum)

            for (int count = 0; count < cNSize; count++){
                curNode->leftSubtree();
            }

            root->value() = curNode->value(); //assign root value as curNode's value
            root->rightSubtree(deletes(root->rightSubtree(),curNode->value()));
            // reattach remaining subtrees
        }
    }

    return root;
}

/*
 returns the k-th smallest value in the tree. The
 pre-condition for this function is: size() >= k.
 Returns zero if the pre-condition is not met.
 Function has a recursive solution.
*/
int BinSearchTree::kthSmallest( int k ){
    int target = 0;

    if (size() >= k) { // precondition: the size of the tree is larger or equal to the target value

        kthSmallest(root, k, target);
        return target;
    }
    else {
        return 0;
    }

}

void BinSearchTree::kthSmallest(TreeNode *root,int &k,int &target){ // done

    if(root!=nullptr) { // in order recursive traversal until value held at position k is reached

        kthSmallest(root->leftSubtree(),k,target);
        k -= 1; // decrement from k to find target value
        if (k == 0){
            target = root->value(); // when found attach value to address of target
            return; // end recursion
        }

        kthSmallest(root->rightSubtree(),k,target);
    }
}

/*
 prints a list of values at level k in the tree, in
 increasing order of values. The level of the root node
 is 1. That is, valuesAtLevel( 1 ) should print the value
 at the root-node of the tree. The children of the root,
 if any, are at level 2, and so on. Function has a recursive
 solution.
*/

void BinSearchTree::valuesAtLevel( int k ){
    valuesAtLevel(root,k);
}

void BinSearchTree::valuesAtLevel(TreeNode * root , int level){ // done
    // base case
    if(root == nullptr)
        return;

    // target level prints all values from the level
    if(level == 1)
        std::cout << root->value() << std::endl;

    // traverse level by level and decrement until level found
        valuesAtLevel(root->leftSubtree(), level - 1);
        valuesAtLevel(root->rightSubtree(), level - 1);
}

/*
 same as valuesAtLevel except this one
 is to be implemented iteratively.
*/

void BinSearchTree::iterValuesAtLevel( int k ){
    iterValuesAtLevel(root,k);
}

void BinSearchTree::iterValuesAtLevel(TreeNode * root, int level) { // done

    if (root == nullptr) // base case
        return;

    int newLevel = level;
    std::queue<TreeNode *> queue;
    TreeNode * curNode;

    queue.push(root);

    // FCFS queue that enqueues a level of values,
    // displays them and dequeues until queue is empty

    while(!queue.empty()){

        int queueSize = queue.size();

            while (queueSize != 0) {

                curNode = queue.front();

                if (newLevel == 1) { // target level to display
                    std::cout << curNode->value() << std::endl;
                }

                queue.pop();

                if (curNode->leftSubtree() != nullptr) {
                    queue.push(curNode->leftSubtree());
                }
                if (curNode->rightSubtree() != nullptr) {
                    queue.push(curNode->rightSubtree());
                }

                queueSize -= 1; // size of queue decreases
            }

        newLevel -= 1; // go further another level
    }
}

/*
 finds the depth of the tree using an iterative algorithm.
 The root of the tree is at depth 1, each of its children
 are at depth 2, etc. Your function should return the depth
 of the deepest node in the tree.
*/

int BinSearchTree::iterMaxDepth(){

    return iterMaxDepth(root);
}

int BinSearchTree::iterMaxDepth(TreeNode *root) { // done

    if(root==nullptr) // base case
        return 0;

    int maxDepth = 0;
    std::queue<TreeNode *> queue;
    TreeNode * curNode;

    queue.push(root);

    // level order traversal using fcfs queue
    // increments the amount of levels
    // returns when the height is reached

    while(!queue.empty()){

    size_t queueSize = queue.size(); // declared as size_t to prevent warning in blue server (size_type in container)

    for (size_t count = 0; count < queueSize; count++) {

        curNode = queue.front();
        queue.pop();

        if (curNode->leftSubtree() != nullptr)
        {
        queue.push(curNode->leftSubtree());
        }

        if(curNode->rightSubtree()!=nullptr)
        {
        queue.push(curNode->rightSubtree());
        }
    }

    maxDepth += 1;
    }

    return maxDepth;
}

/*
 returns true if there is a root-to-leaf path in the tree
 where the sum of the values on that path is equal to the
 input argument, sum. Otherwise, it returns false. Function
 has a recursive solution
*/

bool BinSearchTree::hasRootToLeafSum( int sum ){
    return hasRootToLeafSum(root,sum);
}

bool BinSearchTree::hasRootToLeafSum(TreeNode * root, int sum) { // done

    if (root == nullptr) { // base case
        return false;
    }

    int newSum = sum - root->value(); // subtract current node's value

    // reached the leaf and the nodes in the path subtract from the sum until you have zero so return true
    if (newSum == 0 && root->leftSubtree() == nullptr && root->rightSubtree() == nullptr) {
            return true;
    }

    // return to the left or right subtree depending on paths that exist (so it reaches every spot and doesn't get stuck)
    return hasRootToLeafSum(root->leftSubtree(), newSum) || hasRootToLeafSum(root->rightSubtree(), newSum);

    //return false; not sure if necessary

}

/*
 returns true if the tree in bst is structurally
 identical to that of the tree maintained by the
 callee. Otherwise, it returns false. Function has
 a recursive solution.
*/

bool BinSearchTree::areIdentical( BinSearchTree *bst ){
    return areIdentical(bst->root,root);
}

bool BinSearchTree::areIdentical(TreeNode * bst,TreeNode * root) { // done

    if(root==nullptr && bst==nullptr) { // base case
        return true;
    }

    if(root==nullptr || bst==nullptr){ // size difference will result in false
        return false;
    }

    if(root->value() == bst->value()){ // identical values, keep checking until false or null
        return areIdentical(bst->leftSubtree(),root->leftSubtree()) &&
                areIdentical(bst->rightSubtree(),root->rightSubtree());
    }

    return false; // if not equal return false
}

/*
 computes and returns the set intersection of the tree on which
 the function is called (the callee) and the tree passed to this
 function as bst. Write a recursive solution for this function,
 and feel free to write helper functions if necessary. These trees
 represent sets, so the input trees will not contain duplicate values.
*/

BinSearchTree* BinSearchTree::intersectWith( BinSearchTree *bst ){

    BinSearchTree * resultBst = new BinSearchTree();

    intersectWith(root,bst->root,resultBst);
    return resultBst;
}

void BinSearchTree::intersectWith(TreeNode *root1,TreeNode *root2, BinSearchTree *bst){

    if(root1==nullptr){ //base case
        return;
    }

        intersectWith(root1->leftSubtree(), root2, bst);

    if (find(root2, root1->value())) {

        bst->insert(root1->value());
    }

    // inorder traversal and push back into bst parameter when finding values that are shared between both trees
        intersectWith(root1->rightSubtree(), root2, bst);

}


/*
 computes and returns the set union of the tree on which the
 function is called (the callee) and the tree passed to this
 function as bst.
*/

BinSearchTree* BinSearchTree::unionWith( BinSearchTree *bst ){

    BinSearchTree * resultBst = new BinSearchTree();

    unionWith(bst->root, root, resultBst);
    unionWith(root,bst->root,resultBst);

    return resultBst;
}
void BinSearchTree::unionWith(TreeNode *root1,TreeNode *root2, BinSearchTree * bst){

        if(root1==nullptr) { // base case
            return;
        }
        //inorder traversal pushing back values from both trees but ignoring duplicates

        unionWith(root1->leftSubtree(), root2, bst);

            bst->insert(root1->value());

        unionWith(root1->rightSubtree(), root2, bst);

}

/*
 computes and returns the set difference of the tree passed to
 this function as bst and the tree on which the function is
 called (the callee). Function returns
 T(bst) - T(callee), where T(bst) and T(callee) refer to the
 trees of the bst and callee, respectively.
*/

BinSearchTree* BinSearchTree::differenceOf( BinSearchTree *bst ) {

    BinSearchTree * resultBst = new BinSearchTree();

    differenceOf(bst->root,root, resultBst);
    return resultBst;
}

void BinSearchTree::differenceOf(TreeNode *root1,TreeNode *root2, BinSearchTree *bst) {

    if (root1 == nullptr) {
        return;
    }

    // inorder traversal that pushes values that are found
    // only in the bst parameter of the original function
    // (don't intersect or include other tree)

        differenceOf(root1->leftSubtree(), root2, bst);

        if (!find(root2, root1->value())) {

            bst->insert(root1->value());
        }


        differenceOf(root1->rightSubtree(), root2, bst);

}
bool BinSearchTree::isBST() {
    return isBST(root);
}

bool BinSearchTree::isBST(TreeNode *root) {
    if(root == nullptr)
        return true;

        if(root->leftSubtree()!=nullptr && root->leftSubtree()->value() > root->value()){

                return false;
        }
        if(root->rightSubtree()!=nullptr && root->rightSubtree()->value() < root->value()){

                return false;
        }

        return isBST(root->leftSubtree()) && isBST(root->rightSubtree());
}
