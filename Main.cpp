#include "pch.h"
#include <iostream>
#include "forward_list.h"

int main()
{
	List<int> list;
	list.push_front(7);
	list.insert(9, list.begin());
	for (List<int>::Iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << std::ends;
	}
	std::cout << std::endl;
}
