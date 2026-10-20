#include <types.h>
#pragma force_active on

class ftManager {
public:
    u32 getFighterOperationType(int);
};

extern "C" void* getEntity__14ftEntryManagerFUl(u32);
extern "C" u32 fn_27_124680(u32);

u32 ftManager::getFighterOperationType(int) {
    void* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)this + 0x154));
    return fn_27_124680(*(u32*)((char*)entry + 0x2c));
}
