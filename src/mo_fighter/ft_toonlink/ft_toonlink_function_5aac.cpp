#pragma force_active on
struct WorkBase {
    unsigned int pad[2];
};

struct ToonLinkWork : WorkBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
};

extern "C" ToonLinkWork* fn_121_47AC(
    ToonLinkWork*, void*, void*, void*, void*, void*, void*);

struct ToonLinkObject {
    char data[0x1c0];
    ToonLinkWork work;
};

extern "C" ToonLinkObject* fn_121_5AAC(ToonLinkObject* self) {
    fn_121_47AC(
        &self->work,
        self,
        (void*)0x4d,
        (char*)self + 0x134,
        (void*)0x20,
        (char*)self + 0x1b4,
        (void*)3);
    self->work.f25();
    return self;
}
