#pragma force_active on
typedef unsigned int u32;

struct Arg {
    char pad[0xC];
    float unkC;
};

struct StopCls {
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
    virtual void f16(int, int);
    virtual void f17();
};

struct WorkCls {
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
    virtual void f18(u32);
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_63914(void* acc, void* arg, float f, int i);
float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 id, u32 index);
long fn_41_FD44(void* self, float f);
void fn_41_10008(void* self, void* arg, long v, int a, bool b);
extern const char __RTTI__16emStopModuleImpl;
extern const char __RTTI__12soStopModule;
extern const float lbl_41_rodata_BE8;
}

extern "C" void fn_41_118D0(void* self, Arg* arg) {
    __dynamic_cast(
        *(char**)(*(char**)(*(char**)((char*)self + 0x3c) + 0xd8) + 0x44),
        0, &__RTTI__16emStopModuleImpl, &__RTTI__12soStopModule, 1);
    int frames = fn_27_63914(*(char**)((char*)self + 0x3c), arg, lbl_41_rodata_BE8, 0);
    float val = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        *(char**)((char*)self + 0x3c), 0xbd4, 0);
    float prod = arg->unkC * val;
    long v = fn_41_FD44(self, prod);
    fn_41_10008(self, arg, v, 0, false);
    if (frames > 0) {
        StopCls* m1 = (StopCls*)(*(char**)(*(char**)(*(char**)((char*)self + 0x3c) + 0xd8) + 0x44));
        m1->f16(frames, 1);
    }
    WorkCls* m2 = (WorkCls*)(*(char**)(*(char**)(*(char**)((char*)self + 0x3c) + 0xd8) + 0x64));
    m2->f18(0x22000006);
}
