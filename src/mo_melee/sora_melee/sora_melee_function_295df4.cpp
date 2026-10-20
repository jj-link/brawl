#pragma force_active on
typedef unsigned int u32;

struct Obj {
    int pad[2];
    u32 flags;
};

extern "C" {
int fn_27_295DF4(Obj* p)
{
    return (int)((p->flags << 8) & 0xF8000000) >> 28;
}
}
