#pragma force_active on
class Foo {
public:
    virtual void vf0(int a);
    virtual void vf1();
    virtual void vf2();
};

extern "C" void fn_802D4CFC(Foo* self) {
    self->vf0(-1);
}
