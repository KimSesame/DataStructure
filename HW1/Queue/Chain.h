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

    template <typename T>
    friend class Chain;

public:
    ChainNode(const T data, ChainNode<T> *next = nullptr);
};

template <typename T>
class Chain
{
private:
    ChainNode<T> *head;
    ChainNode<T> *tail;

public:
    Chain();
    virtual ~Chain();
    bool IsEmpty(void) const;
    ChainNode<T>* Search(const T& data) const;
    void Append(const T& data);
    void Delete(const T& data);
    //void Print(void) const;
};

#include "chain.hpp"
#endif