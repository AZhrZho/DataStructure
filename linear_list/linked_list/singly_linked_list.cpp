#include <iostream>
#include "singly_linked_list.h"
#include "../../options.h"

struct singly_linked_list::list_node
{
    ElemType data;
    list_node* next;
};

#if LINKLISTUSEHEAD
#pragma region implement with head node
struct singly_linked_list::list
{
    list_node* head;
    int length;
};

singly_linked_list::list& singly_linked_list::init_list()
{
    list* list = new singly_linked_list::list;
    list->head = new singly_linked_list::list_node;
    list->head->next = nullptr;
    list->length = 0;

    return *list;
}

void singly_linked_list::destroy_list(list& list)
{
    while (list.head->next != nullptr)
    {
        auto node = list.head->next;
        list.head = node->next;
        delete node;
    }
    delete list.head;
    delete& list;
}

bool singly_linked_list::insert(list& list, int index, ElemType elem)
{
    // index out of range
    if (index < 0 || index > list.length) return false;

    ++list.length;

    auto new_node = new list_node;
    new_node->data = elem;

    auto front_node = list.head;
    for (int i = 0; i < index; i++)
    {
        front_node = front_node->next;
    }
    auto behind_node = front_node->next;
    front_node->next = new_node;
    new_node->next = behind_node;

    return true;
}

bool singly_linked_list::push_back(list& list, ElemType elem)
{
    return singly_linked_list::insert(list, list.length, elem);
}

bool singly_linked_list::remove_at(list& list, int index)
{
    // index out of range
    if (index < 0 || index >= list.length) return false;

    --list.length;

    auto front_node = list.head;
    for (int i = 0; i < index; ++i)
    {
        front_node = front_node->next;
    }
    auto cur_node = front_node->next;
    front_node->next = cur_node->next;
    delete cur_node;

    return true;
}

bool singly_linked_list::get(const list& list, int index, ElemType& result)
{
    // index out of range
    if (index < 0 || index >= list.length) return false;

    auto node = list.head->next;
    while (index-- > 0)
    {
        node = node->next;
    }

    result = node->data;
    return true;
}

bool singly_linked_list::get_mut(const list& list, int index, ElemType_P& pResult)
{
    // index out of range
    if (index < 0 || index >= list.length) return false;

    auto node = list.head->next;
    while (index-- > 0)
    {
        node = node->next;
    }

    pResult = &node->data;
    return true;
}

int singly_linked_list::length(const list& list)
{
    return list.length;
}

int singly_linked_list::find(const list& list, const ElemType& elem)
{
    int index = 0;
    for (auto node = list.head->next; node != nullptr; node = node->next, ++index)
    {
        if (node->data == elem)
        {
            return index;
        }
    }
    return -1;
}

void singly_linked_list::print_list(const list& list)
{
    std::cout << "singly_linked_list(" << list.length << ")" << ": ";
    for (auto node = list.head->next; node != nullptr; node = node->next)
    {
        std::cout << node->data << ' ';
    }
    std::cout << std::endl;
}
#pragma endregion
#else
#pragma region implement without head node

struct singly_linked_list::list
{
    list_node* first;
    int length;
};

singly_linked_list::list& singly_linked_list::init_list()
{
    list* list = new singly_linked_list::list;
    list->first = nullptr;
    list->length = 0;

    return *list;
}

void singly_linked_list::destroy_list(list& list)
{
    while (list.first != nullptr)
    {
        auto node = list.first;
        if (node->next != nullptr)
        {
            list.first = list.first->next;
            delete node;
        }
        else
        {
            delete node;
            list.first = nullptr;
        }
    }
    delete &list;
}

bool singly_linked_list::insert(list& list, int index, ElemType elem)
{
    // index out of range
    if (index < 0 || index > list.length) return false;

    ++list.length;

    auto new_node = new list_node;
    new_node->data = elem;

    // insert at first position
    if (index == 0)
    {
        new_node->next = list.first;
        list.first = new_node;

        return true;
    }
    // else
    auto front_node = list.first;
    for (int i = 1; i < index; i++)
    {
        front_node = front_node->next;
    }
    auto behind_node = front_node->next;
    front_node->next = new_node;
    new_node->next = behind_node;

    return true;
}

bool singly_linked_list::push_back(list& list, ElemType elem)
{
    return singly_linked_list::insert(list, list.length, elem);
}

bool singly_linked_list::remove_at(list& list, int index)
{
    // index out of range
    if (index < 0 || index >= list.length) return false;

    --list.length;

    // delete first node
    if (index == 0)
    {
        auto node = list.first;
        list.first = node->next;
        delete node;

        return true;
    }

    auto front_node = list.first;
    for (int i = 1; i < index; ++i)
    {
        front_node = front_node->next;
    }
    auto cur_node = front_node->next;
    front_node->next = cur_node->next;
    delete cur_node;

    return true;
}

bool singly_linked_list::get(const list& list, int index, ElemType& result)
{
    // index out of range
    if (index < 0 || index >= list.length) return false;

    auto node = list.first;
    while (index-- > 0)
    {
        node = node->next;
    }

    result = node->data;
    return true;
}

bool singly_linked_list::get_mut(const list& list, int index, ElemType_P& pResult)
{
    // index out of range
    if (index < 0 || index >= list.length) return false;

    auto node = list.first;
    while (index-- > 0)
    {
        node = node->next;
    }

    pResult = &node->data;
    return true;
}

int singly_linked_list::length(const list& list)
{
    return list.length;
}

int singly_linked_list::find(const list& list, const ElemType& elem)
{
    int index = 0;
    for (auto node = list.first; node != nullptr; node = node->next, ++index)
    {
        if (node->data == elem)
        {
            return index;
        }
    }
    return -1;
}

void singly_linked_list::print_list(const list& list)
{
    std::cout << "singly_linked_list(" << list.length << ")" << ": ";
    for (auto node = list.first; node != nullptr; node = node->next)
    {
        std::cout << node->data << ' ';
    }
    std::cout << std::endl;
}
#pragma endregion
#endif
