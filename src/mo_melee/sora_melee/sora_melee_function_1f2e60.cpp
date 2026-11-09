#include <ai/ai_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_21C8D4(void* table, int index, void* manager);
void fn_27_20B0D0(void* entry, void* data, signed char* id);

int fn_27_1F2E60(u8* mgr, int idx) {
    u8* entry;
    if (idx >= 0 && idx < 7 && (mgr + 0x4c) != 0) {
        u8* node = *(u8**)(mgr + idx * 4 + 0x4c);
        if (node != 0) {
            u8* obj = *(u8**)(node + 0x34);
            if (obj != 0 && *(s32*)(obj + 0x48) == 0x79) {
                signed char value = *(signed char*)(obj + 0x42);
                if (value >= 0) {
                    bool normal = false;
                    if (value >= 0 && value < 14) {
                        normal = true;
                    }
                    if (normal) {
                        entry = *(u8**)((u8*)g_aiMgr + 0xF8) + (int)value * 0x1C4;
                    } else {
                        void* table = *(void**)((u8*)g_aiMgr + 0x100);
                        void* data = fn_27_21C8D4(table, (int)value - 14, g_aiMgr);
                        entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
                        if (*(signed char*)((u8*)g_aiMgr + 0xA4) != *(signed char*)(obj + 0x42) - 14 && data != 0) {
                            fn_27_20B0D0(entry, data, (signed char*)(obj + 0x42));
                            *(u8*)((u8*)g_aiMgr + 0xA4) = (u8)(*(signed char*)(obj + 0x42) - 14);
                        }
                    }
                } else {
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
                }
                if (!(*(u32*)(entry + 0x50) & 0x8000)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
}
