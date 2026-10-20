#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
} Bits;

extern "C" void fn_70_92A0(void *self, u32 value) {
    Bits *bf = (Bits*)((u8*)self + 8);
    bf->b = value;
}
