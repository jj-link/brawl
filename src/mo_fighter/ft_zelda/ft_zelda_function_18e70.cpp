#include <so/so_instance_manager.h>
class soEventUnit;
template <class Observer, int Capacity> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};
extern "C" void* __dt__23soEventManageModuleImplFv(void*, short);
#pragma force_active on
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
void operator delete(void*);
extern "C" {
void* fn_104_3804(void*, short);
void* fn_104_3844(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_104_38E0(void*, short);
void* fn_104_21D0(void*, short);
void* fn_104_226C(void*, short);
void* fn_104_22AC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_104_3AF0(void*, short);
void* fn_104_3B4C(void*, short);
void* fn_104_3BA8(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_10424(void*, short);
void* fn_104_3C04(void*, short);
void* fn_104_3D50(void*, short);
void* fn_104_3E4C(void*, short);
void* fn_104_3F88(void*, short);
void* fn_104_400C(void*, short);
void* fn_27_1A4D90(void*, short);
void* fn_104_406C(void*, short);
void* fn_104_3DB0(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_104_4194(void*, short);
void* fn_104_42C8(void*, short);
void* fn_104_4324(void*, short);
void* fn_104_4380(void*, short);
void* fn_104_43EC(void*, short);
void* fn_104_444C(void*, short);
void* fn_104_44AC(void*, short);
void* fn_104_4508(void*, short);
void* fn_104_458C(void*, short);
void* fn_104_4658(void*, short);
void* fn_104_4720(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_104_480C(void*, short);
void* fn_104_4894(void*, short);
void* fn_104_4900(void*, short);
void* fn_104_49B8(void*, short);
void* fn_104_49F8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_104_18E70(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20E8 != 0) {
            if (storage + 0x20E8 != 0) fn_104_3804(storage + 0x20E8, 0);
        }
        if (object != 0) {
            fn_104_3844(storage + 0x20A0, -1);
            fn_27_1DBB60(storage + 0x2068, -1);
            if (storage + 0xCC != 0) {
                if (storage + 0x1AB8 != 0) {
                    fn_104_38E0(storage + 0x1F68, -1);
                    if (storage + 0x1E3C != 0) {
                        fn_104_21D0(storage + 0x1F18, -1);
                        fn_104_226C(storage + 0x1EFC, -1);
                        fn_104_22AC(storage + 0x1E50, -1);
                        if (storage + 0x1E3C != 0) fn_27_C7770(storage + 0x1E3C, -1);
                    }
                    if (storage + 0x1D10 != 0) {
                        fn_104_21D0(storage + 0x1DEC, -1);
                        fn_104_226C(storage + 0x1DD0, -1);
                        fn_104_22AC(storage + 0x1D24, -1);
                        if (storage + 0x1D10 != 0) fn_27_C7770(storage + 0x1D10, -1);
                    }
                    if (storage + 0x1BE4 != 0) {
                        fn_104_21D0(storage + 0x1CC0, -1);
                        fn_104_226C(storage + 0x1CA4, -1);
                        fn_104_22AC(storage + 0x1BF8, -1);
                        if (storage + 0x1BE4 != 0) fn_27_C7770(storage + 0x1BE4, -1);
                    }
                    if (storage + 0x1AB8 != 0) {
                        fn_104_21D0(storage + 0x1B94, -1);
                        fn_104_226C(storage + 0x1B78, -1);
                        fn_104_22AC(storage + 0x1ACC, -1);
                        if (storage + 0x1AB8 != 0) fn_27_C7770(storage + 0x1AB8, -1);
                    }
                }
                if (storage + 0xCC != 0) {
                    fn_104_3AF0(storage + 0x1A9C, -1);
                    fn_104_3B4C(storage + 0x1A5C, -1);
                    fn_104_3BA8(storage + 0x1A44, -1);
                    if (storage + 0x18EC != 0) fn_27_BED74(storage + 0x18EC, -1);
                    if (storage + 0x189C != 0) fn_27_10424(storage + 0x18A0, -1);
                    fn_104_3C04(storage + 0x1708, -1);
                    fn_104_3D50(storage + 0x16A8, -1);
                    fn_104_3E4C(storage + 0x15F4, -1);
                    if (storage + 0x140C != 0) {
                        fn_104_3F88(storage + 0x1544, -1);
                        fn_104_400C(storage + 0x1530, -1);
                        if (storage + 0x1500 != 0) fn_27_1A4D90(storage + 0x1500, -1);
                        fn_104_406C(storage + 0x145C, -1);
                        if (storage + 0x141C != 0) fn_104_3DB0(storage + 0x1438, -1);
                        fn_27_C74E8(storage + 0x140C, -1);
                    }
                    fn_104_4194(storage + 0x1368, -1);
                    fn_104_42C8(storage + 0x1334, -1);
                    fn_104_4324(storage + 0x131C, -1);
                    fn_104_4380(storage + 0x11B8, -1);
                    fn_104_43EC(storage + 0x1150, -1);
                    fn_104_444C(storage + 0x1144, -1);
                    fn_104_44AC(storage + 0x111C, -1);
                    fn_104_4508(storage + 0xF4C, -1);
                    fn_104_458C(storage + 0xEE8, -1);
                    fn_104_4658(storage + 0xEAC, -1);
                    fn_104_4720(storage + 0xDF4, -1);
                    if (storage + 0xBE8 != 0) {
                        fn_27_13C90(storage + 0xC84, -1);
                        fn_27_21038(storage + 0xC70, -1);
                        fn_104_480C(storage + 0xBE8, -1);
                    }
                    fn_104_4894(storage + 0xA08, -1);
                    fn_104_4900(storage + 0x9D8, -1);
                    fn_104_49B8(storage + 0x9C8, -1);
                    fn_104_49F8(storage + 0x9B0, -1);
                    __dt__16soModuleAccesserFv(storage + 0x8D0, -1);
                    if (storage + 0xCC != 0) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(storage + 0x894)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(storage + 0x85C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(storage + 0x800)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(storage + 0x7A4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(storage + 0x748)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(storage + 0x6EC)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(storage + 0x690)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(storage + 0x64C, -1);
                        fn_27_18D498(storage + 0x5E4, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(storage + 0x588)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(storage + 0x52C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(storage + 0x4D0)->~soEventUnitWithWorkArea();
                        fn_27_D597C(storage + 0x48C, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(storage + 0x430)->~soEventUnitWithWorkArea();
                        fn_27_18D6CC(storage + 0x284, -1);
                        fn_27_18D788(storage + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(storage + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(storage + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}