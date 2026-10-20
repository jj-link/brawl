#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0 : 4;
    u32 f : 4;
    u32 rest : 24;
};

extern "C" {
void fn_27_CAD40(void* p, u32 v)
{
    Bits* w = (Bits*)((char*)p + 8);
    w->f = v;
}
}
