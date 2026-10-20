#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" u8* getEntity__14ftEntryManagerFUl(void*, u32);

extern "C" bool fn_27_10A448(void* self, u32 id) {
    if (fn_27_1190D0(*(void**)((char*)self + 0x154)) == 0) {
        return false;
    }
    u8* entry = getEntity__14ftEntryManagerFUl(*(void**)((char*)self + 0x154), id);
    return entry[0xf] == 6;
}
