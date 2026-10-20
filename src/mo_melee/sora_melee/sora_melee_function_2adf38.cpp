#pragma force_active on
typedef unsigned char u8;
typedef short s16;

struct FnObj {
    u8 hi : 1;
    u8 lo : 7;
    u8 pad1[7];
    s16 s8;
    s16 sA;
};

extern "C" {
void fn_27_2ADF38(FnObj* p) {
    p->hi = 0;
    p->s8 = -1;
    p->sA = -1;
}
}
