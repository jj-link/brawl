#include <types.h>
#pragma dont_inline on
#include <so/work/so_general_work.h>
#include <so/so_heap_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/model/so_model_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/event/so_event_manage_module_impl.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/controller/so_controller_module_link_ref.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/event/so_event_system.h>
#include <so/collision/so_collision_catch_event_presenter.h>
#pragma force_active on

template <> class soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1> {
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
extern "C" void __dt__13soGeneralWorkFv(soGeneralWork*, int);
extern "C" void __dt__16soHeapModuleImplFv(soHeapModuleImpl*, int);

extern "C" void fn_27_14B658(void*, int);
extern "C" void fn_27_63EBC(void*, int);
extern "C" void fn_27_5C674(void*, int);
extern "C" void fn_27_C21DC(void*, int);
extern "C" void fn_27_197EF4(void*, int);
extern "C" void fn_27_2689A8(void*, int);
extern "C" void fn_27_1990E8(void*, int);
extern "C" void fn_27_A3704(void*, int);
extern "C" void fn_27_A78FC(void*, int);
extern "C" void fn_27_10424(void*, int);
extern "C" void fn_27_97968(void*, int);
extern "C" void fn_27_A0C34(void*, int);
extern "C" void fn_27_1CCCC(void*, int);
extern "C" void fn_27_CBF58(void*, int);
extern "C" void fn_27_281880(void*, int);
extern "C" void fn_27_1E0B24(void*, int);
extern "C" void fn_27_72C40(void*, int);
extern "C" void fn_27_1E08D4(void*, int);
extern "C" void fn_27_C7770(void*, int);
extern "C" void fn_27_71184(void*, int);
extern "C" void fn_27_75B6C(void*, int);
extern "C" void fn_27_2821B8(void*, int);
extern "C" void fn_27_C74E8(void*, int);
extern "C" void fn_27_1A4C8C(void*, int);
extern "C" void fn_27_281FF4(void*, int);
extern "C" void fn_27_A1E80(void*, int);
extern "C" void fn_27_291138(void*, int);
extern "C" void fn_27_2912E8(void*, int);
extern "C" void fn_27_291470(void*, int);
extern "C" void fn_27_291620(void*, int);
extern "C" void fn_27_2917D0(void*, int);
extern "C" void fn_27_291958(void*, int);
extern "C" void fn_27_B21D0(void*, int);
extern "C" void fn_27_CB4A0(void*, int);
extern "C" void fn_27_19BE34(void*, int);
extern "C" void fn_27_5AE44(void*, int);
extern "C" void fn_27_6A3D8(void*, int);
extern "C" void fn_27_19A0BC(void*, int);
extern "C" void fn_27_565F0(void*, int);
extern "C" void fn_27_580E0(void*, int);
extern "C" void fn_27_689B0(void*, int);
extern "C" void fn_27_1985B4(void*, int);
extern "C" void fn_27_69684(void*, int);
extern "C" void fn_27_C31CC(void*, int);
extern "C" void fn_27_64D9C(void*, int);
extern "C" void fn_27_614C4(void*, int);
extern "C" void fn_27_291A58(void*, int);
extern "C" void fn_27_48BE8(void*, int);
extern "C" void fn_27_47CCC(void*, int);
extern "C" void fn_27_4B53C(void*, int);
extern "C" void fn_27_19C214(void*, int);
extern "C" void fn_27_4CAA0(void*, int);
extern "C" void fn_27_CDDE8(void*, int);
extern "C" void fn_27_CD78C(void*, int);
extern "C" void fn_27_4742C(void*, int);
extern "C" void fn_27_4E038(void*, int);
extern "C" void fn_27_CD4A4(void*, int);
extern "C" void fn_27_291B50(void*, int);
extern "C" void fn_27_19958C(void*, int);
extern "C" void fn_27_291CF8(void*, int);
extern "C" void fn_27_1A12AC(void*, int);
extern "C" void fn_27_CB998(void*, int);
extern "C" void fn_27_CD1F0(void*, int);
extern "C" void fn_27_B5324(void*, int);
extern "C" void fn_27_1E0BEC(void*, int);
extern "C" void fn_27_3544C(void*, int);
extern "C" void fn_27_31270(void*, int);
extern "C" void fn_27_25740(void*, int);
extern "C" void fn_27_CC0F0(void*, int);
extern "C" void fn_27_19FFEC(void*, int);
extern "C" void fn_27_13C90(void*, int);
extern "C" void fn_27_22A38(void*, int);
extern "C" void fn_27_291F7C(void*, int);
extern "C" void fn_27_C9858(void*, int);
extern "C" void fn_27_281E4C(void*, int);
extern "C" void fn_27_21038(void*, int);
extern "C" void fn_27_19A6FC(void*, int);
extern "C" void fn_27_2BC770(void*, int);
extern "C" void fn_27_281550(void*, int);
extern "C" void fn_27_D6B9C(void*, int);
extern "C" void fn_27_290760(void*, int);
extern "C" void fn_27_D7BEC(void*, int);
extern "C" void fn_27_D815C(void*, int);
extern "C" void fn_27_290920(void*, int);
extern "C" void fn_27_290AE0(void*, int);
extern "C" void fn_27_D6F3C(void*, int);
extern "C" void fn_27_D597C(void*, int);
extern "C" void fn_27_D5EEC(void*, int);
extern "C" void fn_27_290CA0(void*, int);
extern "C" void fn_27_290E60(void*, int);
extern "C" void fn_27_7F7D0(void*, int);
extern "C" void fn_27_174418(void*, int);
extern "C" void fn_27_63E00(void*, int);
extern "C" void fn_27_125D64(void*, int);
extern "C" void fn_27_978AC(void*, int);
extern "C" void fn_27_63D44(void*, int);
extern "C" void fn_27_56534(void*, int);
extern "C" void fn_27_10368(void*, int);
extern "C" void fn_27_3994(void*, int);
extern "C" void fn_27_A0C74(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), int, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_282248(void* self, int deleting) {
    if (self) {
        u8* base = static_cast<u8*>(self);
        fn_27_14B658(base + 0x3D10, -1);
        fn_27_63EBC(base + 0x3CD0, -1);
        fn_27_5C674(base + 0x3CB8, -1);
        fn_27_C21DC(base + 0x3C6C, -1);
        fn_27_197EF4(base + 0x3C58, -1);
        fn_27_2689A8(base + 0x3B8C, -1);
        fn_27_1990E8(base + 0x3AB4, -1);
        fn_27_A3704(base + 0x3A68, -1);
        fn_27_A78FC(base + 0x3A4C, -1);
        fn_27_10424(base + 0x3A04, -1);
        fn_27_97968(base + 0x38CC, -1);
        fn_27_A0C34(base + 0x38C0, -1);
        fn_27_1CCCC(base + 0x38B0, -1);
        fn_27_CBF58(base + 0x3878, -1);
        fn_27_281880(base + 0x3474, -1);
        fn_27_1E0B24(base + 0x33F4, -1);
        fn_27_72C40(base + 0x33D0, -1);
        fn_27_1E08D4(base + 0x33B4, -1);
        fn_27_1E08D4(base + 0x3398, -1);
        fn_27_1E08D4(base + 0x337C, -1);
        fn_27_1E08D4(base + 0x3360, -1);
        fn_27_1E08D4(base + 0x3344, -1);
        fn_27_1E08D4(base + 0x3328, -1);
        fn_27_C7770(base + 0x3318, -1);
        fn_27_C7770(base + 0x3308, -1);
        fn_27_C7770(base + 0x32F8, -1);
        fn_27_C7770(base + 0x32E8, -1);
        fn_27_C7770(base + 0x32D8, -1);
        fn_27_C7770(base + 0x32C8, -1);
        __destroy_arr(base + 0x2EC0, fn_27_A0C74, 0xAC, 6);
        fn_27_71184(base + 0x2E70, -1);
        fn_27_71184(base + 0x2E20, -1);
        fn_27_71184(base + 0x2DD0, -1);
        fn_27_71184(base + 0x2D80, -1);
        fn_27_71184(base + 0x2D30, -1);
        fn_27_71184(base + 0x2CE0, -1);
        fn_27_75B6C(base + 0x2C34, -1);
        fn_27_2821B8(base + 0x2C20, -1);
        fn_27_C74E8(base + 0x2C10, -1);
        fn_27_1A4C8C(base + 0x2BE4, -1);
        fn_27_281FF4(base + 0x2AE0, -1);
        fn_27_A1E80(base + 0x2AAC, -1);
        __dt__13soGeneralWorkFv(reinterpret_cast<soGeneralWork*>(base + 0x2A94), -1);
        fn_27_291138(base + 0x2A48, -1);
        fn_27_2912E8(base + 0x2A04, -1);
        fn_27_291470(base + 0x297C, -1);
        __dt__13soGeneralWorkFv(reinterpret_cast<soGeneralWork*>(base + 0x2964), -1);
        fn_27_291620(base + 0x293C, -1);
        fn_27_2917D0(base + 0x2918, -1);
        fn_27_291958(base + 0x28F8, -1);
        fn_27_B21D0(base + 0x28D4, -1);
        fn_27_CB4A0(base + 0x284C, -1);
        reinterpret_cast<soControllerModuleLinkRef*>(base + 0x2830)->soControllerModuleLinkRef::~soControllerModuleLinkRef();
        fn_27_19BE34(base + 0x2810, -1);
        fn_27_5AE44(base + 0x27FC, -1);
        fn_27_6A3D8(base + 0x27A8, -1);
        fn_27_19A0BC(base + 0x25FC, -1);
        fn_27_565F0(base + 0x25A0, -1);
        fn_27_580E0(base + 0x2594, -1);
        fn_27_689B0(base + 0x2578, -1);
        fn_27_1985B4(base + 0x24FC, -1);
        fn_27_69684(base + 0x24C4, -1);
        reinterpret_cast<soStopModuleImpl*>(base + 0x24A0)->soStopModuleImpl::~soStopModuleImpl();
        fn_27_C31CC(base + 0x2488, -1);
        fn_27_64D9C(base + 0x2424, -1);
        fn_27_614C4(base + 0x2320, -1);
        fn_27_291A58(base + 0x2134, -1);
        fn_27_48BE8(base + 0x20D0, -1);
        fn_27_47CCC(base + 0x20C0, -1);
        fn_27_4B53C(base + 0x1FDC, -1);
        fn_27_19C214(base + 0x1F74, -1);
        fn_27_4CAA0(base + 0x1EF0, -1);
        fn_27_CDDE8(base + 0x1E2C, -1);
        fn_27_CD78C(base + 0x1DC0, -1);
        fn_27_48BE8(base + 0x1D6C, -1);
        fn_27_4742C(base + 0x1D5C, -1);
        fn_27_4CAA0(base + 0x1CD8, -1);
        fn_27_CDDE8(base + 0x1C14, -1);
        fn_27_CD78C(base + 0x1BA8, -1);
        fn_27_4E038(base + 0x1AA0, -1);
        fn_27_CD4A4(base + 0x1A34, -1);
        reinterpret_cast<soCollisionHitModuleImpl*>(base + 0x19CC)->soCollisionHitModuleImpl::~soCollisionHitModuleImpl();
        fn_27_291B50(base + 0x1918, -1);
        fn_27_19958C(base + 0x17A4, -1);
        fn_27_291CF8(base + 0x1660, -1);
        reinterpret_cast<soCollisionAttackModuleImpl*>(base + 0x15C0)->soCollisionAttackModuleImpl::~soCollisionAttackModuleImpl();
        fn_27_1A12AC(base + 0x14E4, -1);
        fn_27_CB998(base + 0x1280, -1);
        fn_27_CD1F0(base + 0xFA4, -1);
        fn_27_B5324(base + 0xF60, -1);
        fn_27_1E0BEC(base + 0xF50, -1);
        fn_27_1E0BEC(base + 0xF40, -1);
        fn_27_3544C(base + 0xF04, -1);
        fn_27_31270(base + 0xED4, -1);
        fn_27_25740(base + 0xE7C, -1);
        fn_27_CC0F0(base + 0xE2C, -1);
        reinterpret_cast<soPostureModuleImpl*>(base + 0xDB4)->soPostureModuleImpl::~soPostureModuleImpl();
        fn_27_19FFEC(base + 0xD78, -1);
        fn_27_13C90(base + 0xC08, -1);
        fn_27_22A38(base + 0xC00, -1);
        fn_27_291F7C(base + 0xBD4, -1);
        fn_27_C9858(base + 0xB44, -1);
        fn_27_281E4C(base + 0xAE0, -1);
        fn_27_21038(base + 0xAD0, -1);
        reinterpret_cast<soModelModuleImpl*>(base + 0xA04)->soModelModuleImpl::~soModelModuleImpl();
        fn_27_19A6FC(base + 0x95C, -1);
        fn_27_2BC770(base + 0x920, -1);
        fn_27_281550(base + 0x900, -1);
        __dt__16soHeapModuleImplFv(reinterpret_cast<soHeapModuleImpl*>(base + 0x8E8), -1);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>*>(base + 0x874)->soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>::~soEventUnitWithWorkArea();
        fn_27_D6B9C(base + 0x83C, -1);
        fn_27_290760(base + 0x7F8, -1);
        fn_27_D7BEC(base + 0x7B4, -1);
        fn_27_D815C(base + 0x77C, -1);
        fn_27_290920(base + 0x738, -1);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(base + 0x6DC)->soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>::~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(base + 0x680)->soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>::~soEventUnitWithWorkArea();
        fn_27_290AE0(base + 0x5E8, -1);
        fn_27_D6F3C(base + 0x5A4, -1);
        fn_27_D597C(base + 0x560, -1);
        fn_27_D5EEC(base + 0x528, -1);
        fn_27_290CA0(base + 0x394, -1);
        fn_27_290E60(base + 0x278, -1);
        reinterpret_cast<soEventManageModuleImpl*>(base + 0x264)->soEventManageModuleImpl::~soEventManageModuleImpl();
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(base + 0x1AC)->soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >::~soInstanceManagerSimpleEntity();
        reinterpret_cast<soModuleAccesser*>(base + 0xCC)->soModuleAccesser::~soModuleAccesser();
        fn_27_7F7D0(base + 0xB8, 0);
        fn_27_174418(base + 0xAC, 0);
        fn_27_63E00(base + 0xA0, 0);
        fn_27_125D64(base + 0x94, 0);
        fn_27_978AC(base + 0x88, 0);
        fn_27_63D44(base + 0x7C, 0);
        fn_27_56534(base + 0x70, 0);
        fn_27_10368(base + 0x64, 0);
        fn_27_3994(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
