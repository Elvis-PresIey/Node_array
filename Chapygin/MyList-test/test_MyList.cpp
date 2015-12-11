#include "List.h"
#include <gtest.h>

TEST(List, can_create_and_fill_list) {
	List myList(5);
	myList.Add(10.0); myList.MoveNext();
	EXPECT_EQ(10.0, myList.operator*());
	myList.Add(5.1); myList.MoveNext();
	EXPECT_EQ(5.1, myList.operator*());
	myList.Add(6.8); myList.MoveNext();
	EXPECT_EQ(6.8, myList.operator*());
	myList.Add(152.3); myList.MoveNext();
	EXPECT_EQ(152.3, myList.operator*());
	myList.Add(14.2); myList.MoveNext();
	EXPECT_EQ(14.2, myList.operator*());
}

TEST(List, Move_Next_knows_where_the_list_ends) {
	List myList(3);
	myList.Add(5.32); myList.MoveNext();
	ASSERT_ANY_THROW(myList.MoveNext());
}

TEST(List, can_delete_node) {
	List myList(5);
	myList.Add(10.0); myList.MoveNext();
	myList.Add(5.1); myList.MoveNext();
	myList.Add(6.8); myList.MoveNext();
	myList.Add(152.3); myList.MoveNext();
	myList.Add(14.2); myList.MoveNext();
	myList.Rewind();
	myList.MoveNext();
	myList.Del();
	myList.Rewind();
	myList.MoveNext();
	EXPECT_EQ(6.8, myList.operator*());
}

TEST(List, list_knows_hes_full) {
	List myList(3);
	myList.Add(11.1); myList.MoveNext();
	myList.Add(22.2); myList.MoveNext();
	myList.Add(33.3); myList.MoveNext();
	EXPECT_TRUE(myList.isFull());
}

TEST(List, list_knows_hes_empty) {
	List myList(3);
	EXPECT_TRUE(myList.isEmpty());
}
