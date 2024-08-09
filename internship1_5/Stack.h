#pragma once

#include"List.h"

///@brief スタック構造のクラスです。
///@tparam DataType スタックに格納するデータの型です。
template<typename DataType>
class Stack
{
public:

	///@brief データ数を返します。
	///@return データの数
	size_t size()const;

	///@brief 先頭に要素を追加します。
	///@param data 追加するデータ
	///@return 追加に成功したらtrue 失敗したらfalseを返します。
	bool push(const DataType& data);

	///@brief 先頭の要素を取り出します
	///@param data 取り出すデータを受け取る
	///@return 取り出しに成功したらtrue 失敗したらfalseを返します。
	bool pop(DataType& data);

	///@brief リストの先頭コンストイテレーターを返します
	///@return 先頭コンストイテレーター
	typename List<DataType>::ConstIterator begin()const;

	///@brief リストの末尾コンストイテレーターを返します
	///@return 末尾コンストイテレーター
	typename List<DataType>::ConstIterator end()const;

private:

	//! データを入れるリストです
	List<DataType>m_list;

};

#include"Stack.inl"
