#pragma force_active on
typedef unsigned int u32;

struct Motion {
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
    virtual u32 getKind();
};

struct Modules {
    unsigned char unused[0x70];
    Motion* motion;
};

struct Fighter {
    unsigned char unused[0x3c];
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
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual u32 getKind();
};

struct Context {
    unsigned char unused0[8];
    Fighter* fighter;
    unsigned char unused1[0xcc];
    Modules* modules;
};

struct CommonData {
    unsigned char unused;
};

extern "C" CommonData g_ftCommonDataAccesser;
extern "C" u32* fn_27_14554C(CommonData*, u32, u32);

extern "C" u32 fn_27_151888(void*, Context* context) {
    u32 motionKind;
    Fighter* fighter = context->fighter;
    motionKind = context->modules->motion->getKind();
    u32 fighterKind = fighter->getKind();
    return ((*fn_27_14554C(&g_ftCommonDataAccesser, fighterKind, motionKind) >> 4) & 1) ^ 1;
}
