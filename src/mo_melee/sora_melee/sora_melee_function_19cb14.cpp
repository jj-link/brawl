#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 pad0 : 2;
    u32 field : 2;
    u32 rest : 28;
} FlagsHolder;

extern "C" void fn_27_19CB14(FlagsHolder *p, u32 v)
{
    p->field = v;
}
