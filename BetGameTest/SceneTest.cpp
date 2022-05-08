#include "gtest/gtest.h"
#include "../ConsoleApplication1/Scene.h"

TEST(SceneTest, CleanScreenTest) {
	Scene* scene = new Scene();
	scene->cleanScreen();
	EXPECT_EQ(' ', scene->scene[10][20]);
}