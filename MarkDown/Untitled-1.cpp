class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        LinkedList = 0;
    }
    ListNode* LinkedList;
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
        ListNode* head = LinkedList;
        while(head && i < index) {
            head = head->next;
            i++;
        }
        if(head && i == index) {
            return head->val;
        } else {
            return -1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* head = (ListNode*)malloc(sizeof(ListNode));
        head->next = LinkedList;
        head->val = val;
        LinkedList = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* head = LinkedList;
        ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
        temp->next = 0;
        temp->val = val;
        if(!head) {
            LinkedList = temp;
            return;
        }
        while(head->next) {
            head = head->next;
        }
        head->next = temp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int i = 0;
        ListNode* head = LinkedList;
        if(!head && index == 0) {
            ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
            temp->val = val;
            temp->next = 0;
            LinkedList = temp;
            return ;
        }
        while(head && i < index - 1) {
            head = head->next;
            i++;
        }
        if(head && head->next == 0) {
            ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
            temp->val = val;
            temp->next = 0;
            head->next = temp;
        } else if(i == index - 1 && head && head->next) {
            ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
            temp->val = val;
            temp->next = head->next;
            head->next = temp;
        }
    }
    void deleteHead(ListNode* head){
        if(head == NULL)
            return;
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* head = LinkedList;
        int i = 0;
        while(head && i < index - 1) {
            head = head->next;
            i++;
        }
        if(head == 0) {
            return;
        }
        if(index == 0) {
            deleteHead(head);
            return;
        }
        if(head->next == 0 && index == 0) {
            LinkedList = 0;
            return ;
        }
        if(head->next) {
            ListNode* temp = head->next;
            head->next = temp->next;
            free(temp);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */