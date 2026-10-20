#pragma force_active on
typedef unsigned int u32;

struct fn_27_C9784_obj {
    char pad[8];
    u32 flags;
};

extern "C" {
void fn_27_C9784(fn_27_C9784_obj* p) {
    p->flags &= ~0x02000000;
}
}
