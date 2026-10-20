#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct FnState {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u8 f10;
    u8 pad11;
    u8 pad12;
    u8 f13;
    u8 f14;
} FnState;

extern "C" void fn_27_35C3C(FnState* s, u32 a4, u8 a5, u32 a6, u32 a7, u32 a8, u8 a9)
{
    s->f00 = a7;
    s->f04 = a6;
    s->f08 = a8;
    s->f0C = a4;
    s->f10 = a5;
    s->f13 = 0;
    s->f14 = a9;
}
