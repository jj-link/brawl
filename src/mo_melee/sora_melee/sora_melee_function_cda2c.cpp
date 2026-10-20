#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 pad8 : 4;
    u32 field8 : 2;
    u32 rest8 : 26;
} FnStruct;

extern "C" void fn_27_CDA2C(FnStruct* p, u32 v) {
    p->field8 = v;
}
