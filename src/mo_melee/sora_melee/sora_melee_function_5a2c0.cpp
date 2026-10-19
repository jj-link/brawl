#pragma force_active on
// sora_melee: fn_27_5A2C0
//
// Forwards two virtual "callback" calls (vtable slots 0x2c and 0x30) on the
// object passed in r3.  The class has a virtual destructor plus 8 pure virtual
// hooks before the two dispatched slots, giving the original's pair of
// lwz/mtctr/bctrl vtable dispatches.

struct soCallbackHolder {
    virtual ~soCallbackHolder();

    virtual void hook0();
    virtual void hook1();
    virtual void hook2();
    virtual void hook3();
    virtual void hook4();
    virtual void hook5();
    virtual void hook6();
    virtual void hook7();

    // the two slots actually invoked by fn_27_5A2C0 (offsets 0x2c / 0x30)
    virtual void onRelease();
    virtual void onDestroy();
};

extern "C" void fn_27_5A2C0(soCallbackHolder* holder) {
    holder->onRelease();
    holder->onDestroy();
}
