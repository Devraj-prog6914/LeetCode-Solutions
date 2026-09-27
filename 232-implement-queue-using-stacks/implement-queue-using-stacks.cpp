class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        move();

        int x = s2.top();
        s2.pop();

        return x;
    }

    int peek() {
        move();
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

    void move() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
};