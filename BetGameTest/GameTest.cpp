#include "gtest/gtest.h"
#include "../ConsoleApplication1/Game.h"
#include "../ConsoleApplication1/Person.h"

TEST(GameTest, GetMostRichPersonTest) {
	Game* game = new Game();
	Person* person = new Person();
	person->fullName = "Tahir Uzelli";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 5000;
	game->persons.push_back(*person);
	person->fullName = "Ali Veli";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 6000;
	game->persons.push_back(*person);
	person->fullName = "Ayþe Fatma";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 3000;
	game->persons.push_back(*person);
	game->getMostRichPerson();
	EXPECT_EQ("Ali Veli", game->mostRichPerson.fullName);
}

TEST(GameTest, GetLuckyNumberTest) {
	Game* game = new Game();
	EXPECT_TRUE(1<=game->getLuckyNumber()<=10);
}

TEST(GameTest, GetTableBalanceTest) {
	Game* game = new Game();
	game->tableBalance = 200;
	game->getTableBalance(100);
	EXPECT_EQ(100,game->tableBalance);
}

TEST(GameTest, GetLuckyPersonMoneyTest) {
	Game* game = new Game();
	Person* person = new Person();
	person->fullName = "Tahir Uzelli";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 5000;
	game->persons.push_back(*person);
	person->fullName = "Ali Veli";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 6000;
	game->persons.push_back(*person);
	person->fullName = "Ayþe Fatma";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 3000;
	game->persons.push_back(*person);
	EXPECT_EQ(22200, game->getPersonMoney(5, 1));
}

TEST(GameTest, GetUnLuckyPersonMoneyTest) {
	Game* game = new Game();
	Person* person = new Person();
	person->fullName = "Tahir Uzelli";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 5000;
	game->persons.push_back(*person);
	person->fullName = "Ali Veli";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 6000;
	game->persons.push_back(*person);
	person->fullName = "Ayþe Fatma";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 3000;
	game->persons.push_back(*person);
	EXPECT_EQ(3500, game->getPersonMoney(5, 0));
}

TEST(GameTest, GetUnLuckyPersonMoneyTest) {
	Game* game = new Game();
	Person* person = new Person();
	person->fullName = "Tahir Uzelli";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 5000;
	game->persons.push_back(*person);
	person->fullName = "Ali Veli";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 6000;
	game->persons.push_back(*person);
	person->fullName = "Ayþe Fatma";
	person->bettNumber = 5;
	person->bettOdd = 0.3;
	person->money = 3000;
	game->persons.push_back(*person);
	game->luckyNumber = 5;
	game->getLuckyPerson();
	EXPECT_EQ(person[1], game->luckyPerson);
}
