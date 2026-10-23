#pragma force_active on
extern "C" const float lbl_119_rodata_48;

struct MotionMod {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
    virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
    virtual void p10(); virtual void p11(); virtual void p12();
    virtual void doAction(int, int, int); // 0x3C
};

struct WorkMod {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
    virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
    virtual void p10(); virtual void p11();
    virtual float getFloat(unsigned int); // 0x38
    virtual void p13(); virtual void p14(); virtual void p15(); virtual void p16();
    virtual int isFlag(unsigned int);     // 0x4C
    virtual void onFlag(unsigned int);    // 0x50
    virtual void offFlag(unsigned int);   // 0x54
};

struct StatusMod {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
    virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
    virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14();
    virtual void p15();
    virtual int getStatus();              // 0x48
};

struct LoopObj {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
    virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
    virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13();
    virtual int f16(int, int);            // 0x40
    virtual void p15(); virtual void p16();
    virtual void f19(int, int, int);      // 0x4C
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23(); virtual void p24();
    virtual void p25(); virtual void p26(); virtual void p27(); virtual void p28(); virtual void p29();
    virtual void p30(); virtual void p31(); virtual void p32(); virtual void p33(); virtual void p34();
    virtual void p35(); virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43(); virtual void p44();
    virtual void p45(); virtual void p46(); virtual void p47(); virtual void p48(); virtual void p49();
    virtual void p50(); virtual void p51(); virtual void p52(); virtual void p53(); virtual void p54();
    virtual void p55();
    virtual int count();                  // 0xE0
};

struct Enumeration {
    char pad0[0x1C];
    LoopObj* loop;      // 0x1C
    char pad1[0x4];
    MotionMod* motion;  // 0x24
    char pad2[0x3C];
    WorkMod* work;      // 0x64
    char pad3[0x8];
    StatusMod* status;  // 0x70
};

struct Accesser {
    char pad[0xD8];
    Enumeration* enumerationStart; // 0xD8
};

extern "C" void fn_119_DA90(void* process, Accesser* a) {
    switch (a->enumerationStart->status->getStatus()) {
    case 0x115:
        if (a->enumerationStart->work->isFlag(0x22000012) == 0) {
            if (a->enumerationStart->work->isFlag(0x22000011) != 0) {
                a->enumerationStart->motion->doAction(0, 1, 1);
                a->enumerationStart->work->onFlag(0x22000012);
            }
        } else {
            if (a->enumerationStart->work->isFlag(0x22000011) == 0) {
                a->enumerationStart->motion->doAction(0, 0, 1);
                a->enumerationStart->work->offFlag(0x22000012);
            }
        }
        break;
    case 0x121: {
        LoopObj* obj = a->enumerationStart->loop;
        float f = a->enumerationStart->work->getFloat(0x21000004);
        if (f <= lbl_119_rodata_48) {
            break;
        }
        for (int i = 0; i < obj->count(); i++) {
            if (obj->f16(i, 0) != 0) {
                obj->f19(i, (int)f, 0);
            }
        }
        break;
    }
    }
}
