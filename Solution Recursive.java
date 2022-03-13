
import java.util.Map;
import java.util.HashMap;

public class Solution {

    Map<Node, Node> originalToCloned = new HashMap<>();

    public Node copyRandomList(Node original) {
        if (original == null) {
            return null;
        }
        if (originalToCloned.containsKey(original)) {
            return originalToCloned.get(original);
        }
        
        Node cloned = new Node(original.val);
        originalToCloned.put(original, cloned);
        cloned.next = copyRandomList(original.next);
        cloned.random = copyRandomList(original.random);
        
        return cloned;
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
