#ifndef PUMP_H
#define PUMP_H

enum class PumpState
{
    ON,
    OFF
};

class Pump
{
    protected:
    PumpState m_state;

    public:
    Pump() : m_state(PumpState::OFF) {};
    
    /**
     * @fn   PumpState GetState(void)
     * @brief Get the state of the pump
     * @return PumpState
     */
    PumpState GetState(void) { return m_state; };

    /**
     * @fn bool RequestState(PumpState)
     * @brief Request the pump to change state.
     *
     * @param reqState - the state requested
     *
     * @return whether the request was successful or not (does not mean pump state is there yet)
     */
    virtual bool RequestState(PumpState reqState) = 0;

    /**
     * @fn SetState(PumpState)
     * @brief Set the state of the pump.
     *
     * @param state - the requested state
     *
     * @return Whether or not the pump is at that state (may block)
     */
    virtual bool SetState(PumpState state) = 0;
};

#endif //PUMP_H
