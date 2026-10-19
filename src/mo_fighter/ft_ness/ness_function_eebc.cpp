#pragma force_active on
class NessFtBase {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual bool fn3();
};

extern "C" bool fn_101_EEBC(NessFtBase* obj) {
    return !obj->fn3();
}
