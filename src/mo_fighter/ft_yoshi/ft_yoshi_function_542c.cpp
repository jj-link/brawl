#include <so/so_instance_manager.h>
#include <so/so_array.h>
#include <so/so_instance_unit.h>
#pragma force_active on
class soEventUnit;
class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
class soCollisionAttackEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;
template <class T, int N> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
void operator delete(void*);
extern "C" {
void* fn_95_37C8(void*, short);
void* fn_95_3808(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_95_39D0(void*, short);
void* fn_95_22E0(void*, short);
void* fn_95_237C(void*, short);
void* fn_95_23BC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_95_3A3C(void*, short);
void* fn_95_3AC8(void*, short);
void* fn_95_3B24(void*, short);
void* fn_27_BED74(void*, short);
void* fn_95_2F7C(void*, short);
void* fn_95_3B80(void*, short);
void* fn_95_3C0C(void*, short);
void* fn_95_3D08(void*, short);
void* fn_95_3E44(void*, short);
void* fn_95_4154(void*, short);
void* fn_95_4288(void*, short);
void* fn_95_42E4(void*, short);
void* fn_95_4340(void*, short);
void* fn_95_43AC(void*, short);
void* fn_95_440C(void*, short);
void* fn_95_446C(void*, short);
void* fn_95_44C8(void*, short);
void* fn_95_454C(void*, short);
void* fn_95_4618(void*, short);
void* fn_95_46E0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_95_5800(void*, short);
void* fn_95_47CC(void*, short);
void* fn_95_4854(void*, short);
void* fn_95_48C0(void*, short);
void* fn_95_4978(void*, short);
void* fn_95_49B8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}
extern "C" void* fn_95_542C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        if (p + 0x20E4 != 0) {
            if (p + 0x20E4 != 0) fn_95_37C8(p + 0x20E4, 0);
        }
        if (object != 0) {
            fn_95_3808(p + 0x209C, d);
            fn_27_1DBB60(p + 0x2064, d);
            if (p + 0xCC != 0) {
                if (p + 0x1AB4 != 0) {
                    fn_95_39D0(p + 0x1F64, d);
                    if (p + 0x1E38 != 0) {
                        fn_95_22E0(p + 0x1F14, d);
                        fn_95_237C(p + 0x1EF8, d);
                        fn_95_23BC(p + 0x1E4C, d);
                        if (p + 0x1E38 != 0) fn_27_C7770(p + 0x1E38, d);
                    }
                    if (p + 0x1D0C != 0) {
                        fn_95_22E0(p + 0x1DE8, d);
                        fn_95_237C(p + 0x1DCC, d);
                        fn_95_23BC(p + 0x1D20, d);
                        if (p + 0x1D0C != 0) fn_27_C7770(p + 0x1D0C, d);
                    }
                    if (p + 0x1BE0 != 0) {
                        fn_95_22E0(p + 0x1CBC, d);
                        fn_95_237C(p + 0x1CA0, d);
                        fn_95_23BC(p + 0x1BF4, d);
                        if (p + 0x1BE0 != 0) fn_27_C7770(p + 0x1BE0, d);
                    }
                    fn_95_3A3C(p + 0x1AB4, d);
                }
                if (p + 0xCC != 0) {
                    fn_95_3AC8(p + 0x1A70, d);
                    fn_95_3B24(p + 0x1A58, d);
                    if (p + 0x1900 != 0) fn_27_BED74(p + 0x1900, d);
                    fn_95_2F7C(p + 0x18B4, d);
                    fn_95_3B80(p + 0x171C, d);
                    fn_95_3C0C(p + 0x16BC, d);
                    fn_95_3D08(p + 0x1608, d);
                    fn_95_3E44(p + 0x1448, d);
                    fn_95_4154(p + 0x13A4, d);
                    fn_95_4288(p + 0x1370, d);
                    fn_95_42E4(p + 0x1358, d);
                    fn_95_4340(p + 0x11F4, d);
                    fn_95_43AC(p + 0x118C, d);
                    fn_95_440C(p + 0x1180, d);
                    fn_95_446C(p + 0x1158, d);
                    fn_95_44C8(p + 0xF88, d);
                    fn_95_454C(p + 0xF24, d);
                    fn_95_4618(p + 0xEE8, d);
                    fn_95_46E0(p + 0xE30, d);
                    if (p + 0xBE8 != 0) {
                        fn_27_13C90(p + 0xCC0, d);
                        fn_27_21038(p + 0xCAC, d);
                        fn_95_5800(p + 0xC70, d);
                        fn_95_47CC(p + 0xBE8, d);
                    }
                    fn_95_4854(p + 0xA08, d);
                    fn_95_48C0(p + 0x9D8, d);
                    fn_95_4978(p + 0x9C8, d);
                    fn_95_49B8(p + 0x9B0, d);
                    __dt__16soModuleAccesserFv(p + 0x8D0, d);
                    if (p + 0xCC != 0) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x894)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x85C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x800)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x7A4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x748)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x6EC)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x690)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(p + 0x64C, d);
                        fn_27_18D498(p + 0x5E4, d);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x588)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x52C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x4D0)->~soEventUnitWithWorkArea();
                        fn_27_D597C(p + 0x48C, d);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x430)->~soEventUnitWithWorkArea();
                        fn_27_18D6CC(p + 0x284, d);
                        fn_27_18D788(p + 0x198, d);
                        __dt__23soEventManageModuleImplFv(p + 0x184, d);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}