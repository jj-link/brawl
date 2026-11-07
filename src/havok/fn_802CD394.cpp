#pragma force_active on

class Object_vptr_0 {
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
    virtual void slot14();
    virtual int slot15(void* arg);
};

struct S20 {
    char pad[0x20];
    int field_20;
};

extern "C" void fn_802CD1D0(void*, int, int);

extern "C" void fn_802CD394(void* arg0, S20* arg1, Object_vptr_0* arg2, void* arg3) {
    fn_802CD1D0(arg0, arg1->field_20, arg2->slot15(arg3));
}
