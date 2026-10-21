#include <types.h>
#pragma force_active on

class ipPadConfig {
public:
    s32 getPlayerNo(long arg0);
    char pad0[0xB5];
    u8 player[4];
};

s32 ipPadConfig::getPlayerNo(long arg0) {
    for (u32 i = 0; i < 4; i++) {
        if ((u32)arg0 == player[i]) {
            return i;
        }
    }
    return -1;
}
