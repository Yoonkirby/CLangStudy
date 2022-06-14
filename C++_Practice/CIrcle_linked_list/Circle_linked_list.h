#include "Common_head.h"
#ifndef __CIRCLE_LINKED_LIST_H__
#define __CIRCLE_LINKED_LIST_H__
template <typename T>
class Node
{
    private:
        T data;
    public:
        Node * next;
    Node()
        :data(), next(NULL) { }
    Node(T data)
        :data(data), next(NULL) { }
    void SetData(T data);
    T GetData();
};

template <typename T>
void Node<T>::SetData(T data)
{
    this->data = data;
}

template <typename T>
T Node<T>::GetData()
{
    return data;
}


template <typename T>
class Circle_Queue
{
    private:
        int size;
        Node<T> * front;
        Node<T> * back;
    public:
        Circle_Queue()
            : size(0), front(NULL), back(NULL) { }
        Circle_Queue(T data)
            : size(1)
        {
            Node<T> * tmp = new Node<T>(data);
            front = tmp;
            back = tmp;
        }
        void ll_insert(T data);
        T ll_delete();
        void ll_Turn();
        void ShowAll() const;
        ~Circle_Queue()
        {
            Node<T> * tmp = front;
            for(int i = 0; i < size; i++){
                front = front->next;
                delete tmp;
                tmp = front;
            }
        }
};

template <typename T>
void Circle_Queue<T>::ll_insert(T data)
{
    Node<T> * tmp = new Node<T>(data);
    if(size == 0){
        front = tmp;
        back = tmp;
    }
    else{
        back->next = tmp;
        back = tmp;
        tmp->next = front;
    }
    size++;
}

template <typename T>
T Circle_Queue<T>::ll_delete()
{
    if(size > 1){
        T data = front->GetData();
        back->next = front->next;
        delete front;
        front = back->next;
        size--;
        return data;
    }
    else if(size == 1){
        T data = front->GetData();
        delete front;
        front = NULL;
        back = NULL;
        size--;
        return data;
    }
    else{
        cout<<"Queue is Empty"<<endl;
    }
}

template <typename T>
void Circle_Queue<T>::ll_Turn()
{
    front = front->next;
    back = back->next;
}

template <typename T>
void Circle_Queue<T>::ShowAll() const
{
    if(size == 0){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        Node<T> * tmp = front;
        for(int i = 0; i < size; i++){
            cout<<tmp->GetData()<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
}
#endif