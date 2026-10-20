#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct FeffObj {
    u8 pad[8];
    u32 a : 4;
    u32 f : 4;
    u32 b : 24;
};

extern "C" void fn_27_FEFF8(FeffObj* p, u32 v) {
    p->f = v;
}
