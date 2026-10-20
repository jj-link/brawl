#pragma force_active on
extern "C" void fn_27_1D8FC8(void*, int);

class VObj {
public:
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
    virtual void f20(int);
};

extern "C" void fn_27_1E4064(char* self, int arg) {
    int v = *(int*)(self + 0x9e8);
    if (v != 0) {
        void* p = *(void**)(self + 0x60);
        p = *(void**)((char*)p + 0xd8);
        p = *(void**)((char*)p + 0x88);
        ((VObj*)p)->f20(v);
        *(int*)(self + 0x9e8) = 0;
    }
    fn_27_1D8FC8(self, arg);
}
