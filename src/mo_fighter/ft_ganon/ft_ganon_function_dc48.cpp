#pragma force_active on
class VBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(int);
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
    virtual void f18(unsigned int);
};

extern "C" {
void fn_109_E00C(void* self);

void fn_109_DC48(void*, void* ft) {
    VBase* a = *(VBase**)(*(char**)((char*)ft + 0xd8) + 0x58);
    a->f7(0);
    VBase* b = *(VBase**)(*(char**)((char*)ft + 0xd8) + 0x64);
    b->f18(0x12000001);
    fn_109_E00C(ft);
}
}
