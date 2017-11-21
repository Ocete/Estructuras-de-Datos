#ifndef __queue_H__
#define __queue_H__

template <class T>
class queue{
  private:
    struct Celda{
      T val;
      Celda *next;

      Celda():next(0){}
    };

    Celda *first;
    Celda *last;
    int n;

  public:
    queue();
    ~queue();
    bool isEmpty() const;
    int size() const;
    void push(const T& val);
    T pop();
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
};

#include "../src/queue.cpp"
#endif
