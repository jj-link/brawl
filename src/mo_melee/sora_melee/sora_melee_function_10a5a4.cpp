#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" void* getEntity__14ftEntryManagerFUl(void*, u32);

class ftManager {
public:
    void* getSubFighter(int index);
};

void* ftManager::getSubFighter(int index) {
    if (fn_27_1190D0(*(void**)((char*)this + 0x154)) == 0) {
        return 0;
    }
    void* entry = getEntity__14ftEntryManagerFUl(*(void**)((char*)this + 0x154), index);
    if (*(s32*)((char*)entry + 0x5c) == 0x10) {
        entry = getEntity__14ftEntryManagerFUl(*(void**)((char*)this + 0x154), index);
        return *(void**)((char*)entry + 0x3c);
    }
    return 0;
}
