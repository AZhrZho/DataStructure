#include "seq_list.h"
#include <cstring>
#include <iostream>

struct static_seq_list::list
{
	ElemType data[MAXSIZE];
	int length;
};

static_seq_list::list& static_seq_list::init_list()
{
	auto list = new static_seq_list::list;
	std::memset(list->data, 0, sizeof(ElemType) * MAXSIZE);
	list->length = 0;
	return *list;
}

void static_seq_list::destroy_list(list& list)
{
	list.length = 0;
	delete& list;
}

bool static_seq_list::insert(list& list, int index, ElemType elem)
{
	// list is full
	if (list.length >= MAXSIZE) return false;
	// index out of range
	if (index < 0 || index > list.length) return false;

	for (int i = list.length; i > index; --i)
	{
		list.data[i] = list.data[i - 1];
	}

	list.data[index] = elem;
	++list.length;

	return true;
}

bool static_seq_list::push_back(list& list, ElemType elem)
{
	return insert(list, list.length, elem);
}

bool static_seq_list::remove_at(list& list, int index)
{
	// index out of range
	if (index < 0 || index >= list.length) return false;
	
	for (int i = index; i < list.length - 1; ++i)
	{
		list.data[i] = list.data[i + 1];
	}

	--list.length;

	return true;
}

bool static_seq_list::get(const list& list, int index, ElemType& result)
{
	// index out of range
	if (index < 0 || index >= list.length) return false;
	
	result = list.data[index];
	return true;
}

bool static_seq_list::get_mut(const list& list, int index, ElemType_P& pResult)
{
	// index out of range
	if (index < 0 || index >= list.length) return false;

	pResult = const_cast<ElemType_P>(list.data + index);
	return true;
}

int static_seq_list::length(const list& list)
{
	return list.length;
}

int static_seq_list::find(const list& list, const ElemType& elem)
{
	for (int i = 0; i < list.length; ++i)
	{
		if (list.data[i] == elem) return i;
	}

	return -1;
}

void static_seq_list::print_list(const list& list)
{
	std::cout << "list(" << list.length << ")" << ": ";
	for (int i = 0; i < list.length; ++i)
	{
		std::cout << list.data[i] << ' ';
	}
	std::cout << std::endl;
}
