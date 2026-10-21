#pragma force_active on
class wnemSimple {
public:
    int changeProcFnc(long, long);
};

extern "C" void* getInstance__15emWeaponManagerFv();
extern "C" void* fn_41_2C31C(void* mgr, long id);
extern "C" int fn_41_31E7C(void* self, void* proc, long arg);

int wnemSimple::changeProcFnc(long proc, long arg) {
    if (arg != 0 && *(int*)((char*)this + 0x2210) == proc) {
        return 1;
    }

    if (proc == -1) {
        *(int*)((char*)this + 0x220C) = 0;
    } else {
        void* mgr = getInstance__15emWeaponManagerFv();
        void* result = fn_41_2C31C(mgr, proc);
        if (result != 0) {
            *(int*)((char*)this + 0x2210) = proc;
            return fn_41_31E7C(this, result, arg);
        }
    }

    return 0;
}
