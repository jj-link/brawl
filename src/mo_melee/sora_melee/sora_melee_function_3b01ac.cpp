#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_1BFA8[];
extern "C" void fn_27_CE0BC(void);
extern "C" void fn_27_25290(void);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), u32, s32);
extern "C" void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, s32, s32);

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
    u32 a : 6;
    u32 b : 3;
    u32 c : 1;
    u32 d : 22;
};

extern "C" u8* fn_27_3B01AC(u8* self, void* a1, void* a2) {
    Flags* f = (Flags*)(self + 0x8);
    *(void**)(self + 0x4) = lbl_27_data_1BFA8 + 0x48;
    f->a = 0;
    f->b = 3;
    *(void**)(self + 0x0) = lbl_27_data_1BFA8;
    f->c = 0;
    __construct_array(self + 0xC, (void (*)(void*))fn_27_CE0BC,
                      (void (*)(void*))fn_27_25290, 0x30, 3);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        self + 0x4, 3, 3);
    ((soPostureModuleImpl*)(self + 0x9C))->__ct(
        (soModuleAccesser*)a1,
        (soArray<soInterpolation<Vec3f> >*)self,
        (soEventObserverRegistrationDesc*)a2);
    ((PostureIface*)(self + 0x9C))->call14();
    return self;
}
