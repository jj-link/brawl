#pragma force_active on
extern "C" {
void fn_800B8EDC(void*, void*);
}

struct VObj {
    virtual ~VObj();
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
    virtual void f12(void* a);
};

extern "C" void fn_2_2A1A8(void* self) {
    char* p = (char*)self;
    (*(VObj**)(p + 0x654))->f12(*(void**)(p + 0x68C));
    (*(VObj**)(p + 0x654))->f12(*(void**)(p + 0x690));
    fn_800B8EDC(*(void**)(p + 0x678), *(void**)(p + 0x680));
    fn_800B8EDC(*(void**)(p + 0x678), *(void**)(p + 0x684));
}
