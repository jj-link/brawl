#pragma force_active on
extern "C" {
void* fn_93_62B8(void*, short);
void* fn_93_62F8(void*, short);
void* fn_93_6394(void*, short);
void* fn_93_63F0(void*, short);
void* fn_93_644C(void*, short);
void* fn_93_229C(void*, short);
void* fn_93_64A8(void*, short);
void* fn_93_6508(void*, short);
void* fn_93_6564(void*, short);
void* fn_93_65C4(void*, short);
void* fn_93_2240(void*, short);
void* fn_93_664C(void*, short);
void* fn_93_66A8(void*, short);
void* fn_93_6714(void*, short);
void* fn_93_6774(void*, short);
void* fn_93_6800(void*, short);
void* fn_93_6888(void*, short);
void* fn_93_68F4(void*, short);
void* fn_93_696C(void*, short);
void* fn_93_1F54(void*, short);
void* fn_93_2C0C(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* __dl__FPv(void*);
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
class soEventUnit;

template <class Observer, int Capacity>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template <class Element> class soInstanceUnit;
template <class Element, int Capacity> class soArrayVector;
template <class Element, class Storage>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" void* fn_93_5FA8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_93_62B8(p + 0x16ac, (short)-1);
        fn_27_C7770(p + 0x169c, (short)-1);
        if (object != 0) {
            if (p + 0xcc != 0) {
                if (p + 0x1564 != 0 && p + 0x1568 != 0) {
                    fn_93_62F8(p + 0x1644, (short)-1);
                    fn_93_62B8(p + 0x1628, (short)-1);
                    fn_93_6394(p + 0x157c, (short)-1);
                    if (p + 0x1568 != 0)
                        fn_27_C7770(p + 0x1568, (short)-1);
                }
                if (p + 0xcc != 0) {
                    fn_93_63F0(p + 0x1548, (short)-1);
                    fn_93_644C(p + 0x13f0, (short)-1);
                    fn_93_229C(p + 0x13a4, (short)-1);
                    fn_93_64A8(p + 0x1354, (short)-1);
                    if (p + 0x11b4 != 0) {
                        fn_27_97968(p + 0x1218, (short)-1);
                        fn_27_1CCCC(p + 0x1208, (short)-1);
                        fn_93_6508(p + 0x11ec, (short)-1);
                        if (p + 0x11b4 != 0)
                            fn_27_CBF58(p + 0x11b4, (short)-1);
                    }
                    fn_93_6564(p + 0x1154, (short)-1);
                    fn_93_65C4(p + 0x10ac, (short)-1);
                    fn_93_2240(p + 0x1078, (short)-1);
                    fn_93_664C(p + 0x1060, (short)-1);
                    fn_93_66A8(p + 0xefc, (short)-1);
                    fn_93_6714(p + 0xeec, (short)-1);
                    fn_93_6774(p + 0xe7c, (short)-1);
                    if (p + 0xe30 != 0)
                        fn_27_252D0(p + 0xe34, (short)-1);
                    if (p + 0xbe8 != 0) {
                        fn_27_13C90(p + 0xcc0, (short)-1);
                        fn_27_21038(p + 0xcac, (short)-1);
                        fn_93_2C0C(p + 0xc70, (short)-1);
                        fn_93_6800(p + 0xbe8, (short)-1);
                    }
                    fn_93_6888(p + 0xa08, (short)-1);
                    fn_93_68F4(p + 0x9d8, (short)-1);
                    fn_93_696C(p + 0x9c8, (short)-1);
                    fn_93_1F54(p + 0x9b0, (short)-1);
                    __dt__16soModuleAccesserFv(p + 0x8d0, (short)-1);
                    if (p + 0xcc != 0) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x894)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x85c)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x800)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x7a4)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x748)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x6ec)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x690)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(p + 0x64c, (short)-1);
                        fn_27_18D498(p + 0x5e4, (short)-1);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x588)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x52c)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x4d0)->~soEventUnitWithWorkArea();
                        fn_27_D597C(p + 0x48c, (short)-1);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x430)->~soEventUnitWithWorkArea();
                        fn_27_18D6CC(p + 0x284, (short)-1);
                        fn_27_18D788(p + 0x198, (short)-1);
                        __dt__23soEventManageModuleImplFv(p + 0x184, (short)-1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xcc)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, (short)0);
        }
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}