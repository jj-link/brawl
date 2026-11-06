#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
};

extern "C" int fn_80300488(void*, void*);
extern "C" void fn_802F377C();

extern "C" void fn_8032C24C(void*, char* arg) {
    if ((*(Object_vptr_0**)(arg + 0xC))->slot3() != 0xB &&
        fn_80300488(*(char**)(arg + 0x14) + 0x1C, *(char**)(arg + 0x18) + 0x1C) != 0) {
        fn_802F377C();
    }
}
