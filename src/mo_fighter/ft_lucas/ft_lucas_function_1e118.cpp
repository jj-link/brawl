#include <types.h>
#include <so/event/so_event_manage_module_impl.h>
#include <so/model/so_model_event_presenter.h>
#include <so/collision/so_collision_attack_event_presenter.h>
#include <so/situation/so_situation_event_presenter.h>
#include <so/damage/so_damage_event_presenter.h>
#pragma force_active on


template <typename T>
class soEventUnitWithWorkArea<T, 4> : public soEventUnitImpl<T> {
    soInstanceManagerFullPropertyVector<T*, 4> m_observerList;
public:
    virtual ~soEventUnitWithWorkArea();
    virtual u32 getObserverNum() const;
};

extern "C" void* fn_27_1A8B10(void*, short);
extern "C" void* fn_27_D7DBC(void*, short);
extern "C" void* fn_27_18D3DC(void*, short);
extern "C" void* fn_27_D597C(void*, short);
extern "C" void* fn_27_1AA128(void*, short);
extern "C" void* fn_27_18D788(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_1E118(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A8B10((char*)object + 0x544, -1);
        fn_27_D7DBC((char*)object + 0x504, -1);
        fn_27_18D3DC((char*)object + 0x4bc, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>((char*)object + 0x460)->soEventUnitWithWorkArea<soModelEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>((char*)object + 0x404)->soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>((char*)object + 0x3a4)->soEventUnitWithWorkArea<soSituationEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_D597C((char*)object + 0x360, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>((char*)object + 0x304)->soEventUnitWithWorkArea<soDamageEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_1AA128((char*)object + 0x1b8, -1);
        fn_27_18D788((char*)object + 0xcc, -1);
        reinterpret_cast<soEventManageModuleImpl*>((char*)object + 0xb8)->~soEventManageModuleImpl();
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(object)->~soInstanceManagerSimpleEntity();
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
