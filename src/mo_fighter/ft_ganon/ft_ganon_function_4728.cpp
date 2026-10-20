#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_109_21F0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_109_3A08(void*, short);
void* fn_109_3A94(void*, short);
void* fn_27_BED74(void*, short);
void* fn_109_2DF0(void*, short);
void* fn_27_10424(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_109_3104(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_109_3AF0(void*, short);
void* fn_109_3E10(void*, short);
void* fn_109_3F44(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_109_4014(void*, short);
void* fn_109_4080(void*, short);
void* fn_109_4164(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_109_4300(void*, short);
void* fn_109_435C(void*, short);
void* fn_109_43E4(void*, short);
void* fn_109_4450(void*, short);
void* fn_109_4508(void*, short);
void* fn_109_4548(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
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

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

class soEventUnit;

template<class T>
class soInstanceUnit {};

template<class T, int N>
class soArrayVector {};

template<class T, class A>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

#pragma always_inline on
#pragma inline_depth(16)

static inline void destroyEvents(char* p) {
    if (p + 0xcc) {
        short d = -1;
        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x894)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x85c)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x800)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x7a4)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x748)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x6ec)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x690)->~soEventUnitWithWorkArea();
        fn_27_18D3DC(p + 0x64c, d);
        fn_27_18D498(p + 0x5e4, d);
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x588)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x52c)->~soEventUnitWithWorkArea();
        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x4d0)->~soEventUnitWithWorkArea();
        fn_27_D597C(p + 0x48c, d);
        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x430)->~soEventUnitWithWorkArea();
        fn_27_18D6CC(p + 0x284, d);
        fn_27_18D788(p + 0x198, d);
        __dt__23soEventManageModuleImplFv(p + 0x184, d);
        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xcc)->~soInstanceManagerSimpleEntity();
    }
}

static inline void destroyModules(char* p) {
    if (p + 0xcc) {
        short d = -1;
        fn_109_3A94(p + 0x1548, d);
        if (p + 0x13f0)
            fn_27_BED74(p + 0x13f0, d);
        fn_109_2DF0(p + 0x13a4, d);
        if (p + 0x1354)
            fn_27_10424(p + 0x1358, d);
        if (p + 0x11b4) {
            fn_27_97968(p + 0x1218, d);
            fn_27_1CCCC(p + 0x1208, d);
            fn_109_3104(p + 0x11ec, d);
            if (p + 0x11b4)
                fn_27_CBF58(p + 0x11b4, d);
        }
        fn_109_3AF0(p + 0x1154, d);
        fn_109_3E10(p + 0x10ac, d);
        fn_109_3F44(p + 0x1078, d);
        if (p + 0x1060)
            fn_27_5AE44(p + 0x1060, d);
        fn_109_4014(p + 0xefc, d);
        fn_109_4080(p + 0xeec, d);
        fn_109_4164(p + 0xe7c, d);
        if (p + 0xe30)
            fn_27_252D0(p + 0xe34, d);
        if (p + 0xbe8) {
            fn_27_13C90(p + 0xcc0, d);
            fn_27_21038(p + 0xcac, d);
            fn_109_4300(p + 0xc70, d);
            fn_109_435C(p + 0xbe8, d);
        }
        fn_109_43E4(p + 0xa08, d);
        fn_109_4450(p + 0x9d8, d);
        fn_109_4508(p + 0x9c8, d);
        fn_109_4548(p + 0x9b0, d);
        __dt__16soModuleAccesserFv(p + 0x8d0, d);
        destroyEvents(p);
    }
}

static inline void destroyBase(char* p) {
    if (p) {
        short d = -1;
        if (p + 0xcc) {
            if (p + 0x1564)
                fn_109_3A08(p + 0x1568, d);
            destroyModules(p);
        }
        fn_27_1D81C8(p, static_cast<short>(0));
    }
}

extern "C" void* fn_109_4728(void* object, int deleting) {
    if (object) {
        short d = -1;
        fn_109_21F0(static_cast<char*>(object) + 0x16ac, d);
        char* p = static_cast<char*>(object);
        fn_27_C7770(p + 0x169c, d);
        destroyBase(p);
        if (static_cast<short>(deleting) > 0)
            operator delete(object);
    }
    return object;
}
