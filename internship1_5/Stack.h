#pragma once

#include"List.h"

///@brief �X�^�b�N�\���̃N���X�ł��B
///@tparam DataType �X�^�b�N�Ɋi�[����f�[�^�̌^�ł��B
template<typename DataType>
class Stack
{
public:

	///@brief �f�[�^����Ԃ��܂��B
	///@return �f�[�^�̐�
	size_t size()const;

	///@brief �擪�ɗv�f��ǉ����܂��B
	///@param data �ǉ�����f�[�^
	///@return �ǉ��ɐ���������true ���s������false��Ԃ��܂��B
	bool push(const DataType& data);

	///@brief �擪�̗v�f�����o���܂�
	///@param data ���o���f�[�^���󂯎��
	///@return ���o���ɐ���������true ���s������false��Ԃ��܂��B
	bool pop(DataType& data);

	///@brief ���X�g�̐擪�R���X�g�C�e���[�^�[��Ԃ��܂�
	///@return �擪�R���X�g�C�e���[�^�[
	typename List<DataType>::ConstIterator begin()const;

	///@brief ���X�g�̖����R���X�g�C�e���[�^�[��Ԃ��܂�
	///@return �����R���X�g�C�e���[�^�[
	typename List<DataType>::ConstIterator end()const;

private:

	//! �f�[�^�����郊�X�g�ł�
	List<DataType>m_list;

};

#include"Stack.inl"
