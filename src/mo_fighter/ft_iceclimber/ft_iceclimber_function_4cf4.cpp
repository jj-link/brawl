#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_3674(void*, short);
void* fn_105_3F1C(void*, short);
void* fn_105_51C4(void*, short);
void* fn_105_3814(void*, short);
void* fn_105_218C(void*, short);
void* fn_105_2228(void*, short);
void* fn_105_2268(void*, short);
void* fn_27_C7770(void*, short);
void* fn_105_3A24(void*, short);
void* fn_105_3A80(void*, short);
void* fn_105_3ADC(void*, short);
void* fn_27_ACC5C(void*, short);
void* fn_105_3B38(void*, short);
void* fn_105_3BC4(void*, short);
void* fn_105_102B8(void*, short);
void* fn_105_5220(void*, short);
void* fn_105_5290(void*, short);
void* fn_105_3EA0(void*, short);
void* fn_105_3F78(void*, short);
void* fn_27_1A405C(void*, short);
void* fn_105_3FD8(void*, short);
void* fn_105_4100(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_105_4160(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_42F0(void*, short);
void* fn_105_434C(void*, short);
void* fn_105_43B8(void*, short);
void* fn_105_4418(void*, short);
void* fn_105_4478(void*, short);
void* fn_105_52FC(void*, short);
void* __dt__24soCollisionHitModuleImplFv(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19AB9C(void*, short);
void* fn_105_44D4(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_5370(void*, short);
void* fn_105_4680(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_105_476C(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4860(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D784C(void*, short);
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
class soModelEventObserver;
class soCollisionHitEventObserver;
class soSituationEventObserver;
class soDamageEventObserver;
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

extern "C" void* fn_105_4CF4(void* arg0, short arg1) {
    if (arg0 != 0) {
        char* p = static_cast<char*>(arg0);
        short d = 0;
        if (p + 0x2360 != 0) {
            if (p + 0x2360 != 0) {
                fn_105_3674(p + 0x2360, static_cast<short>(0));
            }
        }
        fn_105_3F1C(p + 0x2350, d);
        fn_105_51C4(p + 0x2344, d);
        if (arg0 != 0) {
            if (p + 0xCC != 0) {
                if (p + 0x1D90 != 0) {
                    d = -1;
                    fn_105_3814(p + 0x2240, d);
                    if (p + 0x2114 != 0) {
                        fn_105_218C(p + 0x21F0, d);
                        fn_105_2228(p + 0x21D4, d);
                        fn_105_2268(p + 0x2128, d);
                        if (p + 0x2114 != 0) {
                            fn_27_C7770(p + 0x2114, d);
                        }
                    }
                    if (p + 0x1FE8 != 0) {
                        d = -1;
                        fn_105_218C(p + 0x20C4, d);
                        fn_105_2228(p + 0x20A8, d);
                        fn_105_2268(p + 0x1FFC, d);
                        if (p + 0x1FE8 != 0) {
                            fn_27_C7770(p + 0x1FE8, d);
                        }
                    }
                    if (p + 0x1EBC != 0) {
                        d = -1;
                        fn_105_218C(p + 0x1F98, d);
                        fn_105_2228(p + 0x1F7C, d);
                        fn_105_2268(p + 0x1ED0, d);
                        if (p + 0x1EBC != 0) {
                            fn_27_C7770(p + 0x1EBC, d);
                        }
                    }
                    if (p + 0x1D90 != 0) {
                        d = -1;
                        fn_105_218C(p + 0x1E6C, d);
                        fn_105_2228(p + 0x1E50, d);
                        fn_105_2268(p + 0x1DA4, d);
                        if (p + 0x1D90 != 0) {
                            fn_27_C7770(p + 0x1D90, d);
                        }
                    }
                }
                if (p + 0xCC != 0) {
                    d = -1;
                    fn_105_3A24(p + 0x1D74, d);
                    fn_105_3A80(p + 0x1D34, d);
                    fn_105_3ADC(p + 0x1D1C, d);
                    if (p + 0x1C94 != 0) {
                        fn_27_ACC5C(p + 0x1C94, d);
                    }
                    d = -1;
                    fn_105_3B38(p + 0x1AFC, d);
                    fn_105_3BC4(p + 0x1A9C, d);
                    if (p + 0x1974 != 0) {
                        if (p + 0x1A54 != 0) {
                            fn_105_102B8(p + 0x1A58, d);
                        }
                        d = -1;
                        fn_105_5220(p + 0x19A4, d);
                        fn_105_5290(p + 0x1974, d);
                    }
                    if (p + 0x17AC != 0) {
                        d = -1;
                        fn_105_3EA0(p + 0x18C4, d);
                        fn_105_3F78(p + 0x18B0, d);
                        if (p + 0x1898 != 0) {
                            fn_27_1A405C(p + 0x1898, d);
                        }
                        d = -1;
                        fn_105_3FD8(p + 0x17F4, d);
                        fn_105_4100(p + 0x17BC, d);
                        fn_27_C74E8(p + 0x17AC, d);
                    }
                    d = -1;
                    fn_105_4160(p + 0x1708, d);
                    fn_105_4294(p + 0x16D4, d);
                    fn_105_42F0(p + 0x16BC, d);
                    fn_105_434C(p + 0x1558, d);
                    fn_105_43B8(p + 0x14F0, d);
                    fn_105_4418(p + 0x14E4, d);
                    fn_105_4478(p + 0x14BC, d);
                    fn_105_52FC(p + 0x1360, d);
                    if (p + 0x11B4 != 0) {
                        __dt__24soCollisionHitModuleImplFv(p + 0x12F0, d);
                        fn_27_CC984(p + 0x12AC, d);
                        fn_27_4CAA0(p + 0x1228, d);
                        fn_27_19AB9C(p + 0x11B4, d);
                    }
                    d = -1;
                    fn_105_44D4(p + 0xFF0, d);
                    fn_105_4558(p + 0xF8C, d);
                    fn_105_4624(p + 0xF50, d);
                    fn_105_5370(p + 0xEA8, d);
                    fn_105_4680(p + 0xDF4, d);
                    if (p + 0xBE8 != 0) {
                        fn_27_13C90(p + 0xC84, d);
                        fn_27_21038(p + 0xC70, d);
                        fn_105_476C(p + 0xBE8, d);
                    }
                    d = -1;
                    fn_105_47F4(p + 0xA08, d);
                    fn_105_4860(p + 0x9D8, d);
                    fn_105_4918(p + 0x9C8, d);
                    fn_105_4958(p + 0x9B0, d);
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
                        reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(p + 0x5F0)->~soEventUnitWithWorkArea();
                        fn_27_D784C(p + 0x588, d);
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
            fn_27_1D81C8(arg0, static_cast<short>(0));
        }
        if (arg1 > 0) {
            operator delete(arg0);
        }
    }
    return arg0;
}
