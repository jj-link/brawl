#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 a : 12;
    u32 b : 6;
    u32 c : 14;
} Bits;

extern "C" {
void fn_27_CEBD8(Bits* p, u32 v) {
    p->b = v;
}
}
