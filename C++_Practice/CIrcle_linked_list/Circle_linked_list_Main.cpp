#include "Common_head.h"
#include "Circle_linked_list.h"

int main(void)
{
    Circle_Queue<int> * Q = new Circle_Queue<int>(0);
    Q->ShowAll();

    for(int i = 1; i <= 10; i++){
        Q->ll_insert(i);
    }
    Q->ShowAll();
    
    cout<<endl<<"Homp Homp <"<<Q->ll_delete()<<">"<<endl<<endl;    
    Q->ShowAll();

    Q->ll_Turn();
    Q->ShowAll();

    Q->ll_Turn();
    Q->ShowAll();

    Q->ll_Turn();
    Q->ShowAll();

    delete Q;
    return 0;
}