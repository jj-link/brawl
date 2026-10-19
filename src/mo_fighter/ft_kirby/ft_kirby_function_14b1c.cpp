#pragma force_active on
struct Dummy1 { virtual ~Dummy1(); };
struct Base : Dummy1 {
    virtual void f2();
    virtual void f3();
    virtual int isSomething();
};

struct Holder {
    char pad[0x14];
    Base* obj;
};

extern "C" {
void fn_96_154C0(void*);
void fn_96_15808(void*);
void fn_96_15740(void*);

void fn_96_14B1C(void* a, void* b) {
    Holder* h = *(Holder**)((char*)b + 0xD8);
    Base* obj = h->obj;
    if (obj->isSomething() == 0) {
        fn_96_154C0(b);
        fn_96_15808(b);
    } else {
        fn_96_15740(b);
    }
}
}
