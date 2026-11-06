#pragma force_active on

struct ModuleA {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13(int, int, int); // index 13 -> 0x3C
};

struct WorkModule {
    virtual int w0();
    virtual int w1();
    virtual int w2();
    virtual int w3();
    virtual int w4();
    virtual int w5();
    virtual int w6();
    virtual int w7();
    virtual int w8();
    virtual int w9();
    virtual int w10();
    virtual int w11();
    virtual int w12();
    virtual int w13();
    virtual int w14();
    virtual int w15();
    virtual int w16();
    virtual int isFlag(unsigned int);   // index 17 -> 0x4C
    virtual void onFlag(unsigned int);  // index 18 -> 0x50
    virtual void offFlag(unsigned int); // index 19 -> 0x54
};

struct Enumeration {
    char pad0[0x2c];
    ModuleA* moduleA; // 0x2c
    char pad1[0x64 - 0x30];
    WorkModule* work; // 0x64
};

struct Accesser {
    char pad[0xd8];
    Enumeration* enumerationStart; // 0xd8
};

extern "C" void fn_107_124A4(void*, Accesser* a) {
    if (a->enumerationStart->work->isFlag(0x22000012)) {
        if (a->enumerationStart->work->isFlag(0x22000013) == 0) {
            a->enumerationStart->moduleA->p13(0, 1, 0);
            a->enumerationStart->work->onFlag(0x22000013);
        }
        a->enumerationStart->work->offFlag(0x22000012);
    }
}
