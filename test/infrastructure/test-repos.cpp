#include <gtest/gtest.h>
#include "../../src/infrastructure/repos.h"

TEST(Repo, SubscriptionOperator)
{
	Repo<int> repo = Repo<int>();
	int element = 0;
	ASSERT_ANY_THROW(repo[0]);
	repo.Add(element);
	ASSERT_TRUE(repo[0] == 0);
	ASSERT_TRUE(repo[0] == element);
	ASSERT_ANY_THROW(repo[1]);
	repo[0] = 1;
	ASSERT_TRUE(repo[0] == 1);
	ASSERT_TRUE(repo[0] != element);
	element = 2;
	ASSERT_TRUE(repo[0] == 1);
	repo.FreeElements();
}

TEST(Repo, Size)
{
	Repo<int> repo = Repo<int>();
	int element = 0;
	ASSERT_TRUE(repo.Size() == 0);
	repo.Add(element);
	ASSERT_TRUE(repo.Size() == 1);
	repo.Add(element);
	ASSERT_TRUE(repo.Size() == 2);
	repo.Add(element, true);
	ASSERT_TRUE(repo.Size() == 3);
	repo.FreeElements();
}

TEST(Repo, Empty)
{
	Repo<int> repo = Repo<int>();
	ASSERT_TRUE(repo.Empty());
	repo.Add(0);
	ASSERT_FALSE(repo.Empty());
	repo.FreeElements();
}

TEST(Repo, Add)
{
	Repo<int> repo = Repo<int>();
	int element1 = 1, element2 = 2, element3 = 3;
	repo.Add(element1);
	ASSERT_TRUE(repo[0] == element1);
	repo.Add(element2);
	ASSERT_TRUE(repo[0] == element1);
	ASSERT_TRUE(repo[1] == element2);
	repo.Add(element3, true);
	ASSERT_TRUE(repo[0] == element3);
	ASSERT_TRUE(repo[1] == element1);
	ASSERT_TRUE(repo[2] == element2);
	repo.FreeElements();
}

TEST(Repo, Insert)
{
	Repo<int> repo = Repo<int>();
	int element1 = 1, element2 = 2, element3 = 3;
	ASSERT_ANY_THROW(repo.Insert(element1, 1));
	repo.Insert(element1, 0);
	ASSERT_TRUE(repo[0] == element1);
	repo.Insert(element2, 1);
	ASSERT_TRUE(repo[0] == element1);
	ASSERT_TRUE(repo[1] == element2);
	repo.Insert(element3, 1);
	ASSERT_TRUE(repo[0] == element1);
	ASSERT_TRUE(repo[1] == element3);
	ASSERT_TRUE(repo[2] == element2);
	repo.Insert(element3, 0);
	ASSERT_TRUE(repo[0] == element3);
	ASSERT_TRUE(repo[1] == element1);
	ASSERT_TRUE(repo[2] == element3);
	ASSERT_TRUE(repo[3] == element2);
	repo.FreeElements();
}

TEST(Repo, Erase)
{
	Repo<int> repo = Repo<int>();
	int element1 = 1, element2 = 2, element3 = 3;
	repo.Add(element1);
	repo.Add(element2);
	repo.Add(element3);
	repo.Erase(1);
	ASSERT_TRUE(repo[0] == element1);
	ASSERT_TRUE(repo[1] == element3);
	repo.Erase(0);
	ASSERT_TRUE(repo[0] == element3);
	repo.FreeElements();
}
