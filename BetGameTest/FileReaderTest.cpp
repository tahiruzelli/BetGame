#include "pch.h"
#include "../ConsoleApplication1/FileReader.h"

TEST(FileReaderTest, ReadFileTestLine) {
	FileReader* fileReader = new FileReader();
	fileReader->readFile("C:/Users/Tahir Uzelli/Documents/GitHub/BetGame/Kisiler.txt");
	EXPECT_EQ(10, fileReader->lines.size());
	delete fileReader;
}

TEST(FileReaderTest, ReadFileTestNoFileThrow) {
	FileReader* fileReader = new FileReader();
	fileReader->readFile("olmayandosya.txt");
	EXPECT_ANY_THROW();
	delete fileReader;
}

TEST(FileReaderTest, ReadFileTestFileFormatThrow) {
	FileReader* fileReader = new FileReader();
	fileReader->readFile("Kisiler.png");
	EXPECT_ANY_THROW();
	delete fileReader;
}

TEST(FileReaderTest, GetPersonEmptyLineTest) {
	FileReader* fileReader = new FileReader();
	fileReader->getPerson("");
	EXPECT_EQ("", fileReader->person->fullName);
}

TEST(FileReaderTest, GetPersonEmptyLineTestThrow) {
	FileReader* fileReader = new FileReader();
	fileReader->getPerson("");
	EXPECT_ANY_THROW();
}

TEST(FileReaderTest, GetPersonSplitTest) {
	FileReader* fileReader = new FileReader();
	fileReader->getPerson("Raphael Adams#47624.35#0.58#5");
	EXPECT_EQ("Raphael Adams", fileReader->person->fullName);
}

TEST(FileReaderTest, GetPersonSplitTest2) {
	FileReader* fileReader = new FileReader();
	fileReader->getPerson("Raphael Adams#47624.35#0.58#5");
	EXPECT_EQ(5, fileReader->person->bettNumber);
}

TEST(FileReaderTest, ToDoubleTest) {
	FileReader* fileReader = new FileReader();
	EXPECT_DOUBLE_EQ(234, fileReader->toDouble("234"));
}

TEST(FileReaderTest, ToDoubleThrowTest) {
	FileReader* fileReader = new FileReader();
	fileReader->toDouble("test");
	EXPECT_ANY_THROW();
}

TEST(FileReaderTest, RunThrowTest) {
	FileReader* fileReader = new FileReader();
	fileReader->run("C:/Users/Tahir Uzelli/Documents/GitHub/BetGame/BosKisiler.txt");
	EXPECT_ANY_THROW();
}

TEST(FileReaderTest, RunPersonSizeTest) {
	FileReader* fileReader = new FileReader();
	fileReader->run("C:/Users/Tahir Uzelli/Documents/GitHub/BetGame/Kisiler.txt");
	EXPECT_EQ(10,fileReader->persons2.size());
}

