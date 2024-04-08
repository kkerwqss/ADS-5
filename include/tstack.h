// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    T * data = new T[size];
    int top = 0;
  public:
    TStack () {
      top = 0;
    }

    ~TStack() {delete[] data}

    void push(const T& item) {
      if (top > size - 1) {
        throw std::string("Full!!");
      } else {
        data[top++] = item;
      }
    }

    T pop() {
      if (top == 0) {
        throw std::string("Empty!!");
      } else {
        top--;
        return data[top];
      }
    }

    T stTop() {
      if (top > 0) {
        return data[top - 1];
      } else {
        return -1;
      }
    }

    bool isEmpty() const {
      return top == 0;
    }
};

#endif
