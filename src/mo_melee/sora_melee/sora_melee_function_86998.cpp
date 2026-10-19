#pragma force_active on
class fn27Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_27_86998(fn27Obj* obj) {
    return !obj->f3();
}
