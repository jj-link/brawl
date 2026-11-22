#include <types.h>
#include <mt/mt_prng.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_3FC0;
extern int lbl_27_rodata_3FC8[];
}
struct Obj {
    char pad0[0x40];
    unsigned char b40;
    char pad41[0x1f];
    float f60;
    float f64;
    float f68;
    unsigned char b6C;
};
inline void update(Obj* self, int off) {
    struct Block { int data[6]; };
    Block block = *(Block*)lbl_27_rodata_3FC8;
    self->f60 = lbl_27_rodata_3FC0;
    float* f = (float*)&block;
    self->f64 = *(float*)((char*)f + off)
        + (*(float*)((char*)&block.data[1] + off) - *(float*)((char*)f + off)) * randf();
}
extern "C" void fn_27_247810(Obj* self) {
    self->b40 = 1;
    update(self, self->b6C * 8);
}
