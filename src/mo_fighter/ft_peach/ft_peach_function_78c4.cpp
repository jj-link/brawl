#pragma force_active on
typedef unsigned char u8;

class soModuleAccesser;
class soEventObserverRegistrationDesc;
struct Vec3f;
template <class T> class soInterpolation;
template <class T> class soArray;

class soPostureModuleImpl {
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
    virtual void init();
    soPostureModuleImpl(soModuleAccesser*,
                       soArray<soInterpolation<Vec3f> >*,
                       soEventObserverRegistrationDesc*);
};

struct Object {
    u8 padding[0x6C];
    soPostureModuleImpl member;
};

extern "C" void fn_27_1A00F4(void*, int, int);

extern "C" void* fn_103_78C4(Object* object, soModuleAccesser* accesser,
                            soEventObserverRegistrationDesc* desc) {
    fn_27_1A00F4(object, 2, 0);
    object->member.__ct(
        accesser, reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(object), desc);
    object->member.init();
    return object;
}
