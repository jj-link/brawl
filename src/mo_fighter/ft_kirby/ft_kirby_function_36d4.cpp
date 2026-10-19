#pragma use_simple_stdpnew on
#include <new>
#pragma force_active on

class Vec3f;
template<class T> class soInterpolation;
template<class T> class soArray;
class soModuleAccesser;
class soEventObserverRegistrationDesc;
class soPostureModuleImpl {
public:
    soPostureModuleImpl(soModuleAccesser*, soArray<soInterpolation<Vec3f> >*, soEventObserverRegistrationDesc*);
private:
    unsigned long storage[100];
};

extern "C" void fn_27_19FF5C(void*, int, int);

class KirbyVirtualInterface {
public:
    virtual unsigned long slot08() = 0;
    virtual unsigned long slot0C() = 0;
    virtual unsigned long slot10() = 0;
    virtual unsigned long slot14() = 0;
    virtual unsigned long slot18() = 0;
    virtual unsigned long slot1C() = 0;
    virtual unsigned long slot20() = 0;
    virtual unsigned long slot24() = 0;
    virtual unsigned long slot28() = 0;
    virtual unsigned long slot2C() = 0;
    virtual unsigned long slot30() = 0;
    virtual unsigned long slot34() = 0;
    virtual unsigned long slot38() = 0;
};

extern "C" unsigned char* fn_96_36D4(unsigned char* posture, soModuleAccesser* accesser, soEventObserverRegistrationDesc* eventDesc) {
    fn_27_19FF5C(posture, 1, 0);
    new (posture + 0x3c) soPostureModuleImpl(accesser, reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture), eventDesc);
    reinterpret_cast<KirbyVirtualInterface*>(posture + 0x3c)->slot38();
    return posture;
}
