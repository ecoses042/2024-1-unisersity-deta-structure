#pragma once

#include <iostream>
#include<assert.h>

using namespace std;
const int max_queue_size = 100;

template<typename elemtype>
class queue{
    public:
        queue();
        ~queue();
        void enqueue(const elemtype& data);
        elemtype dequeue();
        elemtype front();
        bool isempty();
        bool isfull();
        int nextindex(int current);
    private:
        elemtype content[max_queue_size];
        int f;
        int r;
        int m_nElement;
};

template<typename elemtype>
queue<elemtype>::queue(){
    f = 0;
    r = 0;
    m_nElement = 0;
}

template<typename elemtype>
queue<elemtype>::~queue(){

}

template <typename elemtype>
int queue<elemtype>::nextindex(int current)
{
    if (current == max_queue_size)
    {
        return 0;
    }
    else
        return current + 1;
}
template<typename elemtype>
void queue<elemtype>::enqueue(const elemtype& data)
{
    assert(!isfull());
    r = nextindex(r);
    content[r] = data;
    m_nElement++;
}

template<typename elemtype>
elemtype queue<elemtype>::dequeue()
{
    assert(!isempty());
    f = nextindex(f);
    m_nElement--;
    return content[f];
}

template<typename elemtype>
elemtype queue<elemtype>::front()
{
    assert(!isempty());
    return content[nextindex(f)];
}
template<typename elemtype>
bool queue<elemtype>::isempty()
{
    return m_nElement == 0;
}

template<typename elemtype>
bool queue<elemtype>::isfull()
{
    return max_queue_size == m_nElement;
}
