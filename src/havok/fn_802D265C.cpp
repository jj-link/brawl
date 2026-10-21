#pragma force_active on

class Foo {
public:
    virtual void vf0(int);
};

extern "C" void fn_802D265C(Foo* p) {
    p->vf0(-1);
}
