#pragma once

#include"List.h"

///@brief �L���[�\���̃N���X�ł��B
///@tparam DataType �L���[�Ɋi�[����f�[�^�̌^�ł��B
template<typename DataType>
class Queue
{
public:

	///@brief �f�[�^����Ԃ��܂��B
	///@return �f�[�^�̐�
	size_t size()const;

	///@brief �擪�ɗv�f��ǉ����܂��B
	///@param [in] data �ǉ�����f�[�^
	///@return �ǉ��ɐ���������true ���s������false��Ԃ��܂��B
	bool push(const DataType& data);

	///@brief �����̗v�f�����o���܂�
	///@param [out] data ���o���f�[�^���󂯎��
	///@return ���o���ɐ���������true ���s������false��Ԃ��܂��B
	///@detail �L���[����̂Ƃ��ɌĂԂƎ��s���܂��B
	///		   ���o���Ɏ��s�����ꍇdata�̒l�͕ς��܂���B
	bool pop(DataType& data);

private:

	//! �f�[�^�����郊�X�g�ł�
	List<DataType>m_list;

};

#include"Queue.inl"
