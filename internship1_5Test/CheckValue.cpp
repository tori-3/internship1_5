#include "pch.h"
#include"CheckValue.h"

void CheckValue(const std::vector<Grades>& ans, const List<Grades>& list)
{
	EXPECT_TRUE(ans.size() == list.size());

	size_t i = 0;
	for (const auto& grades : list)
	{

		EXPECT_EQ(grades, ans[i]);

		++i;
	}
}
