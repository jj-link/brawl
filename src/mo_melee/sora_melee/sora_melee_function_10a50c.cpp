#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" void* getEntity__14ftEntryManagerFUl(void*, u32);

extern "C" void* getFighter__9ftManagerFii(void* self, s32 entryId, s32 index) {
    void* mgr = *(void**)((char*)self + 0x154);
    if (fn_27_1190D0(mgr) == 0) {
        return 0;
    }
    if (index != -1) {
        char* entry = (char*)getEntity__14ftEntryManagerFUl(*(void**)((char*)self + 0x154), entryId);
        return *(void**)(entry + (index << 3) + 0x34);
    }
    char* entry = (char*)getEntity__14ftEntryManagerFUl(*(void**)((char*)self + 0x154), entryId);
    u8 n = *(u8*)(entry + 0xa);
    return *(void**)(entry + (n << 3) + 0x34);
}
