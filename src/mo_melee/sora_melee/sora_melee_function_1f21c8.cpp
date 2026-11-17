#include <ai/ai_mgr.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_21C8D4(void* table, int index, void* manager);
void fn_27_20B0D0(void* entry, void* data, signed char* id);
void fn_27_1FA86C(void* self, void* arg1, int arg2, int arg3);
void fn_27_1FAA80(void* self, signed char* id, void* arg);
}

union AlignedId { signed char value; int alignment; };

inline bool valid(u8* self, int n) {
    if (n >= 0 && n < 14 && *(s8*)(self + n + 0x84) != 0 &&
        *(void**)(self + n * 4 + 0x4c) != 0) {
        return true;
    }
    return false;
}

inline u8* getEntry(const signed char* id) {
    u8 value = *id;
    u8* result;
    if ((signed char)value >= 0) {
        bool normal = false;
        if ((signed char)value >= 0 && (signed char)value < 14) {
            normal = true;
        }
        if (normal) {
            result = *(u8**)((u8*)g_aiMgr + 0xF8) + (int)(signed char)value * 0x1C4;
        } else {
            void* table = *(void**)((u8*)g_aiMgr + 0x100);
            void* data = fn_27_21C8D4(table, (int)(signed char)value - 14, g_aiMgr);
            result = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
            if (*(signed char*)((u8*)g_aiMgr + 0xA4) != (signed char)*id - 14 && data != 0) {
                fn_27_20B0D0(result, data, (signed char*)id);
                *(u8*)((u8*)g_aiMgr + 0xA4) = (u8)(*id - 14);
            }
        }
    } else {
        result = *(u8**)((u8*)g_aiMgr + 0xF8) + 0x18B8;
    }
    return result;
}

extern "C" void fn_27_1F21C8(u8* self, int entryId, int unused, u8* arg) {
    int playerNo = g_ftManager->getPlayerNo(entryId);
    if (valid(self, playerNo)) {
        AlignedId id;
        id.value = playerNo;
        u8* entry = getEntry(&id.value);
        *(s32*)(entry + 0xD8) = (s8)arg[0x30];
        fn_27_1FA86C(*(void**)(self + id.value * 4 + 0x4c), arg, 0, 0);
    }
    u8* walk = self;
    for (int i = 0; i < 7; i++) {
        AlignedId id;
        id.value = i;
        u8* entry = getEntry(&id.value);
        if (*(s32*)(entry + 0xAC) != -1 &&
            *(u32*)(arg + 0x1C) == *(u32*)(entry + 0xE0) &&
            (int)self[0x84 + i] == 1 && *(void**)(walk + 0x4c) != 0) {
            AlignedId other;
            other.value = playerNo;
            fn_27_1FAA80(*(void**)(walk + 0x4c), &other.value, arg);
        }
        walk += 4;
    }
}