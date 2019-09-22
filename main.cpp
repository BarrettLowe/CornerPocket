#include <cstdio>
#include "Components/FakePump.hpp"

int main(void) {
    printf("Pool Controller v0.0.0\n");
    FakePump p1;

    p1.SetState(PumpState::ON);
}
