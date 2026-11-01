#include <ai/ai_mgr.h>
#include <types.h>

#pragma force_active on

struct AiEntry {
    u8 data[0x1C4];
};

extern "C" {
void* fn_27_21C8D4(void* table, int index, void* manager);
void fn_27_20B0D0(void* entry, void* data, signed char* id);

AiEntry* fn_27_1F1F58(const signed char* id) {
    u8 value;
    value = *id;
    AiEntry* result;

    if ((signed char)value >= 0) {
        bool normal = false;
        if ((signed char)value >= 0 && (signed char)value < 14) {
            normal = true;
        }

        if (normal) {
            result = (AiEntry*)(*(u8**)((u8*)g_aiMgr + 0xF8) +
                                (int)(signed char)value * 0x1C4);
        } else {
            void* table = *(void**)((u8*)g_aiMgr + 0x100);
            void* data = fn_27_21C8D4(
                table, (int)(signed char)value - 14, g_aiMgr);
            result = (AiEntry*)(*(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8);

            if (*(signed char*)((u8*)g_aiMgr + 0xA4) !=
                    (signed char)*id - 14 &&
                data != 0) {
                fn_27_20B0D0(result, data, (signed char*)id);
                *(u8*)((u8*)g_aiMgr + 0xA4) = (u8)(*id - 14);
            }
        }
    } else {
        result = (AiEntry*)((u8*)g_aiMgr + 0xF8);
        result = (AiEntry*)(*(u8**)result + 0x18B8);
    }

    return result;
}
}
