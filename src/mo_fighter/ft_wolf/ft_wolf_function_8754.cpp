// fn_125_8754 - ft_wolf collision-attack build config constructor.
//
// Initializes the collision-attack build config embedded in the Wolf fighter
// module storage: the soCollisionAttackPart vector starts at the object
// itself, the soCollisionGroup vector sits at +0x2DC, the
// soCollisionAttackAbsolute vector at +0x540 and the
// soCollisionAttackModuleImpl member is constructed at +0x61C.
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

// ABI views of the out-of-line constructors and array-vector initializers
// used by this collision-attack build config; the storage belongs to the
// containing fighter object, not these declaration-only views.
class soModuleAccesser;
class soEventObserverRegistrationDesc;
template <class T> class soArray;

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

extern "C" {
// soArrayVector<soCollisionAttackPart, 5>(int size, const soCollisionAttackPart&, int)
void fn_27_CD0B0(void* parts, int count, void* fill, int param);
// soArrayVector<soCollisionGroup, 5>(int size, int count, int param)
void fn_27_CB908(void* groups, int count, int param);
// soArrayVector<soCollisionAttackAbsolute, 2>(int size, int count, int param)
void fn_27_1A121C(void* absolutes, int count, int param);
}

// Builds the collision-attack module config in place and returns it.
extern "C" void* fn_125_8754(void* object, soModuleAccesser* accesser, int taskId,
                             unsigned char taskCategory,
                             soEventObserverRegistrationDesc* desc) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    {
        soCollisionAttackPart attackPart(soCollision::CategoryDefault, true);
        fn_27_CD0B0(storage, 5, &attackPart, 0);
    }
    fn_27_CB908(storage + 0x2DC, 5, 0);
    fn_27_1A121C(storage + 0x540, 2, 0);
    new (storage + 0x61C) soCollisionAttackModuleImpl(
        accesser, taskId, static_cast<gfTask::Category>(taskCategory),
        reinterpret_cast<soArray<soCollisionAttackPart>*>(storage),
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x2DC),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(storage + 0x540),
        desc, true);
    return object;
}
