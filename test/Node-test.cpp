#include "gtest/gtest.h"
#include "Node.h"

TEST (NodeTest, constructor)
{
  Node<int> node(13, 0);
  EXPECT_EQ(node.get_data(), 13);
  EXPECT_EQ(node.get_priority(), 0);
  EXPECT_EQ(node.get_next(), nullptr);
}

TEST(NodeTst, getter_and_setter_data)
{
  Node<std::string> node("Hello", 1);
  EXPECT_EQ(node.get_data(), "Hello");
  node.set_data("Test");
  EXPECT_EQ(node.get_data(), "Test");
}

TEST(NodeTst, getter_and_setter_next)
{
  Node<double> *first = new Node<double>(7.6, 0);
  Node<double> *secound= new Node<double>(0.2, 1);
  first->set_next(secound);

  EXPECT_EQ(first->get_next(), secound);
}