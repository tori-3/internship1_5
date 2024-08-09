#include "pch.h"
#include"../internship1_5/Stack.h"
#include"../internship1_5/Queue.h"

#include"manualTest.h"


/**********************************************************************************//**
	@brief		スタック　データ数の取得　constのメソッドであるか
	@details	ID:スタック-7(手動)\n
				スタックのsize関数のテストです。
				有効にしてコンパイルが通れば成功です。\n
				TEST_STACK_SIZE_IS_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestStackSize, IsConst)
{
#ifdef TEST_STACK_SIZE_IS_CONST

	const Stack<int>stack;
	stack.size();

#endif
}

/**********************************************************************************//**
	@brief		スタック　プッシュ　非constのメソッドであるか
	@details	ID:スタック-10(手動)\n
				スタックのpush関数のテストです。
				有効にしてコンパイルエラーになれば成功です。\n
				TEST_STACK_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestStackPush, IsNotConst)
{
#ifdef TEST_STACK_PUSH_IS_NOT_CONST

	const Stack<int>stack;
	stack.push(10);

#endif
}

/**********************************************************************************//**
	@brief		スタック　ポップ　非constのメソッドであるか
	@details	ID:スタック-14(手動)\n
				スタックのpop関数のテストです。
				有効にしてコンパイルエラーになれば成功です。\n
				TEST_STACK_POP_IS_NOT_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestStackPop, IsNotConst)
{
#ifdef TEST_STACK_POP_IS_NOT_CONST

	const Stack<int>stack;
	int temp;
	stack.pop(temp);

#endif
}

/**********************************************************************************//**
	@brief		キュー　データ数の取得　constのメソッドであるか
	@details	ID:キュー-7(手動)\n
				キューのsize関数のテストです。
				有効にしてコンパイルが通れば成功です。\n
				TEST_QUEUE_SIZE_IS_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestQueueSize, IsConst)
{
#ifdef TEST_QUEUE_SIZE_IS_CONST

	const Stack<int>stack;
	stack.size();

#endif
}

/**********************************************************************************//**
	@brief		キュー　プッシュ　非constのメソッドであるか
	@details	ID:キュー-10(手動)\n
				キューのpush関数のテストです。
				有効にしてコンパイルエラーになれば成功です。\n
				TEST_QUEUE_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestQueuePush, IsNotConst)
{
#ifdef TEST_QUEUE_PUSH_IS_NOT_CONST

	const Stack<int>stack;
	stack.push(10);

#endif
}

/**********************************************************************************//**
	@brief		キュー　ポップ　非constのメソッドであるか
	@details	ID:キュー-14(手動)\n
				キューのpop関数のテストです。
				有効にしてコンパイルエラーになれば成功です。\n
				TEST_QUEUE_POP_IS_NOT_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestQueuePop, IsNotConst)
{
#ifdef TEST_QUEUE_POP_IS_NOT_CONST

	const Stack<int>stack;
	int temp;
	stack.pop(temp);

#endif
}
