#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

class soModuleAccesser;
template <class T> class soArray;
class soEventObserverRegistrationDesc;

class soCollision {
public:
    enum Category { CategoryDefault };
};

class soCollisionAttackPart {
    unsigned long storage[36];
public:
    soCollisionAttackPart(soCollision::Category, bool);
    ~soCollisionAttackPart();
};

class soCollisionGroup;
class soCollisionAttackAbsolute;

class gfTask {
public:
    enum Category { CategoryDefault };
};

class soCollisionAttackModuleImpl {
public:
    soCollisionAttackModuleImpl(soModuleAccesser*, int, gfTask::Category,
                                soArray<soCollisionAttackPart>*,
                                soArray<soCollisionGroup>*,
                                soArray<soCollisionAttackAbsolute>*,
                                soEventObserverRegistrationDesc*, bool);
};

extern "C" void fn_27_19D018(void*, int, void*, int);
extern "C" void fn_27_CB908(void*, int, int);
extern "C" void fn_27_1A121C(void*, int, int);

extern "C" soArray<soCollisionAttackPart>* fn_103_7998(soArray<soCollisionAttackPart>* arg0,
                                                      soModuleAccesser* arg1, int arg2,
                                                      unsigned char arg3,
                                                      soEventObserverRegistrationDesc* arg4) {
    unsigned char* storage = reinterpret_cast<unsigned char*>(arg0);
    {
        soCollisionAttackPart attackPart(soCollision::CategoryDefault, true);
        fn_27_19D018(arg0, 7, &attackPart, 0);
    }
    fn_27_CB908(storage + 0x3FC, 5, 0);
    fn_27_1A121C(storage + 0x660, 2, 0);
    new (storage + 0x73C) soCollisionAttackModuleImpl(
        arg1, arg2, static_cast<gfTask::Category>(arg3),
        arg0,
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x3FC),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(storage + 0x660),
        arg4, true);
    return arg0;
}
