#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> verticalSum(Node* root) {
        map<int, int> mp;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            mp[hd] += curr->data;

            if (curr->left) {
                q.push({curr->left, hd - 1});
            }

            if (curr->right) {
                q.push({curr->right, hd + 1});
            }
        }

        vector<int> ans;

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7

    Vertical Sum Output:
    4 2 12 3 7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<int> result = obj.verticalSum(root);

    cout << "Vertical Sum: ";

    for (int val : result) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}



