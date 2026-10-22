#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_3F258[];
extern "C" void fn_27_CE0BC(void);
extern "C" void fn_27_25290(void);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);

class soModuleAccesser;
class soEventObserverRegistrationDesc;
class Vec3f;
template <class T> class soInterpolation;
template <class T> class soArray;

class soPostureModuleImpl {
public:
    soPostureModuleImpl(soModuleAccesser*, soArray<soInterpolation<Vec3f> >*, soEventObserverRegistrationDesc*);
};

class PostureIface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void call14();
};

struct Flags {
    u32 hi : 4;
    u32 m : 2;
    u32 b : 1;
    u32 lo : 25;
};

extern "C" u8* fn_27_2DAC38(u8* self, void* a1, void* a2) {
    Flags* f = (Flags*)(self + 0x8);
    *(void**)(self + 0x4) = lbl_27_data_3F258 + 0x48;
    f->hi = 0;
    f->m = 1;
    f->b = 0;
    *(void**)(self + 0x0) = lbl_27_data_3F258;
    __construct_array(self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        self + 0x4, (void*)1, 1);
    ((soPostureModuleImpl*)(self + 0x3C))->__ct(
        (soModuleAccesser*)a1,
        (soArray<soInterpolation<Vec3f> >*)self,
        (soEventObserverRegistrationDesc*)a2);
    ((PostureIface*)(self + 0x3C))->call14();
    return self;
}
