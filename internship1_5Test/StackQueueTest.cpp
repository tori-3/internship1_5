#include "pch.h"
#include"CheckValue.h"
#include"../internship1_5/Stack.h"
#include"../internship1_5/Queue.h"

///@brief ���X�g�̓��e�������Ɠ��������m�F���܂�
///@param ans ������vector�Ƃ��ēn���܂�
///@param stack ���e�������������ׂ����X�^�b�N��n���܂�
void CheckValue(const std::vector<int>& ans, Stack<int>& stack)
{
	EXPECT_TRUE(ans.size() == stack.size());

	size_t i = 0;
	while (0 < stack.size())
	{
		int temp;

		stack.pop(temp);
		EXPECT_EQ(temp, ans[i]);

		++i;
	}
}

///@brief ���X�g�̓��e�������Ɠ��������m�F���܂�
///@param ans ������vector�Ƃ��ēn���܂�
///@param queue ���e�������������ׂ����L���[��n���܂�
void CheckValue(const std::vector<int>& ans, Queue<int>& queue)
{
	EXPECT_TRUE(ans.size() == queue.size());

	size_t i = 0;
	while (0 < queue.size())
	{
		int temp;

		queue.pop(temp);
		EXPECT_EQ(temp, ans[i]);

		++i;
	}
}

//==================================== �X�^�b�N�\�� ====================================

//=================================== �f�[�^���̎擾 ===================================

