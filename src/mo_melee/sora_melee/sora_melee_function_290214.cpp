#include <types.h>
#pragma force_active on

class Poly {
public:
    virtual void f0(int a);
    virtual void f1(int a);
    virtual void f2(int a);
    virtual void f3(int a);
    virtual void f4(int a);
    virtual void f5(int a);
    virtual void f6(int a);
    virtual void f7(int a);
    virtual void f8(int a);
    virtual void f9(int a);
    virtual void f10(int a);
    virtual void f11(int a);
    virtual void f12(int a);
    virtual void f13(int a);
    virtual void f14(int a);
    virtual void f15(int a);
    virtual void f16(int a);
    virtual void f17(int a);
    virtual void f18(int a);
    virtual void f19(int a, int b);
};

struct Pad8 {
    char pad[0x8];
};

class Class90D8 : public Pad8 {
public:
    virtual void f0(int a);
    virtual void f1(int a);
    virtual void f2(int a);
    virtual void f3(int a);
    virtual void f4(int a);
    virtual void f5(int a);
};

struct Pad3c {
    char pad[0x3c];
};

class CastObj : public Pad3c {
public:
    virtual void f0(int a);
    virtual void f1(int a);
    virtual void f2(int a);
    virtual void f3(int a);
    virtual void f4(int a);
    virtual void f5(int a);
    virtual void f6(int a);
    virtual void f7(int a);
    virtual void f8(int a);
    virtual void f9(int a);
    virtual void f10(int a);
    virtual void f11(int a);
    virtual void f12(int a);
    virtual void f13(int a);
    virtual void f14(int a);
    virtual void f15(int a);
    virtual void f16(int a);
    virtual void f17(int a);
    virtual void f18(int a);
    virtual void f19(int a);
    virtual void f20(int a);
    virtual void f21(int a);
    virtual void f22(int a);
    virtual void f23(int a);
    virtual void f24(int a);
    virtual void f25(int a);
    virtual void f26(int a);
    virtual void f27(int a);
    virtual void f28(int a);
    virtual void f29(int a);
    virtual void f30(int a);
    virtual void f31(int a);
    virtual void f32(int a);
    virtual void f33(int a);
    virtual void f34(int a);
    virtual void f35(int a);
    virtual void f36(int a);
    virtual void f37(int a);
    virtual void f38(int a);
    virtual void f39(int a);
    virtual void f40(int a);
    virtual void f41(int a);
    virtual void f42(int a);
    virtual void f43(int a);
    virtual void f44(int a);
    virtual void f45(int a);
    virtual void f46(int a);
    virtual void f47(int a);
    virtual void f48(int a);
    virtual void f49(int a);
    virtual void f50(int a);
    virtual void f51(int a);
    virtual void f52(int a);
    virtual void f53(int a);
    virtual void f54(int a);
    virtual void f55(int a);
    virtual void f56(int a);
    virtual void f57(int a);
    virtual void f58(int a);
    virtual void f59(int a);
    virtual void f60(int a);
    virtual void f61(int a);
    virtual void f62(int a);
    virtual void f63(int a);
    virtual void f64(int a);
    virtual void f65(int a);
    virtual void f66(int a);
    virtual void f67(int a);
    virtual void f68(int a);
    virtual void f69(int a);
    virtual void f70(int a);
    virtual void f71(int a);
    virtual void f72(int a);
    virtual void f73(int a);
    virtual void f74(int a);
    virtual void f75(int a);
    virtual void f76(int a);
    virtual void f77(int a);
    virtual void f78(int a);
    virtual void f79(int a);
    virtual void f80(int a);
    virtual void f81(int a);
    virtual void f82(int a);
    virtual void f83(int a);
    virtual void f84(int a);
    virtual void f85(int a);
    virtual void f86(int a);
    virtual void f87(int a);
    virtual void f88(int a);
    virtual void f89(int a);
    virtual void f90(int a);
    virtual void f91(int a);
    virtual void f92(int a);
    virtual void f93(int a);
    virtual void f94(int a);
    virtual void f95(int a);
    virtual void f96(int a);
    virtual void f97(int a);
    virtual void f98(int a);
    virtual void f99(int a);
    virtual void f100(int a);
    virtual void f101(int a);
    virtual void f102(int a);
    virtual void f103(int a);
    virtual void f104(int a);
    virtual void f105(int a);
    virtual void f106(int a);
    virtual void f107(int a);
    virtual void f108(int a);
    virtual void f109(int a);
    virtual void f110(int a);
    virtual void f111(int a);
    virtual void f112(int a);
    virtual void f113(int a);
    virtual void f114(int a);
    virtual void f115(int a);
    virtual void f116(int a);
    virtual void f117(int a);
    virtual void f118(int a);
    virtual void f119(int a);
    virtual void f120(int a);
    virtual void f121(int a);
    virtual void f122(int a);
    virtual void f123(int a);
    virtual void f124(int a);
    virtual void f125(int a);
    virtual void f126(int a);
    virtual void f127(int a);
    virtual void f128(int a);
    virtual void f129(int a);
    virtual void f130(int a);
    virtual void f131(int a);
    virtual void f132(int a);
    virtual void f133(int a);
    virtual void f134(int a);
    virtual void f135(int a);
    virtual void f136(int a);
};

struct Mid {
    char pad0[0x20];
    Poly* p20;
    char pad1[0x34];
    Poly* p58;
    char pad2[0x4];
    Poly* p60;
    char pad3[0x2c];
    Poly* p90;
    char pad4[0x10];
    Poly* pa4;
    char pad5[0x8];
    Class90D8* pb0;
};

struct Self {
    char pad0[0x8];
    void* task;
    char pad1[0xcc];
    Mid* mid;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" char lbl_27_data_4A000[];
extern "C" char lbl_27_data_248[];

extern "C" void fn_27_290214(void* unused, Self* self, int type) {
    if (type != 0) {
        self->mid->p58->f7(1);
        self->mid->p20->f19(0, 0);
        self->mid->p90->f10(1);
        self->mid->p60->f11(1);
        self->mid->pb0->f5(1);
        self->mid->pa4->f4(1);
        CastObj* c = (CastObj*)__dynamic_cast(self->task, 0x3c, lbl_27_data_4A000, lbl_27_data_248, 1);
        c->f136(1);
    }
}
