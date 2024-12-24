    void dequeue() {
        Node *temp = front;
        if (front == nullptr) {
            cout << "Queue is underflow!" << endl;
        } else {
            Node* deletenode = front;         
            front = front->next;              
            cout << "Dequeue: " << deletenode->data << endl;
            delete deletenode;               
            if (front == nullptr) {           
                rear = nullptr;               
            }
        }
    }
