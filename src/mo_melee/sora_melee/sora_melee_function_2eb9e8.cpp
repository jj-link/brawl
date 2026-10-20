#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
} FnBits;

extern "C" {
void fn_27_2EB9E8(FnBits *p, u32 v) {
    p->b = v;
}
}
