#pragma force_active on
struct VTableTarget {
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
    virtual void dispatch();
};

extern "C" void fn_41_C38C(VTableTarget* target) {
    target->dispatch();
}
