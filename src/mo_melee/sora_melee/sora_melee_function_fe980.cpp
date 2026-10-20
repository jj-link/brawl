#pragma force_active on
typedef unsigned int u32;

struct FieldWord {
    u32 a : 3;
    u32 b : 3;
    u32 c : 3;
    u32 rest : 23;
};

extern "C" void fn_27_FE980(void *p, u32 v)
{
    FieldWord *w = (FieldWord *)((char *)p + 8);
    w->b = v;
}
