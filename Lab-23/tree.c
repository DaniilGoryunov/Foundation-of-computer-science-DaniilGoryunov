#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

TreeNode *CreateNode(TreeNode * parent, float data){
    TreeNode *new_node = malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = parent;
    return new_node;
}

void AddNode(TreeNode *root, float data){
    TreeNode **added_node = &root, *parent_node;
    while(*added_node != NULL){
        parent_node = *added_node;
        if (parent_node->data > data){
            added_node = &parent_node->left;
        }
        else{
            added_node = &parent_node->right;
        }
    }
    *added_node = CreateNode(parent_node, data);
}

void PrintTree(TreeNode *node, uint level){
    if (node != NULL){
        for (uint i = 0; i < level; i++){
            printf("\t");
        }
        printf("%.2f\n", node->data);
        PrintTree(node->right, level + 1);
        PrintTree(node->left, level + 1);
    }
}

void PreorderTraversal(TreeNode *node){
    if (node != NULL){
        printf("%.2f ", node->data);
        PreorderTraversal(node->left);
        PreorderTraversal(node->right);
    }
}

void InorderTraversal(TreeNode *node){
    if (node != NULL){
        InorderTraversal(node->left);
        printf("%.2f ", node->data);
        InorderTraversal(node->right);
    }
}

void PostorderTraversal(TreeNode *node){
    if (node != NULL){
        InorderTraversal(node->left);
        InorderTraversal(node->right);
        printf("%.2f ", node->data);
    }
}

void PrintAllTraversal(TreeNode *tree){
    printf("It's Preorder tree traversal:\n");
    PreorderTraversal(tree);
    printf("\n");
    printf("It's Inorder tree traversal:\n");
    InorderTraversal(tree);
    printf("\n");
    printf("It's Postorder tree traversal:\n");
    PostorderTraversal(tree);
    printf("\n");
}

TreeNode *SearchNode(TreeNode *root, float data){
    TreeNode **desired_node = &root;
    while ((*desired_node)->data != data){
        if ((*desired_node)->data > data){
            desired_node = &(*desired_node)->left;
        }
        else{
            desired_node = &(*desired_node)->right;
        }
    }
    return *desired_node;
}

TreeNode *SearchMinNode(TreeNode *root){
    TreeNode **desired_node = &root;
    while ((*desired_node)->left != NULL){
        desired_node = &(*desired_node)->left;
    }
    return *desired_node;
}

void DeleteNode(TreeNode *root, float data){
    TreeNode *deleted_node = SearchNode(root, data);
    if (((deleted_node)->left == NULL) && ((deleted_node)->right == NULL)){
        if (((deleted_node)->data) < (((deleted_node)->parent)->data)){
            ((deleted_node)->parent)->left = NULL;
        } 
        else{
            ((deleted_node)->parent)->right = NULL;
        }
        free(deleted_node);
    } 
    else if (((deleted_node)->left != NULL) && ((deleted_node)->right == NULL)){
        ((deleted_node)->left)->parent = ((deleted_node)->parent);
        if (((deleted_node)->data) < (((deleted_node)->parent)->data)){
            ((deleted_node)->parent)->left = ((deleted_node)->left);
        } 
        else{
            ((deleted_node)->parent)->right = ((deleted_node)->left);
        }
        free(deleted_node);
    } 
    else if (((deleted_node)->left == NULL) && ((deleted_node)->right != NULL)){
        ((deleted_node)->right)->parent = ((deleted_node)->parent);
        if (((deleted_node)->data) < (((deleted_node)->parent)->data)){
            ((deleted_node)->parent)->left = ((deleted_node)->right);
        } 
        else{
            ((deleted_node)->parent)->right = ((deleted_node)->right);
        }
        free(deleted_node);
    } 
    else if (((deleted_node)->left != NULL) && ((deleted_node)->right != NULL)){
        TreeNode *min_in_right_tree = SearchMinNode((deleted_node)->right);
        (deleted_node)->data = min_in_right_tree->data;
        DeleteNode(min_in_right_tree, min_in_right_tree->data);
    } 
}

bool IsLeaf(TreeNode *leaf){
    if ((leaf->left == NULL) && (leaf->right == NULL)){
        return true;
    }
    else return false;
}

uint MinDepth(TreeNode *root){
    if (root == NULL)
        return 0;
    int l = MinDepth(root->left);
    int r = MinDepth(root->right);
    if (root->left == NULL)
        return 1+r;
    if (root->right == NULL)
        return 1+l;
    return fmin(l,r) + 1;
}

uint getmin(TreeNode *node){
    uint current_level = 1, finish_level = MinDepth(node);
    return IsLeafonLevel(node, current_level, finish_level);
}

uint IsLeafonLevel(TreeNode *node, uint current_level, uint finish_level){
    if (current_level == finish_level){
        if (IsLeaf(node))
            return node->data;
    }
    else{
        if (node->left != NULL && ((!IsLeaf(node->left) && current_level != finish_level) || (IsLeaf(node->left))))
            return IsLeafonLevel(node->left, ++current_level, finish_level);
        if (node->right != NULL && ((!IsLeaf(node->right) && current_level != finish_level) || (IsLeaf(node->right))))
            return IsLeafonLevel(node->right, ++current_level, finish_level);
    }
    return 0;
}
