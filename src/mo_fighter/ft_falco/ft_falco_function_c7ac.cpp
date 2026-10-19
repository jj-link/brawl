#pragma force_active on
struct Object {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual int f3() = 0;
};

extern "C" bool fn_108_C7AC(Object* self) {
    return !self->f3();
}
