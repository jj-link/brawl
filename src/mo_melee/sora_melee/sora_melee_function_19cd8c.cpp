#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} fn_27_19CD8C_arg;

extern "C" void fn_27_19CD8C(fn_27_19CD8C_arg *p)
{
    p->flags &= ~0x00400000u;
}
