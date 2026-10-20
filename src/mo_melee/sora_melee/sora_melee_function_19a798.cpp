#pragma force_active on
typedef unsigned int u32;

struct Target {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_19A798(Target* p)
{
    p->flags &= 0xFFBFFFFF;
}
