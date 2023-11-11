#include<iostream>
#include<windows.h>
#include<queue>
using namespace std;

// BST NODE
template <typename T = int>
struct BstNode {
    T data;
    BstNode<T>* BstLeft;
    BstNode<T>* BstRight;
    // Constructor in Structure
    BstNode(T val) : data(val), BstLeft(nullptr), BstRight(nullptr) {}
};

// Binary Tree
template <typename T = int>
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
    T FindMin() 
    {
        BstNode<T>* current = root;
        while (current->BstLeft != nullptr)
        {
            current = current->BstLeft;
        }
        return current->data;   
    }
    T FindMax() {
        BstNode<T>* current = root;
        while (current->BstRight != nullptr)
        {
            current = current->BstRight;
            cout << "s";
        }
        return current->data;
    }
    int FindHeight(BstNode<T>* root)
    {
        if (root == nullptr) return -1;
        int leftHeight = FindHeight(root->BstLeft);
        int rightHeight = FindHeight(root->BstRight);
        return 1 + max(leftHeight, rightHeight);
    }
    int FindHeight()
    {
        return FindHeight(root);
    }
    void levelOrderTraversel()
    {
        if (root == nullptr)
            return;
        queue<BstNode<T>*> tempQue;
        tempQue.push(root);
        while (!tempQue.empty())
        {
            BstNode<T>* current = tempQue.front();
            cout << current->data << " ,";

            if (current->BstLeft != nullptr)
                tempQue.push(current->BstLeft);
            if (current->BstRight != nullptr)
                tempQue.push(current->BstRight);

            tempQue.pop();
        }
    }
    void Preorder(BstNode<T>* root)
    {
        if (root == nullptr)
            return;
        cout << root->data <<", ";
        Preorder(root->BstLeft);
        Preorder(root->BstRight);
    }
    void Preorder()
    {
        Preorder(root);
    }
    void Inorder(BstNode<T>* root)
    {
        if (root == nullptr)
            return;
        Inorder(root->BstLeft);
        cout << root->data << ", ";
        Inorder(root->BstRight);
    }
    void Inorder()
    {
        Inorder(root);
    }
//idk 
    BstNode<T>* Delete(BstNode<T>* root, T data) 
    {
        if (root == nullptr)
            return root;

        if (data < root->data) {
            root->BstLeft = Delete(root->BstLeft, data);
        }
        else if (data > root->data) {
            root->BstRight = Delete(root->BstRight, data);
        }
        else {
            if (root->BstLeft == nullptr) {
                BstNode<T>* temp = root->BstRight;
                delete root;
                return temp;
            }
            else if (root->BstRight == nullptr) {
                BstNode<T>* temp = root->BstLeft;
                delete root;
                return temp;
            }

            BstNode<T>* temp = FindMin(root->BstRight);
            root->data = temp->data;
            root->BstRight = Delete(root->BstRight, temp->data);
        }
        return root;
    }

    void Delete(T data) {
        root = Delete(root, data);
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
    cout << "LEVEL ORDER TRAVERSEL";
    rt->levelOrderTraversel();
    cout << endl;
    rt->Preorder();
}
