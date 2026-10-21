#pragma force_active on

class Foo {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3() const;
};

extern "C" char* fn_80197C40(const Foo* self) {
    return self->f3() + 4;
}
