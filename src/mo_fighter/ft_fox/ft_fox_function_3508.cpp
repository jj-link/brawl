#include <so/so_instance_manager.h>
#include <so/so_array.h>
#include <so/so_instance_unit.h>
#pragma force_active on
class soEventUnit;
template <class T, int N> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
void operator delete(void*);
extern "C" {
void* fn_97_37F8(void*, short);
void* fn_97_3838(void*, short);
void* fn_97_38A4(void*, short);
void* fn_97_3930(void*, short);
void* fn_97_39BC(void*, short);
void* fn_97_3A48(void*, short);
void* fn_97_3AD4(void*, short);
void* fn_27_BED74(void*, short);
void* fn_97_3B30(void*, short);
void* fn_97_3BBC(void*, short);
void* fn_97_3CB8(void*, short);
void* fn_97_3FC8(void*, short);
void* fn_97_40FC(void*, short);
void* fn_97_4158(void*, short);
void* fn_97_41B4(void*, short);
void* fn_97_4220(void*, short);
void* fn_97_4280(void*, short);
void* fn_97_42E0(void*, short);
void* fn_97_433C(void*, short);
void* fn_97_4408(void*, short);
void* fn_97_4464(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_97_44D8(void*, short);
void* fn_97_4534(void*, short);
void* fn_97_45BC(void*, short);
void* fn_97_4628(void*, short);
void* fn_97_46E0(void*, short);
void* fn_97_4720(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D5B4C(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}
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

extern "C" void* fn_97_3508(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        if (members + 0x1D50 != 0) {
            if (members + 0x1D50 != 0) {
                fn_97_37F8(members + 0x1D50, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short destroy = -1;
            if (members + 0xCC != 0) {
                if (members + 0x1798 != 0) {
                    fn_97_3838(members + 0x1C48, destroy);
                    fn_97_38A4(members + 0x1B1C, destroy);
                    fn_97_3930(members + 0x19F0, destroy);
                    fn_97_39BC(members + 0x18C4, destroy);
                    fn_97_3A48(members + 0x1798, destroy);
                }
                if (members + 0xCC != 0) {
                    fn_97_3AD4(members + 0x177C, destroy);
                    if (members + 0x1624 != 0) {
                        fn_27_BED74(members + 0x1624, destroy);
                    }
                    fn_97_3B30(members + 0x148C, destroy);
                    fn_97_3BBC(members + 0x142C, destroy);
                    fn_97_3CB8(members + 0x126C, destroy);
                    fn_97_3FC8(members + 0x11C8, destroy);
                    fn_97_40FC(members + 0x1194, destroy);
                    fn_97_4158(members + 0x117C, destroy);
                    fn_97_41B4(members + 0x1018, destroy);
                    fn_97_4220(members + 0xFB0, destroy);
                    fn_97_4280(members + 0xFA4, destroy);
                    fn_97_42E0(members + 0xF7C, destroy);
                    fn_97_433C(members + 0xF0C, destroy);
                    fn_97_4408(members + 0xED0, destroy);
                    fn_97_4464(members + 0xE18, destroy);
                    if (members + 0xBD0 != 0) {
                        fn_27_13C90(members + 0xCA8, destroy);
                        fn_27_21038(members + 0xC94, destroy);
                        fn_97_44D8(members + 0xC58, destroy);
                        fn_97_4534(members + 0xBD0, destroy);
                    }
                    fn_97_45BC(members + 0x9F0, destroy);
                    fn_97_4628(members + 0x9C0, destroy);
                    fn_97_46E0(members + 0x9B0, destroy);
                    fn_97_4720(members + 0x998, destroy);
                    __dt__16soModuleAccesserFv(members + 0x8B8, destroy);
                    if (members + 0xCC != 0) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(members + 0x87C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(members + 0x844)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(members + 0x7E8)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(members + 0x78C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(members + 0x730)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(members + 0x6D4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(members + 0x678)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(members + 0x634, destroy);
                        fn_27_D5B4C(members + 0x5E4, destroy);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(members + 0x588)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(members + 0x52C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(members + 0x4D0)->~soEventUnitWithWorkArea();
                        fn_27_D597C(members + 0x48C, destroy);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(members + 0x430)->~soEventUnitWithWorkArea();
                        fn_27_18D6CC(members + 0x284, destroy);
                        fn_27_18D788(members + 0x198, destroy);
                        __dt__23soEventManageModuleImplFv(members + 0x184, destroy);
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
