#include <types.h>
#pragma force_active on
#pragma peephole off

extern "C" {
extern float lbl_805A3118;

inline void setPair(float* out, float x, float y) {
    out[0] = x;
    out[1] = y;
}

void fn_8018ACEC(float* out, const void* object, u32 index) {
    const char* p = (const char*)object;
    if (index >= (*(const u32*)(p + 0x3C) >> 28)) {
        float zero = lbl_805A3118;
        out[0] = zero;
        out[1] = zero;
    } else {
        const char* entry = *(const char* const*)(p + 0x40) + index * 0x1C;
        setPair(out, (float)*(const u16*)(entry + 8),
                     (float)*(const u16*)(entry + 0xA));
    }
}
}
