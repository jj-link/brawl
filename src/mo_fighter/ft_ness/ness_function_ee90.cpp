#pragma force_active on
struct FnSlot {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

extern "C" void fn_101_EE90(void* object) {
    FnSlot* slot = reinterpret_cast<FnSlot*>(reinterpret_cast<char*>(object) + 0x50000 - 0x578c);
    slot->f2();
}