/**********************************************************************************//**
	@brief		���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
	@details	ID:�X�^�b�N-0\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestStackSize, Empty)
{
	Stack<int>stack;
	EXPECT_EQ(0,stack.size());
}

/**********************************************************************************//**
	@brief		�v�f���v�b�V��������̃f�[�^���̎擾�e�X�g
	@details	ID:�X�^�b�N-1\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�f���v�b�V��������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����1�ł���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestStackSize, AfterPush)
{
	Stack<int>stack;
	ASSERT_TRUE(stack.push(0));
	EXPECT_EQ(1, stack.size());
}

/**********************************************************************************//**
	@brief		�v�f���|�b�v������̃f�[�^���̎擾�e�X�g
	@details	ID:�X�^�b�N-2\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�f���|�b�v������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestStackSize, AfterPop)
{
	Stack<int>stack;
	int temp;
	ASSERT_TRUE(stack.push(0));
	ASSERT_TRUE(stack.pop(temp));
	EXPECT_EQ(0, stack.size());
}

/**********************************************************************************//**
	@brief		�v�f�̃v�b�V���Ɏ��s������̃f�[�^���̎擾�e�X�g
	@details	ID:�X�^�b�N-3\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�f�̃v�b�V���Ɏ��s������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestStackSize, AfterPopFailure)
{
	//�v�b�V���̓������[�A���P�[�V�����G���[�ȊO�Ŏ��s����\�����Ȃ��̂ŃX�L�b�v����
	//Stack<int>stack;
	//ASSERT_FALSE(stack.push(0));
	//EXPECT_EQ(0, stack.size());
}

/**********************************************************************************//**
	@brief		�v�b�V����2��s������̃f�[�^���̎擾�e�X�g
	@details	ID:�X�^�b�N-4\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�b�V����2��s������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����2�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackSize, After2Push)
{
	Stack<int>stack;
	ASSERT_TRUE(stack.push(0));
	ASSERT_TRUE(stack.push(1));
	EXPECT_EQ(2, stack.size());
}

/**********************************************************************************//**
	@brief		�v�b�V����2��s������A�P��|�b�v������̃f�[�^���̎擾�e�X�g
	@details	ID:�X�^�b�N-5\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�b�V����2��s������A�P��|�b�v������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����1�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackSize, After2Push1Pop)
{
	Stack<int>stack;
	int temp;
	ASSERT_TRUE(stack.push(0));
	ASSERT_TRUE(stack.push(1));
	ASSERT_TRUE(stack.pop(temp));
	EXPECT_EQ(1, stack.size());
}

/**********************************************************************************//**
	@brief		���X�g����ł���ꍇ�ɁA�|�b�v���s������̃f�[�^���̎擾�e�X�g
	@details	ID:�X�^�b�N-6\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackSize, AfterPopFromEmpty)
{
	Stack<int>stack;
	int temp;
	ASSERT_FALSE(stack.pop(temp));
	EXPECT_EQ(0, stack.size());
}

//====================================== �v�b�V�� ======================================

/**********************************************************************************//**
	@brief		���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̃v�b�V���̋����e�X�g
	@details	ID:�X�^�b�N-8\n
				�v�b�V���@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̃v�b�V���̖߂�l��\n
				�v�b�V����̃X�^�b�N�̓��e���m�F���Ă��܂��B\n
				�߂�l��TRUE�ŃX�^�b�N�̓��e����������ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestStackPush, Empty)
{
	Stack<int>stack;
	EXPECT_TRUE(stack.push(0));
	CheckValue({0}, stack);
}

/**********************************************************************************//**
	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̃v�b�V���̋����e�X�g
	@details	ID:�X�^�b�N-9\n
				�v�b�V���@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̃v�b�V���̖߂�l��\n
				�v�b�V����̃X�^�b�N�̓��e���m�F���Ă��܂��B\n
				�߂�l��TRUE�ŃX�^�b�N�̓��e����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackPush, MultipleElements)
{
	Stack<int>stack;
	EXPECT_TRUE(stack.push(0));
	EXPECT_TRUE(stack.push(1));
	EXPECT_TRUE(stack.push(2));
	CheckValue({ 2,1,0 }, stack);
}

//======================================= �|�b�v =======================================

/**********************************************************************************//**
	@brief		���X�g����ł���ꍇ�ɁA�|�b�v���������ۂ̃|�b�v�̋����e�X�g
	@details	ID:�X�^�b�N-11\n
				�|�b�v�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�|�b�v���������ۂ̃|�b�v�̖߂�l��\n
				�|�b�v��̃X�^�b�N�̓��e���m�F���Ă��܂��B\n
				�߂�l��FALSE�ŃX�^�b�N�̓��e����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackPop, Empty)
{
	Stack<int>stack;
	int temp = 1;
	EXPECT_FALSE(stack.pop(temp));
	CheckValue({}, stack);
	EXPECT_EQ(1, temp);
}

/**********************************************************************************//**
	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̃|�b�v�̋����e�X�g
	@details	ID:�X�^�b�N-12\n
				�|�b�v�@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̃|�b�v�̖߂�l��\n
				�|�b�v��̃X�^�b�N�̓��e�A�擾�����l�̓��e���m�F���Ă��܂��B\n
				�߂�l��TRUE�ŃX�^�b�N�̓��e�A�擾�������e����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackPop, MultipleElements)
{
	Stack<int>stack;
	ASSERT_TRUE(stack.push(0));
	ASSERT_TRUE(stack.push(1));
	ASSERT_TRUE(stack.push(2));
	int temp;
	EXPECT_TRUE(stack.pop(temp));
	EXPECT_EQ(2,temp);
	CheckValue({1,0}, stack);
}

/**********************************************************************************//**
	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̃|�b�v�̋����e�X�g
	@details	ID:�X�^�b�N-13\n
				�|�b�v�@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̃|�b�v�̖߂�l��\n
				�|�b�v��̃X�^�b�N�̓��e�A�擾�����l�̓��e���m�F���Ă��܂��B\n
				�߂�l��TRUE�ŃX�^�b�N�̓��e�A�擾�������e����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackPop, PopMultipleTimes)
{
	constexpr size_t num = 3;

	Stack<int>stack;
	for (size_t i = 0; i < num; ++i)
	{
		ASSERT_TRUE(stack.push(i));
	}

	for (size_t i = 0; i < num; ++i)
	{
		int temp;
		EXPECT_TRUE(stack.pop(temp));
		EXPECT_EQ(num-1-i,temp);
	}

	CheckValue({}, stack);
}



//==================================== �L���[�\�� ====================================

//=================================== �f�[�^���̎擾 ===================================

/**********************************************************************************//**
	@brief		���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
	@details	ID:�L���[-0\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestQueueSize, Empty)
{
	Queue<int>queue;
	EXPECT_EQ(0, queue.size());
}

/**********************************************************************************//**
	@brief		�v�f���v�b�V��������̃f�[�^���̎擾�e�X�g
	@details	ID:�L���[-1\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�f���v�b�V��������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����1�ł���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestQueueSize, AfterPush)
{
	Queue<int>queue;
	ASSERT_TRUE(queue.push(0));
	EXPECT_EQ(1, queue.size());
}

/**********************************************************************************//**
	@brief		�v�f���|�b�v������̃f�[�^���̎擾�e�X�g
	@details	ID:�L���[-2\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�f���|�b�v������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestQueueSize, AfterPop)
{
	Queue<int>queue;
	int temp;
	ASSERT_TRUE(queue.push(0));
	ASSERT_TRUE(queue.pop(temp));
	EXPECT_EQ(0, queue.size());
}

/**********************************************************************************//**
	@brief		�v�f�̃v�b�V���Ɏ��s������̃f�[�^���̎擾�e�X�g
	@details	ID:�L���[-3\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�f�̃v�b�V���Ɏ��s������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestQueueSize, AfterPopFailure)
{
	//�v�b�V���̓������[�A���P�[�V�����G���[�ȊO�Ŏ��s����\�����Ȃ��̂ŃX�L�b�v����
	//Queue<int>queue;
	//ASSERT_FALSE(queue.push(0));
	//EXPECT_EQ(0, queue.size());
}

/**********************************************************************************//**
	@brief		�v�b�V����2��s������̃f�[�^���̎擾�e�X�g
	@details	ID:�L���[-4\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�b�V����2��s������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����2�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueueSize, After2Push)
{
	Queue<int>queue;
	ASSERT_TRUE(queue.push(0));
	ASSERT_TRUE(queue.push(1));
	EXPECT_EQ(2, queue.size());
}

/**********************************************************************************//**
	@brief		�v�b�V����2��s������A�P��|�b�v������̃f�[�^���̎擾�e�X�g
	@details	ID:�L���[-5\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				�v�b�V����2��s������A�P��|�b�v������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����1�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueueSize, After2Push1Pop)
{
	Queue<int>queue;
	int temp;
	ASSERT_TRUE(queue.push(0));
	ASSERT_TRUE(queue.push(1));
	ASSERT_TRUE(queue.pop(temp));
	EXPECT_EQ(1, queue.size());
}

/**********************************************************************************//**
	@brief		���X�g����ł���ꍇ�ɁA�|�b�v���s������̃f�[�^���̎擾�e�X�g
	@details	ID:�L���[-6\n
				�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l���m�F���Ă��܂��B\n
				�f�[�^����0�ł���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueueSize, AfterPopFromEmpty)
{
	Queue<int>queue;
	int temp;
	ASSERT_FALSE(queue.pop(temp));
	EXPECT_EQ(0, queue.size());
}

//====================================== �v�b�V�� ======================================

/**********************************************************************************//**
	@brief		���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̃v�b�V���̋����e�X�g
	@details	ID:�L���[-8\n
				�v�b�V���@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̃v�b�V���̖߂�l��\n
				�v�b�V����̃L���[�̓��e���m�F���Ă��܂��B\n
				�߂�l��TRUE�ŃL���[�̓��e����������ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestQueuePush, Empty)
{
	Queue<int>queue;
	EXPECT_TRUE(queue.push(0));
	CheckValue({ 0 }, queue);
}

/**********************************************************************************//**
	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̃v�b�V���̋����e�X�g
	@details	ID:�L���[-9\n
				�v�b�V���@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̃v�b�V���̖߂�l��\n
				�v�b�V����̃L���[�̓��e���m�F���Ă��܂��B\n
				�߂�l��TRUE�ŃL���[�̓��e����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueuePush, MultipleElements)
{
	Queue<int>queue;
	EXPECT_TRUE(queue.push(0));
	EXPECT_TRUE(queue.push(1));
	EXPECT_TRUE(queue.push(2));
	CheckValue({ 0,1,2 }, queue);
}

//======================================= �|�b�v =======================================

/**********************************************************************************//**
	@brief		���X�g����ł���ꍇ�ɁA�|�b�v���������ۂ̃|�b�v�̋����e�X�g
	@details	ID:�L���[-11\n
				�|�b�v�@�\�̃e�X�g�ł��B\n
				���X�g����ł���ꍇ�ɁA�|�b�v���������ۂ̃|�b�v�̖߂�l��\n
				�|�b�v��̃L���[�̓��e���m�F���Ă��܂��B\n
				�߂�l��FALSE�ŃL���[�̓��e����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueuePop, Empty)
{
	Queue<int>queue;
	int temp = 1;
	EXPECT_FALSE(queue.pop(temp));
	CheckValue({}, queue);
	EXPECT_EQ(1, temp);
}

/**********************************************************************************//**
	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̃|�b�v�̋����e�X�g
	@details	ID:�L���[-12\n
				�|�b�v�@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̃|�b�v�̖߂�l��\n
				�|�b�v��̃L���[�̓��e�A�擾�����l�̓��e���m�F���Ă��܂��B\n
				�߂�l��TRUE�ŃL���[�̓��e�A�擾�������e����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueuePop, MultipleElements)
{
	Queue<int>queue;
	ASSERT_TRUE(queue.push(0));
	ASSERT_TRUE(queue.push(1));
	ASSERT_TRUE(queue.push(2));
	int temp;
	EXPECT_TRUE(queue.pop(temp));
	EXPECT_EQ(0, temp);
	CheckValue({ 1,2 }, queue);
}

/**********************************************************************************//**
	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̃|�b�v�̋����e�X�g
	@details	ID:�L���[-13\n
				�|�b�v�@�\�̃e�X�g�ł��B\n
				���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̃|�b�v�̖߂�l��\n
				�|�b�v��̃L���[�̓��e�A�擾�����l�̓��e���m�F���Ă��܂��B\n
				�߂�l��TRUE�ŃL���[�̓��e�A�擾�������e����������ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueuePop, PopMultipleTimes)
{
	constexpr size_t num = 3;

	Queue<int>queue;
	for (size_t i = 0; i < num; ++i)
	{
		ASSERT_TRUE(queue.push(i));
	}

	for (size_t i = 0; i < num; ++i)
	{
		int temp;
		EXPECT_TRUE(queue.pop(temp));
		EXPECT_EQ(i, temp);
	}

	CheckValue({}, queue);
}

