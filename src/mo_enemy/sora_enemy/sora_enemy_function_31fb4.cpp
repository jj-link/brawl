#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern "C" void* getInstance__15emWeaponManagerFv();
extern "C" s32 fn_41_2C31C(void* mgr, s32 p);

class wnemSimple {
public:
    bool setProcFnc_LifeZero(long p);

private:
    u8 pad[0x21C0];

public:
    s32 unk21C0;
};

bool wnemSimple::setProcFnc_LifeZero(long p) {
    if (p == -1) {
        unk21C0 = 0;
    } else {
        void* mgr = getInstance__15emWeaponManagerFv();
        unk21C0 = fn_41_2C31C(mgr, p);
        if (unk21C0 != 0) {
            return true;
        }
    }
    return false;
}
