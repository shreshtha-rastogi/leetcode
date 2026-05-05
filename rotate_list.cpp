#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to rotate the list
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        int n = 1;
        ListNode* tail = head;
        
        // Find length and last node
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        
        // Reduce k
        k = k % n;
        if (k == 0) return head;
        
        // Make circular
        tail->next = head;
        
        int steps = n - k;
        ListNode* newTail = head;
        
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        
        return newHead;
    }
};

// Helper function to insert node at end
ListNode* insert(ListNode* head, int val) {
    if (!head) return new ListNode(val);
    
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
    
    return head;
}

// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    ListNode* head = NULL;
    
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    
    int k = 2;
    
    Solution obj;
    head = obj.rotateRight(head, k);
    
    printList(head);  // Output: 4 5 1 2 3
    
    return 0;
}






