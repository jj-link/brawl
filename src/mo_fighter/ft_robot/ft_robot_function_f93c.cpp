#pragma force_active on

extern "C" float lbl_120_rodata_50;
extern "C" float lbl_120_rodata_58;

struct MotionModule {
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
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void doAction(int, int, int, int, float, float, int); // index 39 -> 0xA4
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
    void* pad0[2];        // 0x00, 0x04
    MotionModule* motion; // 0x08
    void* pad1[22];       // 0x0C .. 0x60
    WorkModule* work;     // 0x64
};

struct Accesser {
    char pad[0xd8];
    Enumeration* enumerationStart; // 0xd8
};

extern "C" void fn_120_F93C(void*, Accesser* a) {
    if (a->enumerationStart->work->isFlag(0x22000017)) {
        a->enumerationStart->motion->doAction(2, 0x1D8, 0x60, 1, lbl_120_rodata_50, lbl_120_rodata_58, 0);
        a->enumerationStart->work->offFlag(0x22000017);
        a->enumerationStart->work->onFlag(0x12000040);
    }
}
