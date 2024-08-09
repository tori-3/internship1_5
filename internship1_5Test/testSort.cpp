#include "pch.h"
#include"CheckValue.h"
#include"../internship1_5/List.h"
#include"../internship1_5/Grades.h"

///@brief score�ŏ����ɕ��ׂ邽�߂̔�r�֐��ł��B
///@param left �����̃f�[�^
///@param right �E���̃f�[�^
bool AscendingOrderScore(const Grades& left, const Grades& right)
{
	return left.score < right.score;
};

///@brief score�ō~���ɕ��ׂ邽�߂̔�r�֐��ł��B
///@param left �����̃f�[�^
///@param right �E���̃f�[�^
bool DescendingOrderScore(const Grades& left, const Grades& right)
{
	return left.score > right.score;
};

///@brief name�ŏ����ɕ��ׂ邽�߂̔�r�֐��ł��B
///@param left �����̃f�[�^
///@param right �E���̃f�[�^
bool AscendingOrderName(const Grades& left, const Grades& right)
{
	return left.name < right.name;
};

///@brief name�ō~���ɕ��ׂ邽�߂̔�r�֐��ł��B
///@param left �����̃f�[�^
///@param right �E���̃f�[�^
bool DescendingOrderName(const Grades& left, const Grades& right)
{
	return left.name > right.name;
};

/**********************************************************************************//**
	@brief		�N�C�b�N�\�[�g �v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋���
	@details	ID:���X�g-0\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B
				�G���[�܂߂āA�����N����Ȃ�����ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, Empty)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.sort(AscendingOrderScore);
		CheckValue({}, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.sort(DescendingOrderScore);
		CheckValue({}, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.sort(AscendingOrderName);
		CheckValue({}, list);
	}

	//name�ō~��
	{
		List<Grades>list;
		list.sort(DescendingOrderName);
		CheckValue({}, list);
	}

}

/**********************************************************************************//**
	@brief		�N�C�b�N�\�[�g �v�f��1���������X�g�Ƀ\�[�g�����s�������̋���
	@details	ID:���X�g-1\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B
				�G���[�܂߂āA�����N����Ȃ�����ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, OneElement)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//name�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}
}

/**********************************************************************************//**
	@brief		�N�C�b�N�\�[�g 2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋���
	@details	ID:���X�g-2\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B
				�v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ��ׂΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, MultipleElements)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//name�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		�N�C�b�N�\�[�g �����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋���
	@details	ID:���X�g-3\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B
				�v�f���\�[�g����ĕ��ׂΐ����ł��B(�����v�f�̏����͕ۏ؂���Ȃ��B)\n
*//***********************************************************************************/

TEST(TestListSort, ContainsSameKey)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//name�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		�N�C�b�N�\�[�g ����ς݃��X�g�Ƀ\�[�g�����s�������̋���
	@details	ID:���X�g-4\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B
				�����L�[�̗v�f�̊ԈȊO�̏��Ԃ��ϓ����Ȃ���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, AlignedList)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 0,"hoge" });
		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//name�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		�N�C�b�N�\�[�g ��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋���
	@details	ID:���X�g-5\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B
				�v�f���\�[�g����ĕ��ׂΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, SortedList)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderScore);

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" },Grades{ 3,"bbbb" },Grades{ 4,"aaaa" },Grades{ 5,"cccc" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderScore);

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 5,"cccc" },Grades{ 4,"aaaa" },Grades{ 3,"bbbb" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderName);

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 4,"aaaa" },Grades{ 3,"bbbb" },Grades{ 5,"cccc" },Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//name�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderName);
		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 5,"cccc" },Grades{ 3,"bbbb" },Grades{ 4,"aaaa" } }, list);
	}
}


/**********************************************************************************//**
	@brief		�N�C�b�N�\�[�g �L�[�w������Ȃ�����(nullptr��n����)���̋���
	@details	ID:���X�g-6\n
				�N�C�b�N�\�[�g�̃e�X�g�ł��B
				�G���[�܂߂āA�����N����Ȃ���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, NotSpecifyKey)
{
	List<Grades>list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 2,"piyo" });
	list.add(Grades{ 1,"fuga" });
	list.sort(nullptr);
	CheckValue({ Grades{ 0,"hoge" },Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list);
}
