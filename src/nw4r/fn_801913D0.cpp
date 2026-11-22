#include <types.h>
#include <GX.h>
#pragma force_active on
extern "C" void fn_8018CC44(unsigned char*, unsigned int);
static inline void set(u32 i2, unsigned char* ptr, unsigned char* color) {
    u32 v2;
    u32 v1 = color[0] | ((i2 + 0xE0) << 24) | ((color[3] << 12) & 0xff000);
    v2 = ((color[1] << 12) & 0xff000) | color[2] | ((i2 + 0xE1) << 24);
    fn_8018CC44(ptr, v1);
    fn_8018CC44(ptr + 5, v2);
    fn_8018CC44(ptr + 10, v2);
    fn_8018CC44(ptr + 15, v2);
}
extern "C" void GXSetTevColor__Q34nw4r3g3d14ResMatTevColorFUl8_GXColor(void* self, u32 index, GXColor color) {
    set(index * 2, *(unsigned char**)self + (index - 1) * 20, (unsigned char*)&color);
}