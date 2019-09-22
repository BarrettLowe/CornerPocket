#include "gtest/gtest.h"
#include "FakePump.hpp"

TEST(Pump, BasicTest)
{
    Pump *p1;
    p1 = new FakePump();
    ASSERT_EQ(p1->GetState(), PumpState::OFF);

    ASSERT_EQ(p1->SetState(PumpState::ON), true);

    ASSERT_EQ(p1->RequestState(PumpState::OFF), true);
    ASSERT_EQ(p1->GetState(), PumpState::OFF);
}


