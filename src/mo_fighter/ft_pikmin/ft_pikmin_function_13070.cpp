#pragma force_active on
struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void f7();
};

extern "C" void *lbl_113_bss_F4;

extern "C" void fn_113_13070() {
    ((Obj *)&lbl_113_bss_F4)->f7();
}
