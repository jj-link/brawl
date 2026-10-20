#pragma force_active on
typedef unsigned int u32;

struct fn_27_1E7CD8_obj {
    u32 pad0;
    u32 pad4;
    u32 flags;
};

extern "C" void fn_27_1E7CD8(fn_27_1E7CD8_obj *p)
{
    p->flags &= ~0x02000000;
}
