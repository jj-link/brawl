#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" void* getEntity__14ftEntryManagerFUl(u32, u32);
extern "C" void* fn_27_11538C(char* p);

extern "C" void* fn_27_10B174(void* self, u32 idx) {
    if (fn_27_1190D0(*(void**)((char*)self + 0x154)) == 0) {
        return 0;
    }
    return fn_27_11538C((char*)getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154), idx));
}
