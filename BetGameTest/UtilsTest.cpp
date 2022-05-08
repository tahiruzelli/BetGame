#include "gtest/gtest.h"
#include "../ConsoleApplication1/Utils.h"


TEST(UtilsTest, GetScreenHeightPositiveTest) {
	Utils* utils = new Utils();
	EXPECT_TRUE(utils->getScreenHeight()>0);
}

TEST(UtilsTest, GetScreenWidthPositiveTest) {
	Utils* utils = new Utils();
	EXPECT_TRUE(utils->getScreenWidth() > 0);
}

TEST(UtilsTest, GetScreenHeightSceneTest) {
	Utils* utils = new Utils();
	double screenHeight = utils->getScreenHeight();
	bool expectValue = false;
	if (screenHeight > 14) { // 14 sahne uzunluðudur.
		bool expectValue = true;
	}
	EXPECT_TRUE(expectValue);
}

TEST(UtilsTest, GetScreenWidthSceneTest) {
	Utils* utils = new Utils();
	double screenHeight = utils->getScreenWidth();
	bool expectValue = false;
	if (screenHeight > 50) { // 50 sahne geniþliðidir.
		bool expectValue = true;
	}
	EXPECT_TRUE(expectValue);
}

TEST(UtilsTest, ChangeCursorPositionTest) {
	Utils* utils = new Utils();
	utils->changeCursorPosition(100, 100);
	EXPECT_ANY_THROW();

}

TEST(UtilsTest, GetPaddingTest) {
	Utils* utils = new Utils();
	EXPECT_EQ(15, utils->getPadding(40, 10));
}

TEST(UtilsTest, GetPaddingThrowTest) {
	Utils* utils = new Utils();
	utils->getPadding(20,30);
	EXPECT_ANY_THROW();
}

TEST(UtilsTest, StrToCharArrayTest) {
	Utils* utils = new Utils();
	char* charStr = utils->strToCharArray("hello world");
	EXPECT_EQ('h',charStr[0]);
}

TEST(UtilsTest, StrToCharArrayThrowTest) {
	Utils* utils = new Utils();
	char* charStr = utils->strToCharArray("hello world");
	charStr[12]; // out of range
	EXPECT_ANY_THROW();
}

TEST(UtilsTest, StrToCharArraySizeTest) {
	Utils* utils = new Utils();
	char* charStr = utils->strToCharArray("hello world");
	EXPECT_EQ(11, utils->getCharArrayLength(charStr));
}

TEST(UtilsTest, CharArrayLengthTest) {
	Utils* utils = new Utils();
	char* charStr = "test case";
	EXPECT_EQ(9,utils->getCharArrayLength(charStr));
}

TEST(UtilsTest, SplitLengthTest) {
	Utils* utils = new Utils();
	int size = utils->split("tahir.uzelli.g181210005",'.').size();
	EXPECT_EQ(3, size);
}

TEST(UtilsTest, SplitTest) {
	Utils* utils = new Utils();
	EXPECT_EQ("tahir", utils->split("tahir.uzelli.g181210005", '.')[0]);
}