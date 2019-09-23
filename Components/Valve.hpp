enum class ValvePosition
{
    TRANSITION,
    POOL,
    SPA
}

class Valve 
{
protected:
    ValvePosition m_state;


public:
    ValvePosition GetPosition() { return m_state; };

    bool RequestPostion(ValvePosition);

    bool SetPosition(ValvePosition);

}
