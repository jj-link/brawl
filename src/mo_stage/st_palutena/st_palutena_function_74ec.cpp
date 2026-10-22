#include <types.h>
#pragma force_active on

struct P {
    u32 x;
    u32 y;
};

struct Rec {
    P p00;
    u32 w08;
    P p0c;
    u32 w14;
    u32 w18;
    P p1c;
    u32 w24;
    P p28;
    u32 w30;
    u32 w34;
    u32 w38;
    u32 w3c;
    P p40;
    u32 w48;
    float f4c;
    float f50;
    float f54;
    P p58;
    P p60;
    P p68;
    s16 h70;
    u8 b72;
    u8 b73;
    u8 b74;
};

#define D(x) virtual void f##x() {}
class V1 {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25)
    virtual Rec* getSrc();
};
class V2 {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25)
    virtual Rec* getDst(u32 idx);
};

extern "C" void fn_67_74EC(V1* self, void* unused, u32 idx) {
    Rec* src = self->getSrc();
    Rec* dst = ((V2*)self)->getDst(idx);
    *dst = *src;
}
