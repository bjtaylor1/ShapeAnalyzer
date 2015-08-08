#include <gtest/gtest.h>
#include "iteratorpair.h"
#include <vector>
using namespace std;
class iteratorpairTest : public ::testing::Test
{
public:
	vector<int> ints;
	iteratorpairTest()
	{
		for(int i = 0; i < 10; i++)
		{
			ints.push_back(i); //we've got 0-9
		}
	}
};

TEST_F(iteratorpairTest, increment)
{
	iteratorpair<vector<int>::iterator> it = ints.begin();
	ASSERT_EQ(0, *it.start);
	ASSERT_EQ(1, *it.end);
	
	it.increment();
	ASSERT_EQ(1, *it.start);
	ASSERT_EQ(2, *it.end);
}
