#include<iostream>
#include"Stack.h"
#include"Queue.h"


int main()
{
	Stack<int>stack;
	Queue<int>queue;

	constexpr size_t num = 10;

	for (size_t i = 0; i < num; ++i)
	{
		stack.push(i);
		queue.push(i);
	}

	std::cout << "スタック構造" << std::endl;


	for (size_t i = 0; i < num; ++i)
	{
		int tmp;
		stack.pop(tmp);
		std::cout << tmp << std::endl;
	}

	std::cout << "キュー構造" << std::endl;

	for (size_t i = 0; i < num; ++i)
	{
		int tmp;
		queue.pop(tmp);
		std::cout << tmp << std::endl;
	}

}