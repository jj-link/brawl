#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

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
void fn_27_CD0B0(void*, int, void*, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_1A13B4(void*, int, int);
}

extern "C" void* fn_111_662C(void* object, soModuleAccesser* accesser, int taskId,
                             unsigned char category,
                             soEventObserverRegistrationDesc* desc) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    {
        soCollisionAttackPart attackPart(soCollision::CategoryDefault, false);
        fn_27_CD0B0(storage, 5, &attackPart, 0);
    }
    fn_27_CB6E0(storage + 0x2DC, 1, 0);
    fn_27_1A13B4(storage + 0x360, 6, 0);
    new (storage + 0x5DC) soCollisionAttackModuleImpl(
        accesser, taskId, static_cast<gfTask::Category>(category),
        reinterpret_cast<soArray<soCollisionAttackPart>*>(storage),
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x2DC),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(storage + 0x360),
        desc, true);
    return object;
}
