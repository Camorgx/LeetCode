// https://leetcode.cn/problems/design-circular-deque/
class MyCircularDeque {
    // array from 0 to max_size
    // the size of the array is max_size + 1
    int* data;
    // head + 1 point to the first
    // tail point to the last
    unsigned head = 0, tail = 0;
    unsigned max_size = 0, actual_size = 0;

public:
    explicit MyCircularDeque(int k) {
        max_size = k;
        data = new int[k + 1];
    }

    ~MyCircularDeque() { delete[] data; }

    bool insertFront(int value) {
        if (isFull()) return false;
        ++actual_size;
        data[head] = value;
        head = (head == 0) ? max_size : head - 1;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        ++actual_size;
        tail = (tail + 1) % (max_size + 1);
        data[tail] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % (max_size + 1);
        --actual_size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail == 0) ? max_size : tail - 1;
        --actual_size;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : data[(head + 1) % (max_size + 1)];
    }

    int getRear() {
        return isEmpty() ? -1 : data[tail];
    }

    bool isEmpty() const {
        return actual_size == 0;
    }

    bool isFull() const {
        return actual_size >= max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */