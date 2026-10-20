#pragma force_active on
typedef unsigned int u32;

typedef struct FooObj {
    u32 unk0;
    u32 unk4;
    u32 hi : 8;
    u32 rest : 24;
} FooObj;

extern "C" void fn_27_D0FFC(FooObj* p, u32 v) {
    p->hi = v;
}
