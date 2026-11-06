#include <types.h>
#include <ft/ft_entry_manager.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*, u32);
extern "C" void fn_27_14D218(void*, void*);

extern "C" void fn_27_10AD38(void* self, void* mgr, u32 id, s32 idx) {
    void* p;
    if (fn_27_1190D0(*(void**)((u8*)mgr + 0x154), id) == 0) {
        p = 0;
    } else if (idx != -1) {
        u8* e = (u8*)(*(ftEntryManager**)((u8*)mgr + 0x154))->getEntity(id);
        p = *(void**)(e + (idx << 3) + 0x34);
    } else {
        u8* e = (u8*)(*(ftEntryManager**)((u8*)mgr + 0x154))->getEntity(id);
        u32 i = e[0xa];
        p = *(void**)(e + (i << 3) + 0x34);
    }
    fn_27_14D218(self, p);
}