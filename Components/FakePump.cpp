#include "FakePump.hpp"

bool FakePump::RequestState(PumpState reqState)
{
    m_state = reqState; 
    return true;
}

bool FakePump::SetState(PumpState state)
{
    m_state = state; 
    return true;
}
