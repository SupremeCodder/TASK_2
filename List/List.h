//
// Created by user on 09.12.2022.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>

template<typename T>
class List
{
public:
    List();
    ~List();
    void Insert(int pos, T _data);  //на какую позицию делать вставку (по-умолчанию 0)
    void Add_head(T _data);         //вставить в начало списка
    void Add_tail(T _data);         //ставить в конец списка
    void Del (int pos);             //удалить
    void Print (int pos);           //напечатать
    void swap(int pos1, int pos2);  //поменять местами данные с 2-х узлов

    template<typename T_>
    class Node
    {
    public:

        Node* pNext;
        Node* pPrev;
        T_ data;

        explicit Node(T_ _data = T(), Node* _pNext = nullptr) // = T() - чтобы по-умолчанию не было мусора
        {
            this->data = _data;
            this->pNext = _pNext;
            this->pPrev = nullptr;
        }
        ~Node()
        = default;
    };

    Node<T>* head;
    Node<T>* tail;
    int list_size{}; //размер списка

    void split (Node<T>* head, Node<T>** a, Node<T>** b);
    void mergesort(Node<T>** head);

    //компилятор ругается на тип возвращаемого значения, поэтому описываю тут
    Node<T>* merge (Node<T>* a, Node<T>* b) //слить
    {
        //тривиальные случаи
        if (a == nullptr)
        {
            return b;
        }
        if (b == nullptr)
        {
            return a;
        }

        if (a->data <= b->data)
        {
            a->pNext = merge(a->pNext,b);
            a->pNext->pPrev = a;
            a->pPrev = nullptr;
            return a;
        }
        else
        {
            b->pNext = merge(a, b->pNext);
            b->pPrev = nullptr;
            return b;
        }
    }
};

template<typename T>
List<T>::List()
{
    this->list_size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
List<T>::~List()
= default;
#endif //LIST_LIST_H
