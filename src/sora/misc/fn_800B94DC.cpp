#pragma force_active on
struct WindowSetting {
    char _0[0x30];
    float hScale;
    char _34[0x14];
};

class MuMsg {
public:
    void setHScale(unsigned long msgIndex, float val);
    char pad[0xc];
    WindowSetting* m_elems;
};

void MuMsg::setHScale(unsigned long msgIndex, float val)
{
    m_elems[msgIndex].hScale = val;
}
