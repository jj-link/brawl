#pragma force_active on
extern "C" {

struct O {
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
    virtual void call(void*);
};

void fn_2_2C61C(char* self) {
    unsigned off;
    unsigned i;
    O* o = *(O**)(self + 0x654);
    o->call(*(void**)(*(char**)(self + 0x650) + 0x5c));

    i = 0;
    off = 0;
    do {
        O* o2 = *(O**)(self + 0x654);
        char* base = *(char**)(self + 0x64c);
        o2->call(*(void**)(*(char**)(base + off + 0x2d8) + 0x10));
        off += 4;
        i++;
    } while (i < 8);

    o = *(O**)(self + 0x654);
    o->call(*(void**)(*(char**)(self + 0x650) + 0x60));

    o = *(O**)(self + 0x654);
    o->call(*(void**)(*(char**)(*(char**)(self + 0x64c) + 0x300) + 0x10));
}

}
