#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 hi : 20;
    u32 mid : 10;
    u32 lo : 2;
} FnState;

extern "C" void fn_27_1A3A10(FnState* s, u32 v)
{
    s->mid = v;
}
