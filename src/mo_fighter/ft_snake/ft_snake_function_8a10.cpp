#include <so/so_module_accesser.h>
#include <so/so_inside_event_manage_module_builder.h>
#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_122_21F4(void*, short);
void* fn_27_C7770(void*, short);
void* fn_122_55B0(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_6498(void*, short);
void* fn_122_2E00(void*, short);
void* fn_27_10424(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_122_3114(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_44FC(void*, short);
void* fn_122_4558(void*, short);
void* fn_122_4624(void*, short);
void* fn_122_4850(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_122_8CFC(void*, short);
void* fn_122_4AD0(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
}
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };

extern "C" void* fn_122_8A10(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_122_21F4(members + 0x16AC, memberDeleting);
        fn_27_C7770(members + 0x169C, memberDeleting);
        if (object != 0) {
            if (members + 0xCC != 0) {
                if (members + 0x1564 != 0) {
                    fn_122_55B0(members + 0x1568, memberDeleting);
                }
                if (members + 0xCC != 0) {
                    short memberDeleting = -1;
                    fn_122_3C7C(members + 0x1548, memberDeleting);
                    fn_122_6498(members + 0x13F0, memberDeleting);
                    fn_122_2E00(members + 0x13A4, memberDeleting);
                    if (members + 0x1354 != 0) {
                        fn_27_10424(members + 0x1358, memberDeleting);
                    }
                    if (members + 0x11B4 != 0) {
                        short memberDeleting = -1;
                        fn_27_97968(members + 0x1218, memberDeleting);
                        fn_27_1CCCC(members + 0x1208, memberDeleting);
                        fn_122_3114(members + 0x11EC, memberDeleting);
                        if (members + 0x11B4 != 0) {
                            fn_27_CBF58(members + 0x11B4, memberDeleting);
                        }
                    }
                    short deleting2 = -1;
                    fn_122_3DE8(members + 0x1154, deleting2);
                    fn_122_430C(members + 0x10AC, deleting2);
                    fn_122_4440(members + 0x1078, deleting2);
                    fn_122_44FC(members + 0x1060, deleting2);
                    fn_122_4558(members + 0xEFC, deleting2);
                    fn_122_4624(members + 0xEEC, deleting2);
                    fn_122_4850(members + 0xE7C, deleting2);
                    if (members + 0xE30 != 0) {
                        fn_27_252D0(members + 0xE34, deleting2);
                    }
                    if (members + 0xBE8 != 0) {
                        short memberDeleting = -1;
                        fn_27_13C90(members + 0xCC0, memberDeleting);
                        fn_27_21038(members + 0xCAC, memberDeleting);
                        fn_122_8CFC(members + 0xC70, memberDeleting);
                        fn_122_4AD0(members + 0xBE8, memberDeleting);
                    }
                    short deleting3 = -1;
                    fn_122_4B58(members + 0xA08, deleting3);
                    fn_122_4BC4(members + 0x9D8, deleting3);
                    fn_122_4C7C(members + 0x9C8, deleting3);
                    fn_122_4CBC(members + 0x9B0, deleting3);
                    __dt__16soModuleAccesserFv(members + 0x8D0, deleting3);
                    if (members + 0xCC != 0) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(members + 0x894)->soEventUnitWithWorkArea<soMotionEventObserver, 1>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(members + 0x85c)->soEventUnitWithWorkArea<soItemManageEventObserver, 1>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(members + 0x800)->soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(members + 0x7a4)->soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(members + 0x748)->soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(members + 0x6ec)->soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(members + 0x690)->soEventUnitWithWorkArea<soCaptureEventObserver, 4>::~soEventUnitWithWorkArea();
                        fn_27_18D3DC(members + 0x64C, deleting3);
                        fn_27_18D498(members + 0x5E4, deleting3);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(members + 0x588)->soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(members + 0x52c)->soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>::~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(members + 0x4d0)->soEventUnitWithWorkArea<soSituationEventObserver, 4>::~soEventUnitWithWorkArea();
                        fn_27_D597C(members + 0x48C, deleting3);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(members + 0x430)->soEventUnitWithWorkArea<soDamageEventObserver, 4>::~soEventUnitWithWorkArea();
                        fn_27_18D6CC(members + 0x284, deleting3);
                        fn_27_18D788(members + 0x198, deleting3);
                        __dt__23soEventManageModuleImplFv(members + 0x184, deleting3);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(members + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
