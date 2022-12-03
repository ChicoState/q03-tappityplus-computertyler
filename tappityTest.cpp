/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};


//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
TEST(PracticeTest, Test_length_difference_With_same_txt){//tests difference with same length
	tappity T("Test");
	T.entry("Test");
    ASSERT_EQ(T.length_difference(),0);	
}
TEST(PracticeTest, Test_length_difference_same_Len_Dif_Text){//tests difference with same length different text
	tappity T("Test");
	T.entry("chek");
    ASSERT_EQ(T.length_difference(),0);	
}
TEST(PracticeTest, Test_length_difference_Dif_Len){//tests difference with same text but different length
	tappity T("Test");
	T.entry("Tes");
    ASSERT_EQ(T.length_difference(),1);	
}
TEST(PracticeTest, Test_length_difference_both_Empty){//tests difference with empty strings
	tappity T("");
	T.entry("");
    ASSERT_EQ(T.length_difference(),0);	
}

TEST(PracticeTest, Test_length_difference_Empty_Ref){//tests difference with same text but different length
	tappity T("");
	T.entry("Testing");
    ASSERT_EQ(T.length_difference(),7);	
}
TEST(PracticeTest, Test_length_difference_Empty_Entry){//tests difference with same text but different length
	tappity T("Testing");
	T.entry("");
    ASSERT_EQ(T.length_difference(),7);	
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
//double accuracy();

TEST(PracticeTest, Test_accuracy_same_No_Spaces){//tests accuracy with same text no spaces
	tappity T("TestingTesting");
	T.entry("TestingTesting");
    ASSERT_EQ(T.accuracy(),100);	
}
TEST(PracticeTest, Test_accuracy_same_With_Spaces){//tests accuracy with same text and space
	tappity T("Testing Testing");
	T.entry("Testing Testing");
    ASSERT_EQ(T.accuracy(),100);	
}
TEST(PracticeTest, Test_accuracy_different){//tests accuracy with half the length
	tappity T("Test Testing");
	T.entry("Test T");
    ASSERT_EQ(T.accuracy(),50);	
}
TEST(PracticeTest, Test_accuracy_different_no_Space){//tests accuracy with different text and no spaces
	tappity T("TestingTesting");
	T.entry("Testing");
    ASSERT_EQ(T.accuracy(),50);	
}
TEST(PracticeTest, Test_accuracy_different_Ref_Longer_No_Space){//tests accuracy with a longer ref but no spaces
	tappity T("TestTest");
	T.entry("Test");
    ASSERT_EQ(T.accuracy(),50);	
}
TEST(PracticeTest, Test_accuracy_different_Ref_Longer_With_Spaces){//tests accuracy with longer ref and spaces
	tappity T("The brown ");
	T.entry("The b");
    ASSERT_EQ(T.accuracy(),50);	
}
TEST(PracticeTest, Test_accuracy_Both_Empty){//tests accuracy with empty strings
	tappity T("");
	T.entry("");
    ASSERT_EQ(T.accuracy(),100);	
}
TEST(PracticeTest, Test_accuracy_Empty_Entry){//tests accuracy with an empty entry but Test in reference
	tappity T("Test");
	T.entry("");
    ASSERT_EQ(T.accuracy(),0);	
}
TEST(PracticeTest, Test_accuracy_Empty_Ref){//tests accuracy with Empty ref but text in entry
	tappity T("");
	T.entry("Test");
    ASSERT_EQ(T.accuracy(),0);	
}
TEST(PracticeTest, Test_accuracy_buf_Check){//tests accuracy with really long text
	tappity T("testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest");
	T.entry("testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest");
    ASSERT_EQ(T.accuracy(),100);	
}
TEST(PracticeTest, Test_accuracy_special_Char){//tests accuracy with special characters
	tappity T("~`!@#$%^&*()_+-=?/{}[]|");
	T.entry("~`!@#$%^&*()_+-=?/{}[]|");
    ASSERT_EQ(T.accuracy(),100);	
}
TEST(PracticeTest, Test_accuracy_wrong_special_Char){//tests accuracy with special characters
	tappity T("~`!@#$%^&*()_+-=?/{}[]|");
	T.entry("***********************");
    ASSERT_EQ(T.accuracy(),0);	
}
TEST(PracticeTest, Test_accuracy_25pcnt){//tests accuracy with 25% accuracy to make sure different percentages work
	tappity T("Test");
	T.entry("T");
    ASSERT_EQ(T.accuracy(),25);	
}
TEST(PracticeTest, Test_accuracy_75pcnt){//tests accuracy with 75% accuracy to make sure different percentages work
	tappity T("Test");
	T.entry("Tes");
    ASSERT_EQ(T.accuracy(),75);	
}
TEST(PracticeTest, Test_accuracy_25pcnt_Longer_Entry){//tests accuracy with 25% accuracy and a longer entry to make sure different percentages work
	tappity T("T");
	T.entry("Test");
    ASSERT_EQ(T.accuracy(),25);	
}
TEST(PracticeTest, Test_accuracy_Longer_Entry){//tests accuracy with 25% accuracy and a longer entry to make sure different percentages work
	tappity T("Tes");
	T.entry("Test");
    ASSERT_EQ(T.accuracy(),75);	
}
TEST(PracticeTest, Test_accuracy_10pcnt){//tests accuracy with 10% accuracy 
	tappity T("TestTestTe");
	T.entry("T");
    ASSERT_EQ(T.accuracy(),10);	
}
TEST(PracticeTest, Test_accuracy_First_Letter_Off){
	tappity T("TestTestTe");
	T.entry("cestTestTe");
    ASSERT_EQ(T.accuracy(),0);	
}
TEST(PracticeTest, Test_accuracy_First_Letter_Not_Cap){
	tappity T("TestTestTe");
	T.entry("testTestTe");
    ASSERT_EQ(T.accuracy(),0);	
}
TEST(PracticeTest, Test_accuracy_Last_letter_Wrong){
	tappity T("TestTestTe");
	T.entry("TestTestTd");
    ASSERT_EQ(T.accuracy(),90);	
}
TEST(PracticeTest, Test_accuracy_middle_letter_Wrong){
	tappity T("TestTestTe");
	T.entry("TestrestTe");
    ASSERT_EQ(T.accuracy(),40);	
}
TEST(PracticeTest, Test_accuracy_Same_numbers){//tests accuracy with 10% accuracy 
	tappity T("12345");
	T.entry("12345");
    ASSERT_EQ(T.accuracy(),100);	
}
TEST(PracticeTest, Test_accuracy_Wrong_numbers){//tests accuracy with 10% accuracy 
	tappity T("12345");
	T.entry("54321");
    ASSERT_EQ(T.accuracy(),0);	
}
