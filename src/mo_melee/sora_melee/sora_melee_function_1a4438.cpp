#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 : 20;
    u32 value : 10;
    u32 : 2;
};

extern "C" void fn_27_1A4438(void* p, u32 v)
{
    Flags* w = (Flags*)((char*)p + 8);
    w->value = v;
}
