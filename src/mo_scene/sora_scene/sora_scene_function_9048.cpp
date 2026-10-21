#include <types.h>
#pragma force_active on

extern "C" {
int fn_1_3E50(void*);
void* fn_800AFBFC(const void*, u32, void*, u32);
void* fn_9_0(void*, void*, void*);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
extern const char lbl_1_data_2110[];
s32 fn_1_9048(void* self) {
    u8* s = (u8*)self;
    if (*(s32*)(*(u8**)(s + 0x35c) + 4) == 0) {
        if (fn_1_3E50(*(void**)(s + 0x39c))) {
            void* r = fn_800AFBFC(lbl_1_data_2110, 0x100, *(void**)(s + 0x398), 0xA);
            **(void***)(s + 0x35c) = r;
            changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
            void* r3 = fn_9_0(*(void**)(*(u8**)(*(u8**)(s + 0x35c)) + 0x48), s + 0x360, *(void**)(s + 0x398));
            *(void**)(*(u8**)(s + 0x35c) + 4) = r3;
        }
    }
    return 0;
}
}
