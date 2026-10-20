#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct FnBits {
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

struct FnObj {
    u8 pad[8];
    FnBits bits;
};

extern "C" {
void fn_27_CD9C8(FnObj* p, u32 v) {
    p->bits.b = v;
}
}
