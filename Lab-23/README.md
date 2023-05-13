# Отчёт по лабораторной работе №23 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М80-108Б-22 Горюнов Даниил Владимирович, № по списку: 4</ins>

<b>Контакты e-mail:</b> <ins>dania.goryunow2013@yandex.ru/ins>

<b>Работа выполнена:</b> «10» <ins>мая</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «13» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Динамические структуры данных. Обработка деревьев
## 2. Цель работы
Составить программу на языке Си для построения и обработки дерева общего вида или упорядоченного двоичного дерева, содержащего узлы типа float.
## 3. Задание (вариант № 2)
Найти значения листа двоичного дерева с минимальной глубиной

## 4. Оборудование

Процессор: AMD RYZEN 7 5800H 3.20GHz ОП 16 ГБ

HDD: 952 ГБ

Монитор: 3840x2400

## 5. Программное обеспечение

Операционная система семейства: Linux Ubuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: -

Редактор текстов: 

Местонахождение и имена файлов программ и данных на домашнем компьютере: -

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

- CreateNode - создание вершины дерева (корня дерева в т.ч.)
- AddNode - добавление узла в дерево
- SearchNode - поиск элемента в дереве
- SearchMinNode - поиск в дереве элемента с наименьшим значением
- DeleteNode - удаление элемента из дерева
- PrintTree - печать дерева
- PreorderTraversal - прямой обход дерева
- InorderTraversal - центрированный обход дерева
- PostorderTraversal - обратный обход дерева
- PrintAllTraversal - печать всех обходов дерева
- MinDepth - Минмальная глубина листа всего дерева
- IsLeaf - проверка на листовость
- IsLeafonLevel - поиск значения листа минимальной глубины

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

```c:/Lab-23/main.c
#include <stdio.h>
#include "tree.h"

int main(){
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
    IsLeafonLevel(tree, 1,MinDepth(tree));
    return 0;
}
```
```c:/Lab-23/tree.h
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
void IsLeafonLevel(TreeNode *node, uint current_level, uint finish_level);

struct TreeNode{
    float data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};
#endif
```c:/Lab-23/tree.c
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

void IsLeafonLevel(TreeNode *node, uint current_level, uint finish_level){
    if (current_level == finish_level){
        if (IsLeaf(node))
            printf("The value of node with min depth: %f\n", node->data);
    }
    else{
        if (node->left != NULL)
            IsLeafonLevel(node->left, ++current_level, finish_level);
        if (node->right !=NULL)
            IsLeafonLevel(node->right, ++current_level, finish_level);
    }
}
```
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
-----------------------------------------------------------------------------
10.00
        15.00
                17.00
                        16.00
                11.00
                        13.00
                                14.00
                                12.00
        7.00
                8.00
                5.00
                        6.00
-----------------------------------------------------------------------------
It's Preorder tree traversal:
10.00 7.00 5.00 6.00 8.00 15.00 11.00 13.00 12.00 14.00 17.00 16.00 
It's Inorder tree traversal:
5.00 6.00 7.00 8.00 10.00 11.00 12.00 13.00 14.00 15.00 16.00 17.00 
It's Postorder tree traversal:
5.00 6.00 7.00 8.00 11.00 12.00 13.00 14.00 15.00 16.00 17.00 10.00 
Tree width: 4
-----------------------------------------------------------------------------
10.00
        15.00
                17.00
                        16.00
                11.00
                        13.00
                                14.00
                                12.00
        7.00
                8.00
                6.00
-----------------------------------------------------------------------------
10.00
        15.00
                17.00
                        16.00
                11.00
                        13.00
                                14.00
                                12.00
        8.00
                6.00
-----------------------------------------------------------------------------
10.00
        15.00
                16.00
                11.00
                        13.00
                                14.00
                                12.00
        8.00
                6.00
-----------------------------------------------------------------------------
10.00
        15.00
                16.00
                13.00
                        14.00
                        12.00
        8.00
                6.00
-----------------------------------------------------------------------------
12.00
        15.00
                16.00
                13.00
                        14.00
        8.00
                6.00
-----------------------------------------------------------------------------
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.05.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________

