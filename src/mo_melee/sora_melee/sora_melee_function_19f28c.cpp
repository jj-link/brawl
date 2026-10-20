#pragma force_active on
typedef unsigned int u32;

struct Field {
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
};

extern "C" void fn_27_19F28C(void *p, u32 v)
{
    Field *w = (Field *)((char *)p + 8);
    w->b = v;
}
