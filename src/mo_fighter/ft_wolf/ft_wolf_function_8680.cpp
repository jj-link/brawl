#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" void fn_27_19FF5C(void*, int, int);

class Vec3f;
template<class T> class soInterpolation;
template<class T> class soArray;
class soModuleAccesser;
class soEventObserverRegistrationDesc;

class PostureInterface {
public:
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1C() = 0;
    virtual void v20() = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2C() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
};

class soPostureModuleImpl {
public:
    soPostureModuleImpl(
        soModuleAccesser*,
        soArray<soInterpolation<Vec3f> >*,
        soEventObserverRegistrationDesc*
    );
};

extern "C" void* fn_125_8680(unsigned char* obj, void* accesser, void* desc) {
    fn_27_19FF5C(obj, 1, 0);
    new (obj + 0x3C) soPostureModuleImpl(
        reinterpret_cast<soModuleAccesser*>(accesser),
        reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(obj),
        reinterpret_cast<soEventObserverRegistrationDesc*>(desc)
    );
    reinterpret_cast<PostureInterface*>(obj + 0x3C)->v38();
    return obj;
}
