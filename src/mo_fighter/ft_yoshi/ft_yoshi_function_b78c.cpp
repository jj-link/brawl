#pragma force_active on
typedef unsigned int u32;

class Work {
    u32 data[2];

public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void offFlag(u32 flag, u32 index);
    virtual void clearFlag(u32 index);
    virtual u32 isFlag(u32 flag, u32 index) const;
};

extern "C" u32 fn_95_B78C(Work* work, u32 flag, u32 index) {
    u32 result = work->isFlag(flag, index);
    if (result == 1) {
        work->offFlag(flag, index);
    }
    return result;
}
