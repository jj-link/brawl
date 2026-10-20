#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 mode : 2;
    u32 rest : 30;
} FnState;

extern "C" void fn_27_CB514(FnState* p, u32 v) {
    p->mode = v;
}
