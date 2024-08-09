#include "pch.h"
#include"CheckValue.h"
#include"../internship1_5/List.h"
#include"../internship1_5/Grades.h"

//���X�g�̃e�X�g

//�f�[�^���̎擾

//���X�g����ł���ꍇ�̖߂�l
TEST(TestListSize, Empty)
{
	List<Grades> list;
	EXPECT_EQ(0, list.size());
}

//���X�g�����ւ̑}�����s�����ۂ̖߂�l
TEST(TestListSize, Add)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_EQ(1, list.size());
}

//�f�[�^�̑}�����s�����ۂ̖߂�l
TEST(TestListSize, Insert)
{
	List<Grades> list;
	list.insert(list.begin(), Grades{ 0,"hoge" });
	EXPECT_EQ(1, list.size());
}

//�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
TEST(TestListSize, FailInsert)
{
	List<Grades> list;
	list.insert(List<Grades>::Iterator{}, Grades{ 0,"hoge" });
	EXPECT_EQ(0, list.size());
}

//�f�[�^�̍폜���s�����ۂ̖߂�l
TEST(TestListSize, Remove)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.remove(list.begin());
	EXPECT_EQ(0, list.size());
}

//�f�[�^�̍폜�����s�����ۂ̖߂�l
TEST(TestListSize, FailRemove)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.remove(List<Grades>::Iterator{});
	EXPECT_EQ(1, list.size());
}

//���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
TEST(TestListSize, RemoveWhenEmpty)
{
	List<Grades> list;
	list.remove(list.begin());
	EXPECT_EQ(0, list.size());
}

//�f�[�^�̑}��

//���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
TEST(TestListInsert, Empty)
{

	//�擪�C�e���[�^�ő}��
	{
		List<Grades> list;
		EXPECT_TRUE(list.insert(list.begin(), Grades{ 0,"hoge" }));
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//�����C�e���[�^�ő}��
	{
		List<Grades> list;
		EXPECT_TRUE(list.insert(list.end(), Grades{ 0,"hoge" }));
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
TEST(TestListInsert, InsertBegin)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.begin(), Grades{ 2,"piyo" }));
	CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋���
TEST(TestListInsert, InsertEnd)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.end(), Grades{ 2,"piyo" }));
	CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
TEST(TestListInsert, InsertCenter)
{

	//�擪�ɒǉ�
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_TRUE(list.insert(list.begin(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

	//�����ɒǉ�
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_TRUE(list.insert(list.end(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//�r���ɒǉ�
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		EXPECT_TRUE(list.insert(iterator, Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list);
	}
}

//ConstIterator���w�肵�đ}�����s�����ۂ̋���
TEST(TestListInsert, InsertConstIterator)
{

	//�擪�ɒǉ�
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_TRUE(list.insert(list.constBegin(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

	//�����ɒǉ�
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_TRUE(list.insert(list.constEnd(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}
	//�r���ɒǉ�
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.constBegin();
		++iterator;
		EXPECT_TRUE(list.insert(iterator, Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list);
	}
}

//�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
TEST(TestListInsert, InsertInvalidIterator)
{
	//�Q�Ƃ̖����C�e���[�^�[
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		EXPECT_FALSE(list.insert(List<Grades>::Iterator{}, Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

	//�ʂ̃��X�g�̃C�e���[�^�[
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });

		List<Grades> otherList;
		otherList.add(Grades{ 2,"piyo" });

		EXPECT_FALSE(list.insert(otherList.begin(), Grades{ 2,"piyo" }));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

}


//�f�[�^�̍폜

//���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
TEST(TestListRemove, Empty)
{
	//�擪�C�e���[�^�[�ō폜
	{
		List<Grades> list;
		EXPECT_FALSE(list.remove(list.begin()));
		CheckValue({ }, list);
	}

	//�����C�e���[�^�[�ō폜
	{
		List<Grades> list;
		EXPECT_FALSE(list.remove(list.end()));
		CheckValue({ }, list);
	}
}


//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
TEST(TestListRemove, RemoveBegin)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.remove(list.begin()));
	CheckValue({ Grades{ 1,"fuga" } }, list);
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
TEST(TestListRemove, RemoveEnd)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_FALSE(list.remove(list.end()));
	CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
TEST(TestListRemove, RemoveCenter)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });

	auto iterator = list.begin();
	++iterator;
	EXPECT_TRUE(list.remove(iterator));
	CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
}

//ConstIterator���w�肵�č폜���s�����ۂ̋���
TEST(TestListRemove, RemoveConstIterator)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });

	auto iterator = list.constBegin();
	++iterator;
	EXPECT_TRUE(list.remove(iterator));
	CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
}

//�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
TEST(TestListRemove, RemoveInvalidIterator)
{
	//�Q�Ƃ̖����C�e���[�^�[
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });

		EXPECT_FALSE(list.remove(List<Grades>::Iterator{}));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}

	//���̃��X�g�̃C�e���[�^�[
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });

		List<Grades> otherList;
		otherList.add(Grades{ 2,"piyo" });

		EXPECT_FALSE(list.remove(otherList.begin()));
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}
}

