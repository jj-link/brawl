#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} FnObj27;

extern "C" void fn_27_19B0F0(FnObj27* p) {
    p->flags &= 0xFFFEFFFF;
}
