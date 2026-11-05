#include <so/event/so_event_manage_module_impl.h>
#pragma force_active on
extern "C" void* fn_27_18D3DC(void*, short);
extern "C" void* fn_27_18D498(void*, short);
extern "C" void* fn_27_D597C(void*, short);
extern "C" void* fn_27_18D6CC(void*, short);
extern "C" void* fn_27_18D788(void*, short);
extern "C" void __dl__FPv(void*);
class soMotionEventObserver;
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
class soItemManageEventObserver;
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
class soCollisionSearchEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionAbsorberEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionReflectorEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionShieldEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCaptureEventObserver;
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionAttackEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soCollisionHitEventObserver;
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soSituationEventObserver;
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
class soDamageEventObserver;
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
extern "C" void* fn_119_114E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x7c8)->soEventUnitWithWorkArea<soMotionEventObserver, 1>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x790)->soEventUnitWithWorkArea<soItemManageEventObserver, 1>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x734)->soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x6d8)->soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x67c)->soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x620)->soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x5c4)->soEventUnitWithWorkArea<soCaptureEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_18D3DC(storage + 0x580, -1);
        fn_27_18D498(storage + 0x518, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x4bc)->soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x460)->soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x404)->soEventUnitWithWorkArea<soSituationEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_D597C(storage + 0x3c0, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x364)->soEventUnitWithWorkArea<soDamageEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_18D6CC(storage + 0x1b8, -1);
        fn_27_18D788(storage + 0xcc, -1);
        reinterpret_cast<soEventManageModuleImpl*>(storage + 0xb8)->~soEventManageModuleImpl();
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
