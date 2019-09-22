#include "gtest/gtest.h"
#include "ModeEnums.h"

TEST(TimeInterval, SetIterval)
{
    TimeInterval interval;
    ASSERT_EQ(interval.SetInterval(12, 10), false) << "Why can we make an interval with start time after stop time?";
    ASSERT_EQ(interval.SetInterval(10, 12), true) << "Why can't we make this, all seems fine...?";
    auto theTimes = interval.GetInterval();
    ASSERT_EQ(theTimes.first, 10);
    ASSERT_EQ(theTimes.second, 12);
}

TEST(TimeInterval, OverlappingTest)
{
    TimeInterval int1;
    TimeInterval int2;
    int1.SetInterval(9, 12);
    int2.SetInterval(13, 21);
    ASSERT_FALSE(int1.Overlaps(&int2));
    ASSERT_FALSE(int2.Overlaps(&int1));

    
    int2.SetInterval(12, 21);
    ASSERT_FALSE(int1.Overlaps(&int2));
    ASSERT_FALSE(int2.Overlaps(&int1));

    int2.SetInterval(9, 10);
    ASSERT_TRUE(int1.Overlaps(&int2));
    ASSERT_TRUE(int2.Overlaps(&int1));

    int2.SetInterval(9, 12);
    ASSERT_TRUE(int1.Overlaps(&int2));
    ASSERT_TRUE(int2.Overlaps(&int1));
}

TEST(Days, Init)
{
    Days day;
    day.SetDay(DAYS_OF_THE_WEEK::FRIDAY);
    ASSERT_EQ(DAYS_OF_THE_WEEK::FRIDAY, day.GetDays());

    day.SetDay(DAYS_OF_THE_WEEK::FRIDAY | DAYS_OF_THE_WEEK::MONDAY);
    ASSERT_EQ(DAYS_OF_THE_WEEK::FRIDAY | DAYS_OF_THE_WEEK::MONDAY, day.GetDays());

    ASSERT_NE(DAYS_OF_THE_WEEK::TUESDAY | DAYS_OF_THE_WEEK::MONDAY, day.GetDays());
}

TEST(Days, OverlappingTest)
{
    Days d1;
    Days d2;

    d1.SetDay(DAYS_OF_THE_WEEK::FRIDAY);
    d2.SetDay(DAYS_OF_THE_WEEK::MONDAY);
    EXPECT_FALSE(d1.Overlaps(&d2));
    EXPECT_FALSE(d2.Overlaps(&d1));

    auto testDays = DAYS_OF_THE_WEEK::MONDAY |
        DAYS_OF_THE_WEEK::TUESDAY |
        DAYS_OF_THE_WEEK::WEDNESDAY |
        DAYS_OF_THE_WEEK::THURSDAY |
        DAYS_OF_THE_WEEK::FRIDAY;

    d1.SetDay(testDays);
    EXPECT_TRUE(d1.Overlaps(&d2));
}

TEST(Schedule, Init)
{
    Program pgm;

    auto testDays = DAYS_OF_THE_WEEK::MONDAY |
        DAYS_OF_THE_WEEK::TUESDAY |
        DAYS_OF_THE_WEEK::WEDNESDAY |
        DAYS_OF_THE_WEEK::THURSDAY |
        DAYS_OF_THE_WEEK::FRIDAY;

    ASSERT_EQ(pgm.days.GetDays(), 0);
    pgm.days.SetDay(testDays);
    ASSERT_EQ(pgm.days.GetDays(), testDays);

    

}
