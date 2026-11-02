#include <so/event/so_event_system.h>
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

void operator delete(void*);

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
void* fn_27_BED74(void*, short);
void* fn_92_3B5C(void*, short);
void* fn_92_3BE8(void*, short);
void* fn_92_3CE4(void*, short);
void* fn_92_3E20(void*, short);
void* fn_92_3EA4(void*, short);
void* fn_27_1A2D10(void*, short);
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
void* fn_27_19CA80(void*, short);
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
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_92_34F0(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);

        if (p + 0x205c) {
            if (p + 0x205c)
                fn_92_395C(p + 0x205c, 0);
        }

        if (object) {
            fn_92_399C(p + 0x2014, -1);
            fn_27_1DBB60(p + 0x1fdc, -1);

            if (p + 0xcc) {
                if (p + 0x1a2c) {
                    fn_92_3A38(p + 0x1edc, -1);

                    if (p + 0x1db0) {
                        fn_92_2204(p + 0x1e8c, -1);
                        fn_92_22A0(p + 0x1e70, -1);
                        fn_92_22E0(p + 0x1dc4, -1);
                        if (p + 0x1db0)
                            fn_27_C7770(p + 0x1db0, -1);
                    }

                    if (p + 0x1c84) {
                        fn_92_2204(p + 0x1d60, -1);
                        fn_92_22A0(p + 0x1d44, -1);
                        fn_92_22E0(p + 0x1c98, -1);
                        if (p + 0x1c84)
                            fn_27_C7770(p + 0x1c84, -1);
                    }

                    if (p + 0x1b58) {
                        fn_92_2204(p + 0x1c34, -1);
                        fn_92_22A0(p + 0x1c18, -1);
                        fn_92_22E0(p + 0x1b6c, -1);
                        if (p + 0x1b58)
                            fn_27_C7770(p + 0x1b58, -1);
                    }

                    if (p + 0x1a2c) {
                        fn_92_2204(p + 0x1b08, -1);
                        fn_92_22A0(p + 0x1aec, -1);
                        fn_92_22E0(p + 0x1a40, -1);
                        if (p + 0x1a2c)
                            fn_27_C7770(p + 0x1a2c, -1);
                    }
                }

                if (p + 0xcc) {
                    fn_92_3AA4(p + 0x19e8, -1);
                    fn_92_3B00(p + 0x19d0, -1);
                    if (p + 0x1878)
                        fn_27_BED74(p + 0x1878, -1);
                    fn_92_3B5C(p + 0x16e0, -1);
                    fn_92_3BE8(p + 0x1680, -1);
                    fn_92_3CE4(p + 0x15cc, -1);

                    if (p + 0x140c) {
                        fn_92_3E20(p + 0x151c, -1);
                        fn_92_3EA4(p + 0x1508, -1);
                        if (p + 0x14f8)
                            fn_27_1A2D10(p + 0x14f8, -1);
                        fn_92_3F04(p + 0x1454, -1);
                        fn_92_402C(p + 0x141c, -1);
                        fn_27_C74E8(p + 0x140c, -1);
                    }

                    fn_92_408C(p + 0x1368, -1);
                    fn_92_41C0(p + 0x1334, -1);
                    fn_92_421C(p + 0x131c, -1);
                    fn_92_4278(p + 0x11b8, -1);
                    fn_92_42E4(p + 0x1150, -1);
                    fn_92_4344(p + 0x1144, -1);
                    fn_92_43A4(p + 0x111c, -1);

                    if (p + 0xf4c) {
                        __dt__27soCollisionAttackModuleImplFv(p + 0x1070, -1);
                        fn_27_82AD4(p + 0x106c, -1);
                        fn_27_4CAA0(p + 0xfe8, -1);
                        fn_27_19CA80(p + 0xf4c, -1);
                    }

                    fn_92_4400(p + 0xee8, -1);
                    fn_92_44CC(p + 0xeac, -1);
                    fn_92_4528(p + 0xdf4, -1);

                    if (p + 0xbe8) {
                        fn_27_13C90(p + 0xc84, -1);
                        fn_27_21038(p + 0xc70, -1);
                        fn_92_459C(p + 0xbe8, -1);
                    }

                    fn_92_4624(p + 0xa08, -1);
                    fn_92_4690(p + 0x9d8, -1);
                    fn_92_4748(p + 0x9c8, -1);
                    fn_92_4788(p + 0x9b0, -1);
                    __dt__16soModuleAccesserFv(p + 0x8d0, -1);

                    if (p + 0xcc) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x894)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x85c)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x800)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x7a4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x748)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x6ec)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x690)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(p + 0x64c, -1);
                        fn_27_18D498(p + 0x5e4, -1);
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
