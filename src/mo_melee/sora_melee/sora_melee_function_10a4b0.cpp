#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" s32 fn_27_1190D0(void*, s32);
extern "C" ftEntry* getEntity__14ftEntryManagerFUl(void*, u32);

extern "C" s32 fn_27_10A4B0(void* self, s32 id) {
    if (!fn_27_1190D0(*(void**)((char*)self + 0x154), id)) {
        return 0;
    }
    ftEntry* entry = getEntity__14ftEntryManagerFUl(*(void**)((char*)self + 0x154), (u32)id);
    return *(u8*)((char*)entry + 0x8);
}
