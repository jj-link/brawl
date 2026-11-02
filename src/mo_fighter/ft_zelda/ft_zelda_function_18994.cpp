#include <so/event/so_event_system.h>
#pragma force_active on

class soModelEventObserver;
class soCollisionAttackEventObserver;
class soSituationEventObserver;

#define DECLARE_EVENT(Observer) \
template <> class soEventUnitWithWorkArea<Observer, 4> : public soEventUnitImpl<Observer> { \
    soInstanceManagerFullPropertyVector<Observer*, 4> m_observerList; \
public: \
    soEventUnitWithWorkArea(s16, s16); \
    virtual ~soEventUnitWithWorkArea(); \
    virtual u32 getObserverNum() const; \
};

DECLARE_EVENT(soModelEventObserver)
DECLARE_EVENT(soCollisionAttackEventObserver)
DECLARE_EVENT(soSituationEventObserver)

#undef DECLARE_EVENT

void operator delete(void*);

extern "C" {
void* fn_104_3804(void*, short);
void* fn_104_3844(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_104_18360(void*, short);
void* fn_104_21D0(void*, short);
void* fn_104_226C(void*, short);
void* fn_104_183CC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_104_3B4C(void*, short);
void* fn_104_3BA8(void*, short);
void* fn_104_3C04(void*, short);
void* fn_104_3D50(void*, short);
void* fn_104_3E4C(void*, short);
void* fn_104_3F88(void*, short);
void* fn_104_400C(void*, short);
void* fn_104_18428(void*, short);
void* fn_104_18484(void*, short);
void* fn_104_1850C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_104_4194(void*, short);
void* fn_104_42C8(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_104_4380(void*, short);
void* fn_104_43EC(void*, short);
void* fn_104_444C(void*, short);
void* fn_104_44AC(void*, short);
void* fn_104_458C(void*, short);
void* fn_104_4658(void*, short);
void* fn_104_4720(void*, short);
void* fn_104_51C0(void*, short);
void* fn_104_4894(void*, short);
void* fn_104_4900(void*, short);
void* fn_104_49B8(void*, short);
void* fn_104_49F8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_1A8B10(void*, short);
void* fn_27_D7DBC(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D57AC(void*, short);
void* fn_27_1A9F58(void*, short);
void* fn_27_D645C(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_104_18994(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (p + 0x17c8 != 0) {
            if (p + 0x17c8 != 0)
                fn_104_3804(p + 0x17c8, 0);
        }
        if (object != 0) {
            fn_104_3844(p + 0x1780, -1);
            fn_27_1DBB60(p + 0x1748, -1);
            if (p + 0xcc != 0) {
                if (p + 0x13f0 != 0) {
                    fn_104_18360(p + 0x16c0, -1);
                    if (p + 0x160c != 0) {
                        fn_104_21D0(p + 0x1670, -1);
                        fn_104_226C(p + 0x1654, -1);
                        fn_104_183CC(p + 0x1620, -1);
                        if (p + 0x160c != 0)
                            fn_27_C7770(p + 0x160c, -1);
                    }
                    if (p + 0x1558 != 0) {
                        fn_104_21D0(p + 0x15bc, -1);
                        fn_104_226C(p + 0x15a0, -1);
                        fn_104_183CC(p + 0x156c, -1);
                        if (p + 0x1558 != 0)
                            fn_27_C7770(p + 0x1558, -1);
                    }
                    if (p + 0x14a4 != 0) {
                        fn_104_21D0(p + 0x1508, -1);
                        fn_104_226C(p + 0x14ec, -1);
                        fn_104_183CC(p + 0x14b8, -1);
                        if (p + 0x14a4 != 0)
                            fn_27_C7770(p + 0x14a4, -1);
                    }
                    if (p + 0x13f0 != 0) {
                        fn_104_21D0(p + 0x1454, -1);
                        fn_104_226C(p + 0x1438, -1);
                        fn_104_183CC(p + 0x1404, -1);
                        if (p + 0x13f0 != 0)
                            fn_27_C7770(p + 0x13f0, -1);
                    }
                }
                if (p + 0xcc != 0) {
                    fn_104_3B4C(p + 0x13ac, -1);
                    fn_104_3BA8(p + 0x1394, -1);
                    fn_104_3C04(p + 0x11f8, -1);
                    fn_104_3D50(p + 0x1198, -1);
                    fn_104_3E4C(p + 0x10e4, -1);
                    if (p + 0xf58 != 0) {
                        fn_104_3F88(p + 0x1034, -1);
                        fn_104_400C(p + 0x1020, -1);
                        fn_104_18428(p + 0x1004, -1);
                        fn_104_18484(p + 0xfa0, -1);
                        fn_104_1850C(p + 0xf68, -1);
                        fn_27_C74E8(p + 0xf58, -1);
                    }
                    fn_104_4194(p + 0xeb4, -1);
                    fn_104_42C8(p + 0xe80, -1);
                    if (p + 0xe4c != 0)
                        fn_27_5B39C(p + 0xe4c, -1);
                    fn_104_4380(p + 0xce8, -1);
                    fn_104_43EC(p + 0xc80, -1);
                    fn_104_444C(p + 0xc74, -1);
                    fn_104_44AC(p + 0xc4c, -1);
                    fn_104_458C(p + 0xbdc, -1);
                    fn_104_4658(p + 0xba0, -1);
                    fn_104_4720(p + 0xae8, -1);
                    fn_104_51C0(p + 0x8dc, -1);
                    fn_104_4894(p + 0x6fc, -1);
                    fn_104_4900(p + 0x6cc, -1);
                    fn_104_49B8(p + 0x6bc, -1);
                    fn_104_49F8(p + 0x6a4, -1);
                    __dt__16soModuleAccesserFv(p + 0x5c4, -1);
                    if (p + 0xcc != 0) {
                        fn_27_1A8B10(p + 0x54c, -1);
                        fn_27_D7DBC(p + 0x50c, -1);
                        fn_27_18D3DC(p + 0x4c4, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p + 0x468)->soEventUnitWithWorkArea<soModelEventObserver, 4>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x40c)->soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x3ac)->soEventUnitWithWorkArea<soSituationEventObserver, 4>::~soEventUnitWithWorkArea();
                        fn_27_D57AC(p + 0x374, -1);
                        fn_27_1A9F58(p + 0x254, -1);
                        fn_27_D645C(p + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(p + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xcc)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0)
            operator delete(object);
    }
    return object;
}
