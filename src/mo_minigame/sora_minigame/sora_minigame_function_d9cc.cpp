#pragma force_active on
struct FnObj {
    unsigned char pad0[0x21];
    signed char m_state;
    unsigned char pad1[0x30 - 0x22];
    float m_value;
    unsigned char pad2[0x64 - 0x34];
    float m_factor;
};

extern "C" void fn_20_D9CC(FnObj* obj) {
    if (obj->m_state != 1) {
        return;
    }
    obj->m_value = obj->m_value * obj->m_factor;
}
