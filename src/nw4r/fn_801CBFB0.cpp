#pragma force_active on

class A {
public:
    virtual void v0();
    virtual int m(void*, void*, void*, void*, int, void*);
};

class B {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void m();
};

extern "C" int fn_801CBFB0(void* a, void* b, void* c, void* d, void* e, void* f) {
    int r = ((A*)a)->m(b, c, d, e, 0, f);
    if (r != 0)
        return r;

    void* p = *(void**)b;
    if (p != 0)
        ((B*)p)->m();

    return 0;
}
