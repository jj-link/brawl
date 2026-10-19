#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Pair32 {
    u32 first;
    u32 second;
};

struct CopyData {
    float f0, f1, f2, f3;
    Pair32 q10;
    u32 w18, w1c;
    Pair32 q20;
    u32 w28;
    u16 h2c, h2e;
    u8 b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b3a;
    u32 w3c;
    Pair32 q40;
    u32 w48;
    float f4c;
    u32 w50, w54, w58, w5c;
    float f60, f64, f68;
    u32 w6c, w70, w74, w78;
    float f7c;
    Pair32 q80;
    u32 w88;
    Pair32 q8c;
    float f94;
    u32 w98;
    u8 b9c;
};

struct VtablePrefix {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
};

struct ViewFirst : VtablePrefix {
    virtual CopyData* get(u32, u32) = 0;
};

struct ViewSecond : VtablePrefix {
    virtual CopyData* get(u32) = 0;
};

extern "C" void fn_72_60A4(void* self, u32 arg1, u32 arg2) {
    CopyData* source = reinterpret_cast<ViewFirst*>(self)->get(arg1, arg2);
    CopyData* destination = reinterpret_cast<ViewSecond*>(self)->get(arg2);
    *destination = *source;
}
