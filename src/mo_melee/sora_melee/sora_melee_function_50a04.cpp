#pragma force_active on
class fnSub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct fnOuter {
    char pad[0x10];
    fnSub sub;
};

extern "C" void fn_27_50A04(fnOuter* self) {
    fnSub* p = (fnSub*)((char*)self + 0x10);
    p->f3();
}
