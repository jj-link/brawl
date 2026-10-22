#include <types.h>
#pragma force_active on

extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_8014652C(void* arg);
extern u8 g_Network[];
extern u8 lbl_80457904[];
extern void* g_muWifiInterfaceTask;

extern "C" s32 fn_800C9D70(u8* self) {
    s32 flag;
    void* task = g_muWifiInterfaceTask;
    if (task != nullptr && *(s32*)((u8*)task + 0x40) == 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag == 0) {
        return 0;
    }
    netReport__FPCce((const char*)lbl_80457904);
    fn_8014652C(g_Network);
    *(s32*)(self + 0x40) = 1;
    return 1;
}
