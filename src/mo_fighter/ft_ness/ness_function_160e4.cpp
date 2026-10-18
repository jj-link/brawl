#pragma force_active on
class NessWeaponVtable {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual int getTaskId();
};

extern "C" int fn_101_160E4(void* object) {
    return static_cast<NessWeaponVtable*>(object)->getTaskId();
}