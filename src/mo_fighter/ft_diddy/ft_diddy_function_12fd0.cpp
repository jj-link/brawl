#pragma force_active on
struct EnumView {
    char _pad0[0x50];
    void* m_effectModule;    // offset 0x50
    char _pad1[0x10];
    void* m_workModule;      // offset 0x64
};

struct AccesserView {
    char _pad[0xd8];
    EnumView* m_enumerationStart; // offset 0xd8
};

struct WorkView {
    virtual int s0();
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int getInt(int);    // offset 0x18
    virtual void setInt(int, int); // offset 0x1C
};

struct EffectView {
    virtual int s0();
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int sA();
    virtual int sB();
    virtual int sC();
    virtual int sD();
    virtual int sE();
    virtual int sF();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual void kill(int, int); // offset 0x58
};

extern "C" void fn_115_12FD0(void* _unused, AccesserView* accesser) {
    int effect = reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workModule)->getInt(0x20000004);
    if (effect >= 0) {
        reinterpret_cast<EffectView*>(accesser->m_enumerationStart->m_effectModule)->kill(effect, 0);
        reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workModule)->setInt(-1, 0x20000004);
    }
}
