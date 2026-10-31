#pragma force_active on

class FnToonLinkBase {
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
    virtual void fn15(int a, int b, int c);
};

extern "C" void fn_121_9914(unsigned char* self, void* ctx, unsigned int param) {
    if (*(self + 0x1A384) != 1)
        return;
    if (param == 1) {
        void* p = *(void**)((unsigned char*)ctx + 0xd8);
        FnToonLinkBase* obj = (FnToonLinkBase*)(*(void**)((unsigned char*)p + 0x24));
        obj->fn15(0, 0, 1);
    } else {
        void* p = *(void**)((unsigned char*)ctx + 0xd8);
        FnToonLinkBase* obj = (FnToonLinkBase*)(*(void**)((unsigned char*)p + 0x24));
        obj->fn15(0, 1, 1);
    }
}