#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" void* getEntity__14ftEntryManagerFUl(void*, u32);

class ftManager {
public:
    s32 getPlayerNo(int i);
};

s32 ftManager::getPlayerNo(int i) {
    if (fn_27_1190D0(*(void**)((char*)this + 0x154)) == 0) {
        return -1;
    }
    void* entry = getEntity__14ftEntryManagerFUl(*(void**)((char*)this + 0x154), i);
    return *(s32*)((char*)entry + 0x58);
}
