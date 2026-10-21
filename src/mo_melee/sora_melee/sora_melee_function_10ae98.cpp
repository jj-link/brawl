#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" void* getEntity__14ftEntryManagerFUl(void*, u32);
extern "C" s32 fn_27_8CA94(void*);

extern "C" {
void fn_27_10AE98(void* self, u32 arg1, s32 arg2) {
    void* p;
    if (fn_27_1190D0(*(void**)((u8*)self + 0x154)) == 0) {
        p = 0;
    } else if (arg2 != -1) {
        u8* e = (u8*)getEntity__14ftEntryManagerFUl(*(void**)((u8*)self + 0x154), arg1);
        p = *(void**)(e + (arg2 << 3) + 0x34);
    } else {
        u8* e = (u8*)getEntity__14ftEntryManagerFUl(*(void**)((u8*)self + 0x154), arg1);
        u32 idx = e[0xa];
        p = *(void**)(e + (idx << 3) + 0x34);
    }
    fn_27_8CA94(p);
}
}
