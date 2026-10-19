#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" void* getInstance__15emWeaponManagerFv();
extern "C" void* fn_41_2C31C(void* mgr, s32 id);

class wnemSimple {
public:
    char pad_0000[0x21C8];
    void* unk21C8;
    bool setProcFnc_HitShell(long id);
};

bool wnemSimple::setProcFnc_HitShell(long id) {
    if (id == -1) {
        unk21C8 = 0;
    } else {
        void* p = fn_41_2C31C(getInstance__15emWeaponManagerFv(), (s32)id);
        unk21C8 = p;
        if (p != 0) {
            return true;
        }
    }
    return false;
}
