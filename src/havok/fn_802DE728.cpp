#pragma force_active on
extern unsigned char lbl_80487BB8[];

struct Frame {
    void* m_p;
    short _a;
    short m_s;
    char _0[0x1C];
};

extern "C" void* fn_802DE728() {
    __attribute__((aligned(16))) Frame f;
    void** pp = &f.m_p;
    if (pp != 0) {
        f.m_s = 1;
        f.m_p = lbl_80487BB8;
    }
    return f.m_p;
}
