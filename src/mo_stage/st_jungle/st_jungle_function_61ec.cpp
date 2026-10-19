#pragma force_active on
class soBaseObject {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual bool fn5();
};

extern "C" bool fn_51_61EC(soBaseObject* obj) {
    return !obj->fn5();
}
