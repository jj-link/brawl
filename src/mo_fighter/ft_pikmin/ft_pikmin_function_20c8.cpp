#pragma force_active on
#include <types.h>

void operator delete(void*);

extern "C" {
void* fn_27_196CC0(void*, short);
void* fn_113_E04(void*, short);
void* fn_27_C7770(void*, short);
void* fn_113_22E38(void*, short);
void* fn_113_2908(void*, short);
void* fn_113_A6C(void*, short);
void* fn_27_64874(void*, short);
void* fn_27_D3B50(void*, short);
void* fn_113_D68(void*, short);
void* fn_113_E44(void*, short);
void* fn_113_2948(void*, short);
void* fn_113_EA0(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_113_29B4(void*, short);
void* fn_27_C21DC(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_198E00(void*, short);
void* fn_27_199318(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_A3704(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_113_1D18(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_113_2A10(void*, short);
void* fn_27_8B300(void*, short);
void* fn_113_EC94(void*, short);
void* fn_113_E968(void*, short);
void* fn_113_EB00(void*, short);
void* fn_113_4730(void*, short);
void* fn_113_EE84(void*, short);
void* fn_113_2AAC(void*, short);
void* fn_113_2B5C(void*, short);
void* fn_113_2C28(void*, short);
void* fn_113_2CAC(void*, short);
void* fn_27_1A4A84(void*, short);
void* fn_113_2D0C(void*, short);
void* fn_27_1A172C(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_113_2DAC(void*, short);
void* fn_113_2EE0(void*, short);
void* fn_113_2F3C(void*, short);
void* fn_27_19BE34(void*, short);
void* fn_27_1998BC(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_113_2F98(void*, short);
void* fn_113_3004(void*, short);
void* fn_113_3064(void*, short);
void* fn_113_30C4(void*, short);
void* fn_113_3120(void*, short);
void* fn_27_5CC1C(void*, short);
void* fn_27_D3080(void*, short);
void* fn_27_4E038(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CD4A4(void*, short);
void* fn_27_4B53C(void*, short);
void* fn_27_19C214(void*, short);
void* __dt__24soCollisionHitModuleImplFv(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_CC654(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_1A12AC(void*, short);
void* fn_27_CCF74(void*, short);
void* fn_113_317C(void*, short);
void* fn_113_3248(void*, short);
void* fn_113_32A4(void*, short);
void* fn_113_3310(void*, short);
void* fn_27_13C90(void*, short);
void* fn_113_3384(void*, short);
void* fn_27_21038(void*, short);
void* fn_113_33F0(void*, short);
void* fn_113_344C(void*, short);
void* fn_113_34D4(void*, short);
void* fn_113_3540(void*, short);
void* fn_113_35F8(void*, short);
void* fn_113_3638(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D784C(void*, short);
void* fn_27_1AA40C(void*, short);
void* fn_27_1A9818(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_D597C(void*, short);
}

class soMotionEventObserver;
class soItemManageEventObserver;
class soCollisionSearchEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionShieldEventObserver;
class soCaptureEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;
class soCollisionCatchEventObserver;
class soEventUnit;

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template<class T>
class soInstanceUnit {};

template<class T, int N>
class soArrayVector {};

template<class T, class A>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" void* fn_113_20C8(void* object, short deleting) {
    if (object) {
        char* p = static_cast<char*>(object);
        short d = -1;
        fn_27_196CC0(p + 0x3334, d);
        fn_113_E04(p + 0x3318, d);
        fn_27_C7770(p + 0x3308, d);
        fn_113_E04(p + 0x32EC, d);
        fn_27_C7770(p + 0x32DC, d);
        fn_113_E04(p + 0x32C0, d);
        fn_27_C7770(p + 0x32B0, d);
        if (p + 0x3148) {
            fn_113_22E38(p + 0x32A0, d);
            if (p + 0x3148) fn_113_2908(p + 0x3148, 0);
        }
        fn_113_A6C(p + 0x3130, 0);
        if (p + 0x3124) fn_27_64874(p + 0x3124, 0);
        if (p + 0x3118) fn_27_D3B50(p + 0x3118, 0);

        if (object) {
            if (p + 0xcc) {
                if (p + 0x2A5C) {
                    if (p + 0x2FE8) {
                        fn_113_D68(p + 0x30C4, d);
                        fn_113_E04(p + 0x30A8, d);
                        fn_113_E44(p + 0x2FFC, d);
                        if (p + 0x2FE8) fn_27_C7770(p + 0x2FE8, d);
                    }
                    fn_113_2948(p + 0x2EEC, d);
                    if (p + 0x2DD0) {
                        fn_113_D68(p + 0x2E9C, d);
                        fn_113_E04(p + 0x2E80, d);
                        fn_113_E44(p + 0x2DD4, d);
                    }
                    if (p + 0x2CB4) {
                        fn_113_D68(p + 0x2D80, d);
                        fn_113_E04(p + 0x2D64, d);
                        fn_113_E44(p + 0x2CB8, d);
                    }
                    if (p + 0x2B98) {
                        fn_113_D68(p + 0x2C64, d);
                        fn_113_E04(p + 0x2C48, d);
                        fn_113_E44(p + 0x2B9C, d);
                    }
                    if (p + 0x2A5C) {
                        fn_113_D68(p + 0x2B48, d);
                        fn_113_E04(p + 0x2B2C, d);
                        fn_113_E44(p + 0x2A80, d);
                        fn_113_EA0(p + 0x2A6C, d);
                        if (p + 0x2A5C) fn_27_C7770(p + 0x2A5C, d);
                    }
                }
                if (p + 0xcc) {
                    if (p + 0x2A40) fn_27_C31CC(p + 0x2A40, d);
                    if (p + 0x2A00) fn_27_63EBC(p + 0x2A00, d);
                    fn_113_29B4(p + 0x29E8, d);
                    if (p + 0x2998) fn_27_C21DC(p + 0x2998, d);
                    if (p + 0x2844) fn_27_BED74(p + 0x2844, d);
                    if (p + 0x2734) {
                        fn_27_198E00(p + 0x280C, d);
                        fn_27_199318(p + 0x27A0, d);
                        fn_27_A78FC(p + 0x2784, d);
                        fn_27_A3704(p + 0x2738, d);
                    }
                    if (p + 0x25A0) {
                        fn_27_97968(p + 0x25F8, d);
                        fn_27_1CCCC(p + 0x25E8, d);
                        fn_113_1D18(p + 0x25DC, d);
                        if (p + 0x25A0) fn_27_CBF58(p + 0x25A0, d);
                    }
                    if (p + 0x24E8) fn_113_2A10(p + 0x2578, d);
                    if (p + 0x22B4) {
                        if (p + 0x2394) {
                            if (!(p + 0x2398) || !(p + 0x2398)) goto end2394;
                            if (p + 0x24A4 && p + 0x24AC) fn_27_8B300(p + 0x24B0, d);
                            if (!(p + 0x2398) || !(p + 0x2398)) goto end2394;
                            if (p + 0x2484 && p + 0x248C) fn_113_EC94(p + 0x2490, d);
                            if (!(p + 0x2398) || !(p + 0x2398)) goto end2394;
                            if (p + 0x2438 && p + 0x2440) fn_113_E968(p + 0x2444, d);
                            if (!(p + 0x2398) || !(p + 0x2398)) goto end2394;
                            if (p + 0x23FC && p + 0x2404) fn_113_EB00(p + 0x2408, d);
                            if (!(p + 0x2398) || !(p + 0x2398)) goto end2394;
                            if (p + 0x23DC && p + 0x23E4 && p + 0x23E8) fn_113_4730(p + 0x23E8, 0);
                            fn_113_EE84(p + 0x2398, 0);
                        end2394:;
                        }
                        fn_113_2AAC(p + 0x22E4, d);
                        fn_113_2B5C(p + 0x22B4, d);
                    }
                    if (p + 0x1F7C) {
                        fn_113_2C28(p + 0x2204, d);
                        fn_113_2CAC(p + 0x21F0, d);
                        if (p + 0x2114) fn_27_1A4A84(p + 0x2114, d);
                        if (p + 0x1FD0) {
                            fn_113_2D0C(p + 0x20FC, d);
                            if (p + 0x1FF0 && p + 0x1FF0 && p + 0x1FF0) fn_27_1A172C(p + 0x1FF0, d);
                            fn_27_CD934(p + 0x1FD0, d);
                        }
                        if (p + 0x1F8C) fn_113_2A10(p + 0x1FAC, d);
                        fn_27_C74E8(p + 0x1F7C, d);
                    }
                    fn_113_2DAC(p + 0x1ED8, d);
                    fn_113_2EE0(p + 0x1EA4, d);
                    if (p + 0x1DCC) {
                        fn_113_2F3C(p + 0x1E84, d);
                        if (p + 0x1E64) fn_27_19BE34(p + 0x1E64, d);
                        if (p + 0x1DCC) fn_27_1998BC(p + 0x1DCC, d);
                    }
                    if (p + 0x1D9C) fn_27_5B39C(p + 0x1D9C, d);
                    fn_113_2F98(p + 0x1C38, d);
                    fn_113_3004(p + 0x1BD0, d);
                    fn_113_3064(p + 0x1BC4, d);
                    fn_113_30C4(p + 0x1B9C, d);
                    fn_113_3120(p + 0x1B34, d);
                    if (p + 0x19DC) {
                        fn_27_5CC1C(p + 0x1A88, d);
                        if (p + 0x19DC) fn_27_D3080(p + 0x19DC, d);
                    }
                    if (p + 0x17E4) {
                        fn_27_4E038(p + 0x18D4, d);
                        fn_27_4CAA0(p + 0x1850, d);
                        fn_27_CD4A4(p + 0x17E4, d);
                    }
                    if (p + 0x1698) {
                        fn_27_4B53C(p + 0x1700, d);
                        fn_27_19C214(p + 0x1698, d);
                    }
                    if (p + 0x1488) {
                        __dt__24soCollisionHitModuleImplFv(p + 0x162C, d);
                        fn_27_CC984(p + 0x15E8, d);
                        fn_27_4CAA0(p + 0x1564, d);
                        fn_27_CC654(p + 0x1488, d);
                    }
                    if (p + 0x10CC) {
                        __dt__27soCollisionAttackModuleImplFv(p + 0x13E8, d);
                        fn_27_1A12AC(p + 0x130C, d);
                        fn_27_4CAA0(p + 0x1288, d);
                        fn_27_CCF74(p + 0x10CC, d);
                    }
                    fn_113_317C(p + 0x1068, d);
                    fn_113_3248(p + 0x102C, d);
                    fn_113_32A4(p + 0xF84, d);
                    fn_113_3310(p + 0xED0, d);
                    if (p + 0xC50) {
                        fn_27_13C90(p + 0xD60, d);
                        fn_113_3384(p + 0xD24, d);
                        fn_27_21038(p + 0xD14, d);
                        fn_113_33F0(p + 0xCD8, d);
                        fn_113_344C(p + 0xC50, d);
                    }
                    fn_113_34D4(p + 0xA70, d);
                    fn_113_3540(p + 0xA40, d);
                    fn_113_35F8(p + 0xA30, d);
                    fn_113_3638(p + 0xA18, d);
                    __dt__16soModuleAccesserFv(p + 0x938, d);
                    if (p + 0xcc) {
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>*>(p + 0x900)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x8C4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x88C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x830)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x7D4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x778)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x71C)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x6C0)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(p + 0x67C, d);
                        fn_27_18D498(p + 0x614, d);
                        fn_27_D784C(p + 0x5AC, d);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x550)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x4F4)->~soEventUnitWithWorkArea();
                        fn_27_D597C(p + 0x4B0, d);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x454)->~soEventUnitWithWorkArea();
                        fn_27_1AA40C(p + 0x29C, d);
                        fn_27_1A9818(p + 0x198, d);
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
