#pragma once

template<typename DataType>
size_t Queue<DataType>::size()const
{
	return m_list.size();
}

template<typename DataType>
bool Queue<DataType>::push(const DataType& data)
{
	return m_list.insert(m_list.begin(), data);
}

template<typename DataType>
bool Queue<DataType>::pop(DataType& data)
{
	if (0 == m_list.size())
	{
		return false;
	}
	auto it = m_list.end();
	--it;
	data = *it;
	m_list.remove(it);

	return true;
}
