#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

// ABI views of the out-of-line constructors used by this unit. Their storage
// belongs to the containing fighter object, not these declaration-only views.
class soCollision {
public:
    enum Category {
        CategoryDefault = 0,
    };
};

class soModuleAccesser;
class soEventObserverRegistrationDesc;

class gfTask {
public:
    enum Category {
        CategoryDefault = 0,
    };
};

// Pointer-only view; the array type is completed in the sora module.
template <class T>
class soArray;

class soCollisionHitPart {
public:
    soCollisionHitPart(soCollision::Category selfCategory, unsigned long opponentCategory);
    ~soCollisionHitPart();

    unsigned char m_storage[0x68];
};

class soCollisionGroup;
class soCollisionHitGroup;

class soCollisionHitModuleImpl {
public:
    soCollisionHitModuleImpl(soModuleAccesser* moduleAccesser, int taskId,
                             gfTask::Category taskCategory,
                             soArray<soCollisionHitPart>* hitPartArray,
                             soArray<soCollisionGroup>* collisionGroupArray,
                             soArray<soCollisionHitGroup>* collisionHitGroupArray,
                             soEventObserverRegistrationDesc* registrationDesc, bool param8);
};

extern "C" {
void fn_27_19B5C4(void* hitPartVector, int size, const soCollisionHitPart* element, int param3);
void fn_27_CB6E0(void* collisionGroupVector, int size, int param2);
void fn_27_CC8F4(void* collisionHitGroupVector, int size, int param2);
}

extern "C" void* fn_114_9378(void* object, soModuleAccesser* accesser, int taskId,
                             unsigned char category, soEventObserverRegistrationDesc* desc) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    {
        soCollisionHitPart hitPart(static_cast<soCollision::Category>(0), 0x3FF);
        fn_27_19B5C4(storage, 20, &hitPart, 0);
    }
    fn_27_CB6E0(storage + 0x82C, 1, 0);
    fn_27_CC8F4(storage + 0x8B0, 1, 0);
    new (storage + 0x8F4) soCollisionHitModuleImpl(
        accesser, taskId, static_cast<gfTask::Category>(category),
        reinterpret_cast<soArray<soCollisionHitPart>*>(storage),
        reinterpret_cast<soArray<soCollisionGroup>*>(storage + 0x82C),
        reinterpret_cast<soArray<soCollisionHitGroup>*>(storage + 0x8B0),
        desc, true);
    return object;
}
