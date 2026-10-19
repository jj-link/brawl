#pragma force_active on
struct Target {
    virtual ~Target();
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
    virtual bool check(unsigned int);
};

struct At64 {
    char pad[0x64];
    Target* target;
};

struct AtD8 {
    char pad[0xD8];
    At64* next;
};

struct At60 {
    char pad[0x60];
    AtD8* next;
};

extern "C" bool fn_27_29F3B0(void*, At60* p) {
    return !p->next->next->target->check(0x12000000);
}
