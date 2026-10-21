// fn_95_87C0 - ft_yoshi collision-hit module build config constructor.
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

struct YoshiCollisionHitBuildConfig {
    unsigned char m_hitPartVector[0x82C];
    unsigned char m_collisionGroupVector[0x84];
    unsigned char m_collisionHitGroupVector[0x44];
    unsigned char m_hitModule[0x68];
};

extern "C" {
void fn_27_19B5C4(void* hitPartVector, int size, const soCollisionHitPart* element, int param3);
void fn_27_CB6E0(void* collisionGroupVector, int size, int param2);
void fn_27_CC8F4(void* collisionHitGroupVector, int size, int param2);
}

extern "C" YoshiCollisionHitBuildConfig* fn_95_87C0(
    YoshiCollisionHitBuildConfig* config, soModuleAccesser* moduleAccesser, int taskId,
    unsigned char taskCategory, soEventObserverRegistrationDesc* registrationDesc) {
    {
        soCollisionHitPart hitPart(static_cast<soCollision::Category>(0), 0x3FF);
        fn_27_19B5C4(config->m_hitPartVector, 20, &hitPart, 0);
    }
    fn_27_CB6E0(config->m_collisionGroupVector, 1, 0);
    fn_27_CC8F4(config->m_collisionHitGroupVector, 1, 0);
    new (reinterpret_cast<soCollisionHitModuleImpl*>(config->m_hitModule))
        soCollisionHitModuleImpl(
            moduleAccesser, taskId, static_cast<gfTask::Category>(taskCategory),
            reinterpret_cast<soArray<soCollisionHitPart>*>(config->m_hitPartVector),
            reinterpret_cast<soArray<soCollisionGroup>*>(config->m_collisionGroupVector),
            reinterpret_cast<soArray<soCollisionHitGroup>*>(config->m_collisionHitGroupVector),
            registrationDesc, true);
    return config;
}
