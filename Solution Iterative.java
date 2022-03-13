
import java.util.Map;
import java.util.HashMap;

public class Solution {

    public Node copyRandomList(Node head) {        
        if (head == null) {
            return null;
        }
        
        Map<Node, Node> originalToCloned = new HashMap<>();
        Node cloned = new Node(head.val);
        originalToCloned.put(head, cloned);
        Node original = head;

        while (original != null) {
            cloned.random = getClonedNode(originalToCloned, original.random);
            cloned.next = getClonedNode(originalToCloned, original.next);
            cloned = cloned.next;
            original = original.next;
        }

        return originalToCloned.get(head);
    }

    private Node getClonedNode(Map<Node, Node> originalToCloned, Node original) {
        if (original == null) {
            return null;
        }
        originalToCloned.putIfAbsent(original, new Node(original.val));
        return originalToCloned.get(original);
    }
}

// Class Node is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this class.
class Node {

    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
