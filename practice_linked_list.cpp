#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
    Node(int val, Node* nxt) {
        data = val;
        next = nxt;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* y = Node(arr[0], nullptr);
    cout<<y->data<<endl;
}












