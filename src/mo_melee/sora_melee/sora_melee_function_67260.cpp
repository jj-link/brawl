#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern "C" char lbl_27_data_7830[];
extern "C" char lbl_27_data_7788[];
extern "C" char __vt__22soAnimCmdEventObserver[];

class soModuleAccesser;

class IAccSub {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual s32 s9(soModuleAccesser* a);
};

class IObs {
public:
    virtual void t2(s16 a, s32 b);
};

class soStopModuleImpl {
public:
    soStopModuleImpl(soModuleAccesser* acc);

    void* vt0;
    void* vt4;
    s16 m8;
    s16 mA;
    s16 mC;
    u8 padE[2];
    s32 m10;
    s32 m14;
    s32 m18;
    u8 m1C_hi : 6;
    u8 m1C_lo : 2;
    u8 pad1D[3];
    soModuleAccesser* m20;
};

soStopModuleImpl::soStopModuleImpl(soModuleAccesser* acc) {
    char* base;
    IAccSub* sub;
    s32 r;
    vt0 = lbl_27_data_7830;
    base = *(char**)((char*)acc + 0xD8);
    base = *(char**)(base + 0x80);
    sub = (IAccSub*)(base + 8);
    r = sub->s9(acc);
    m8 = -1;
    mA = 5;
    mC = -1;
    vt4 = __vt__22soAnimCmdEventObserver;
    ((IObs*)&vt4)->t2((s16)r, -1);
    vt0 = lbl_27_data_7788;
    vt4 = (char*)lbl_27_data_7788 + 0x50;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1C_hi = 0;
    m20 = acc;
}
