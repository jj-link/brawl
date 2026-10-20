#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 f8_hi : 5;
    u32 f8_mid : 5;
    u32 f8_lo : 22;
} FnStruct;

extern "C" {
void fn_27_19D8C4(FnStruct* p, u32 v) {
    p->f8_mid = v;
}
}
