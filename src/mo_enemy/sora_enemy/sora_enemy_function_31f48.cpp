#pragma force_active on
extern "C" void* getInstance__15emWeaponManagerFv();
extern "C" void* fn_41_2C31C(void* mgr, long id);

class wnemSimple {
public:
    int setProcFnc_HpZero(long p);

    char pad[0x21BC];
    void* unk21BC;
};

int wnemSimple::setProcFnc_HpZero(long p) {
    if (p == -1) {
        unk21BC = 0;
    } else {
        void* mgr = getInstance__15emWeaponManagerFv();
        void* r = fn_41_2C31C(mgr, p);
        unk21BC = r;
        if (r) {
            return 1;
        }
    }
    return 0;
}
