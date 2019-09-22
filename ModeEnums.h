#ifndef MODEENUMS_H
#define MODEENUMS_H

#include <utility>

enum RequestableModes 
{
    POOL    = 0x01,
    SPA     = 0x02,
    HEAT    = 0x04,
    HOT_POOL= POOL & SPA, //POOL AND HEAT
    CLEANER = 0x08,
    CLEAN_POOL  = POOL & CLEANER, //POOL AND CLEANER
    BLOWER  = 0x0A,
    BLOW_SPA = BLOWER & SPA
};

enum DAYS_OF_THE_WEEK {
    INVALID     = 0x00,
    SUNDAY      = 1 << 0,
    MONDAY      = 1 << 1,
    TUESDAY     = 1 << 2,
    WEDNESDAY   = 1 << 3,
    THURSDAY    = 1 << 4,
    FRIDAY      = 1 << 5,
    SATURDAY    = 1 << 6
};

inline DAYS_OF_THE_WEEK operator|(DAYS_OF_THE_WEEK a, DAYS_OF_THE_WEEK b)
{
    return static_cast<DAYS_OF_THE_WEEK>(static_cast<int>(a) | static_cast<int>(b));
}
inline DAYS_OF_THE_WEEK operator&(DAYS_OF_THE_WEEK a, DAYS_OF_THE_WEEK b)
{
    return static_cast<DAYS_OF_THE_WEEK>(static_cast<int>(a) & static_cast<int>(b));
}

class Days
{
    uint8_t rawVal=0;
    bool valid() { return rawVal & 0b10000000; };

public:

    /**
     * @brief Get number coresponding to the day of the week
     * 1-7 = Sunday-Saturday
     * 0 = invalid
     *
     * @return The day or invalid
     */
    DAYS_OF_THE_WEEK GetDays() { 
        if(valid()) 
            return DAYS_OF_THE_WEEK(rawVal & 0b01111111); 
        else 
            return DAYS_OF_THE_WEEK::INVALID;
    }

    void SetDay(DAYS_OF_THE_WEEK day) { rawVal = (0b10000000 | static_cast<uint8_t>(day)); };

    bool Overlaps(Days* otherDay)
    {
        // Just do a bitwise and to see if anything is the same
        return (bool)(otherDay->GetDays() & GetDays());
    }
};

class TimeInterval
{
    uint8_t startTime;
    uint8_t stopTime;

public:
    bool SetInterval(uint8_t start, uint8_t stop)
    {
        if (start > stop) return false;

        startTime = start;
        stopTime = stop;
        return true;
    }
    std::pair<uint8_t, uint8_t> GetInterval() 
    {
        return std::make_pair(startTime, stopTime);
    }

    bool Overlaps(TimeInterval * otherTime)
    {
        auto other = otherTime->GetInterval();
        auto otherStart = other.first;
        auto otherStop = other.second;

        if (otherStop <= startTime) return false;
        if (otherStart >= stopTime) return false;

        return true;
    }
};

struct Program
{
    Days days;
    TimeInterval time;
};

#endif // MODEENUMS_H
