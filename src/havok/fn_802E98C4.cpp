#pragma force_active on
extern char lbl_804882F0[];

struct Frame {
    void* m_p;
    char _1[0x2];
    short m_s;
    char _2[0x48];
};

extern "C" void* fn_802E98C4(void) {
    Frame f __attribute__((aligned(16)));
    if (&f != 0) {
        f.m_s = 1;
        f.m_p = lbl_804882F0;
    }
    return f.m_p;
}
