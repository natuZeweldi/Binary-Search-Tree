//
// Created by Ali Kooshesh on 3/1/23.
// School Assignment Completed by: Natnael Zeweldi
//

#ifndef BINSEARCHTREE_TREENODE_HPP
#define BINSEARCHTREE_TREENODE_HPP


class TreeNode {
public:
    TreeNode( int n ): left(nullptr), right(nullptr), data(n) {}
    ~TreeNode() {
        leftSubtree(nullptr);
        rightSubtree(nullptr);
    }

    TreeNode *leftSubtree() { return left; }
    TreeNode *rightSubtree() { return right; }

    void leftSubtree( TreeNode *newLeft ) { left = newLeft; }
    void rightSubtree(TreeNode *newRight) { right = newRight; }

    int& value() { return data; }

private:
    TreeNode *left, *right;
    int data;
};

#endif //BINSEARCHTREE_TREENODE_HPP
