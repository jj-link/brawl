#pragma force_active on
typedef unsigned int u32;

struct fn_27_CDCB4_bits {
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

struct fn_27_CDCB4_obj {
    u32 unk0;
    u32 unk4;
    fn_27_CDCB4_bits w;
};

extern "C" {
void fn_27_CDCB4(fn_27_CDCB4_obj *p, u32 v)
{
    p->w.f = v;
}
}
