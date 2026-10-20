#pragma force_active on
typedef unsigned int u32;

struct fn_40_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_40_289AC(fn_40_Obj* p) {
    p->flags &= 0xFFF7FFFF;
}
}
