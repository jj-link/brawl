#pragma force_active on

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
    virtual int isFlag(unsigned int);   // 0x4C
    virtual void onFlag(unsigned int);  // 0x50
    virtual void offFlag(unsigned int); // 0x54
};

struct ModuleB {
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
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16(int, void*, int); // 0x48
};

struct Enumeration {
    char pad0[0x54];
    ModuleB* moduleB; // 0x54
    char pad1[0x64 - 0x58];
    WorkModule* work; // 0x64
};

struct Accesser {
    char pad[0xd8];
    Enumeration* enumerationStart; // 0xd8
};

extern "C" void fn_96_178C4(void*, Accesser* a) {
    if (a->enumerationStart->work->isFlag(0x22000019)) {
        struct {
            int value;
            unsigned char flag;
        } data;
        data.value = 0x36;
        data.flag = 0;
        a->enumerationStart->moduleB->p16(0, &data, 0);
        a->enumerationStart->work->offFlag(0x22000019);
    }
}
