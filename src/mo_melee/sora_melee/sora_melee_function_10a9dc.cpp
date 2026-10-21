#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" u8* getEntity__14ftEntryManagerFUl(void*, u32);
extern "C" s32 fn_27_13C984(void*);

extern "C" bool fn_27_10A9DC(void* self, u32 id) {
    s32 result;
    if (fn_27_1190D0(*(void**)((char*)self + 0x154)) == 0) {
        result = 0;
    } else {
        u8* entry = getEntity__14ftEntryManagerFUl(*(void**)((char*)self + 0x154), id);
        result = *(s32*)((char*)entry + *(u8*)(entry + 0xa) * 8 + 0x34);
    }
    return result != 0 && fn_27_13C984((void*)result) != 0;
}
