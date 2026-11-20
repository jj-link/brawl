#include <ai/ai_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1FACE4(void* self, u32 flag);
void* fn_27_21C8D4(void* table, int index, void* manager);
void fn_27_20B0D0(void* entry, void* data, signed char* id);
void fn_27_21DB30(void* a, s8 b, int c, int d);
void fn_27_1F25C8(void* self, int playerNo, int flag);
}

struct AiMgrSlots {
    char pad[0x4c];
    void* first[7];
    void* second[7];
};

extern "C" void fn_27_1F13E4(int arg0, int arg1, int arg2) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;

    if (arg0 < 0 || arg0 >= 7) {
        return;
    } else {
        if (reinterpret_cast<AiMgrSlots*>(g_aiMgr)->first[arg0] != NULL) {
            fn_27_1FACE4(reinterpret_cast<AiMgrSlots*>(g_aiMgr)->first[arg0], arg1);
        }
        if (reinterpret_cast<AiMgrSlots*>(g_aiMgr)->second[arg0] != NULL) {
            fn_27_1FACE4(reinterpret_cast<AiMgrSlots*>(g_aiMgr)->second[arg0], arg1);
        }

        if (arg1 != 0) {
            void* table;
            void* data;
            u8* entry;
            u8* sub;
            *(u8*)&sp14 = (u8)arg0;
            if (*(s8*)&sp14 >= 0) {
                bool normal = false;
                if (*(s8*)&sp14 >= 0 && *(s8*)&sp14 < 14) {
                    normal = true;
                }
                if (normal) {
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + *(s8*)&sp14 * 0x1C4;
                } else {
                    table = *(void**)((u8*)g_aiMgr + 0x100);
                    data = fn_27_21C8D4(table, *(s8*)&sp14 - 14, g_aiMgr);
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
                    if (*(s8*)((u8*)g_aiMgr + 0xA4) != *(s8*)&sp14 - 14 && data != NULL) {
                        fn_27_20B0D0(entry, data, (signed char*)&sp14);
                        *((u8*)g_aiMgr + 0xA4) = (u8)(*(s8*)&sp14 - 14);
                    }
                }
            } else {
                entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
            }
            *(u32*)(entry + 0x50) &= 0xBFFFFFFF;

            {
            u8* entry;
            *(u8*)&sp10 = (u8)(arg0 + 7);
            if (*(s8*)&sp10 >= 0) {
                bool normal = false;
                if (*(s8*)&sp10 >= 0 && *(s8*)&sp10 < 14) {
                    normal = true;
                }
                if (normal) {
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + *(s8*)&sp10 * 0x1C4;
                } else {
                    table = *(void**)((u8*)g_aiMgr + 0x100);
                    data = fn_27_21C8D4(table, *(s8*)&sp10 - 14, g_aiMgr);
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
                    if (*(s8*)((u8*)g_aiMgr + 0xA4) != *(s8*)&sp10 - 14 && data != NULL) {
                        fn_27_20B0D0(entry, data, (signed char*)&sp10);
                        *((u8*)g_aiMgr + 0xA4) = (u8)(*(s8*)&sp10 - 14);
                    }
                }
            } else {
                entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
            }
            *(u32*)(entry + 0x50) &= 0xBFFFFFFF;
            }

            sub = (u8*)reinterpret_cast<AiMgrSlots*>(g_aiMgr)->first[arg0];
            if (sub != NULL) {
                u8* sec = *(u8**)(sub + 0x34);
                fn_27_21DB30(sub + 0x90, (s8)sub[0x98], 1, 1);
                if (sec != NULL) {
                    fn_27_21DB30(sec + 0x90, (s8)sec[0x98], 1, 1);
                }
            }
        } else if (arg2 != 0) {
            void* table;
            void* data;
            u8* entry;
            *(u8*)&spC = (u8)arg0;
            if (*(s8*)&spC >= 0) {
                bool normal = false;
                if (*(s8*)&spC >= 0 && *(s8*)&spC < 14) {
                    normal = true;
                }
                if (normal) {
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + *(s8*)&spC * 0x1C4;
                } else {
                    table = *(void**)((u8*)g_aiMgr + 0x100);
                    data = fn_27_21C8D4(table, *(s8*)&spC - 14, g_aiMgr);
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
                    if (*(s8*)((u8*)g_aiMgr + 0xA4) != *(s8*)&spC - 14 && data != NULL) {
                        fn_27_20B0D0(entry, data, (signed char*)&spC);
                        *((u8*)g_aiMgr + 0xA4) = (u8)(*(s8*)&spC - 14);
                    }
                }
            } else {
                entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
            }
            *(u32*)(entry + 0x50) |= 0x40000000;

            {
            u8* entry;
            *(u8*)&sp8 = (u8)(arg0 + 7);
            if (*(s8*)&sp8 >= 0) {
                bool normal = false;
                if (*(s8*)&sp8 >= 0 && *(s8*)&sp8 < 14) {
                    normal = true;
                }
                if (normal) {
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + *(s8*)&sp8 * 0x1C4;
                } else {
                    table = *(void**)((u8*)g_aiMgr + 0x100);
                    data = fn_27_21C8D4(table, *(s8*)&sp8 - 14, g_aiMgr);
                    entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
                    if (*(s8*)((u8*)g_aiMgr + 0xA4) != *(s8*)&sp8 - 14 && data != NULL) {
                        fn_27_20B0D0(entry, data, (signed char*)&sp8);
                        *((u8*)g_aiMgr + 0xA4) = (u8)(*(s8*)&sp8 - 14);
                    }
                }
            } else {
                entry = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
            }
            *(u32*)(entry + 0x50) |= 0x40000000;
            }
            fn_27_1F25C8(g_aiMgr, arg0, 0);
        }
    }
}
