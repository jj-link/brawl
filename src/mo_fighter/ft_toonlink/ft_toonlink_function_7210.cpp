#include <so/event/so_event_manage_module_impl.h>

#pragma force_active on

void operator delete(void*);
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

template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};

extern "C" void* fn_27_18D3DC(void*, short);
extern "C" void* fn_27_D597C(void*, short);
extern "C" void* fn_27_18D6CC(void*, short);
extern "C" void* fn_27_18D788(void*, short);

extern "C" void* fn_121_7210(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x7BC)->soEventUnitWithWorkArea<soMotionEventObserver, 1>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x784)->soEventUnitWithWorkArea<soItemManageEventObserver, 1>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x728)->soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x6CC)->soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x670)->soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x614)->soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x5B8)->soEventUnitWithWorkArea<soCaptureEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_18D3DC(storage + 0x574, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(storage + 0x518)->soEventUnitWithWorkArea<soModelEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x4BC)->soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x460)->soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x404)->soEventUnitWithWorkArea<soSituationEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_D597C(storage + 0x3C0, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x364)->soEventUnitWithWorkArea<soDamageEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_18D6CC(storage + 0x1B8, -1);
        fn_27_18D788(storage + 0xCC, -1);
        reinterpret_cast<soEventManageModuleImpl*>(storage + 0xB8)->~soEventManageModuleImpl();
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
