#pragma force_active on
class Foo {
public:
    virtual void a(int);
    virtual void b();
    virtual void c();
};

extern "C" void fn_802D7FE0(Foo* p) {
    if (!p) return;
    p->a(1);
}
