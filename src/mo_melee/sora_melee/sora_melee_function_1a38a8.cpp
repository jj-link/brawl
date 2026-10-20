#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" {
void fn_27_1A38A8(void* p, u32 v)
{
    Flags* f = (Flags*)((char*)p + 8);
    f->b = v;
}
}
