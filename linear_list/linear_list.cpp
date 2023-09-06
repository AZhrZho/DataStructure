#include "linear_list.h"
#include <iostream>

int main()
{
    test_static_seq_list();
    test_dynamic_seq_list();
    test_singly_linked_list();
    test_doubly_linked_list();
    return 0;
}

void test_static_seq_list()
{
    std::cout << "init list" << std::endl;
    seq_list_static list = static_seq_list::init_list();
    static_seq_list::push_back(list, 0);
    static_seq_list::push_back(list, 1);
    static_seq_list::push_back(list, 2);
    static_seq_list::push_back(list, 3);
    static_seq_list::push_back(list, 4);
    static_seq_list::push_back(list, 5);
    static_seq_list::print_list(list);

    std::cout << std::endl << "remove" << std::endl;
    static_seq_list::remove_at(list, 0);
    static_seq_list::remove_at(list, static_seq_list::length(list) - 1);
    static_seq_list::print_list(list);

    std::cout << std::endl << "insert" << std::endl;
    static_seq_list::insert(list, 0, 1);
    static_seq_list::insert(list, 2, 4);
    static_seq_list::print_list(list);

    std::cout << std::endl << "get" << std::endl;
    ElemType elem;
    static_seq_list::get(list, 0, elem);
    std::cout << elem << std::endl;
    elem = 999;
    static_seq_list::print_list(list);

    std::cout << std::endl << "alter" << std::endl;
    ElemType_P elem_p;
    static_seq_list::get_mut(list, 0, elem_p);
    std::cout << *elem_p << std::endl;
    *elem_p = 999;
    static_seq_list::print_list(list);

    std::cout << std::endl << "find" << std::endl;
    int index = static_seq_list::find(list, 4);
    std::cout << index << std::endl;
    index = static_seq_list::find(list, 0);
    std::cout << index << std::endl;

    std::cout << std::endl << "invalid" << std::endl;
    static_seq_list::remove_at(list, 7);
    static_seq_list::insert(list, 8, 10);
    static_seq_list::insert(list, 100, 100);
    static_seq_list::print_list(list);

    std::cout << std::endl << "destroy" << std::endl;
    static_seq_list::destroy_list(list);

    // should be invalid
    // static_seq_list::print_list(list);
}

void test_dynamic_seq_list()
{
    std::cout << "init list" << std::endl;
    seq_list_dynamic list = dynamic_seq_list::init_list();
    dynamic_seq_list::push_back(list, 0);
    dynamic_seq_list::push_back(list, 1);
    dynamic_seq_list::push_back(list, 2);
    dynamic_seq_list::push_back(list, 3);
    dynamic_seq_list::push_back(list, 4);
    dynamic_seq_list::push_back(list, 5);
    dynamic_seq_list::print_list(list);

    std::cout << std::endl << "remove" << std::endl;
    dynamic_seq_list::remove_at(list, 0);
    dynamic_seq_list::remove_at(list, dynamic_seq_list::length(list) - 1);
    dynamic_seq_list::print_list(list);

    std::cout << std::endl << "insert" << std::endl;
    dynamic_seq_list::insert(list, 0, 1);
    dynamic_seq_list::insert(list, 2, 4);
    dynamic_seq_list::print_list(list);

    std::cout << std::endl << "get" << std::endl;
    ElemType elem;
    dynamic_seq_list::get(list, 0, elem);
    std::cout << elem << std::endl;
    elem = 999;
    dynamic_seq_list::print_list(list);

    std::cout << std::endl << "alter" << std::endl;
    ElemType_P elem_p;
    dynamic_seq_list::get_mut(list, 0, elem_p);
    std::cout << *elem_p << std::endl;
    *elem_p = 999;
    dynamic_seq_list::print_list(list);

    std::cout << std::endl << "find" << std::endl;
    int index = dynamic_seq_list::find(list, 4);
    std::cout << index << std::endl;
    index = dynamic_seq_list::find(list, 0);
    std::cout << index << std::endl;

    std::cout << std::endl << "invalid" << std::endl;
    dynamic_seq_list::remove_at(list, 7);
    dynamic_seq_list::insert(list, 8, 10);
    dynamic_seq_list::insert(list, 100, 100);
    dynamic_seq_list::print_list(list);

    std::cout << std::endl << "auto expand" << std::endl;
    for (int i = 0; i < 128; i++)
    {
        dynamic_seq_list::push_back(list, i);
    }

    dynamic_seq_list::print_list(list);

    std::cout << std::endl << "destroy" << std::endl;
    dynamic_seq_list::destroy_list(list);

    // should be invalid
    // dynamic_seq_list::print_list(list);
}

