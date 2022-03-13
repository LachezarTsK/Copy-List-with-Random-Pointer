
// Function Node is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this function.
function Node(val, next, random) {
    this.val = val;
    this.next = next;
    this.random = random;
}

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function (head) {
    if (head === null) {
        return null;
    }

    let originalToCloned = new Map();
    let cloned = new Node(head.val);
    originalToCloned.set(head, cloned);
    let original = head;

    while (original !== null) {
        cloned.random = getClonedNode(originalToCloned, original.random);
        cloned.next = getClonedNode(originalToCloned, original.next);
        cloned = cloned.next;
        original = original.next;
    }

    return originalToCloned.get(head);
};

/**
 * @param {Map (Node,Node)} originalToCloned
 * @param {Node} original
 * @return {Node|null}
 */
function getClonedNode(originalToCloned, original) {
    if (original === null) {
        return null;
    }
    if (!originalToCloned.has(original)) {
        originalToCloned.set(original, new Node(original.val));
    }
    return originalToCloned.get(original);
}
