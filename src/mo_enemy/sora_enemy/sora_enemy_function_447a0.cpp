#pragma force_active on
class wnemSimple {
public:
    char pad[0x21b6];
    bool m_21b6;
    char pad2[1];
    bool m_21b8;
    bool m_21b9;
    char pad3[1];
    bool m_21bb;
    void SetDeadMode();
};

void wnemSimple::SetDeadMode() {
    m_21b6 = true;
    m_21b8 = false;
    m_21bb = false;
    m_21b9 = false;
}
