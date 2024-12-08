#include "ForwardList.h"

int main()
{
    ForwardList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.print();
    Node* first_node = list.GetHead()->next->next;
    list.push_after(first_node, 5);
    list.print();
    return 0;
}
