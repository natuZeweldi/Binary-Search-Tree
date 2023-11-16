//
// Created by Ali Kooshesh on 3/1/23.
// School Assignment Completed by: Natnael Zeweldi
//

#ifndef BINSEARCHTREE_BINSEARCHTREE_HPP
#define BINSEARCHTREE_BINSEARCHTREE_HPP


#include "TreeNode.hpp"
#include <vector>

class BinSearchTree {
public:
    BinSearchTree();
    ~BinSearchTree();

    void insert( int v );
    bool find( int v );
    bool iterFind( int v );
    int size();

    void inorderDump();
    void levelOrderDump();
    bool remove(int v);
    int kthSmallest(int k);

    void valuesAtLevel(int k);
    void iterValuesAtLevel(int k);
    int maxDepth();
    int iterMaxDepth();
    bool hasRootToLeafSum(int sum);

    bool areIdentical(BinSearchTree *bst);
    BinSearchTree *intersectWith(BinSearchTree *bst);
    BinSearchTree *unionWith(BinSearchTree *bst);
    BinSearchTree *differenceOf(BinSearchTree *bst);
    bool isBST ();


private:
    TreeNode *insert( TreeNode *, int );
    TreeNode *root;
    TreeNode* deletes(TreeNode * root,int target);


    int size(TreeNode*);
    bool find(TreeNode*,int);
    void deleteNodes(TreeNode *);
    bool iterFind(TreeNode *, int);

    void inorderDump(TreeNode*);
    int maxDepth(TreeNode*);
    int iterMaxDepth(TreeNode *root);
    void levelOrderDump(TreeNode *root);

    void valuesAtLevel(TreeNode *root, int level);
    void iterValuesAtLevel(TreeNode *root, int k);
    bool hasRootToLeafSum(TreeNode *root, int sum);
    void kthSmallest(TreeNode *root, int &k, int &target);

    bool areIdentical(TreeNode *bst, TreeNode *root);
    void unionWith(TreeNode *root1,TreeNode *root2, BinSearchTree *bst);
    void intersectWith(TreeNode *root1,TreeNode *root2,  BinSearchTree *bst);
    void differenceOf(TreeNode *root1,TreeNode *root2, BinSearchTree *bst);
    bool isBST (TreeNode * root);

};

#endif //BINSEARCHTREE_BINSEARCHTREE_HPP
