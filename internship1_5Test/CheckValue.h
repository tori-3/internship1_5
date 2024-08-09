#pragma once
#include"../internship1_5/List.h"
#include"../internship1_5/Grades.h"

///@brief Listの内容が正解と等しいか確認します
///@param ans 正解をvectorとして渡します
///@param list 内容が正しいか調べたいリストを渡します
void CheckValue(const std::vector<Grades>& ans, const List<Grades>& list);
