#include <iostream>
#include "doubly_linked_list.h"
#include "../../options.h"

struct doubly_linked_list::list_node
{
    ElemType data;
    list_node* prev;
    list_node* next;
};

struct doubly_linked_list::list
{
    list_node head;
    list_node tail;
    int length;
};

doubly_linked_list::list& doubly_linked_list::init_list()
{
    list* list = new doubly_linked_list::list;

    list->head.next = &list->tail;
    list->tail.prev = &list->head;

    list->head.prev = nullptr;
    list->tail.next = nullptr;

    list->length = 0;

    return *list;
}

void doubly_linked_list::destroy_list(list& list)
{
    while (list.head.next != nullptr)
    {
        auto node = list.head.next;
        list.head.next = node->next;
        delete node;
    }
    delete& list;
}

bool doubly_linked_list::insert(list& list, int index, ElemType elem)
{
    // index out of range
    if (index < 0 || index > list.length) return false;

    list_node* front_node;
    // decide to use head-insert or tail-insert
    if (index <= list.length / 2)
    {
        // head-insert
        front_node = &list.head;
        while (index-- > 0)
        {
            front_node = front_node->next;
        }
    }
    else
    {
        // tail-insert
        index = list.length - index + 1;
        front_node = &list.tail;
        while (index-- > 0)
        {
            front_node = front_node->prev;
        }
    }

    auto behind_node = front_node->next;

    auto node = new list_node;
    node->data = elem;
    node->prev = front_node;
    node->next = behind_node;

    front_node->next = node;
    behind_node->prev = node;

    ++list.length;

    return true;
}

bool doubly_linked_list::push_back(list& list, ElemType elem)
{
    auto prev = list.tail.prev;

    auto node = new list_node;
    node->data = elem;
    node->prev = prev;
    node->next = &list.tail;

    prev->next = node;
    list.tail.prev = node;

    ++list.length;

    return true;
}

bool doubly_linked_list::remove_at(list& list, int index)
{
    // index out of range
    if (index < 0 || index >= list.length) return false;

    // node to remove
    list_node* node;
    if (index <= list.length / 2) 
    {
        node = &list.head;
        for (int i = 0; i < index + 1; ++i)
        {
            node = node->next;
        }
    }
    else
    {
        node = &list.tail;
        for (int i = 0; i < list.length - index; ++i)
        {
            node = node->prev;
        }
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
    --list.length;

    return true;
}

bool doubly_linked_list::get(const list& list, int index, ElemType& result)
{
    ElemType_P pResult;
    bool success = get_mut(list, index, pResult);
    if (!success) return false;

    result = *pResult;
    return true;
}

bool doubly_linked_list::get_mut(const list& list, int index, ElemType_P& pResult)
{
    if (index < 0 || index >= list.length) return false;
    list_node* node;
    if (index <= list.length / 2)
    {
        node = const_cast<list_node*>(&list.head);
        for (int i = 0; i < index + 1; ++i)
        {
            node = node->next;
        }
    }
    else
    {
        node = const_cast<list_node*>(&list.tail);
        for (int i = 0; i < list.length - index; ++i)
        {
            node = node->prev;
        }
    }
    pResult = &node->data;
    return true;
}

int doubly_linked_list::length(const list& list)
{
    return list.length;
}

int doubly_linked_list::find(const list& list, const ElemType& elem)
{
    int found_index = -1;
    int index = 0;

    // find from both two sides
    for (auto lptr = list.head.next, rptr = list.tail.prev; lptr != rptr && rptr->prev != lptr; lptr = lptr->next, rptr = rptr->prev, ++index)
    {
        if (lptr->data == elem) return index;
        if (rptr->data == elem) found_index = list.length - index - 1;
    }

    return found_index;
}

void doubly_linked_list::print_list(const list& list)
{
    std::cout << "singly_linked_list(" << list.length << ")" << ": ";
    for (auto node = list.head.next; node != &list.tail; node = node->next)
    {
        std::cout << node->data << ' ';
    }
    std::cout << std::endl;
}
