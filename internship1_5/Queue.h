#pragma once

#include"List.h"

///@brief キュー構造のクラスです。
///@tparam DataType キューに格納するデータの型です。
template<typename DataType>
class Queue
{
public:

	///@brief データ数を返します。
	///@return データの数
	size_t size()const;

	///@brief 先頭に要素を追加します。
	///@param [in] data 追加するデータ
	///@return 追加に成功したらtrue 失敗したらfalseを返します。
	bool push(const DataType& data);

	///@brief 末尾の要素を取り出します
	///@param [out] data 取り出すデータを受け取る
	///@return 取り出しに成功したらtrue 失敗したらfalseを返します。
	///@detail キューが空のときに呼ぶと失敗します。
	///		   取り出しに失敗した場合dataの値は変わりません。
	bool pop(DataType& data);

private:

	//! データを入れるリストです
	List<DataType>m_list;

};

#include"Queue.inl"
