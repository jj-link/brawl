#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad[2];
    u32 x : 5;
    u32 field : 5;
    u32 rest : 22;
};

extern "C" void fn_27_1A5004(void* p, u32 v)
{
    ((Flags*)p)->field = v;
}
