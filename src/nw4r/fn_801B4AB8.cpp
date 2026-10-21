#pragma force_active on
class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3() const;
};

extern "C" char* fn_801B4AB8(const Obj* self) {
    return self->f3() + 4;
}
