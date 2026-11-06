#include <types.h>
#pragma force_active on

struct Entry {
    u8 data[0x2008];
    u8 active;
    u8 padding[0x17];
};
struct Context {
    u8 padding[0x84];
    Entry* entries;
    u16 unused;
    u16 count;
};
extern "C" void fn_801F28F0(void*, u32, u16, u16, u32, u32, u32, u8);
extern "C" int fn_80034924(Context* ctx, u32 index, void* out) {
    int result = 0;
    Entry* entries = ctx->entries;
    if (entries && ctx->count > index && entries[index].active) {
        fn_801F28F0(out, (u32)&entries[index], 0x40, 0x40, 4, 0, 0, 0);
        result = 1;
    }
    return result;
}