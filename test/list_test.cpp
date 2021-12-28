#include "src/lib/LinkedList.hpp"
#include "gtest/gtest.h"

TEST(ListTest, initiate) {
    LinkedList<int> testlist; 
    unsigned expected = 0;
    unsigned actual = testlist.getLength();
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(testlist.isEmpty());
}

TEST(ListTest, appendTest) {
    // testing the append method
    LinkedList<int> testlist; 
    testlist.append(0);
    testlist.append(1);
    testlist.append(2);
    testlist.append(3);
    testlist.append(4);
    unsigned expected = 5; 
    unsigned actual = testlist.getLength();
    EXPECT_EQ(actual, expected);
    EXPECT_FALSE(testlist.isEmpty());
    // testing the clear method
    testlist.clear();
    expected = 0;
    actual = testlist.getLength();
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(testlist.isEmpty());
}

TEST(ListTest, copyTest) {
    LinkedList<int> testlist; 
    testlist.append(0);
    testlist.append(0);
    testlist.append(0);
    testlist.append(0);
    testlist.append(0);
    LinkedList<int> copylist;
    copylist = testlist;
    unsigned testLength = testlist.getLength();
    unsigned copyLength = copylist.getLength();
    EXPECT_EQ(testLength, copyLength);
}

TEST(ListTest, getElementTest) {
    LinkedList<int> testlist; 
    testlist.append(0);
    testlist.append(1);
    testlist.append(2);
    testlist.append(3);
    testlist.append(4);
    // testing the getElement method
    int eExpected = 2;
    int eActual = testlist.getElement(2);
    EXPECT_EQ(eActual, eExpected);
}

TEST(ListTest, insertTest) {
    LinkedList<int> testlist;
    testlist.append(0);
    testlist.append(1);
    testlist.append(2);
    testlist.append(3);
    testlist.append(4);
    testlist.insert(3, 5);
    unsigned actualLength = testlist.getLength();
    unsigned expectedLength = 6;
    EXPECT_EQ(actualLength, expectedLength);
    int actualValue = testlist.getElement(3);
    int expectedValue = 5;
    EXPECT_EQ(actualValue, expectedValue);
}

TEST(ListTest, clearTest) {
    LinkedList<int> testlist; 
    testlist.append(0);
    testlist.append(0);
    testlist.append(0);
    testlist.append(0);
    testlist.append(0);
    // testing the clear method
    testlist.clear();
    unsigned expected = 0;
    unsigned actual = testlist.getLength();
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(testlist.isEmpty());
}

TEST(ListTest, replaceTest) {
    LinkedList<int> testlist;
    testlist.append(1);
    testlist.append(1);
    testlist.append(1);
    testlist.append(1);
    testlist.append(1);
    testlist.append(1);
    testlist.replace(3, 3);
    int expected = 3;
    int actual = testlist.getElement(3);
    EXPECT_EQ(actual, expected);
}

TEST(ListTest, removeTest) {
    LinkedList<int> testlist;
    testlist.append(1);
    testlist.append(1);
    testlist.append(1);
    testlist.append(1);
    testlist.append(1);
    testlist.append(1);
    testlist.remove(3);
    unsigned expectedLength = 5;
    unsigned actualLength = testlist.getLength();
    EXPECT_EQ(actualLength, expectedLength);
}