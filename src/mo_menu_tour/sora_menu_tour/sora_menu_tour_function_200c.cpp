#include <types.h>
#pragma force_active on

extern "C" void fn_800B672C(void* obj, float* out, const char* name);
extern char lbl_3_data_54[];

extern "C" void fn_3_200C(u8* self, s32 arg) {
    float pos[3];
    u8* data = (u8*)lbl_3_data_54;
    u32 idx = *(u32*)(self + 0xf28);
    u32 idx2 = *(u32*)(self + idx * 4 + 0xf14);
    void* obj = *(void**)(self + idx2 * 4 + 0xfd0);
    pos[0] = *(float*)((u8*)obj + 0x3c);
    pos[1] = *(float*)((u8*)obj + 0x40);
    pos[2] = *(float*)((u8*)obj + 0x44);
    *(float*)(self + *(u32*)(self + 0xf28) * 4 + 0xf2c) = pos[0];
    u32 idx3 = *(u32*)(self + 0xb88);
    fn_800B672C(*(void**)(self + idx3 * 4 + 4), pos, (const char*)data);
    idx = *(u32*)(self + 0xf28);
    u8* p = self + idx * 4;
    *(float*)(p + 0xf3c) = pos[0] + *(float*)(p + 0xf2c);
    *(u32*)(self + 0xf24) = 0;
    *(u32*)(self + 0xf4c) = arg;
}
