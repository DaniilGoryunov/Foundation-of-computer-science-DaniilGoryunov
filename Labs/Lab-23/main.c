#include <stdio.h>
#include "tree.h"

int main(void){
    TreeNode *tree = CreateNode(NULL, 50);
    AddNode(tree, 6);
    AddNode(tree, 57);
    AddNode(tree, 84);
    AddNode(tree, 16);
    AddNode(tree, 15);
    AddNode(tree, 52);
    AddNode(tree, 17);
    AddNode(tree, 163);
    AddNode(tree, 77);
    AddNode(tree, 3);
    AddNode(tree, 53);
    PrintTree(tree, 0);
    PrintAllTraversal(tree);
    printf("%d",GetMin(tree));
    return 0;
}
