#include<iostream>
#include<windows.h>

using namespace std;

// BST NODE
template <typename T>
struct BstNode {
    T data;
    BstNode<T>* BstLeft;
    BstNode<T>* BstRight;
    // Constructor in Structure
    BstNode(T val) : data(val), BstLeft(nullptr), BstRight(nullptr) {}
};

// Binary Tree
template <typename T>
class BinaryTree {
public:
    BstNode<T>* root;
    BinaryTree() {
        root = nullptr;
    }
    BstNode<T>* GetNewNode(T data)
    {
        BstNode<T>* next = new BstNode<T>(data);
        return next;
    }
    void insert(T data)
    {
        int x = 0;
        BstNode<T>* Ptr = root;
        if (root == nullptr)  root = GetNewNode(data);
        else
        {
            BstNode<T>* temp = root;
            while (temp != nullptr)
            {
                Ptr = temp;
                if (temp->data < data)
                {
                    temp = temp->BstRight;
                }
                else
                {
                    temp = temp->BstLeft;
                }
            }
            if (Ptr->data < data)
            {
                Ptr->BstRight = GetNewNode(data);
            }
            else
            {
                Ptr->BstLeft = GetNewNode(data);
            }
        }
    }
    bool Search(BstNode<T>* root, T data)
    {
        if (root == nullptr) return false;
        else if (root->data == data) return true;
        else if (root->data >= data) return Search(root->BstLeft, data);
        else return Search(root->BstRight, data);
    }
    bool Search(T data)
    {
        return Search(this->root, data);
    }
    
};

int main()
{
    BinaryTree<int>* rt = new BinaryTree<int>();
    rt->insert(20);
    rt->insert(15);
    rt->insert(30);
    rt->insert(8);
    rt->insert(16);
    rt->insert(40);
    rt->insert(18);
   
    cout << rt->Search(19);
    cout << rt->Search(20) << rt->Search(8) <<rt->Search(15);
}
