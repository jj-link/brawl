#include <new>
#pragma use_simple_stdpnew on
#include <types.h>
#pragma force_active on

class Vec3f {};
template <class T> class soInterpolation { T e[4]; public: soInterpolation() {}; };
template <class T> class soArray { public: soArray() {}; };
class soModuleAccesser {};
class soEventObserverRegistrationDesc {};
class soPostureModuleImpl {
public:
    soPostureModuleImpl(soModuleAccesser*, soArray<soInterpolation<Vec3f> >*, soEventObserverRegistrationDesc*);
};
extern "C" void fn_27_19FF5C(unsigned char*, int, int);

struct VIf13 {
    virtual void s00() = 0; virtual void s04() = 0; virtual void s08() = 0;
    virtual void s0C() = 0; virtual void s10() = 0; virtual void s14() = 0;
    virtual void s18() = 0; virtual void s1C() = 0; virtual void s20() = 0;
    virtual void s24() = 0; virtual void s28() = 0; virtual void s2C() = 0;
    virtual void s30() = 0;
};

typedef unsigned char Byte;
extern "C" void* fn_113_8714(Byte* base, soModuleAccesser* accesser, soEventObserverRegistrationDesc* desc) {
    fn_27_19FF5C(base, 1, 0);
    new (reinterpret_cast<soPostureModuleImpl*>(base + 0x3C)) soPostureModuleImpl(
        accesser,
        reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(base),
        desc);
    reinterpret_cast<VIf13*>(base + 0x3C)->s30();
    return base;
}
