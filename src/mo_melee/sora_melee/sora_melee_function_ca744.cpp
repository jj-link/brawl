#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 pad : 10;
        u32 field : 5;
        u32 rest : 17;
    } flags;
} FnState;

extern "C" {
void fn_27_CA744(FnState *s, u32 v)
{
    s->flags.field = v;
}
}
