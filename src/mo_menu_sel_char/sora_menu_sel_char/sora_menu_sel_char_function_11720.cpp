#include <types.h>
#pragma force_active on

extern "C" s32 getMsgData__5MuMsgFUlPPv(void* self, u32 index, void** size);
extern "C" void* memcpy(void* dest, const void* src, u32 size);
extern "C" int sprintf(char* dest, const char* format, ...);
extern "C" char* strcpy(char* dest, const char* src);
extern "C" const char lbl_10_data_748[];
extern "C" const char lbl_10_data_750[];

extern "C" void fn_10_11720(void* self, char* dest) {
    s32 count = *(s32*)((u8*)self + 0x1CC);
    void* size;
    void* msg = (void*)getMsgData__5MuMsgFUlPPv(*(void**)((u8*)self + 0x40C), count > 0, &size);
    memcpy(dest, msg, (u32)size);
    char suffix[16];
    if (count > 0) {
        sprintf(suffix, lbl_10_data_748, count);
    } else {
        sprintf(suffix, lbl_10_data_750, *(s32*)((u8*)self + 0x1B0) + 1);
    }
    strcpy(dest + (u32)size, suffix);
}
