#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 top : 3;
    u32 rest : 29;
};

extern "C" {
void fn_27_C9F50(void* p, u32 v)
{
    Flags* f = (Flags*)((char*)p + 8);
    f->top = v;
}
}
