#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 a;
    u32 b;
    unsigned int f0 : 6;
    signed int   f1 : 3;
    unsigned int f2 : 23;
} Obj;

extern "C" s32 fn_27_1A1394(Obj* p) {
    return (s32)p->f1;
}
