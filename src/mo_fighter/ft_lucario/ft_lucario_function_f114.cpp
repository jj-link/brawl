#pragma force_active on
extern "C" void fn_118_F158(void* arg);

struct acDispatch {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2(void* arg);
};

extern unsigned int lbl_118_bss_284[];

extern "C" void fn_118_F114(void* a, void* b) {
    acDispatch* obj = reinterpret_cast<acDispatch*>(lbl_118_bss_284);
    obj->fn2(b);
    fn_118_F158(b);
}
