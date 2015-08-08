#include <gtest/gtest.h>
#include "crossinfo.h"
#include <algorithm>

using namespace std;
TEST(crossinfoTest, sorts)
{
	vector<crossinfo> v;
	v.push_back(crossinfo(1.3, 42));
	v.push_back(crossinfo(0.7, 715));
	v.push_back(crossinfo(3.4, 87));

	sort(v.begin(), v.end());

	vector<crossinfo>::iterator it = v.begin();
	ASSERT_EQ(715, it->height);
	ASSERT_EQ(42, (++it)->height);
	ASSERT_EQ(87, (++it)->height);	
}

