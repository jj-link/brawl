#pragma force_active on
typedef unsigned int u32;

struct fn_27_1D06BC_t {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 4;
        u32 b : 4;
        u32 c : 24;
    } unk8;
};

extern "C" void fn_27_1D06BC(fn_27_1D06BC_t* p, u32 v)
{
    p->unk8.b = v;
}
