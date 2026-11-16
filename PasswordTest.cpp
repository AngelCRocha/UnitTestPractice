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

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;

	ASSERT_TRUE(my_password.has_mixed_case("aB"));
	ASSERT_TRUE(my_password.has_mixed_case("password1!A"));
}

TEST(PasswordTest, password_without_mixed_case)
{
	Password my_password;

	ASSERT_FALSE(my_password.has_mixed_case("PASSWORD"));
	ASSERT_FALSE(my_password.has_mixed_case("password"));
	ASSERT_FALSE(my_password.has_mixed_case("123!@#"));
	ASSERT_FALSE(my_password.has_mixed_case(""));
}
