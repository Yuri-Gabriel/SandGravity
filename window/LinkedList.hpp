#pragma once

template<typename T>
struct Node {
    T value;
    int index;
    Node<T>* next;
    Node<T>* prev;

    Node(T val, int index) : value(val), index(index), next(nullptr), prev(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* end;
    int lenght;

    void updateIndex() {
        Node<T>* temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->index = i++;
            temp = temp->next;
        }
    }

public:
    LinkedList() {
        head = nullptr;
        end = nullptr;
        lenght = 0;
    }

    void add(T value) {
        Node<T>* new_node = new Node<T>(value, lenght);
        if (head == nullptr) {
            head = new_node;
            end = new_node;
        } else {
            end->next = new_node;
            new_node->prev = end;
            end = new_node;
        }
        lenght++;
    }

    T get(int index) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->index == index) return temp->value;
            temp = temp->next;
        }
        throw std::out_of_range("Índice inválido");
    }

    template<typename Func>
    void forEach(Func func) {
        Node<T>* current = this->head;
        while(current != nullptr) {
            func(current->value);
            current = current->next;
        }
        
        
    }

    void remove(int index) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->index == index) {
                if (temp->prev != nullptr)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next != nullptr)
                    temp->next->prev = temp->prev;
                else
                    end = temp->prev;

                delete temp;
                lenght--;
                updateIndex();
                return;
            }
            temp = temp->next;
        }
    }

    int length() {
        return this->lenght;
    }
};