//�擪�C�e���[�^�̎擾

//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, Empty)
{
	List<Grades> list;
	EXPECT_EQ(list.begin(), list.end());
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, OneElement)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, MultipleElements)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, AfterInsert)
{
	//�擪�ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.begin(), Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.begin() == Grades{ 2,"piyo" }));
	}

	//�����ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.end(), Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
	}

	//�r���ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		list.insert(iterator, Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
	}
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, AfterRemove)
{
	//�擪���폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.remove(list.begin());
		EXPECT_TRUE((*list.begin() == Grades{ 1,"fuga" }));
	}

	//�������폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		list.remove(it);
		EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
	}

	//�r�����폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto iterator = list.begin();
		++iterator;
		list.remove(iterator);
		EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
	}
}


//�擪�R���X�g�C�e���[�^�̎擾

//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstBegin, Empty)
{
	List<Grades> list;
	EXPECT_EQ(list.constBegin(), list.constEnd());
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstBegin, OneElement)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstBegin, MultipleElements)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(TestListConstBegin, AfterInsert)
{
	//�擪�ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.begin(), Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.constBegin() == Grades{ 2,"piyo" }));
	}

	//�����ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.end(), Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
	}

	//�r���ɑ}�� 
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		list.insert(iterator, Grades{ 2,"piyo" });
		EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
	}

}


//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(TestListConstBegin, AfterRemove)
{
	//�擪���폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.remove(list.begin());
		EXPECT_TRUE((*list.constBegin() == Grades{ 1,"fuga" }));
	}

	//�������폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		list.remove(it);
		EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
	}

	//�r�����폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto iterator = list.begin();
		++iterator;
		list.remove(iterator);
		EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
	}
}


//�����C�e���[�^�̎擾

//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListEnd, Empty)
{
	List<Grades> list;
	EXPECT_EQ(list.end(), list.begin());
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListEnd, OneElement)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 0,"hoge" }));
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListEnd, MultipleElements)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(TestListEnd, AfterInsert)
{
	//�擪�ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.begin(), Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}

	//�����ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.end(), Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}

	//�r���ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		list.insert(iterator, Grades{ 2,"piyo" });
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}
}


//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(TestListEnd, AfterRemove)
{

	//�擪���폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.remove(list.begin());
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}

	//�������폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto endIt = list.end();
		--endIt;
		list.remove(endIt);
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}

	//�r�����폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto iterator = list.begin();
		++iterator;
		list.remove(iterator);
		auto it = list.end();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}
}

//�����R���X�g�C�e���[�^�̎擾

//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstEnd, Empty)
{
	List<Grades> list;
	EXPECT_EQ(list.constEnd(), list.constBegin());
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstEnd, OneElement)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 0,"hoge" }));
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstEnd, MultipleElements)
{
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(TestListConstEnd, AfterInsert)
{
	//�擪�ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.begin(), Grades{ 2,"piyo" });
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}

	//����ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.insert(list.end(), Grades{ 2,"piyo" });
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}

	//�r���ɑ}��
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		auto iterator = list.begin();
		++iterator;
		list.insert(iterator, Grades{ 2,"piyo" });
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}
}

//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
TEST(TestListConstEnd, AfterRemove)
{
	//�擪���폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.remove(list.begin());
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}

	//�������폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto endIt = list.end();
		--endIt;
		list.remove(endIt);
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
	}

	//�r�����폜
	{
		List<Grades> list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		auto iterator = list.begin();
		++iterator;
		list.remove(iterator);
		auto it = list.constEnd();
		--it;
		EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
	}
}

//�C�e���[�^�[�̃e�X�g

