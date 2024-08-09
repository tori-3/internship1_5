#include "pch.h"
#include"../internship1_5/Stack.h"
#include"../internship1_5/Queue.h"

#include"manualTest.h"


/**********************************************************************************//**
	@brief		�X�^�b�N�@�f�[�^���̎擾�@const�̃��\�b�h�ł��邩
	@details	ID:�X�^�b�N-7(�蓮)\n
				�X�^�b�N��size�֐��̃e�X�g�ł��B
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TEST_STACK_SIZE_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestStackSize, IsConst)
{
#ifdef TEST_STACK_SIZE_IS_CONST

	const Stack<int>stack;
	stack.size();

#endif
}

/**********************************************************************************//**
	@brief		�X�^�b�N�@�v�b�V���@��const�̃��\�b�h�ł��邩
	@details	ID:�X�^�b�N-10(�蓮)\n
				�X�^�b�N��push�֐��̃e�X�g�ł��B
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TEST_STACK_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestStackPush, IsNotConst)
{
#ifdef TEST_STACK_PUSH_IS_NOT_CONST

	const Stack<int>stack;
	stack.push(10);

#endif
}

/**********************************************************************************//**
	@brief		�X�^�b�N�@�|�b�v�@��const�̃��\�b�h�ł��邩
	@details	ID:�X�^�b�N-14(�蓮)\n
				�X�^�b�N��pop�֐��̃e�X�g�ł��B
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TEST_STACK_POP_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
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
	@brief		�L���[�@�f�[�^���̎擾�@const�̃��\�b�h�ł��邩
	@details	ID:�L���[-7(�蓮)\n
				�L���[��size�֐��̃e�X�g�ł��B
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TEST_QUEUE_SIZE_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestQueueSize, IsConst)
{
#ifdef TEST_QUEUE_SIZE_IS_CONST

	const Stack<int>stack;
	stack.size();

#endif
}

/**********************************************************************************//**
	@brief		�L���[�@�v�b�V���@��const�̃��\�b�h�ł��邩
	@details	ID:�L���[-10(�蓮)\n
				�L���[��push�֐��̃e�X�g�ł��B
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TEST_QUEUE_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestQueuePush, IsNotConst)
{
#ifdef TEST_QUEUE_PUSH_IS_NOT_CONST

	const Stack<int>stack;
	stack.push(10);

#endif
}

/**********************************************************************************//**
	@brief		�L���[�@�|�b�v�@��const�̃��\�b�h�ł��邩
	@details	ID:�L���[-14(�蓮)\n
				�L���[��pop�֐��̃e�X�g�ł��B
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TEST_QUEUE_POP_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestQueuePop, IsNotConst)
{
#ifdef TEST_QUEUE_POP_IS_NOT_CONST

	const Stack<int>stack;
	int temp;
	stack.pop(temp);

#endif
}
