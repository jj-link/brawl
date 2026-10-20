#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} fn_27_B03B4_obj;

extern "C" void fn_27_B03B4(fn_27_B03B4_obj* p) {
    p->flags &= ~0x10u;
}
