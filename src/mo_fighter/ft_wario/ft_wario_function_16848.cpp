#pragma force_active on
struct WorkView {
    virtual int s0();
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int getInt(int);
    virtual void setInt(int, int);
};

struct SndView {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void call58(int, bool, bool);
};

struct EnumView {
    char _pad0[0x64];
    WorkView* m_workModule;
    char _pad1[0x20];
    SndView* m_sndModule;
};

struct AccesserView {
    char _pad[0xd8];
    EnumView* m_enumerationStart;
};

extern "C" void fn_110_16848(void*, AccesserView* fighter, int event) {
    if (event == 8 || (unsigned)(event - 0xb) <= 2) {
        int id = fighter->m_enumerationStart->m_workModule->getInt(0x20000005);
        if (id >= 0) {
            fighter->m_enumerationStart->m_sndModule->call58(id, true, true);
            fighter->m_enumerationStart->m_workModule->setInt(-1, 0x20000005);
        }
    }
}
