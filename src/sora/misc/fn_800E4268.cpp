#include <types.h>
#pragma force_active on

extern "C" int fn_800B61C0(void*);

extern "C" s32 fn_800E4268(s32 arg0, void* arg1) {
    void* ptr = *(void**)((char*)arg1 + (arg0 + 0x19) * 4 + 0x28);
    if (fn_800B61C0(ptr) != 0) {
        return 0;
    }
    return *(s32*)((char*)arg1 + arg0 * 4 + 0x214);
}