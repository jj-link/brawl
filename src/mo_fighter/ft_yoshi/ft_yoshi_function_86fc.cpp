#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

// ABI views of the out-of-line constructors and array-vector initializers
// used by this collision-attack build-config initializer.
class soModuleAccesser;
template<class T> class soArray;
class soEventObserverRegistrationDesc;
class soCollision { public: enum Category { CategoryDefault }; };
class soCollisionAttackPart {
    unsigned long storage[36];
public: soCollisionAttackPart(soCollision::Category, bool); ~soCollisionAttackPart();
};
class soCollisionGroup; class soCollisionAttackAbsolute;
class gfTask { public: enum Category { CategoryDefault }; };
class soCollisionAttackModuleImpl {
public:
    soCollisionAttackModuleImpl(soModuleAccesser*, int, gfTask::Category,
        soArray<soCollisionAttackPart>*, soArray<soCollisionGroup>*,
        soArray<soCollisionAttackAbsolute>*, soEventObserverRegistrationDesc*, bool);
};

extern "C" void fn_27_CD0B0(void*, int, void*, int);
extern "C" void fn_27_CB908(void*, int, int);
extern "C" void fn_27_1A121C(void*, int, int);

// Initializes the collision-attack build config embedded in the ft_yoshi
// fighter module storage: the soCollisionAttackPart vector starts at the
// object itself, the soCollisionGroup vector sits at +0x2DC, the
// soCollisionAttackAbsolute vector at +0x540, and the soCollisionAttackModuleImpl
// member is placement-constructed at +0x61C.
extern "C" void* fn_95_86FC(void* object, soModuleAccesser* accesser, int taskId,
                            unsigned char category,
                            soEventObserverRegistrationDesc* desc) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    {
        soCollisionAttackPart attackPart(soCollision::CategoryDefault, true);
        fn_27_CD0B0(storage, 5, &attackPart, 0);
    }
    fn_27_CB908(storage + 0x2DC, 5, 0);
    fn_27_1A121C(storage + 0x540, 2, 0);
    new (storage + 0x61C) soCollisionAttackModuleImpl(
        accesser, taskId, static_cast<gfTask::Category>(category),
        reinterpret_cast<soArray<soCollisionAttackPart>*>(storage),
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x2DC),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(storage + 0x540),
        desc, true);
    return object;
}
