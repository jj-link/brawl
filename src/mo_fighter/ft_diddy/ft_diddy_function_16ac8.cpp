#pragma force_active on
extern "C" const float lbl_115_rodata_F8;
extern "C" void fn_27_1D9FF8(void*);

struct VObj {
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
    virtual void f15(float, int);
};

extern "C" void fn_115_16AC8(void* self) {
    void* a = *(void**)((char*)self + 0x60);
    void* b = *(void**)((char*)a + 0xd8);
    VObj* c = *(VObj**)((char*)b + 0x64);
    c->f15(lbl_115_rodata_F8, 0x11000001);
    fn_27_1D9FF8(self);
}
