#include <types.h>
#pragma force_active on

struct ftEntry;

extern "C" ftEntry* getEntity__14ftEntryManagerFUl(char* mgr, u32 id);
extern "C" void fn_27_1140B0(ftEntry* entry, u32 arg);

struct SubObj {
    virtual void f0();
    virtual void* getId(s32 index);
    virtual void f2();
    virtual s32 getCount();
};

extern "C" void fn_27_109F90(char* self) {
    s32 count = ((SubObj*)(*(char**)(self + 0x154) + 8))->getCount();
    for (s32 i = 0; i < count; i++) {
        char* p = (char*)((SubObj*)(*(char**)(self + 0x154) + 8))->getId(i);
        char* inner = *(char**)p;
        u32 id = *(u32*)(inner + 4);
        ftEntry* entry = getEntity__14ftEntryManagerFUl(*(char**)(self + 0x154), id);
        fn_27_1140B0(entry, 1);
    }
}
