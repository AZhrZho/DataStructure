#pragma once

#include "../type.h"

typedef struct LNode
{
    struct LNode* next;
    ElemType data;
} LNode, *LinkList;

namespace link_list
{
    LinkList alloc_new();
    void destroy(LinkList &list);
    LNode* create_node(const ElemType &elem);
    bool head_insert(const LinkList list, LNode *node);
    LNode* at(const LinkList list, int index);
    int find(const LinkList list, const ElemType &elem);
    bool insert_before(LNode *&old_node, LNode *new_node);
    bool insert_after(LNode *old_node, LNode *new_node);
    bool insert(LinkList list, int index, LNode *node);
    bool remove_at(LinkList list, int index);
    int length(const LinkList list);

    bool reverse(LinkList list);

    void print(LinkList list);
}