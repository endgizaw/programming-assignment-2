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
        data.push_back(value);
        // TODO
    }

    void pop() {
        if (data.empty()) {
            cout << "Is Empty!" << endl;
        }
        // TODO
        data.pop_back();
    }

    T top() const {
        if (data.empty()) {
            cout << "Is Empty!" ;
            return T();
        }
        // TODO
        return data[data.size()-1];
    }

    bool empty() const {
        return data.empty();
    }

    int size() const {
        // TODO
        return data.size();;
    }

};

#endif
