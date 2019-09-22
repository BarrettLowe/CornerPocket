#ifndef FAKEPUMP_H
#define FAKEPUMP_H

#include "Pump.hpp"

class FakePump : public Pump
{
    public:
    virtual bool RequestState(PumpState);
    virtual bool SetState(PumpState);


};

#endif //FAKEPUMP_H
