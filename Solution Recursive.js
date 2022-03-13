
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
    let originalToCloned = new Map();
    return cloneList(originalToCloned, head);
};

/**
 * @param {Map (Node,Node)} originalToCloned
 * @param {Node} original
 * @return {Node|null}
 */
function cloneList(originalToCloned, original) {
    if (original === null) {
        return null;
    }
    if (originalToCloned.has(original)) {
        return  originalToCloned.get(original);
    }

    let cloned = new Node(original.val);
    originalToCloned.set(original, cloned);
    cloned.next = cloneList(originalToCloned, original.next);
    cloned.random = cloneList(originalToCloned, original.random);

    return cloned;
}
