#include "link_list.h"
#include <iostream>

LinkList link_list::alloc_new()
{
    auto list = new LNode;
    list->next = nullptr;

    return list;
}

void link_list::destroy(LinkList &list)
{
    if (list == nullptr) return;
    auto node = list->next;
    while (node != nullptr)
    {
        auto to_delete = node;
        node = node->next;
        delete to_delete;
    }
    delete list;
    list = nullptr;
}

LNode *link_list::create_node(const ElemType &elem)
{
    auto node = new LNode;
    node->next = nullptr;
    node->data = elem;
    return node;
}

bool link_list::head_insert(const LinkList list, LNode *node)
{
    if (list == nullptr || node == nullptr) return false;
    node->next = list->next;
    list->next = node;

    return true;
}

bool link_list::insert_after(LNode *old_node, LNode *new_node)
{
    if (old_node == nullptr || new_node == nullptr || old_node == new_node) return false;

    new_node->next = old_node->next;
    old_node->next = new_node;

    return true;
}

bool link_list::insert(LinkList list, int index, LNode *node)
{
    auto next = at(list, index);
    if (next == nullptr) return false;
    return insert_before(next, node);
}

bool link_list::remove_at(LinkList list, int index)
{
    if (list == nullptr || index < 0) return false;

    for (auto node = list; node != nullptr && index >= 0; node = node->next, index--)
    {
        if (index == 0)
        {
            auto to_delete = node->next;
            node->next = to_delete->next;
            delete to_delete;

            return true;
        }
    }
    return false;
}

int link_list::length(const LinkList list)
{
    if (list == nullptr) return 0;
    int length = 0;
    for (auto node = list->next; node != nullptr; node = node->next, length++);

    return length;
}

bool link_list::reverse(LinkList list)
{
    if (list == nullptr) return false;

    LNode *cur = list->next;
    for (LNode *prior = nullptr, *next = cur->next; 
         cur->next = prior, next != nullptr; 
         prior = cur, cur = next, next = next->next);
    list->next = cur;
    
    return true;
}

LNode *link_list::at(const LinkList list, int index)
{
    for (auto node = list->next; node != nullptr && index >= 0; node = node->next, index--)
    {
        if (index == 0) return node;
    }
    return nullptr;
}

int link_list::find(const LinkList list, const ElemType &elem)
{
    int index = 0;
    for (auto node = list->next; node != nullptr; node = node->next, index++)
    {
        if (node->data == elem) 
        return index;
    }
    return -1;
}

bool link_list::insert_before(LNode *&old_node, LNode *new_node)
{
    if (old_node == nullptr || new_node == nullptr || old_node == new_node) return false;
    new_node->next = old_node->next;
    old_node->next = new_node;

    ElemType elem;
    elem = old_node->data;
    old_node->data = new_node->data;
    new_node->data = elem;

    old_node = new_node;

    return true;
}

void link_list::print(LinkList list)
{
    std::cout << "link_list: ";
    for (auto node = list->next; node != nullptr; node = node->next)
    {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;
}
