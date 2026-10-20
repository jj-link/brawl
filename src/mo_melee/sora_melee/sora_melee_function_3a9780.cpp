#pragma force_active on
extern "C" void fn_27_1D8FC8(void*, int);

class IObj {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f26(int, int, int);
};

extern "C" void fn_27_3A9780(void* self, int arg) {
    char* a = (char*)*(void**)((char*)self + 0x60);
    char* b = (char*)*(void**)(a + 0xd8);
    IObj* obj = (IObj*)*(void**)(b + 0x88);
    obj->f26(0, 1, 1);
    fn_27_1D8FC8(self, arg);
}
