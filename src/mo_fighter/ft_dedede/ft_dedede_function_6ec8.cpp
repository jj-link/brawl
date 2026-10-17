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
struct DededeAttackConfigView {
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

// Initializes the collision-attack build config embedded in the ft_dedede
// fighter module storage: the soCollisionAttackPart vector starts at the
// object itself, the soCollisionGroup vector sits at +0x2DC, the
// soCollisionAttackAbsolute vector at +0x540, and the soCollisionAttackModuleImpl
// member is placement-constructed at +0x61C. The caller passes the fighter
// soModuleAccesser, the article task id, the 8-bit task category, and the
// shared soEventObserverRegistrationDesc. The config object is returned.
extern "C" void* fn_117_6EC8(void* object, soModuleAccesser* accesser, int taskId,
                             unsigned char taskCategory,
                             soEventObserverRegistrationDesc* desc) {
    {
        soCollisionAttackPart attackPart(soCollision::CategoryDefault, true);
        fn_27_CD0B0(object, 5, &attackPart, 0);
    }
    fn_27_CB908(static_cast<DededeAttackConfigView*>(object)->collisionGroups, 5, 0);
    fn_27_1A121C(static_cast<DededeAttackConfigView*>(object)->attackAbsolutes, 2, 0);
    new (static_cast<unsigned char*>(object) + 0x61C) soCollisionAttackModuleImpl(accesser, taskId,
        static_cast<gfTask::Category>(taskCategory), reinterpret_cast<soArray<soCollisionAttackPart>*>(object),
        reinterpret_cast<soArray<soCollisionGroup>*>(static_cast<unsigned char*>(object) + 0x2DC),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(static_cast<unsigned char*>(object) + 0x540),
        desc, true);
    return object;
}
