#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 f : 10;
    u32 g : 22;
} FnBitfield;

extern "C" void fn_27_1A3888(FnBitfield* p, u32 v) {
    p->f = v;
}
