#include <types.h>
#pragma force_active on

enum itKind { };

class itManager {
public:
    u8 getItemNum(itKind kind);
};

u8 itManager::getItemNum(itKind kind) {
    s32 k = (s32)kind;
    u8 valid = 0;
    if (k > -1 && k < 0xB2) {
        valid = 1;
    }
    if (valid) {
        u8* p = (u8*)this + k;
        return p[0x1009];
    }
    return 0;
}
