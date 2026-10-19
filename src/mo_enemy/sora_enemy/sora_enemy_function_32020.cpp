#include <types.h>
#pragma force_active on

extern "C" void* getInstance__15emWeaponManagerFv();
extern "C" void* fn_41_2C31C(void* self, s32 id);

class wnemSimple {
public:
    bool setProcFnc_TouchGround(s32 id);

    u8 pad[0x21C4];
    void* unk21C4;
};

bool wnemSimple::setProcFnc_TouchGround(s32 id) {
    if (id == -1) {
        unk21C4 = nullptr;
    } else {
        void* p = fn_41_2C31C(getInstance__15emWeaponManagerFv(), id);
        unk21C4 = p;
        if (p != nullptr) {
            return true;
        }
    }
    return false;
}
