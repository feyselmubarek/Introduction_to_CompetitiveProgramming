package app;

// uncompleted version
public class MyCircularDeque {
    private int[] deque;
    private int front, last, mod;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        deque = new int[k];
        front = 0;
        last = 0;
        mod = k;
    }

    /**
     * Adds an item at the front of Deque. Return true if the operation is
     * successful.
     */
    public boolean insertFront(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                deque[front] = value;
                // front = (front + 1) % mod;
            } else {
                front = (front + 1) % mod;
                deque[front] = value;
            }
            return true;
        }
        return false;
    }

    /**
     * Adds an item at the rear of Deque. Return true if the operation is
     * successful.
     */
    public boolean insertLast(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                deque[last] = value;
                // last = Math.abs((last - 1) % mod);
            } else {
                last = Math.abs((last - 1) % mod);
                deque[last] = value;
            }
            return true;
        }
        return false;
    }

    /**
     * Deletes an item from the front of Deque. Return true if the operation is
     * successful.
     */
    public boolean deleteFront() {
        if (!isEmpty()) {
            deque[front] = -1;
            front = Math.abs((front - 1) % mod);
            return true;
        }
        return false;
    }

    /**
     * Deletes an item from the rear of Deque. Return true if the operation is
     * successful.
     */
    public boolean deleteLast() {
        if (!isEmpty()) {
            deque[last] = -1;
            last = (last + 1) % mod;
            return true;
        }
        return false;
    }

    /** Get the front item from the deque. */
    public int getFront() {
        if (!isEmpty()) {
            return deque[front];
        }
        return -1;
    }

    /** Get the last item from the deque. */
    public int getRear() {
        if (!isEmpty()) {
            return deque[last];
        }
        return -1;
    }

    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return (front == last) && deque[front] > -1;
    }

    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return (front + 1) % mod == last;
    }
}