#include "dynamic_seq_list.h"
#include <iostream>

int main()
{
    DSeqList list;
    dynamic_seq_list::init(list);
    dynamic_seq_list::print(list);

    dynamic_seq_list::insert(list, 0, 1);
    dynamic_seq_list::insert(list, 0, 2);
    dynamic_seq_list::insert(list, 0, 3);
    dynamic_seq_list::insert(list, 0, 4);
    dynamic_seq_list::insert(list, 0, 5);
    dynamic_seq_list::insert(list, 5, 0);
    dynamic_seq_list::print(list);

    dynamic_seq_list::remove_at(list, 5);
    dynamic_seq_list::print(list);
    dynamic_seq_list::remove_at(list, 0);
    dynamic_seq_list::print(list);

    ElemType elem;
    dynamic_seq_list::at(list, 3, elem);

    std::cout << elem << std::endl;
    std::cout << dynamic_seq_list::find(list, 2) << " " << dynamic_seq_list::find(list, 999) << std::endl;

    for(int i = 0; i < 256; i++)
    {
        dynamic_seq_list::insert(list, list.length, i);
    }

    dynamic_seq_list::print(list);
    dynamic_seq_list::destroy(list);

    dynamic_seq_list::print(list);

    return 0;
}
