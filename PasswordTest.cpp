/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, one_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, three_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZ");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, empty_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, single_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Z");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZzZ");
	ASSERT_EQ(true, actual);
}
