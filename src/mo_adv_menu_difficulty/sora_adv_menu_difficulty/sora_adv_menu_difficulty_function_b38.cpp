#include <types.h>
#pragma force_active on

extern "C" {
extern float lbl_32_rodata_0[];
void setFrameNode__8MuObjectFf(void* obj, float frame);

void* fn_32_B38(void* self) {
    float* base = lbl_32_rodata_0;
    void* obj = *(void**)((char*)self + 0x1B4);
    s32 state = *(s32*)((char*)self + 0x4C);
    switch (state) {
    case 0:
        setFrameNode__8MuObjectFf(obj, base[15]);
        break;
    case 1:
        setFrameNode__8MuObjectFf(obj, base[16]);
        break;
    case 2:
        setFrameNode__8MuObjectFf(obj, base[20]);
        break;
    case 3:
        setFrameNode__8MuObjectFf(obj, base[21]);
        break;
    case 4:
        setFrameNode__8MuObjectFf(obj, base[22]);
        break;
    }
    return *(void**)((char*)self + 0x1C8);
}
}
