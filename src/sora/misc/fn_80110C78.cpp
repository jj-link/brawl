#include <types.h>
#pragma force_active on
extern "C" void* fn_80110C78(void* arg0, u32 arg1, u32 arg2, u32 arg3) {
    u16 count = *(u16*)((u8*)arg0 + 6);
    void* entry;
    s32 offset = 0;
    for (u32 i = 0; i < count; i++) {
        void* base = *(void**)((u8*)arg0 + 0x18);
        entry = (void*)((u8*)base + offset);
        if (*(u32*)((u8*)entry + 0x58) == arg1 &&
            *(u16*)((u8*)entry + 0x4E) == arg2 &&
            *(u16*)((u8*)entry + 0x50) == arg3) {
            return (void*)entry;
        }
        offset += 0x60;
    }
    return 0;
}
