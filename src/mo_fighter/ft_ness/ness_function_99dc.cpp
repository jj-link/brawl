#include <new>
#pragma use_simple_stdpnew on

// ABI views of the out-of-line constructors and array-vector initializers
// used by this collision-attack build-config initializer. Their storage
// belongs to the containing fighter object, not these declaration-only views.
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
class soCollisionAttackModuleImpl { public: soCollisionAttackModuleImpl(soModuleAccesser*, int, gfTask::Category, soArray<soCollisionAttackPart>*, soArray<soCollisionGroup>*, soArray<soCollisionAttackAbsolute>*, soEventObserverRegistrationDesc*, bool); };
struct NessAttackConfigView {
    unsigned char attackParts[0x2DC];
    unsigned char collisionGroups[0x264];
    unsigned char attackAbsolutes[0xDC];
    unsigned char impl[0xA0];
};

extern "C" {
void fn_27_CD0B0(void* parts, int count, void* fill, int param);
void fn_27_CB908(void* groups, int count, int param);
void fn_27_1A121C(void* absolutes, int count, int param);
}

// Initializes the collision-attack build config embedded in the ft_ness
// fighter module storage: the soCollisionAttackPart vector starts at the
// object itself, the soCollisionGroup vector sits at +0x2DC, the
// soCollisionAttackAbsolute vector at +0x540, and the soCollisionAttackModuleImpl
// member is placement-constructed at +0x61C. The caller passes the fighter
// soModuleAccesser (modules+0x9D0), the article task id (article+0x28), the
// 8-bit task category extracted from article+0x2C, and the shared
// soEventObserverRegistrationDesc (lbl_27_bss_A48). The config object is
// returned. Mirrors the twin fn_101_9AA0 hit-module initializer.
extern "C" void* fn_101_99DC(void* object, soModuleAccesser* accesser, int taskId,
                             unsigned char taskCategory,
                             soEventObserverRegistrationDesc* desc) {
    {
        soCollisionAttackPart attackPart(soCollision::CategoryDefault, true);
        fn_27_CD0B0(object, 5, &attackPart, 0);
    }
    fn_27_CB908(static_cast<NessAttackConfigView*>(object)->collisionGroups, 5, 0);
    fn_27_1A121C(static_cast<NessAttackConfigView*>(object)->attackAbsolutes, 2, 0);
    new (static_cast<unsigned char*>(object) + 0x61C) soCollisionAttackModuleImpl(accesser, taskId,
        static_cast<gfTask::Category>(taskCategory), reinterpret_cast<soArray<soCollisionAttackPart>*>(object),
        reinterpret_cast<soArray<soCollisionGroup>*>(static_cast<unsigned char*>(object) + 0x2DC),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(static_cast<unsigned char*>(object) + 0x540),
        desc, true);
    return object;
}
