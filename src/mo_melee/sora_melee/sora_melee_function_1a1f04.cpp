#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
} Bits;

extern "C" {
void fn_27_1A1F04(void* p, u32 v);
}

void fn_27_1A1F04(void* p, u32 v) {
    Bits* w = (Bits*)((char*)p + 8);
    w->b = v;
}
