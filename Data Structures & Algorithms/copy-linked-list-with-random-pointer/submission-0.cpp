class Solution {
private:
    void insertAtTail(Node*& head, Node*& tail, int d) {
        Node* newNode = new Node(d);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr){
            return nullptr;
        }

        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;
        Node* temp = head;

        while (temp != nullptr) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        unordered_map<Node*, Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode != nullptr) {
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != nullptr) {

            if (originalNode->random != nullptr) {
                cloneNode->random = oldToNew[originalNode->random];
            }
            else {
                cloneNode->random = nullptr;
            }
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;

        }
        return cloneHead;
    }
};
