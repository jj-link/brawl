void operator delete(void*);

// ABI-only declarations: storage belongs to the enclosing aggregate and the
// destructor implementations are provided by sora_melee.
template <class Observer, int Capacity>
class soEventUnitWithWorkArea {
public:
    virtual ~soEventUnitWithWorkArea();
};

class soEventUnit;
template <class T> class soInstanceUnit;
template <class T, int Capacity> class soArrayVector;
template <class T, class Storage>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
class soModelEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;

extern "C" {
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
}

#pragma always_inline on
static inline void destroyEventUnits(char* members, short memberDeleting) {
#define DESTROY_EVENT(Offset, Observer, Capacity) \
        reinterpret_cast<soEventUnitWithWorkArea<Observer, Capacity>*>(members + Offset)->soEventUnitWithWorkArea<Observer, Capacity>::~soEventUnitWithWorkArea();
        DESTROY_EVENT(0x7BC, soMotionEventObserver, 1)
        DESTROY_EVENT(0x784, soItemManageEventObserver, 1)
        DESTROY_EVENT(0x728, soCollisionSearchEventObserver, 4)
        DESTROY_EVENT(0x6CC, soCollisionAbsorberEventObserver, 4)
        DESTROY_EVENT(0x670, soCollisionReflectorEventObserver, 4)
        DESTROY_EVENT(0x614, soCollisionShieldEventObserver, 4)
        DESTROY_EVENT(0x5B8, soCaptureEventObserver, 4)
        fn_27_18D3DC(members + 0x574, memberDeleting);
        DESTROY_EVENT(0x518, soModelEventObserver, 4)
        DESTROY_EVENT(0x4BC, soCollisionAttackEventObserver, 4)
        DESTROY_EVENT(0x460, soCollisionHitEventObserver, 4)
        DESTROY_EVENT(0x404, soSituationEventObserver, 4)
        fn_27_D597C(members + 0x3C0, memberDeleting);
        DESTROY_EVENT(0x364, soDamageEventObserver, 4)
#undef DESTROY_EVENT
        fn_27_18D6CC(members + 0x1B8, memberDeleting);
        fn_27_18D788(members + 0xCC, memberDeleting);
        __dt__23soEventManageModuleImplFv(members + 0xB8, memberDeleting);
        typedef soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > EventUnitManager;
        reinterpret_cast<EventUnitManager*>(members)->EventUnitManager::~EventUnitManager();
}
#pragma always_inline reset

extern "C" void* fn_98_4C34(void* object, short deleting) {
    if (object) {
        destroyEventUnits(static_cast<char*>(object), -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
