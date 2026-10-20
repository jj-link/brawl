#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 hi : 10;
    u32 lo : 22;
} Obj;

extern "C" {
void fn_27_1A5B10(Obj *p, u32 v)
{
    p->hi = v;
}
}
