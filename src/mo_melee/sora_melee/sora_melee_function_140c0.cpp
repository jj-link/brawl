#pragma force_active on
extern "C" void fn_27_13EF4(void* self);

struct VObj {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11(int) = 0;
};

struct VObj2 {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
};

extern "C" void fn_27_140C0(void* self) {
    char* p = (char*)self;
    fn_27_13EF4(self);
    ((VObj*)*(void**)(p + 0xf0))->f11(-1);
    ((VObj*)*(void**)(p + 0x148))->f4();
    ((VObj2*)(p + 0xf4))->f8();
}
