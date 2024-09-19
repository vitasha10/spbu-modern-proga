#include <iostream>

struct Node {
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int list_size;

public:
    LinkedList() : head(nullptr), list_size(0) {}

    bool empty() const {
        return head == nullptr;
    }

    int size() const {
        return list_size;
    }

    Node* find(int val) const {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->val == val) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void add(int val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        list_size++;
    }

    void remove(int val) {
        if (empty()) return;

        if (head->val == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            list_size--;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->val != val) {
            curr = curr->next;
        }

        if (curr->next != nullptr) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            list_size--;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void print() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    LinkedList list;

    std::cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << "\n";

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    std::cout << "Initial list: ";
    list.print();

    std::cout << "List size: " << list.size() << "\n";

    int find_val = 3;
    std::cout << "Finding value " << find_val << ": " 
              << (list.find(find_val) ? "Found" : "Not found") << "\n";

    list.remove(2);
    std::cout << "List after removing 2: ";
    list.print();

    std::cout << "List size after removal: " << list.size() << "\n";

    std::cout << "Finding value 2: " 
              << (list.find(2) ? "Found" : "Not found") << "\n";

    list.reverse();
    std::cout << "Reversed list: ";
    list.print();

    std::cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << "\n";

    return 0;
}
