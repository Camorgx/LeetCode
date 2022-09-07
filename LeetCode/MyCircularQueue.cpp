// https://leetcode.cn/problems/design-circular-queue/
class MyCircularQueue {
    // array from 0 to max_size
    // the size of the array is max_size + 1
    int* data;
    // head + 1 point to the first
    // tail point to the last
    unsigned head = 0, tail = 0;
    unsigned max_size = 0, actual_size = 0;
    bool full = false;
public:

    MyCircularQueue(int k) {
        max_size = k;
        data = new int[k + 1];
    }

    ~MyCircularQueue() { delete[] data; }

    bool enQueue(int value) {
        if (isFull()) return false;
        ++actual_size;
        tail = (tail + 1) % (max_size + 1);
        data[tail] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % (max_size + 1);
        --actual_size;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[(head + 1) % (max_size + 1)];
    }

    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }

    bool isEmpty() {
        return actual_size == 0;
    }

    bool isFull() {
        return actual_size >= max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */