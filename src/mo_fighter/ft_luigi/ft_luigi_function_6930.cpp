#include <new>

// ABI views of the out-of-line constructors used by this hit-module builder.
// Their storage belongs to the containing object, not these declaration-only views.
class soModuleAccesser;
class soEventObserverRegistrationDesc;
template<class T> class soArray;
class gfTask {
public:
    enum Category { CategoryDefault };
};
class soCollision {
public:
    enum Category { CategoryDefault };
};
class soCollisionGroup;
class soCollisionHitGroup;
class soCollisionHitPart {
public:
    soCollisionHitPart(soCollision::Category, unsigned long);
    ~soCollisionHitPart();
private:
    unsigned long m_storage[26];
};
class soCollisionHitModuleImpl {
public:
    soCollisionHitModuleImpl(soModuleAccesser*, int, gfTask::Category,
        soArray<soCollisionHitPart>*, soArray<soCollisionGroup>*, soArray<soCollisionHitGroup>*,
        soEventObserverRegistrationDesc*, bool);
};

extern "C" {
void fn_27_19B5C4(void*, int, const soCollisionHitPart&, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_CC8F4(void*, int, int);
}

typedef unsigned char Byte;

// Builds the fighter's collision-hit aggregate: a 20-entry hit-part array vector seeded
// from a fighter-category, all-opponents hit part; single collision-group and hit-group
// array vectors; and the embedded hit module at offset 0x8F4. The hit part is a temporary
// bound to the array vector constructor's value parameter, so its destructor runs once the
// call returns.
extern "C" void* fn_99_6930(Byte* object, soModuleAccesser* moduleAccesser, int taskId,
    unsigned char taskCategory, soEventObserverRegistrationDesc* registrationDesc) {
    fn_27_19B5C4(object, 20, soCollisionHitPart(soCollision::CategoryDefault, 0x3ff), 0);
    fn_27_CB6E0(object + 0x82C, 1, 0);
    fn_27_CC8F4(object + 0x8B0, 1, 0);
    new (object + 0x8F4) soCollisionHitModuleImpl(moduleAccesser, taskId,
        static_cast<gfTask::Category>(taskCategory),
        reinterpret_cast<soArray<soCollisionHitPart>*>(object),
        reinterpret_cast<soArray<soCollisionGroup>*>(object + 0x82C),
        reinterpret_cast<soArray<soCollisionHitGroup>*>(object + 0x8B0),
        registrationDesc, true);
    return object;
}
