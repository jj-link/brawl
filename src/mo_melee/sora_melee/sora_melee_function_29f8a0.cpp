#pragma force_active on
class Dummy {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void v7(int a, unsigned int b);
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
    virtual void v20(int a, int b);
};

extern "C" void fn_27_29F8A0(int unused, char* p, int flag) {
    if (flag == 0) {
        char* q = *(char**)(p + 0x60);
        char* r = *(char**)(q + 0xd8);
        Dummy* obj = *(Dummy**)(r + 0x64);
        obj->v20(0x12000000, flag);
        obj->v7(-1, 0x1000000b);
    }
}
