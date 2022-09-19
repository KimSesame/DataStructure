#ifndef __CHAIN_H__
#define __CHAIN_H__

#include <iostream>
using namespace std;

template <typename T>
class Chain;

template <typename T>
class ChainNode
{
private:
    T data;
    ChainNode<T> *next;

    friend class Chain;

public:
    ChainNode(const T data, ChainNode<T> *next = nullptr);
    T &GetData() const { return data; }
};

template <typename T>
class Chain
{
protected:
    ChainNode<T> *head;
    ChainNode<T> *tail;

public:
    Chain();
    virtual ~Chain();
    bool IsEmpty(void) const;
    void StackPush(const T& data);
    void StackPop(void);
    void QueuePush(const T& data);
    void QueuePop(void);
    void Print(void) const;
};

#include "chain.hpp"
#endif