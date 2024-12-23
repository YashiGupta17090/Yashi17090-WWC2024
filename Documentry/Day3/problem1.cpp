//Add Two Numbers
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
//and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.You may assume 
//the two numbers do not contain any leading zero, except the number 0 itself.
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);  // Dummy node to simplify the logic.
    ListNode* p = l1, *q = l2, *current = dummyHead;
    int carry = 0;

    while (p != nullptr || q != nullptr || carry != 0) {
        int sum = carry;  // Start with carry from the previous iteration.
        
        // Add the value from l1 if available.
        if (p != nullptr) {
            sum += p->val;
            p = p->next;
        }
        
        // Add the value from l2 if available.
        if (q != nullptr) {
            sum += q->val;
            q = q->next;
        }
        
        // Calculate the new carry and the current digit.
        carry = sum / 10;  // Carry for the next iteration.
        current->next = new ListNode(sum % 10);  // Create a new node with the current digit.
        current = current->next;  // Move the current pointer.
    }

    return dummyHead->next;  // The actual result starts from the next node of dummyHead.
}

// Helper function to create a linked list from a vector of integers.
ListNode* createList(const vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    for (int num : nums) {
        ListNode* newNode = new ListNode(num);
        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    return head;
}

// Helper function to print a linked list.
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Example: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    ListNode* l1 = createList({2, 4, 3});  // 342
    ListNode* l2 = createList({5, 6, 4});  // 465
    
    ListNode* result = addTwoNumbers(l1, l2);
    
    // Print the result (7 -> 0 -> 8)
    printList(result);  // Output: 7 -> 0 -> 8
    return 0;
}