//�C�e���[�^�̎w���v�f���擾����

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestIteratorGetElement, NoReferences)
{
#ifdef _DEBUG
	List<Grades>::Iterator it;
	EXPECT_DEATH((*it).score, ".*");
#endif
}

//Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
TEST(TestIteratorGetElement, AssignValue)
{
#ifdef _DEBUG
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.begin();
	(*it) = Grades{ 1,"fuga" };

	EXPECT_TRUE(((*it) == Grades{ 1,"fuga" }));
#endif
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIteratorGetElement, BeginIteratorWhenEmpty)
{
#ifdef _DEBUG
	List<Grades> list;
	EXPECT_DEATH((*list.begin()).score, ".*");
#endif
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIteratorGetElement, EndIterator)
{
#ifdef _DEBUG
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_DEATH((*list.end()).score, ".*");
#endif
}


//�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestIteratorIncrement, NoReferences)
{
#ifdef _DEBUG
	List<Grades>::Iterator it;
	EXPECT_DEATH(++it, ".*");
#endif
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIteratorIncrement, BeginIteratorWhenEmpty)
{
#ifdef _DEBUG
	List<Grades> list;
	auto it = list.begin();
	EXPECT_DEATH(++it, ".*");
#endif
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIteratorIncrement, EndIterator)
{
#ifdef _DEBUG
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.end();
	EXPECT_DEATH(++it, ".*");
#endif
}


//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(TestIteratorIncrement, MultipleElements)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });
	list.add({ 2,"piyo" });

	std::vector<Grades>ans{ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } };

	size_t i = 0;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		EXPECT_TRUE((*it == ans[i]));
		++i;
	}
}

