//
// Created by sotti on 10/02/2026.
//
#include "gtest/gtest.h"
#include "..\Date.h"

TEST(DateTest, InvalidConstructor) {
    Date data(27,5,2004);
    EXPECT_EQ(data.getDay(),27);
    EXPECT_EQ(data.getMonth(),5);
    EXPECT_EQ(data.getYear(),2004);
}

TEST(DateTest, IvalidDay) {
    EXPECT_THROW(Date(37,4,2007), std::out_of_range);
    EXPECT_THROW(Date(30,2,2023), std::out_of_range);
}

TEST(DateTest, InvalidMonth) {
    EXPECT_THROW(Date(1,15,2022), std::out_of_range);
    EXPECT_THROW(Date(3,-6,2021), std::out_of_range);
}

TEST(DateTest, InvalidYear) {
    EXPECT_THROW(Date(1,1,1850), std::out_of_range);
    EXPECT_THROW(Date(1,1,2200), std::out_of_range);
}

TEST(DateTest, CheckLeapYear) {
    EXPECT_THROW(Date(29,2,2021), std::out_of_range);
    EXPECT_NO_THROW(Date(29,2,2024));
}

TEST(DateTest, SetsValidation) {
    Date data(25,5,2004);
    data.setDay(1);
    EXPECT_EQ(data.getDay(),1);
    data.setMonth(11);
    EXPECT_EQ(data.getMonth(),11);
    EXPECT_THROW(data.setDay(31),std::out_of_range);
}