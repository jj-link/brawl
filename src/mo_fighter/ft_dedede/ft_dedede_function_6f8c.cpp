// fn_117_6F8C - ft_dedede collision-hit module build config constructor.
//
// Constructs, in place, the fighter's embedded collision-hit build config:
// a 20-entry soCollisionHitPart vector, a one-entry soCollisionGroup vector,
// a one-entry soCollisionHitGroup vector, and the soCollisionHitModuleImpl at
// offset 0x8f4. The hit-part template value is destroyed before the remaining
// vectors are initialized, matching the mem-initializer temporary lifetime of
// soCollisionHitModuleBuildConfig.
#include <new>
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

// Layout of the ft_dedede collision-hit build config embedded in the fighter:
// 20 hit parts, one collision group, one collision hit group, then the hit
// module itself.
struct DededeCollisionHitBuildConfig {
    unsigned char m_hitPartVector[0x82C];
    unsigned char m_collisionGroupVector[0x84];
    unsigned char m_collisionHitGroupVector[0x44];
    unsigned char m_hitModule[0x68];
};

extern "C" {
// soArrayVector<soCollisionHitPart, 20>(int size, const soCollisionHitPart&, int)
void fn_27_19B5C4(void* hitPartVector, int size, const soCollisionHitPart* element, int param3);
// soArrayVector<soCollisionGroup, 1>(int size, int)
void fn_27_CB6E0(void* collisionGroupVector, int size, int param2);
// soArrayVector<soCollisionHitGroup, 1>(int size, int)
void fn_27_CC8F4(void* collisionHitGroupVector, int size, int param2);
}

// Constructs the collision-hit module build config in place and returns it.
extern "C" DededeCollisionHitBuildConfig* fn_117_6F8C(
    DededeCollisionHitBuildConfig* config, soModuleAccesser* moduleAccesser, int taskId,
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
