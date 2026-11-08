#pragma force_active on
void operator delete(void*);

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
template <class T> class soInstanceUnit;
template <class T, int N> class soArrayVector;

template <class T, int N> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template <class T, class S> class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

extern "C" {
void* fn_111_39EC(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_111_21C4(void*, short);
void* fn_111_20E8(void*, short);
void* fn_111_2184(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_BED74(void*, short);
void* fn_111_2D78(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_27_A0C34(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_111_3A2C(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_111_3AC8(void*, short);
void* fn_111_1EA4(void*, short);
void* fn_111_3B08(void*, short);
void* fn_111_3B68(void*, short);
void* fn_111_3BEC(void*, short);
void* fn_27_1A2D10(void*, short);
void* fn_111_3C4C(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A262C(void*, short);
void* fn_111_3CEC(void*, short);
void* fn_111_3D2C(void*, short);
void* fn_111_3D98(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
void* fn_27_B5324(void*, short);
void* fn_111_3DF4(void*, short);
void* fn_111_3E34(void*, short);
void* fn_111_3E90(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_111_3F04(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_CBDE8(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_111_3F60(void*, short);
void* fn_111_3FA0(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_1AA40C(void*, short);
void* fn_27_1A9648(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_111_33BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (object != 0) {
            if (p + 0x2030 != 0) {
                fn_111_39EC(p + 0x2030, 0);
            }
            fn_27_1DBB60(p + 0x1FF8, -1);
            if (p + 0xCC != 0) {
                if (p + 0x1A48 != 0) {
                    if (p + 0x1EF8 != 0) {
                        fn_111_21C4(p + 0x1F48, -1);
                        fn_111_20E8(p + 0x1EF8, -1);
                    }
                    if (p + 0x1DCC != 0) {
                        fn_111_20E8(p + 0x1EA8, -1);
                        fn_111_2184(p + 0x1E8C, -1);
                        fn_111_21C4(p + 0x1DE0, -1);
                        if (p + 0x1DCC != 0) {
                            fn_27_C7770(p + 0x1DCC, -1);
                        }
                    }
                    if (p + 0x1CA0 != 0) {
                        fn_111_20E8(p + 0x1D7C, -1);
                        fn_111_2184(p + 0x1D60, -1);
                        fn_111_21C4(p + 0x1CB4, -1);
                        if (p + 0x1CA0 != 0) {
                            fn_27_C7770(p + 0x1CA0, -1);
                        }
                    }
                    if (p + 0x1B74 != 0) {
                        fn_111_20E8(p + 0x1C50, -1);
                        fn_111_2184(p + 0x1C34, -1);
                        fn_111_21C4(p + 0x1B88, -1);
                        if (p + 0x1B74 != 0) {
                            fn_27_C7770(p + 0x1B74, -1);
                        }
                    }
                    if (p + 0x1A48 != 0) {
                        fn_111_20E8(p + 0x1B24, -1);
                        fn_111_2184(p + 0x1B08, -1);
                        fn_111_21C4(p + 0x1A5C, -1);
                        if (p + 0x1A48 != 0) {
                            fn_27_C7770(p + 0x1A48, -1);
                        }
                    }
                }
                if (p + 0xCC != 0) {
                    if (p + 0x1A04 != 0) {
                        fn_27_63EBC(p + 0x1A04, -1);
                    }
                    if (p + 0x19EC != 0) {
                        fn_27_5C674(p + 0x19EC, -1);
                    }
                    if (p + 0x1894 != 0) {
                        fn_27_BED74(p + 0x1894, -1);
                    }
                    fn_111_2D78(p + 0x1848, -1);
                    if (p + 0x16B0 != 0) {
                        fn_27_97968(p + 0x1708, -1);
                        fn_27_1CCCC(p + 0x16F8, -1);
                        if (p + 0x16EC != 0) {
                            fn_27_A0C34(p + 0x16EC, -1);
                        }
                        if (p + 0x16B0 != 0) {
                            fn_27_CBF58(p + 0x16B0, -1);
                        }
                    }
                    if (p + 0x1650 != 0) {
                        fn_111_3A2C(p + 0x1688, -1);
                    }
                    if (p + 0x159C != 0) {
                        if (p + 0x15CC != 0) {
                            fn_27_1A241C(p + 0x15DC, -1);
                            fn_111_3AC8(p + 0x15CC, 0);
                        }
                        if (p + 0x159C != 0) {
                            fn_111_1EA4(p + 0x15BC, 0);
                            fn_111_3B08(p + 0x159C, 0);
                        }
                    }
                    if (p + 0x13DC != 0) {
                        fn_111_3B68(p + 0x14EC, -1);
                        fn_111_3BEC(p + 0x14D8, -1);
                        if (p + 0x14C8 != 0) {
                            fn_27_1A2D10(p + 0x14C8, -1);
                        }
                        if (p + 0x1424 != 0) {
                            fn_111_3C4C(p + 0x14B0, -1);
                            {
                                void* temp = p + 0x1444;
                                if (temp != 0 && temp != 0 && temp != 0) {
                                    fn_27_1A1E70(temp, -1);
                                }
                            }
                            fn_27_CD934(p + 0x1424, -1);
                        }
                        if (p + 0x13EC != 0) {
                            fn_111_3A2C(p + 0x1400, -1);
                        }
                        fn_27_C74E8(p + 0x13DC, -1);
                    }
                    if (p + 0x1338 != 0) {
                        if (p + 0x135C != 0) {
                            fn_27_1A262C(p + 0x136C, -1);
                            fn_111_3CEC(p + 0x135C, 0);
                        }
                        fn_111_3D2C(p + 0x1338, -1);
                    }
                    fn_111_3D98(p + 0x1304, -1);
                    if (p + 0x12EC != 0) {
                        fn_27_5AE44(p + 0x12EC, -1);
                    }
                    if (p + 0x1188 != 0) {
                        fn_27_6A3D8(p + 0x1298, -1);
                        fn_27_CBB00(p + 0x1188, -1);
                    }
                    if (p + 0x1120 != 0) {
                        fn_27_565F0(p + 0x112C, -1);
                    }
                    if (p + 0x1114 != 0) {
                        fn_27_6880C(p + 0x1118, -1);
                    }
                    if (p + 0x10EC != 0) {
                        __dt__16soStopModuleImplFv(p + 0x10EC, -1);
                    }
                    if (p + 0xF1C != 0) {
                        __dt__27soCollisionAttackModuleImplFv(p + 0x1040, -1);
                        fn_27_82AD4(p + 0x103C, -1);
                        fn_27_4CAA0(p + 0xFB8, -1);
                        fn_27_19CA80(p + 0xF1C, -1);
                    }
                    if (p + 0xEB8 != 0) {
                        fn_27_B5324(p + 0xED8, -1);
                        if (p + 0xEC8 != 0) {
                            fn_111_3DF4(p + 0xEC8, 0);
                        }
                        if (p + 0xEB8 != 0) {
                            fn_111_3DF4(p + 0xEB8, 0);
                        }
                    }
                    fn_111_3E34(p + 0xE7C, -1);
                    fn_111_3E90(p + 0xDC4, -1);
                    if (p + 0xC00 != 0) {
                        fn_27_13C90(p + 0xC54, -1);
                        fn_27_21038(p + 0xC40, -1);
                        fn_111_3F04(p + 0xC04, -1);
                    }
                    if (p + 0xA20 != 0) {
                        __dt__17soModelModuleImplFv(p + 0xB34, -1);
                        fn_27_CBDE8(p + 0xA20, -1);
                    }
                    if (p + 0x9F0 != 0) {
                        __dt__20soResourceModuleImplFv(p + 0xA08, -1);
                        if (p + 0x9F0 != 0) {
                            fn_111_3F60(p + 0x9F0, 0);
                        }
                    }
                    fn_111_3FA0(p + 0x9C8, -1);
                    __dt__16soModuleAccesserFv(p + 0x8E8, -1);
                    if (p + 0xCC != 0) {
                        reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(p + 0x8AC)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(p + 0x874)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(p + 0x818)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(p + 0x7BC)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(p + 0x760)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(p + 0x704)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(p + 0x6A8)->~soEventUnitWithWorkArea();
                        fn_27_18D3DC(p + 0x664, -1);
                        fn_27_18D498(p + 0x5FC, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(p + 0x5A0)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(p + 0x544)->~soEventUnitWithWorkArea();
                        reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(p + 0x4E8)->~soEventUnitWithWorkArea();
                        fn_27_D597C(p + 0x4A4, -1);
                        reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(p + 0x448)->~soEventUnitWithWorkArea();
                        fn_27_1AA40C(p + 0x290, -1);
                        fn_27_1A9648(p + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(p + 0x184, -1);
                        reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(p + 0xCC)->~soInstanceManagerSimpleEntity();
                    }
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
