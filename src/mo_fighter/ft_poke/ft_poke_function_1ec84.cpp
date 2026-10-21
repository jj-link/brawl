#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

class soModuleAccesser;
class soEventObserverRegistrationDesc;
template <class T> class soArray;

class soCollision {
public:
    enum Category { CategoryDefault = 0 };
};

class gfTask {
public:
    enum Category { CategoryDefault = 0 };
};

class soCollisionHitPart {
public:
    soCollisionHitPart(soCollision::Category, unsigned long);
    ~soCollisionHitPart();
    unsigned char m_storage[0x68];
};

class soCollisionGroup;
class soCollisionHitGroup;

class soCollisionHitModuleImpl {
public:
    soCollisionHitModuleImpl(soModuleAccesser*, int, gfTask::Category,
                             soArray<soCollisionHitPart>*,
                             soArray<soCollisionGroup>*,
                             soArray<soCollisionHitGroup>*,
                             soEventObserverRegistrationDesc*, bool);
};

extern "C" {
void fn_27_19BA54(void* vec, int size, const soCollisionHitPart* element, int param3);
void fn_27_CB6E0(void* collisionGroupVector, int size, int param2);
void fn_27_CC8F4(void* collisionHitGroupVector, int size, int param2);
}

extern "C" void* fn_116_1EC84(void* object, soModuleAccesser* accesser, int taskId,
                              unsigned char category,
                              soEventObserverRegistrationDesc* desc) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    {
        soCollisionHitPart hitPart(static_cast<soCollision::Category>(0), 0x3FF);
        fn_27_19BA54(storage, 8, &hitPart, 0);
    }
    fn_27_CB6E0(storage + 0x34C, 1, 0);
    fn_27_CC8F4(storage + 0x3D0, 1, 0);
    new (storage + 0x414) soCollisionHitModuleImpl(
        accesser, taskId, static_cast<gfTask::Category>(category),
        reinterpret_cast<soArray<soCollisionHitPart>*>(storage),
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x34C),
        reinterpret_cast<soArray<soCollisionHitGroup>*>(storage + 0x3D0),
        desc, true);
    return object;
}
