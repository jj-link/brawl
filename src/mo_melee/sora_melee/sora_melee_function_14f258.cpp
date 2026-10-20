#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 f : 7;
    u32 rest : 25;
} S;

extern "C" void fn_27_14F258(S* p, u32 v) {
    p->f = v;
}
