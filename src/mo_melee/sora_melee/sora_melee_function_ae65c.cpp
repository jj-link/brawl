#pragma force_active on
typedef unsigned int u32;

typedef struct Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
} Obj;

extern "C" void fn_27_AE65C(Obj* p) {
    p->flags |= 0x02000000;
}
