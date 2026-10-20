#pragma force_active on
typedef unsigned int u32;

typedef struct {
    char pad[8];
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
} FlagHolder;

extern "C" void fn_27_1E7CA8(FlagHolder *p, u32 v)
{
    p->b = v;
}
