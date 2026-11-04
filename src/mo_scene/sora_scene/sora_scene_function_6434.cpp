#include <types.h>
#pragma force_active on

extern "C" {
int fn_1_3E50(void*);
void* fn_800AFBFC(const void*, u32, void*, u32);
void* fn_12_0(void*, void*);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
extern const char lbl_1_data_146C[];
extern char* g_gfApplication;

s32 fn_1_6434(void* self) {
    u8* s = (u8*)self;
    if (*(u8*)(s + 0x378) == 0) {
        if (fn_1_3E50(*(void**)(s + 0x380)) == 0)
            return 0;
        void* r2 = fn_800AFBFC(lbl_1_data_146C, 0x100, *(void**)(s + 0x37c), 0xA);
        **(void***)(s + 0x35c) = r2;
        changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
        void* r3 = fn_12_0(s + 0x360, *(void**)(s + 0x37c));
        *(void**)(*(u8**)(s + 0x35c) + 4) = r3;
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        *(u8*)(s + 0x378) = 1;
    }
    return 0;
}
}