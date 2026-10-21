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
void fn_27_19B134(void* hitPartVector, int size, const soCollisionHitPart* element, int param3);
void fn_27_CB6E0(void* collisionGroupVector, int size, int param2);
void fn_27_CC8F4(void* collisionHitGroupVector, int size, int param2);
}

extern "C" soArray<soCollisionHitPart>* fn_97_88F0(soArray<soCollisionHitPart>* self,
                                                   soModuleAccesser* moduleAccesser,
                                                   int taskId, unsigned char taskCategory,
                                                   soEventObserverRegistrationDesc* registrationDesc) {
    unsigned char* base = reinterpret_cast<unsigned char*>(self);
    {
        soCollisionHitPart hitPart(static_cast<soCollision::Category>(0), 0x3FF);
        fn_27_19B134(base, 0xD, &hitPart, 0);
    }
    fn_27_CB6E0(base + 0x554, 1, 0);
    fn_27_CC8F4(base + 0x5D8, 1, 0);
    new (base + 0x61C) soCollisionHitModuleImpl(
        moduleAccesser, taskId, static_cast<gfTask::Category>(taskCategory),
        self,
        reinterpret_cast<soArray<soCollisionGroup>*>(base + 0x554),
        reinterpret_cast<soArray<soCollisionHitGroup>*>(base + 0x5D8),
        registrationDesc, true);
    return self;
}
