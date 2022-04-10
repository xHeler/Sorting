#include "gtest/gtest.h"
#include "LinkedList.h"

TEST(LinkedListTest, constructor)
{
  LinkedList<int> list(13, 0);
  EXPECT_EQ(list.get_size(), 1);
}

TEST(LinkedListTest, get_data_at_index)
{
  LinkedList<int> list(13, 0);
  EXPECT_EQ(list[0], 13);
}

TEST(LinkedListTest, soring)
{
  LinkedList<double> list(3.3, 2);
  list.add(9.9, 0);
  list.add(2.0, 1);
  EXPECT_EQ(list[0], 9.9);
  EXPECT_EQ(list[1], 2.0);
  EXPECT_EQ(list[2], 3.3);
}

TEST(LinkedListTest, size)
{
  LinkedList<char> list('a', 0);
  EXPECT_EQ(list.get_size(), 1);
  list.add('c', -1);
  EXPECT_EQ(list.get_size(), 2);
}