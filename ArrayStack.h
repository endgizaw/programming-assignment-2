#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>

using namespace std;


template <typename T>
class ArrayStack {
private:
    vector<T> data;

public:
    void push(const T& value) {
        if (ifFull(data)) {
            return;
        } else {
            data.push_back(value);
        }
        // TODO
    }

    void pop() {
        if (isEmpty(data)) {
            cout << "Is Empty!" ;
            return;
        } else {
            data.pop_back();
        }
        // TODO
    }

    T top() const {
        if (isEmpty(data)) {
            cout << "Is Empty!" ;
            return T();
        }
        // TODO
        return T();
    }

    bool empty() const {
        if (!isEmpty(data)) {
            return false;
        }
        // TODO
        return true;
    }

    int size() const {
        // TODO
        return data.size();;
    }
};

#endif
