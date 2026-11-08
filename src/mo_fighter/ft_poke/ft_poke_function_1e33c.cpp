#include <so/event/so_event_system.h>

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

template<> class soEventUnitWithWorkArea<soMotionEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soModelEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soSituationEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };
template<> class soEventUnitWithWorkArea<soDamageEventObserver, 4> { public: ~soEventUnitWithWorkArea(); };

#pragma force_active on
#pragma inline off

void operator delete(void*);

extern "C" {
void* fn_116_1DAB8(void*, short);
void* fn_116_2164(void*, short);
void* fn_116_2200(void*, short);
void* fn_116_2240(void*, short);
void* fn_116_30B8(void*, short);
void* fn_116_394C(void*, short);
void* fn_116_3A04(void*, short);
void* fn_116_3ACC(void*, short);
void* fn_116_3CA4(void*, short);
void* fn_116_3D28(void*, short);
void* fn_116_3D88(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_116_3F18(void*, short);
void* fn_116_3F84(void*, short);
void* fn_116_3FE4(void*, short);
void* fn_116_4040(void*, short);
void* fn_116_40C4(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_4258(void*, short);
void* fn_116_42CC(void*, short);
void* fn_116_430C(void*, short);
void* fn_116_4B64(void*, short);
void* fn_116_4C70(void*, short);
void* fn_116_6D54(void*, short);
void* fn_116_FEE8(void*, short);
void* fn_27_10424(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_1A4D90(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_CBDE8(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_D2AA4(void*, short);
void* fn_27_D597C(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
}

extern "C" void* fn_116_1E33C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (p + 0x1f4c != 0) {
            if (p + 0x1f4c != 0)
                fn_116_1DAB8(p + 0x1f4c, 0);
        }
        if (object != 0) {
            if (p + 0xcc != 0) {
                if (p + 0x1994 != 0) {
                    if (p + 0x1e44 != 0) {
                        fn_116_2240(p + 0x1e94, -1);
                        fn_116_2164(p + 0x1e44, -1);
                    }
                    if (p + 0x1d18 != 0) {
                        fn_116_2164(p + 0x1df4, -1);
                        fn_116_2200(p + 0x1dd8, -1);
                        fn_116_2240(p + 0x1d2c, -1);
                        if (p + 0x1d18 != 0)
                            fn_27_C7770(p + 0x1d18, -1);
                    }
                    if (p + 0x1bec != 0) {
                        fn_116_2164(p + 0x1cc8, -1);
                        fn_116_2200(p + 0x1cac, -1);
                        fn_116_2240(p + 0x1c00, -1);
                        if (p + 0x1bec != 0)
                            fn_27_C7770(p + 0x1bec, -1);
                    }
                    if (p + 0x1ac0 != 0) {
                        fn_116_2164(p + 0x1b9c, -1);
                        fn_116_2200(p + 0x1b80, -1);
                        fn_116_2240(p + 0x1ad4, -1);
                        if (p + 0x1ac0 != 0)
                            fn_27_C7770(p + 0x1ac0, -1);
                    }
                    if (p + 0x1994 != 0) {
                        fn_116_2164(p + 0x1a70, -1);
                        fn_116_2200(p + 0x1a54, -1);
                        fn_116_2240(p + 0x19a8, -1);
                        if (p + 0x1994 != 0)
                            fn_27_C7770(p + 0x1994, -1);
                    }
                }
                if (p + 0xcc != 0) {
                    fn_116_394C(p + 0x1978, -1);
                    fn_116_3A04(p + 0x195c, -1);
                    if (p + 0x1804 != 0)
                        fn_27_BED74(p + 0x1804, -1);
                    if (p + 0x17b4 != 0)
                        fn_27_10424(p + 0x17b8, -1);
                    if (p + 0x1620 != 0) {
                        fn_27_97968(p + 0x1678, -1);
                        fn_27_1CCCC(p + 0x1668, -1);
                        fn_116_30B8(p + 0x165c, -1);
                        if (p + 0x1620 != 0)
                            fn_27_CBF58(p + 0x1620, -1);
                    }
                    if (p + 0x15c0 != 0)
                        fn_116_3ACC(p + 0x15f8, -1);
                    if (p + 0x13d8 != 0) {
                        fn_116_3CA4(p + 0x1510, -1);
                        fn_116_3D28(p + 0x14fc, -1);
                        if (p + 0x14cc != 0)
                            fn_27_1A4D90(p + 0x14cc, -1);
                        if (p + 0x1428 != 0) {
                            fn_116_4B64(p + 0x14b4, -1);
                            if (p + 0x1448 != 0)
                                if (p + 0x1448 != 0)
                                    if (p + 0x1448 != 0)
                                        fn_27_1A1E70(p + 0x1448, -1);
                            fn_27_CD934(p + 0x1428, -1);
                        }
                        if (p + 0x13e8 != 0)
                            fn_116_3ACC(p + 0x1404, -1);
                        fn_27_C74E8(p + 0x13d8, -1);
                    }
                    fn_116_3D88(p + 0x1334, -1);
                    fn_116_3EBC(p + 0x1300, -1);
                    fn_116_FEE8(p + 0x12e8, -1);
                    fn_116_3F18(p + 0x1184, -1);
                    fn_116_3F84(p + 0x1174, -1);
                    fn_116_3FE4(p + 0x114c, -1);
                    fn_116_4040(p + 0xf7c, -1);
                    fn_116_40C4(p + 0xf18, -1);
                    fn_116_4190(p + 0xedc, -1);
                    fn_116_4258(p + 0xe24, -1);
                    if (p + 0xbdc != 0) {
                        fn_27_13C90(p + 0xcb4, -1);
                        fn_27_21038(p + 0xca0, -1);
                        fn_116_6D54(p + 0xc64, -1);
                        if (p + 0xbdc != 0) {
                            fn_116_4B64(p + 0xc48, -1);
                            if (p + 0xbfc != 0)
                                if (p + 0xbfc != 0)
                                    if (p + 0xbfc != 0)
                                        fn_27_D2AA4(p + 0xbfc, -1);
                            fn_27_CD934(p + 0xbdc, -1);
                        }
                    }
                    if (p + 0x9fc != 0) {
                        __dt__17soModelModuleImplFv(p + 0xb10, -1);
                        fn_27_CBDE8(p + 0x9fc, -1);
                    }
                    fn_116_4C70(p + 0x9cc, -1);
                    fn_116_42CC(p + 0x9bc, -1);
                    fn_116_430C(p + 0x9a4, -1);
                    __dt__16soModuleAccesserFv(p + 0x8c4, -1);
                    if (p + 0xcc != 0) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x888)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x850)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x7f4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x798)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x73c)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x6e0)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x684)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(p + 0x640, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p + 0x5e4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x588)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x52c)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x4d0)->~soEventUnitWithWorkArea();
                        fn_27_D597C(p + 0x48c, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x430)->~soEventUnitWithWorkArea();
                        fn_27_18D6CC(p + 0x284, -1);
                        fn_27_18D788(p + 0x198, -1);
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
