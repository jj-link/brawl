#include <so/event/so_event_system.h>
#pragma force_active on

void operator delete(void*);

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
class soModelEventObserver;
class soDamageEventObserver;

template<> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template<> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};

extern "C" {
void* fn_92_395C(void*, short);
void* fn_92_399C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_92_3A38(void*, short);
void* fn_92_2204(void*, short);
void* fn_92_22A0(void*, short);
void* fn_92_22E0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_92_3AA4(void*, short);
void* fn_92_3B00(void*, short);
void* fn_92_3B5C(void*, short);
void* fn_92_3BE8(void*, short);
void* fn_92_3CE4(void*, short);
void* fn_92_3E20(void*, short);
void* fn_92_3EA4(void*, short);
void* fn_27_1A301C(void*, short);
void* fn_92_3F04(void*, short);
void* fn_92_402C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_92_408C(void*, short);
void* fn_92_41C0(void*, short);
void* fn_92_421C(void*, short);
void* fn_92_4278(void*, short);
void* fn_92_42E4(void*, short);
void* fn_92_4344(void*, short);
void* fn_92_43A4(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CCC8(void*, short);
void* fn_92_4400(void*, short);
void* fn_92_44CC(void*, short);
void* fn_92_4528(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_92_459C(void*, short);
void* fn_92_4624(void*, short);
void* fn_92_4690(void*, short);
void* fn_92_4748(void*, short);
void* fn_92_4788(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_92_4974(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (p + 0x1f90 != 0) {
            if (p + 0x1f90 != 0) {
                fn_92_395C(p + 0x1f90, 0);
            }
        }
        if (object) {
            fn_92_399C(p + 0x1f48, -1);
            fn_27_1DBB60(p + 0x1f10, -1);
            if (p + 0xcc != 0) {
                if (p + 0x1960 != 0) {
                    fn_92_3A38(p + 0x1e10, -1);
                    if (p + 0x1ce4 != 0) {
                        fn_92_2204(p + 0x1dc0, -1);
                        fn_92_22A0(p + 0x1da4, -1);
                        fn_92_22E0(p + 0x1cf8, -1);
                        if (p + 0x1ce4 != 0)
                            fn_27_C7770(p + 0x1ce4, -1);
                    }
                    if (p + 0x1bb8 != 0) {
                        fn_92_2204(p + 0x1c94, -1);
                        fn_92_22A0(p + 0x1c78, -1);
                        fn_92_22E0(p + 0x1bcc, -1);
                        if (p + 0x1bb8 != 0)
                            fn_27_C7770(p + 0x1bb8, -1);
                    }
                    if (p + 0x1a8c != 0) {
                        fn_92_2204(p + 0x1b68, -1);
                        fn_92_22A0(p + 0x1b4c, -1);
                        fn_92_22E0(p + 0x1aa0, -1);
                        if (p + 0x1a8c != 0)
                            fn_27_C7770(p + 0x1a8c, -1);
                    }
                    if (p + 0x1960 != 0) {
                        fn_92_2204(p + 0x1a3c, -1);
                        fn_92_22A0(p + 0x1a20, -1);
                        fn_92_22E0(p + 0x1974, -1);
                        if (p + 0x1960 != 0)
                            fn_27_C7770(p + 0x1960, -1);
                    }
                }
                if (p + 0xcc != 0) {
                    fn_92_3AA4(p + 0x191c, -1);
                    fn_92_3B00(p + 0x1904, -1);
                    fn_92_3B5C(p + 0x1768, -1);
                    fn_92_3BE8(p + 0x1708, -1);
                    fn_92_3CE4(p + 0x1654, -1);
                    if (p + 0x1490 != 0) {
                        fn_92_3E20(p + 0x15a4, -1);
                        fn_92_3EA4(p + 0x1590, -1);
                        if (p + 0x157c != 0)
                            fn_27_1A301C(p + 0x157c, -1);
                        fn_92_3F04(p + 0x14d8, -1);
                        fn_92_402C(p + 0x14a0, -1);
                        fn_27_C74E8(p + 0x1490, -1);
                    }
                    fn_92_408C(p + 0x13ec, -1);
                    fn_92_41C0(p + 0x13b8, -1);
                    fn_92_421C(p + 0x13a0, -1);
                    fn_92_4278(p + 0x123c, -1);
                    fn_92_42E4(p + 0x11d4, -1);
                    fn_92_4344(p + 0x11c8, -1);
                    fn_92_43A4(p + 0x11a0, -1);
                    if (p + 0xf40 != 0) {
                        __dt__27soCollisionAttackModuleImplFv(p + 0x10f4, -1);
                        fn_27_82AD4(p + 0x10f0, -1);
                        fn_27_4CAA0(p + 0x106c, -1);
                        fn_27_19CCC8(p + 0xf40, -1);
                    }
                    fn_92_4400(p + 0xedc, -1);
                    fn_92_44CC(p + 0xea0, -1);
                    fn_92_4528(p + 0xde8, -1);
                    if (p + 0xbdc != 0) {
                        fn_27_13C90(p + 0xc78, -1);
                        fn_27_21038(p + 0xc64, -1);
                        fn_92_459C(p + 0xbdc, -1);
                    }
                    fn_92_4624(p + 0x9fc, -1);
                    fn_92_4690(p + 0x9cc, -1);
                    fn_92_4748(p + 0x9bc, -1);
                    fn_92_4788(p + 0x9a4, -1);
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