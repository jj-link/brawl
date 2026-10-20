#include <types.h>
#pragma force_active on

extern "C" void* getEntity__14ftEntryManagerFUl(void* mgr, u32 id);
extern "C" void fn_27_112C7C(void* w, int n);

extern "C" void fn_27_10C06C(char* self, u32 id, int n) {
    void* entry = getEntity__14ftEntryManagerFUl(*(void**)(self + 0x154), id);
    s32 idx = *(s32*)((char*)entry + 0x50);
    void* mgr = *(void**)(self + 0x154);
    if (idx != -1) {
        id = idx;
    }
    entry = getEntity__14ftEntryManagerFUl(mgr, id);
    fn_27_112C7C(*(void**)((char*)entry + 0x28), n);
}
