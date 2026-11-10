#include <types.h>
#pragma force_active on
struct Entry { u8 data[0x2000]; unsigned long long key; u8 active; u8 pad[0x17]; };
struct Context { u8 pad[0x7c]; Entry* entries; u16 count, size; };
extern "C" void fn_801F28F0(void*, u32, u16, u16, u32, u32, u32, u8);
inline int copyEntry(void* obj, u16 index, void* out) {
    int result = 0;
    Entry* entries = *(Entry**)((u8*)obj + 0x7c);
    if (entries && *(u16*)((u8*)obj + 0x82) > index && entries[index].active) {
        fn_801F28F0(out, (u32)&entries[index], 0x40, 0x40, 4, 0, 0, 0);
        result = 1;
    }
    return result;
}
extern "C" int fn_800342F4(Context* ctx, int unused, unsigned long long key, void* out) {
    int result = 0;
    if (ctx->entries) {
        u16 found = 0xffff;
        for (u16 i = 0; i < ctx->count; i++) {
            if (ctx->entries[i].key == key) {
                found = i;
                break;
            }
        }
        result = copyEntry(ctx, found, out);
    }
    return result;
}