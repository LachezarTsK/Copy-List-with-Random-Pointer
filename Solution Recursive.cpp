
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
    
    unordered_map<Node*, Node*> originalToCloned;

public:
    Node* copyRandomList(Node* original) {
        if (original == nullptr) {
            return nullptr;
        }
        if (originalToCloned.find(original) != originalToCloned.end()) {
            return originalToCloned[original];
        }

        Node* cloned = new Node(original->val);
        originalToCloned[original] = cloned;
        cloned->next = copyRandomList(original->next);
        cloned->random = copyRandomList(original->random);

        return cloned;
    }
};