//�O�u�C���N�������g���s�����ۂ̋���(++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ)
TEST(TestIteratorIncrement, PrefaceIncrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	EXPECT_TRUE((*(++it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(TestIteratorIncrement, PostfixIncrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	EXPECT_TRUE((*(it++) == Grades{ 0,"hoge" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


//�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestIteratorDecrement, NoReferences)
{
#ifdef _DEBUG
	List<Grades>::Iterator it;
	EXPECT_DEATH(--it, ".*");
#endif
}

//���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIteratorDecrement, EndIteratorWhenEmpty)
{
#ifdef _DEBUG
	List<Grades> list;
	auto it = list.end();
	EXPECT_DEATH(--it, ".*");
#endif
}

//�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIteratorDecrement, BeginIterator)
{
#ifdef _DEBUG
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.begin();
	EXPECT_DEATH(--it, ".*");
#endif
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(TestIteratorDecrement, MultipleElements)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });
	list.add({ 2,"piyo" });

	std::vector<Grades>ans{ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } };

	auto it = list.end();

	for (size_t i = 0; i < list.size(); ++i)
	{
		--it;
		EXPECT_TRUE((*it == ans[i]));
	}

}

//�O�u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ)
TEST(TestIteratorDecrement, PrefixDecrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	EXPECT_TRUE((*(--it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//��u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(TestIteratorDecrement, PostfixDecrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	it--;
	EXPECT_TRUE(((*(it--)) == Grades{ 1,"fuga" }));
	EXPECT_TRUE(((*it) == Grades{ 0,"hoge" }));
}



//�C�e���[�^�̃R�s�[���s��


//�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(TestIteratorCopy, CheckCopy)
{
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.begin();

	auto itCopy = it;

	EXPECT_TRUE(itCopy == it);
}

//�C�e���[�^�̑�����s��

//�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(TestIteratorAssign, CheckAssign)
{
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.begin();
	List<Grades>::Iterator itCopy;
	itCopy = it;

	EXPECT_TRUE(itCopy == it);
}

//��̃C�e���[�^������̂��̂ł��邩�A��r���s��


//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(TestIteratorEqual, CompareBeginAndEndWhenEmpty)
{
	List<Grades> list;
	EXPECT_TRUE(list.begin() == list.end());
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(TestIteratorEqual, CompareSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	EXPECT_TRUE(list.begin() == list.begin());
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(TestIteratorEqual, CompareNotSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_FALSE(itA == itB);
}



//��̃C�e���[�^���قȂ���̂ł��邩�A��r���s��


//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(TestIteratorNotEqual, CompareBeginAndEndWhenEmpty)
{
	List<Grades> list;
	EXPECT_FALSE(list.begin() != list.end());
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(TestIteratorNotEqual, CompareSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	EXPECT_FALSE(list.begin() != list.begin());
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(TestIteratorNotEqual, CompareNotSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_TRUE(itA != itB);
}



//�R���X�g�C�e���[�^�[�̃e�X�g

//�C�e���[�^�̎w���v�f���擾����

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestConstIteratorGetElement, NoReferences)
{
#ifdef _DEBUG
	List<Grades>::ConstIterator it;
	EXPECT_DEATH((*it).score, ".*");
#endif
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIteratorGetElement, BeginIteratorWhenEmpty)
{
#ifdef _DEBUG
	List<Grades> list;
	EXPECT_DEATH((*list.constBegin()).score, ".*");
#endif
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIteratorGetElement, EndIterator)
{
#ifdef _DEBUG
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_DEATH((*list.constEnd()).score, ".*");
#endif
}


//�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�


//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestConstIteratorIncrement, NoReferences)
{
#ifdef _DEBUG
	List<Grades>::ConstIterator it;
	EXPECT_DEATH(++it, ".*");
#endif
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIteratorIncrement, BeingIteratorWhenEmpty)
{
#ifdef _DEBUG
	List<Grades> list;
	auto it = list.constBegin();
	EXPECT_DEATH(++it, ".*");
#endif
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIteratorIncrement, EndIterator)
{
#ifdef _DEBUG
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.constEnd();
	EXPECT_DEATH(++it, ".*");
#endif
}



//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(TestConstIteratorIncrement, MultipleElements)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	++it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�O�u�C���N�������g���s�����ۂ̋���(++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ)
TEST(TestConstIteratorIncrement, PrefixIncrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	EXPECT_TRUE((*(++it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(TestConstIteratorIncrement, PostfixIncrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	EXPECT_TRUE((*(it++) == Grades{ 0,"hoge" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


//�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestConstIteratorDecrement, NoReferences)
{
#ifdef _DEBUG
	List<Grades>::ConstIterator it;
	EXPECT_DEATH(--it, ".*");
#endif
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIteratorDecrement, BeingIteratorWhenEmpty)
{
#ifdef _DEBUG
	List<Grades> list;
	auto it = list.constEnd();
	EXPECT_DEATH(--it, ".*");
#endif
}

//�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIteratorDecrement, BeingIterator)
{
#ifdef _DEBUG
	List<Grades> list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.constBegin();
	EXPECT_DEATH(--it, ".*");
#endif
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(TestConstIteratorDecrement, MultipleElements)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�O�u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ)
TEST(TestConstIteratorDecrement, PrefixDecrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	EXPECT_TRUE((*(--it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////��u�f�N�������g���s�����ۂ̋���( --���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(TestConstIteratorDecrement, PostfixDecrement)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	it--;
	EXPECT_TRUE(((*(it--)) == Grades{ 1,"fuga" }));
	EXPECT_TRUE(((*it) == Grades{ 0,"hoge" }));
}




//�C�e���[�^�̃R�s�[���s��

//�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(TestConstIteratorCopy, CheckCopy)
{
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.constBegin();

	auto itCopy = it;

	EXPECT_TRUE(itCopy == it);
}


//�C�e���[�^�̑�����s��

//�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(TestConstIteratorAssign, CheckAssign)
{
	List<Grades> list;
	list.add({ 0,"hoge" });

	auto it = list.constBegin();
	List<Grades>::ConstIterator itCopy;
	itCopy = it;

	EXPECT_TRUE(itCopy == it);
}


//��̃C�e���[�^������̂��̂ł��邩�A��r���s��


//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(TestConstIteratorEqual, CompareBeginAndEndWhenEmpty)
{
	List<Grades> list;
	EXPECT_TRUE(list.constBegin() == list.constEnd());
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(TestConstIteratorEqual, CompareSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	EXPECT_TRUE(list.constBegin() == list.constBegin());
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(TestConstIteratorEqual, CompareNotSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_FALSE(itA == itB);
}



//��̃C�e���[�^���قȂ���̂ł��邩�A��r���s��


//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(TestConstIteratorNotEqual, CompareBeginAndEndWhenEmpty)
{
	List<Grades> list;
	EXPECT_FALSE(list.constBegin() != list.constEnd());
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(TestConstIteratorNotEqual, CompareSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	EXPECT_FALSE(list.constBegin() != list.constBegin());
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(TestConstIteratorNotEqual, CompareNotSame)
{
	List<Grades> list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_TRUE(itA != itB);
}
