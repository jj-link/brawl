#include <types.h>
#pragma force_active on

extern "C" void* fn_27_2134C8(void* arg0, void* arg1, u32 key) {
    if (key & 0xFFFF800F) {
        u32* p;
        for (s32 i = 0; i < 2; i++) {
            void* base = (i == 0) ? arg0 : arg1;
            if (base != NULL) {
                u32 n = *(u32*)((char*)base + 4);
                p = (u32*)base;
                for (u32 j = 0; j < n; j++) {
                    u32* entry = (u32*)((char*)base + p[4]);
                    if (entry != NULL && *entry == key) {
                        return entry;
                    }
                    p++;
                }
            }
        }
    }
    {
        u32* p;
        s32 i;
        u32* entry;
        u32 maskedKey = key & 0x7FF0;
        for (i = 0; i < 2; i++) {
            void* base = (i == 0) ? arg0 : arg1;
            if (base != NULL) {
                u32 n = *(u32*)((char*)base + 4);
                p = (u32*)base;
                for (u32 j = 0; j < n; j++) {
                    entry = (u32*)((char*)base + p[4]);
                    if (entry != NULL && (*entry & 0xFFFF7FFF) == maskedKey) {
                        return entry;
                    }
                    p++;
                }
            }
        }
    }
    return NULL;
}
