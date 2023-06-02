#ifndef UDT_TREE_H
#define UDT_TREE_H

typedef struct TreeNode TreeNode;
typedef unsigned int uint;

TreeNode *CreateNode(TreeNode * parent, float data);
void AddNode(TreeNode *node, float data);
void PrintTree(TreeNode *node, uint level);
void PreorderTraversal(TreeNode *node);
void InorderTraversal(TreeNode *node);
void PostorderTraversal(TreeNode *node);
void PrintAllTraversal(TreeNode *tree);
TreeNode *SearchNode(TreeNode *root, float data);
TreeNode *SearchMinNode(TreeNode *root);
void DeleteNode(TreeNode *root, float data);
uint MinDepth(TreeNode *root);
uint IsLeafonLevel(TreeNode *node, uint current_level, uint finish_level);
uint getmin(TreeNode *node);

struct TreeNode{
    float data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};
#endif 
