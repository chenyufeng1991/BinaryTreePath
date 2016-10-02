//
//  main.cpp
//  BinaryTreePath
//
//  Created by chenyufeng on 10/2/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 *  求二叉树某条路径节点和为x的路径。
 */

typedef struct TreeNode{
    int data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
}Node;

void CreateBinaryTree(Node **node)
{
    int num;
    cin >> num;
    if (num == -1)
    {
        return;
    }

    *node = new Node;
    (*node)->data = num;
    (*node)->lChild = NULL;
    (*node)->rChild = NULL;

    cout << "请输入" << num << "的左孩子节点:";
    CreateBinaryTree(&((*node)->lChild));
    cout << "请输入" << num << "的右孩子节点:";
    CreateBinaryTree(&((*node)->rChild));
}

void PreOrder(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->data << " ";
    PreOrder(node->lChild);
    PreOrder(node->rChild);
}

void PathLength(Node *node, vector<int> &vec, int sum)
{
    if (node == NULL)
    {
        return;
    }

    if (node ->lChild != NULL)
    {
        vec.push_back(node->data);
        PathLength(node->lChild,vec,sum);
    }

    if (node ->rChild != NULL)
    {
        vec.push_back(node->data);
        PathLength(node->rChild,vec,sum);
    }

    if (node ->lChild == NULL || node ->rChild == NULL)
    {
        vec.push_back(node->data);
        int length = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            length += vec[i];
        }

        if (length == sum)
        {
            for (int i = 0; i < vec.size(); i++)
            {
                cout << vec[i] << " ";
            }
            cout << endl;
        }
        vec.clear();
    }
}

int main(int argc, const char * argv[])
{
    cout << "请输入数字创建二叉树，输入-1停止:" << endl;
    Node *node;
    CreateBinaryTree(&node);

    cout << "先序遍历二叉树:";
    PreOrder(node);
    cout << endl;


    cout << "符合长度的路径有：";
    vector<int> vec;
    PathLength(node, vec, 4);

    return 0;
}












