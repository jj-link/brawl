#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1D0(void* a, int b);
extern "C" void* fn_8016E864(void* data, const char* name);

inline void* find(char* self, const char* name, void* start)
{
    void* result;
    if (!*name)
        return 0;
    if (start) {
        result = fn_8016E864(start, name);
        if (result)
            return result;
    }
    void* item = fn_8015C1D0(self + 0x10, 0);
    while (item) {
        result = fn_8016E864(item, name);
        if (result)
            return result;
        item = fn_8015C1D0(self + 0x10, (int)item);
    }
    return 0;
}

extern "C" s32 fn_8016EBB4(char* arg0, u8* arg1, s32 i)
{
    u32* slot;
    u8* base = arg1 + *(u32*)(arg1 + 0xC);
    u8* offset = (u8*)*(u32*)(arg1 + 0x10);
    base = (u8*)((u32)base + (u32)offset);
    base += *(u32*)(arg1 + 0x14);
    u32* t6_11 = (u32*)(base + 0x20);
    slot = t6_11;
    u16* hdr = (u16*)slot;
    u32 count;
    u8* rec = (u8*)t6_11 + 4 + hdr[0] * 4;

    count = 0;
    i = 0;
    while (i < hdr[0]) {
        u16 size = *(u16*)rec;
        rec += 2;
        slot[1] = (u32)find(arg0, (const char*)rec, 0);
        if (rec[0] != 0 && slot[1] == 0)
            count++;
        rec += size;
        slot++;
        i++;
    }
    return count;
}