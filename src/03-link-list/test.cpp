#include <iostream>
#include "link_list.h"

int main()
{
    auto list1 = link_list::alloc_new();
    link_list::head_insert(list1, link_list::create_node(5));
    link_list::head_insert(list1, link_list::create_node(4));
    link_list::head_insert(list1, link_list::create_node(3));
    link_list::head_insert(list1, link_list::create_node(2));
    link_list::head_insert(list1, link_list::create_node(1));
    link_list::print(list1);

    auto list2 = link_list::alloc_new();
    LNode* tail = list2;
    for (int i = 0; i < 5; i++)
    {
        auto node = link_list::create_node(i);
        link_list::insert_after(tail, node);
        tail = node;
    }
    link_list::print(list2);

    link_list::insert(list2, 2, link_list::create_node(5));
    link_list::print(list2);
    link_list::insert(list2, 5, link_list::create_node(8));
    link_list::print(list2);
    link_list::insert(list2, 0, link_list::create_node(7));
    link_list::print(list2);

    std::cout << std::endl;

    link_list::remove_at(list2, 7);
    link_list::print(list2);
    link_list::remove_at(list2, 0);
    link_list::print(list2);
    link_list::remove_at(list2, 3);
    link_list::print(list2);

    std::cout << link_list::length(list2) << std::endl;

    link_list::reverse(list2);
    link_list::print(list2);

    return 0;
}