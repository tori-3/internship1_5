#pragma once

template<typename DataType>
size_t Stack<DataType>::size()const
{
	return m_list.size();
}

template<typename DataType>
bool Stack<DataType>::push(const DataType& data)
{
	return m_list.insert(m_list.begin(), data);
}

template<typename DataType>
bool Stack<DataType>::pop(DataType& data)
{
	if (0 == m_list.size())
	{
		return false;
	}

	auto beginIt = m_list.begin();

	data = *beginIt;

	return m_list.remove(beginIt);
}
