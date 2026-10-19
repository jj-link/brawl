#include <types.h>
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
extern "C" extern const float lbl_49_rodata_100;
extern "C" extern const float lbl_49_rodata_84;

extern "C" void fn_49_4570(u8* self) {
    u8* r30 = self + 0xd0;
    u8* dst;
    if (r30 != 0) {
        u8** arr = *(u8***)(self + 0x44);
        u8* model = arr[*(u32*)(self + 0xc0)];
        if (model != 0) {
            if (*(u32*)(model + 0x11c) == 0) {
                *(u32*)(r30 + 0xc) = 0;
                **(u32**)(r30 + 4) = *(u32*)(self + 0xc4);
                *(u8**)(model + 0x11c) = r30;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(u16*)(model + 0x122) = (u16)**(u32**)(r30 + 4);
            }
            u8* src = *(u8**)(self + 0x158);
            if (src != 0) {
                dst = *(u8**)(r30 + 4);
                *(float*)(dst + 8) = *(float*)(src + 0xc);
                *(float*)(dst + 0xc) = *(float*)(src + 0x10);
                *(float*)(dst + 0x10) = *(float*)(src + 0x14);
                *(float*)(*(u8**)(r30 + 4) + 0xc) += lbl_49_rodata_100;
                *(float*)(*(u8**)(r30 + 4) + 0x10) += lbl_49_rodata_84;
                *(float*)(*(u8**)(r30 + 4) + 0x18) = *(float*)(*(u8**)(self + 0x158) + 0x1c);
            }
        }
    }
}
