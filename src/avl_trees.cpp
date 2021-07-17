
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    int height;
};

Node* Create(int value)
{
    Node* n = new Node();
    n->value = value;
    return n;
}

Node* Create(int value, int height)
{
    Node* n = new Node();
    n->value = value;
    n->height = height;
    return n;
}

void Delete(Node* root)
{
    if (root->left)  { Delete(root->left);  }
    if (root->right) { Delete(root->right); }
    delete root;
}

void Print(Node* n0, unsigned int indent = 0)
{
    if (n0 != nullptr)
    {
        if (indent > 0) { printf("|---"); }
        for (unsigned int i = 1; i < indent; i++) { printf("----"); }
        printf("(%u, %u)\n", n0->value, n0->height);
        Print(n0->left, indent + 1);
        Print(n0->right, indent + 1);
    }
}

int CalculateHeight(Node* node)
{
    int l_height = node->left == nullptr ? 0 : node->left->height;
    int r_height = node->right == nullptr ? 0 : node->right->height;
    return max(l_height, r_height) + 1;
}

Node* Insert(Node* root, Node* node)
{
    if (root == nullptr)
    {
        cout << "error: null root" << endl;
        return nullptr;
    }

    if (node->value < root->value)
    {
        if (root->left == nullptr)
        {
            node->height = 1;
            root->left = node;
        }
        else
        {
            root->left = Insert(root->left, node);
        }
    }
    else
    {
        if (root->right == nullptr)
        {
            node->height = 1;
            root->right = node;
        }
        else
        {
            root->right = Insert(root->right, node);
        }
    }

    root->height = CalculateHeight(root);

    int l_height = root->left  == nullptr ? 0 : root->left->height;
    int r_height = root->right == nullptr ? 0 : root->right->height;
    int b_factor = l_height - r_height;

    Node* new_root = root;

    //printf("\nb factor: %i\n", b_factor);
    //Print(root);
    if (b_factor > 1)
    {
        if (root->left != nullptr)
        {
            if (root->right == nullptr) // right rotation
            {
                new_root = root->left;
                new_root->right = root;
                root->left = nullptr;
                root->height = CalculateHeight(root);
            }
            else // double rotation right
            {
                new_root = root->left;
                root->left = root->left->right;
                new_root->right = root;
                root->height = CalculateHeight(root);
            }
        }
    }
    else if (b_factor < -1)
    {
        if (root->right != nullptr)
        {
            if (root->left == nullptr) // left rotation
            {
                new_root = root->right;
                new_root->left = root;
                root->right = nullptr;
                root->height = CalculateHeight(root);
            }
            else // double rotation left
            {
                new_root = root->right;
                root->right = root->right->left;
                new_root->left = root;
                root->height = CalculateHeight(root);
            }
        }
    }

    //Print(new_root);

    return new_root;
}

bool Compare(Node* n0, Node* n1)
{
    bool ret = false;

    if ((n0 == nullptr) && (n1 == nullptr))
    {
        ret = true;
    }
    else if ((n0 == nullptr) || (n1 == nullptr))
    {
        ret = false;
    }
    else
    {
        ret = n0->value == n1->value;
        if (!ret) { printf("value mismatch: %u vs %u\n", n0->value, n1->value); }
        
        if (ret)
        {
            ret = n0->height == n1->height;
            if (!ret) { printf("height mismatch: %u vs %u\n", n0->height, n1->height); }
        }

        if (ret) { ret = Compare(n0->left,  n1->left);  }
        if (ret) { ret = Compare(n0->right, n1->right); }
    }

    return ret;
}

bool Test1()
{
    Node* root1 = Create(4);
    root1 = Insert(root1, Create(5));
    root1 = Insert(root1, Create(3));
    root1 = Insert(root1, Create(2));
    root1 = Insert(root1, Create(1));

    Node* root2 = Create(4, 3);
    root2->left = Create(2, 2);
    root2->right = Create(5, 1);
    root2->left->left = Create(1, 1);
    root2->left->right = Create(3, 1);

    bool ret = Compare(root1, root2);
    Delete(root1);
    Delete(root2);

    return ret;
}

bool Test2()
{
    Node* root1 = Create(5);
    root1 = Insert(root1, Create(6));
    root1 = Insert(root1, Create(3));
    root1 = Insert(root1, Create(4));
    root1 = Insert(root1, Create(2));
    root1 = Insert(root1, Create(1));

    Node* root2 = Create(3, 3);
    root2->left = Create(2, 2);
    root2->right = Create(5, 2);
    root2->left->left = Create(1, 1);
    root2->right->left = Create(4, 1);
    root2->right->right = Create(6, 1);

    bool ret = Compare(root1, root2);
    Delete(root1);
    Delete(root2);

    return ret;
}

void PrintResult(const char* message, bool result)
{
    printf("%s: %s\n", message, result ? "pass" : "fail");
}

bool AVL_Trees()
{
    PrintResult("Test 1", Test1());
    PrintResult("Test 2", Test2());

    return true;
}
