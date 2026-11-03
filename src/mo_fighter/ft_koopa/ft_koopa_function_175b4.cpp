#pragma force_active on

struct KoopaData {
    int first;
    unsigned char flag;
    unsigned char padding[3];
    int second;
    int value0;
    int value1;
    int value2;
    float scalar;
    unsigned char last;
};

extern "C" void fn_102_E384(KoopaData*, int, int, unsigned char);

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
    virtual void p12(int); // index 12 -> 0x38
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
    virtual void p16(int, KoopaData*, int); // index 16 -> 0x48
};

struct Enumeration {
    char pad0[0x3c];
    ModuleA* moduleA; // 0x3c
    char pad1[0x54 - 0x40];
    ModuleB* moduleB; // 0x54
    char pad2[0x64 - 0x58];
    WorkModule* work; // 0x64
};

struct Accesser {
    char pad[0xd8];
    Enumeration* enumerationStart; // 0xd8
};

extern "C" void fn_102_175B4(void*, Accesser* a, int kind) {
    if (kind != 0x11f) {
        if (a->enumerationStart->work->isFlag(0x22000011)) {
            a->enumerationStart->moduleA->p12(0);
            a->enumerationStart->work->onFlag(0x1200003E);
            KoopaData data;
            fn_102_E384(&data, 0x26, -1, 1);
            a->enumerationStart->moduleB->p16(0, &data, 0);
            a->enumerationStart->work->offFlag(0x22000011);
        }
    }
}
