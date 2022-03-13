
#include <unordered_map>
using namespace std;

// Class Node is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this class.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> originalToCloned;
        Node* cloned = new Node(head->val);
        originalToCloned[head] = cloned;
        Node* original = head;

        while (original != nullptr) {
            cloned->random = getClonedNode(originalToCloned, original->random);
            cloned->next = getClonedNode(originalToCloned, original->next);
            cloned = cloned->next;
            original = original->next;
        }

        return originalToCloned[head];
    }

private:
    Node* getClonedNode(unordered_map<Node*, Node*>& originalToCloned, Node* original) {
        if (original == nullptr) {
            return nullptr;
        }
        if (originalToCloned.find(original) == originalToCloned.end()) {
            originalToCloned[original] = new Node(original->val);
        }
        return originalToCloned[original];
    }
};
