#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

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

extern "C" soArray<soCollisionHitPart>* fn_91_32F8(
    soArray<soCollisionHitPart>* self, soModuleAccesser* moduleAccesser, int taskId,
    unsigned char taskCategory, soEventObserverRegistrationDesc* registrationDesc) {
    unsigned char* base = reinterpret_cast<unsigned char*>(self);
    {
        soCollisionHitPart hitPart(static_cast<soCollision::Category>(0), 0x3FF);
        fn_27_19B5C4(self, 20, &hitPart, 0);
    }
    fn_27_CB6E0(base + 0x82C, 1, 0);
    fn_27_CC8F4(base + 0x8B0, 1, 0);
    new (base + 0x8F4)
        soCollisionHitModuleImpl(
            moduleAccesser, taskId, static_cast<gfTask::Category>(taskCategory),
            self,
            reinterpret_cast<soArray<soCollisionGroup>*>(base + 0x82C),
            reinterpret_cast<soArray<soCollisionHitGroup>*>(base + 0x8B0),
            registrationDesc, true);
    return self;
}
