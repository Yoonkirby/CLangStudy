#include <iostream>

using namespace std;

class node
{
    private:
        int data;
    public:
        node * next;
        node()
            :data(), next(NULL) { }
        node(int data)
            :data(data), next(NULL) { }
        void SetData(int data)
        {
            this->data = data;
        }
        int GetData()
        {
            return data;
        }
};

class Circle_Queue
{
    private:
        int size;
        node * front;
        node * back;
    public:
        Circle_Queue()
            : size(0), front(NULL), back(NULL) { }
        Circle_Queue(int data)
            : size(1)
        {
            node * tmp = new node(data);
            front = tmp;
            back = tmp;
        }
        void ll_insert(int data)
        {
            node * tmp = new node(data);
            if(size == 0){
                front = tmp;
            }
            else{
                tmp->next = front;
                back->next = tmp;
            }
            back = tmp;
            size++;
        }
        int ll_delete()
        {
            if(size > 1){
                int data = front->GetData();
                back->next = front->next;
                delete front;
                front = back->next;
                size--;
                return data;
            }
            else if(size == 1){
                int data = front->GetData();
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
        void ll_Turn()
        {
            front = front->next;
            back = back->next;
        }
        void ShowAll() const
        {
            if(size == 0){
                cout<<"Queue is Empty"<<endl;
            }
            else{
                node * tmp = front;
                for(int i = 0; i < size; i++){
                    cout<<tmp->GetData()<<" ";
                    tmp = tmp->next;
                }
                cout<<endl;
            }
        }
        ~Circle_Queue()
        {
            node * tmp = front;
            for(int i = 0; i < size; i++){
                front = front->next;
                delete tmp;
                tmp = front;
            }
            cout<<"bye bye"<<endl;
        }
};

int main(void)
{
    Circle_Queue * Q = new Circle_Queue(1);
    Q->ShowAll();

    Q->ll_insert(2);
    for(int i = 3; i <= 10; i++){
        Q->ll_insert(i);
    }
    Q->ShowAll();
    
    cout<<endl<<"Homp Homp <"<<Q->ll_delete()<<">"<<endl<<endl;    
    Q->ShowAll();

    // Q->ll_Turn();
    // Q->ShowAll();

    // Q->ll_Turn();
    // Q->ShowAll();

    // Q->ll_Turn();
    // Q->ShowAll();

    delete Q;
    return 0;
}