void test_singly_linked_list()
{
    std::cout << "init list" << std::endl;
    linked_list_single list = singly_linked_list::init_list();
    singly_linked_list::insert(list, 0, 0);
    singly_linked_list::insert(list, 0, 1);
    singly_linked_list::insert(list, 0, 2);
    singly_linked_list::insert(list, 0, 3);
    singly_linked_list::insert(list, 0, 4);
    singly_linked_list::insert(list, 0, 5);
    singly_linked_list::print_list(list);

    std::cout << std::endl << "remove" << std::endl;
    singly_linked_list::remove_at(list, 0);
    singly_linked_list::remove_at(list, singly_linked_list::length(list) - 1);
    singly_linked_list::print_list(list);

    std::cout << std::endl << "insert" << std::endl;
    singly_linked_list::insert(list, 0, 1);
    singly_linked_list::insert(list, 2, 4);
    singly_linked_list::print_list(list);

    std::cout << std::endl << "get" << std::endl;
    ElemType elem;
    singly_linked_list::get(list, 1, elem);
    std::cout << elem << std::endl;
    elem = 999;
    singly_linked_list::print_list(list);

    std::cout << std::endl << "alter" << std::endl;
    ElemType_P elem_p;
    singly_linked_list::get_mut(list, 0, elem_p);
    std::cout << *elem_p << std::endl;
    *elem_p = 999;
    singly_linked_list::print_list(list);

    std::cout << std::endl << "find" << std::endl;
    int index = singly_linked_list::find(list, 4);
    std::cout << index << std::endl;
    index = singly_linked_list::find(list, 0);
    std::cout << index << std::endl;

    std::cout << std::endl << "destroy" << std::endl;
    singly_linked_list::destroy_list(list);

    // should be invalid
    // singly_linked_list::print_list(list);
}

void test_doubly_linked_list()
{
    std::cout << "head insert" << std::endl;
    linked_list_double list = doubly_linked_list::init_list();
    doubly_linked_list::insert(list, 0, 0);
    doubly_linked_list::insert(list, 0, 1);
    doubly_linked_list::insert(list, 0, 2);
    doubly_linked_list::insert(list, 0, 3);
    doubly_linked_list::insert(list, 0, 4);
    doubly_linked_list::insert(list, 0, 5);
    doubly_linked_list::print_list(list);

    std::cout << "tail insert" << std::endl;
    doubly_linked_list::insert(list, doubly_linked_list::length(list), 1);
    doubly_linked_list::insert(list, doubly_linked_list::length(list), 2);
    doubly_linked_list::insert(list, doubly_linked_list::length(list), 3);
    doubly_linked_list::insert(list, doubly_linked_list::length(list), 4);
    doubly_linked_list::insert(list, doubly_linked_list::length(list), 5);
    doubly_linked_list::print_list(list);

    std::cout << "insert" << std::endl;
    doubly_linked_list::insert(list, 1, 3);
    doubly_linked_list::insert(list, 10, 8);
    doubly_linked_list::print_list(list);

    std::cout << "push back" << std::endl;
    doubly_linked_list::push_back(list, 10);
    doubly_linked_list::push_back(list, 11);
    doubly_linked_list::print_list(list);

    std::cout << std::endl << "remove sides" << std::endl;
    doubly_linked_list::remove_at(list, 0);
    doubly_linked_list::remove_at(list, doubly_linked_list::length(list) - 1);
    doubly_linked_list::print_list(list);

    std::cout << std::endl << "remove" << std::endl;
    doubly_linked_list::remove_at(list, 2);
    doubly_linked_list::remove_at(list, doubly_linked_list::length(list) - 3);
    doubly_linked_list::print_list(list);

    std::cout << std::endl << "get" << std::endl;
    ElemType elem;
    doubly_linked_list::get(list, 1, elem);
    std::cout << elem << std::endl;
    elem = 999;
    doubly_linked_list::print_list(list);

    std::cout << std::endl << "alter" << std::endl;
    ElemType_P elem_p;
    doubly_linked_list::get_mut(list, 0, elem_p);
    std::cout << *elem_p << std::endl;
    *elem_p = 999;
    doubly_linked_list::print_list(list);

    std::cout << std::endl << "find" << std::endl;
    int index = doubly_linked_list::find(list, 0);
    std::cout << index << std::endl;
    index = doubly_linked_list::find(list, 2);
    std::cout << index << std::endl;
    index = doubly_linked_list::find(list, 8);
    std::cout << index << std::endl;
    index = doubly_linked_list::find(list, -1);
    std::cout << index << std::endl;
}
