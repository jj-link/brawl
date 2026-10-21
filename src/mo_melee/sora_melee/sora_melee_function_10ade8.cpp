#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*, u32);
extern "C" void* getEntity__14ftEntryManagerFUl(void*, u32);
extern "C" void getHipPos__23ftExternalValueAccesserFP7Fighter(void*, void*);

extern "C" {
void getFighterCenterPos__9ftManagerFii(void* self, void* mgr, u32 id, s32 idx) {
    void* p;
    if (fn_27_1190D0(*(void**)((u8*)mgr + 0x154), id) == 0) {
        p = 0;
    } else if (idx != -1) {
        u8* e = (u8*)getEntity__14ftEntryManagerFUl(*(void**)((u8*)mgr + 0x154), id);
        p = *(void**)(e + (idx << 3) + 0x34);
    } else {
        u8* e = (u8*)getEntity__14ftEntryManagerFUl(*(void**)((u8*)mgr + 0x154), id);
        u32 i = e[0xa];
        p = *(void**)(e + (i << 3) + 0x34);
    }
    getHipPos__23ftExternalValueAccesserFP7Fighter(self, p);
}
}
