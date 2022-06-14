#include <iostream>

using namespace std;

template <typename T>
class node
{
    private:
        T data;
    public:
        node<T> * prev;
        node<T> * next;
        node() :data(), prev(NULL), next(NULL) {}
        node(T data) :data(data), prev(NULL), next(NULL) { }
        T Getdata()
        {
            return data;
        }
};

template <typename T>
class D_linked_list
{
    private:
        node<T> * head;
        node<T> * tail;
        int size;
    public:
        D_linked_list() :head(NULL), tail(NULL), size(0) { }
        D_linked_list(T data) :size(1)
        {
            node<T> * tmp = new node<T>(data);
            head = tmp;
            tail = tmp;
        }
        void Dlist_insert(T data)
        {
            node<T> * tmp = new node<T>(data);
            if(size == 0)
            {
                head = tmp;
            }
            else
            {
                tail->next = tmp;
                tmp->prev = tail;
                tmp->next = head;
                head->prev = tmp;
                
            }
            tail = tmp;
            size++;
        }
        T Dlist_delete(int cnt)
        {
            if(size > 1)
            {
                int data;
                node<T> * tmp = head;
                for(int i = 1; i < cnt; i++){
                    tmp = tmp->next;
                }
                if(cnt == 1){
                    head = head->next;
                }
                if(cnt == size){
                    tail = tail->prev;
                }
                data = tmp->Getdata();
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                size--;
                return data;
            }
            else if(size == 1)
            {
                delete head;
                head = NULL;
                tail = NULL;
                size--;
            }
        }
        void Dlist_turnleft()
        {
            head = head->next;
            tail = tail->next;
        }
        void Dlist_turnright()
        {
            tail = tail->prev;
            head = head->prev;
        }
        void Dlist_print() const
        {
            node<T> * tmp = head;
            for(int i = 0; i < size; i++){
                cout<<tmp->Getdata()<<" ";
                tmp = tmp->next;
            }
            cout<<endl;
        }
        void Dlist_print_reverse() const
        {
            node<T> * tmp = tail;
            for(int i = 0; i < size; i++){
                cout<<tmp->Getdata()<<" ";
                tmp = tmp->prev;
            }
            cout<<endl;
        }
        ~D_linked_list()
        {
            node<T> * tmp = head;
            for(int i = 0; i < size; i++){
                head = head->next;
                delete tmp;
                tmp = head;
            }
        }
};

int main(void)
{
    int i;
    D_linked_list<int> * list = new D_linked_list<int>;
    for(i = 1; i <= 10; i++){
        list->Dlist_insert(i);
    }
    list->Dlist_print();
    list->Dlist_print_reverse();
    cout<<endl;

    for(i = 2; i <= 6; i++){
        list->Dlist_delete(i);
    }
    list->Dlist_print();
    list->Dlist_print_reverse();
    cout<<endl;

    for(i = 2; i <= 10; i+=2){
        list->Dlist_insert(i);
    }
    list->Dlist_print();
    list->Dlist_print_reverse();
    cout<<endl;

    for(i = 0; i < 3; i++){
        list->Dlist_turnleft();
        list->Dlist_print();
    }
    cout<<endl;

    for(i = 0; i < 3; i++){
        list->Dlist_turnright();
        list->Dlist_print();
    }
    return 0;
}