#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 f : 4;
        u32 rest : 28;
    } bits;
} FnStruct;

extern "C" {
void fn_27_1D08C4(FnStruct* p, u32 v) {
    p->bits.f = v;
}
}
