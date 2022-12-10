//
// Created by user on 09.12.2022.
//
#include "List.h"

template<typename T>
void List<T>::Add_head(T _data) //добавление в начало списка
{
    //выделяем место в динамической памяти (автоматически вызывается конструктор Node)
    Node<T>* temp = new Node<T>;

    temp->data = _data;
    temp->pNext = this->head;

    //если head уже содержит какой-то адрес, то нужно обновить pPrev и head бывшего первого узла (теперь второго)
    if (head != nullptr)
    {
        head ->pPrev = temp;
        this->head = temp;
    }
        //если только создаем первый, то head и tail нужно присвоить адрес нового узла
    else this->head = this->tail = temp;

    list_size++;
}

template<typename T>
void List<T>::Add_tail(T _data)
{
    //выделяем место в динамической памяти (автоматически вызывается конструктор Node)
    Node<T>* temp = new Node<T>;

    temp->pPrev = this->tail;
    temp->data = _data;

    //если первый элемент уже создан
    if (tail != nullptr)
    {
        tail->pNext = temp;
        this->tail = temp;
    }
        //если только создаем первый элемент
    else this->head = this->tail = temp;

    list_size++;
}

template<typename T>
void List<T>::Insert(int pos, T _data)
{
    //защита от дурака, если ввели несуществующую позицию узла
    if ((pos < 1) || (pos > list_size+1))
    {
        std::cout << "incorrect position" << std::endl;
        return;
    }

    //если нужно добавить в начало списка
    if (pos == 1)
    {
        //теперь помещаем в узел
        Add_head(_data);
        return;
    }

    //если нужно добавить в конец списка
    if (pos == this->list_size+1)
    {
        //теперь помещаем в узел
        Add_tail(_data);
        return;
    }
    //теперь добавление в произвольное место

        //выделяем место в динамической памяти (автоматически вызывается конструктор Node)
        Node<T>* temp = new Node<T>;

        Node<T>* current = this->head;
        int counter = 1;

        //до конца списка
        while(current != nullptr)
        {
            //когда доходим до нужной позиции
            if (pos == counter)
            {
                //заполняем свойства структуры temp
                temp->pNext = current;
                temp->pPrev = current->pPrev;
                temp->data = _data;

                //меняем свойства следущего и предыдущего от temp узла
                (current->pPrev)->pNext = temp;
                current->pPrev = temp;

                list_size++;
                return;
            }
            current = current->pNext;
            counter++;
        }

        list_size++;
}

template<typename T>
void List<T>::Del(int pos)
{
    //защита от дурака, если введена несуществующая позиция
    if ((pos < 1) | (pos > list_size+1))
    {
        std::cout << "incorrect data";
        return;
    }

    Node<T>* current = this->head;
    int counter = 1;

    while (current != nullptr)
    {
        if (pos == counter)
        {
            //если удаляем единственный элемент списка
            if ((current->pPrev == nullptr) & (current->pNext == nullptr)) {
                delete current;
                list_size--;
                return;
            }
            //если удаляем хвост
            if (current == tail)
            {
                (current->pPrev)->pNext = nullptr;
                tail = current->pPrev;
                delete current;

                list_size--;
                return;
            }
            //если удаляем голову
            if (current == head)
            {
                (current->pNext)->pPrev = nullptr;
                head = current->pNext;
                delete current;

                list_size--;
                return;
            }
            (current->pNext)->pPrev = current->pPrev;
            (current->pPrev)->pNext = current->pNext;

            delete current;
            list_size--;
            return;
        }
        current = current->pNext;
        counter++;
    }
    std::cout << "nothing to delete" << std::endl;
}

template<typename T>
void List<T>::Print(int pos)
{
    //защита от дурака, если введена несуществующая позиция
    if ((pos < 1) | (pos > list_size+1))
    {
        std::cout << "incorrect data";
        return;
    }
    Node<T>* current = this->head;
    int counter = 1;

    while (current != nullptr)
    {
        if (pos == counter)
        {
            std::cout << pos <<"-element = " << current->data << std::endl;
            return;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::swap(int pos1, int pos2)
{
    if ((pos1 == 0) | (pos2 == 0))
    {
        std::cout << "enter 1-pos =" << std::endl;
        std::cin >> pos1;
        std::cout << "enter 2-pos =" << std::endl;
        std::cin >> pos2;
    }

    //если введены некорректные данные
    if ((list_size < 2) | (pos1 < 1) | (pos1 > list_size) | (pos2 < 1) | (pos2 > list_size))
    {
        std::cout << "incorrect data" << std::endl;
        return;
    }

    //перестановка местами позиций для удобства
    if (pos1 > pos2)
    {
        int temp;
        temp = pos1;
        pos1 = pos2;
        pos2 = temp;
    }

    Node<T>* current = this->head;
    Node<T>* first = nullptr;

    int counter = 1;

    while (current != nullptr)
    {
        //запоминаем узел по первой позиции pos1
        if (pos1 == counter)
        {
            first = current;
        }
        //когда доходим до pos2
        if (pos2 == counter)
        {
            int temp = first->data;

            //переносим все свойства второго узла в первый
            first->data = current->data;

            //переносим все свойства первого во второй
            current->data = temp;

            return;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::split(List::Node<T> *head, List::Node<T> **a, List::Node<T> **b)
{
    Node<T>* slow = head;
    Node<T>* fast = head->pNext;

    while (fast != nullptr)
    {
        fast = fast->pNext;
        if (fast != nullptr)
        {
            slow = slow->pNext;
            fast = fast->pNext;
        }
    }
    *b = slow->pNext;
    slow->pNext = nullptr;
}

template<typename T>
void List<T>::mergesort(List::Node<T>** head)
{
    if ((*head == nullptr) | ((*head)->pNext == nullptr))
    {
        return;
    }
    Node<T>* a = *head;
    Node<T>* b = nullptr;
    split(*head,&a,&b);

    mergesort(&a);
    mergesort(&b);

    *head = merge(a,b);
}