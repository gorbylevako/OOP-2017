// lab_2.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class Tree
{
    class Node
    {
        public:
            int key;
            Node *Left;
            Node *Right;

            Node(int k, Node *l = NULL, Node *r = NULL)
            {
                key = k;
                Left = l;
                Right = r;
            }
    };

    Node *root;

    public:
        Tree()
        {
            root = NULL;
        }
        ~Tree()
        {
            DeleteTree(root);
        }

        void Add(const int &item)
        {
            Add(root, item);
        }

        void SearchItem(const int &item)
        {
            SearchItem(root, item);
        }

        void Print()
        {
            Print(root, 0);
        }

    private:
        void Add(Node *&node, const int &item);
        void SearchItem(Node *&node, const int &item);
        void DeleteTree(Node *node);
        void Print(Node *&node, const int &cur);
};

void Tree::DeleteTree(Node *node)
{
    if (node)
    {
        DeleteTree(node->Left);
        DeleteTree(node->Right);
        delete node;
    }
}

void Tree::Add(Node *&node, const int &item)
{
    if (node == NULL)
        node = new Node(item);
    else if (item < node->key)
        Add(node->Left, item);
    else
        Add(node->Right, item);

}

void Tree::SearchItem(Node *&node, const int &item)
{
    bool found = false;
    if (node == NULL)
    {
        cout << "ƒерево пусто!" << endl;
    }
    else
    {
        Node *cur = node;
        while (cur != NULL)
        {
            if (item == cur->key)
            {
                found = true;
                break;
            }
            else
            {
                if (item < cur->key)
                    cur = cur->Left;
                else
                    cur = cur->Right;
            }
        }
    }
    if (!found) cout << "\n\nЁлемент не найден." << endl;
    else cout << "\n\nЁлемент найден." << endl;
}

void Tree::Print(Node *&node, const int &cur)
{
    if (node)
    {
        Print(node->Left, cur+1);
        for(int i=0; i<cur; i++) cout << "   ";
        cout << node->key << endl;
        Print(node->Right, cur+1);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
    Tree lab;

    //lab.Add(5);
    //lab.Add(2);
    //lab.Add(8);
    //lab.Add(1);
    //lab.Add(4);
    //lab.Add(9);
    //lab.Add(7);

    int n, m, p;
    cout << "—колько элементов вы хотите добавить в дерево?\n\nN = ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> m;
        lab.Add(m);
    }

    system("cls");

    lab.Print();

    cout << "\n\n¬ведите элемент, который необходимо найти.\n";
    cin >> p;

    lab.SearchItem(p);

	system("pause");
    //lab.~Tree();

	return 0;
}

