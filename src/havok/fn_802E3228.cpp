#pragma force_active on
extern "C" void fn_802E23CC(void*, int, void*);
class Obj {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10();
};
extern "C" void fn_802E3228(void* p) {
    char buf[0x10] __attribute__((aligned(16)));
    ((Obj*)((char*)p + 0xa0))->f10();
    fn_802E23CC(p, *(int*)((char*)p + 0x1c), buf);
}