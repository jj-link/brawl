#pragma force_active on
typedef unsigned int u32;

struct fn_27_Obj {
    char pad[8];
    u32 flags;
};

extern "C" {
void fn_27_1A17F0(fn_27_Obj* p) {
    p->flags &= 0xFFFFDFFF;
}
}
