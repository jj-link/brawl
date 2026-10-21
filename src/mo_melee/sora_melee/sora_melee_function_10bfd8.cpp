#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32 mgr, u32 id);
extern "C" void fn_27_112CC4(void* self, s32 n);
extern "C" void fn_27_112C10(void* self, s32 amount);

extern "C" void fn_27_10BFD8(char* self, u32 a, s32 b, u32 c) {
    ftEntry* e = getEntity__14ftEntryManagerFUl(*(u32*)(self + 0x154), a);
    s32 x = *(s32*)((char*)e + 0x50);
    u32 mgr = *(u32*)(self + 0x154);
    if (x != -1) {
        a = x;
    }
    ftEntry* e2 = getEntity__14ftEntryManagerFUl(mgr, a);
    void* p = *(void**)((char*)e2 + 0x28);
    fn_27_112CC4(p, b);
    if (c == 1) {
        fn_27_112C10(p, -b);
    }
}
