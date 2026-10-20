#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_CB8B4(Obj* p) {
    p->flags |= 0x400000;
}
