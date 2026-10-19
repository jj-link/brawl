#pragma force_active on
class Base {
public:
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
};

struct Inner {
    char pad[0x7C];
    Base* object;
};

struct Entry {
    char pad[0xD8];
    Inner* inner;
};

extern "C" void fn_98_11C34(void* a, Entry* entry) {
    Base* object = entry->inner->object;
    object->r();
    object->o();
}
