#include <iostream>
#include <map>
#include <list>
#include <stack>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int data;
    int hr;
    int dist;
};

struct node2
{
    int data;
    int hd;
    int distance = 0;
    string str = "";
};

bool comp(node2 *p1, node2 *p2)
{
    if (p1->hd < p2->hd)
    {
        return true;
    }
    return false;
}

void A_str(int node1, map<int, list<node *>> adj, map<int, bool> &visited, stack<int> &s, vector<node2 *> &open_list, vector<int> &close_list, int goal)
{
    int set = 0;
    close_list.push_back(node1);

    cout << "\n\nOpenlist !!!!!\n";
    for (int i = 0; i < open_list.size(); i++)
    {
        cout << open_list[i]->data << " ";
    }
    
    cout << "\n\nCloselist !!!!!\n";
    for (int i = 0; i < close_list.size(); i++)
    {
        cout << close_list[i] << " ";
    }

    if (node1 == goal)
    {
        cout << "\n\nOptimal path to reach Source to destination is : \n"+open_list.front()->str;
        exit(0);
    }

    for (auto neigb : adj[node1])
    {
        node2 *newnode = new node2();
        newnode->data = neigb->data;
        newnode->hd = open_list.front()->distance + neigb->dist + neigb->hr;
        newnode->distance = open_list.front()->distance + neigb->dist;
        newnode->str = open_list.front()->str + " " + to_string(newnode->data);
        open_list.push_back(newnode);
        set = 1;
    }

    open_list.erase(open_list.begin());

    while (!open_list.empty())
    {
        sort(open_list.begin(), open_list.end(), comp);
        A_str(open_list.front()->data, adj, visited, s, open_list, close_list, goal);
    }
}
int main()
{
    map<int, list<node *>> adj;
    map<int, list<node *>>::iterator it;
    int n, src = 0, goal = 5;
    int a, b, c, d;

    cout << "enter no of edges" << endl;
    cin >> n;

    cout << "enter edges between a to b with distance eg. 0 1 5 3(edge between 0 to 1 with distance 5 and hr 3)" << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> a >> b >> c >> d;
        node *newnode = new node();
        newnode->data = b;
        newnode->dist = c;
        newnode->hr = d;
        adj[a].push_back(newnode);
    }

    for (it = adj.begin(); it != adj.end(); it++)
    {
        cout << it->first << " | ";
        for (auto e : it->second)
        {
            cout << "(" << e->data << " " << e->dist << " " << e->hr << ") ";
        }
        cout << "\n";
    }

    map<int, bool> visited;
    stack<int> s1;

    /*while (!s1.empty())
    {
    cout << s1.top();
    s1.pop();
    }*/

    cout << "\n";

    map<int, bool> visited1;
    stack<int> s;
    vector<int> close_list;
    vector<node2 *> open_list;

    node2 *newnode2 = new node2();
    newnode2->data = src;
    newnode2->hd = 12;
    newnode2->str = "0";
    open_list.push_back(newnode2); // initially head is in open list hence we are pushing head (newnode2)

    A_str(0, adj, visited1, s, open_list, close_list, goal);

    return 0;
}