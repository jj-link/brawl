#include <types.h>
#pragma force_active on

extern "C" void* getEntity__14ftEntryManagerFUl(u32);

class ftManager {
public:
    bool getFighterOperationStatus(int fighter);
};

bool ftManager::getFighterOperationStatus(int fighter) {
    char* entry = (char*)getEntity__14ftEntryManagerFUl(*(u32*)((char*)this + 0x154));
    u8* data = *(u8**)(entry + 0x2c);
    bool result = false;
    if ((data[0] >> 7) & 1) {
        if (data[8] != 0) {
            result = true;
        }
    }
    return result;
}
