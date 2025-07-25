class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {  // O(1)
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void push_back(int val) {    // O(1)
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void pop_front() {     //O(1)
        Node* temp = head;
        head = head->next;
        temp = NULL;
        delete temp;
        if(head == NULL) tail = NULL;
    }

    void pop_back() {     //O(n)
        if(head == NULL) return;
        if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos) {    //O(n)
        Node* temp = head;
        Node* newNode = new Node(val);
        if(pos < 0) {
            cout << "position is not valid";
            return;
        }
        if(pos == 0) {
            return push_front(val);
        }
        for(int i = 0; i < pos - 1; i++) {
            temp = temp->next;
            if(temp == NULL) {
                cout << "Position is not valid\n";
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int val) {    //O(n)
        Node* temp = head;
        int idx = 0;
        while(temp != NULL) {
            if(temp->data == val) {
                return idx;
            }
            idx++; temp = temp->next;
        }
        return -1;
    }

    void print_ll() {      //O(n)
        Node* temp = head;
        if(temp == NULL) {
            cout << "The LL is empty!";
            return;
        }
        while(temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << "NULL\n";
        return;
    }
};

void solve() {
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    

    ll.pop_back();
    ll.push_back(4);
    // ll.pop_front();

    // ll.print_ll();

    ll.print_ll();

    ll.insert(3, 2);
    ll.print_ll();
    cout << ll.search(3) << '\n';
}
