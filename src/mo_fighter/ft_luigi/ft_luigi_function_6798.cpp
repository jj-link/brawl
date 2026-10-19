// ft_luigi fn_99_6798
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

struct Vec3f { float x, y, z; };
template<class T> class soInterpolation;
template<class T> class soArray;
class soModuleAccesser;
class soEventObserverRegistrationDesc;

struct soVirtBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
};

class soPostureModuleImpl : public soVirtBase {
public:
    soPostureModuleImpl(soModuleAccesser*, soArray<soInterpolation<Vec3f> >*, soEventObserverRegistrationDesc*);
    virtual void slot38();
};

extern "C" void fn_27_19FF5C(void*, int, int);

extern "C" void* fn_99_6798(void* posture, void* accesser, void* desc) {
    unsigned char* storage = static_cast<unsigned char*>(posture);
    fn_27_19FF5C(posture, 1, 0);
    new (storage + 0x3C) soPostureModuleImpl(
        static_cast<soModuleAccesser*>(accesser),
        reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
        static_cast<soEventObserverRegistrationDesc*>(desc));
    reinterpret_cast<soPostureModuleImpl*>(storage + 0x3C)->slot38();
    return posture;
}
