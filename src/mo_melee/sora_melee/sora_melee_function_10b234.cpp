#include <types.h>
#pragma force_active on

struct ftEntry;
extern "C" ftEntry* getEntity__14ftEntryManagerFUl(u32, u32);

extern "C" s32 fn_27_10B234(char* self, u32 id) {
    char* entry = (char*)getEntity__14ftEntryManagerFUl(*(u32*)(self + 0x154), id);
    if (*(s32*)(entry + 0x50) != -1) {
        char* other = (char*)getEntity__14ftEntryManagerFUl(*(u32*)(self + 0x154), id);
        return *(s32*)(other + 0x50);
    }
    return id;
}
