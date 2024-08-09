#pragma once
#include<string>

///@brief ���тƖ��O�������N���X�ł��B
struct Grades
{
    //! �X�R�A
    int score;

    //! ���O
    std::string name;

    ///@brief �f�[�^�������������ׂ܂��B
    ///@param right ��r����C�e���[�^�[
    ///@return �f�[�^���m�����������true �قȂ��Ă����false��Ԃ��܂��B
    ///@detail score name ���ꂼ����r���Ă��܂��B
    bool operator ==(const Grades& right)const
    {
        return (score == right.score) && (name == right.name);
    }

    ///@brief �f�[�^���قȂ��Ă��邩���ׂ܂��B
    ///@param right ��r����C�e���[�^�[
    ///@return �f�[�^���m���قȂ��Ă����true ���������false��Ԃ��܂��B
    ///@detail score name ���ꂼ����r���Ă��܂��B
    bool operator !=(const Grades& right)const
    {
        return (score != right.score) || (name != right.name);
    }
};
