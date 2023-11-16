#include <iostream>

#include "BinSearchTree.hpp"

#include <fstream>

int main( int argc, char *argv[] ) {
    // create a tree and then print the values of its nodes
    // from the smallest to the largest.
    int target;

    if( argc != 2 ) {
        std::cout << "usage: executable name-of-input-file\n";
        exit(5);
    }
    std::fstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if(!inputStream.is_open()) {
        std::cout << "Unable to open the input file " <<
                  argv[1] << std::endl;
        std::cout << "Terminating...\n";
        exit(7);
    }


    BinSearchTree *tree = new BinSearchTree();
    //BinSearchTree *bin = new BinSearchTree();

    int aValue;
    while( inputStream >> aValue )
        tree->insert( aValue );

    std::cout << "Size: \n";
    std::cout << tree->size() << std::endl;

    /*std::cout << "Size: \n";
    std::cout << bin->size() << std::endl;

    std::cout << "Size: \n";
    std::cout << bin->size() << std::endl;

    std::cout << "Iterative Find: \n";
    std::cout << tree->iterFind(72) << std::endl;

    std::cout << "Max Depth: \n";
    std::cout << tree->maxDepth() << std::endl;

    std::cout << "Find: " << std::endl;
    std::cout << tree->find(72) << std::endl;

    std::cout << "Iterative Find: \n";
    std::cout << tree->iterFind(72) << std::endl;

    std::cout << "inorder traversal: \n";
    tree->inorderDump();

    std::cout << "level order traversal: \n";
    tree->levelOrderDump();
    std::cout << std::endl;

    std::cout << "values at level (k): \n";
    tree->valuesAtLevel(3);

    std::cout << "Iterate values at level: \n";
    tree->iterValuesAtLevel(2);

    std::cout << "kth smallest: \n";
    std::cout << tree->kthSmallest(1) << std::endl;

    std::cout << "max depth iterative: \n";
    std::cout << tree->iterMaxDepth();

    std::cout << "hasRootToLeaf\n";
    std::cout << tree->hasRootToLeafSum(137);

    std::cout << "Removes: \n";
    std::cout << tree->remove(56) << std::endl;

    std::cout << "Tree Size\n";
    std::cout << tree->size() << std::endl;

    std::cout << "inorder traversal: \n";
    tree->inorderDump();

    std::cout << "are identical: \n";
    std::cout << tree->areIdentical(bin);
    BinSearchTree* intersect = tree->unionWith(bin);
    intersect->levelOrderDump();*/

    std::cout << "Testing if BST: \n";
    std::cout << tree->isBST();
    return 0;
}
