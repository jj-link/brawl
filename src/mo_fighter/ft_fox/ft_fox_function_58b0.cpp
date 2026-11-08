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
class soDamageEventObserver;
class soEventUnit;
template <class T> class soInstanceUnit;
template <class T, int N> class soArrayVector;

template <class T, class U> class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

template <class T, int N> class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

extern "C" {
void* fn_97_37F8(void*, short);
void* fn_27_D3B50(void*, short);
void* fn_97_2210(void*, short);
void* fn_97_22AC(void*, short);
void* fn_97_22EC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_97_3838(void*, short);
void* fn_97_4D20(void*, short);
void* fn_97_3AD4(void*, short);
void* fn_27_BED74(void*, short);
void* fn_97_2EAC(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_97_3164(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_27_93100(void*, short);
void* fn_97_4C28(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_97_3A48(void*, short);
void* fn_97_3B30(void*, short);
void* fn_97_3BBC(void*, short);
void* fn_97_4D7C(void*, short);
void* fn_97_3CB8(void*, short);
void* fn_97_3FC8(void*, short);
void* fn_97_40FC(void*, short);
void* fn_97_4158(void*, short);
void* fn_97_41B4(void*, short);
void* fn_97_4220(void*, short);
void* fn_97_4280(void*, short);
void* fn_97_42E0(void*, short);
void* fn_97_5648(void*, short);
void* fn_97_433C(void*, short);
void* fn_97_4408(void*, short);
void* fn_97_4464(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_97_4534(void*, short);
void* fn_97_45BC(void*, short);
void* fn_97_4628(void*, short);
void* fn_97_46E0(void*, short);
void* fn_97_4720(void*, short);
void* fn_97_4FA8(void*, short);
void* fn_97_4C84(void*, short);
void* fn_97_6208(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_97_3C1C(void*, short);
void* fn_97_62C8(void*, short);
void* fn_97_6338(void*, short);
void* fn_27_1A2E14(void*, short);
void* fn_97_3D5C(void*, short);
void* fn_97_3DE0(void*, short);
void* fn_97_63A4(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_D2C18(void*, short);
void* fn_97_4050(void*, short);
void* fn_97_4090(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_27_689B0(void*, short);
void* fn_27_C9A14(void*, short);
void* fn_27_19B94C(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_97_4EB8(void*, short);
void* fn_27_319E9C(void*, short);
void* fn_27_CC0F0(void*, short);
void* fn_97_44D8(void*, short);
void* fn_27_19BC9C(void*, short);
void* fn_27_CBDE8(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_18D498(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_1AA40C(void*, short);
void* fn_27_1A9648(void*, short);
void* fn_27_19EFFC(void*, short);
void* fn_27_1A51A0(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void __dt__17soModelModuleImplFv(void*, short);
void __dt__22soControllerModuleImplFv(void*, short);
void __dt__23soEventManageModuleImplFv(void*, short);
void __dt__24soCollisionHitModuleImplFv(void*, short);
}

extern "C" void* fn_97_58B0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (p + 0x4874 != 0) {
            if (p + 0x4874 != 0) {
                fn_97_37F8(p + 0x4874, 0);
            }
        }
        if (p + 0x4864 != 0) {
            fn_27_D3B50(p + 0x4864, 0);
        }
        if (object != 0) {
            if (p + 0xCC != 0) {
                if (p + 0x4188 != 0) {
                    if (p + 0x4734 != 0) {
                        fn_97_2210(p + 0x4810, -1);
                        fn_97_22AC(p + 0x47F4, -1);
                        fn_97_22EC(p + 0x4748, -1);
                        if (p + 0x4734 != 0) fn_27_C7770(p + 0x4734, -1);
                    }
                    fn_97_3838(p + 0x4638, -1);
                    if (p + 0x450C != 0) {
                        fn_97_2210(p + 0x45E8, -1);
                        fn_97_22AC(p + 0x45CC, -1);
                        fn_97_22EC(p + 0x4520, -1);
                        if (p + 0x450C != 0) fn_27_C7770(p + 0x450C, -1);
                    }
                    if (p + 0x43E0 != 0) {
                        fn_97_2210(p + 0x44BC, -1);
                        fn_97_22AC(p + 0x44A0, -1);
                        fn_97_22EC(p + 0x43F4, -1);
                        if (p + 0x43E0 != 0) fn_27_C7770(p + 0x43E0, -1);
                    }
                    if (p + 0x42B4 != 0) {
                        fn_97_2210(p + 0x4390, -1);
                        fn_97_22AC(p + 0x4374, -1);
                        fn_97_22EC(p + 0x42C8, -1);
                        if (p + 0x42B4 != 0) fn_27_C7770(p + 0x42B4, -1);
                    }
                    if (p + 0x4188 != 0) {
                        fn_97_2210(p + 0x4264, -1);
                        fn_97_22AC(p + 0x4248, -1);
                        fn_97_22EC(p + 0x419C, -1);
                        if (p + 0x4188 != 0) fn_27_C7770(p + 0x4188, -1);
                    }
                }
                if (p + 0xCC != 0) {
                    fn_97_4D20(p + 0x4144, -1);
                    fn_97_3AD4(p + 0x412C, -1);
                    if (p + 0x3FD4 != 0) fn_27_BED74(p + 0x3FD4, -1);
                    fn_97_2EAC(p + 0x3F88, -1);
                    if (p + 0x3DF0 != 0) {
                        fn_27_97968(p + 0x3E48, -1);
                        fn_27_1CCCC(p + 0x3E38, -1);
                        fn_97_3164(p + 0x3E2C, -1);
                        if (p + 0x3DF0 != 0) fn_27_CBF58(p + 0x3DF0, -1);
                    }
                    if (p + 0x1E30 != 0) {
                        fn_27_93100(p + 0x3DB4, -1);
                        if (p + 0x1E70 != 0) {
                            if (p + 0x1E70 != 0) {
                                if (p + 0x1E78 != 0) {
                                    if (p + 0x1E78 != 0) {
                                        if (p + 0x1E7C != 0 && p + 0x1E84 != 0 && p + 0x1E88 != 0) {
                                            if (p + 0x3D84 != 0) {
                                                if (p + 0x3D84 != 0) fn_97_37F8(p + 0x3D84, 0);
                                            }
                                            if (p + 0x1E88 != 0) {
                                                fn_97_4C28(p + 0x3D3C, -1);
                                                fn_27_1DBB60(p + 0x3D04, -1);
                                                if (p + 0x1F54 != 0) {
                                                    if (p + 0x3754 != 0) {
                                                        fn_97_3838(p + 0x3C04, -1);
                                                        if (p + 0x3AD8 != 0) {
                                                            fn_97_2210(p + 0x3BB4, -1);
                                                            fn_97_22AC(p + 0x3B98, -1);
                                                            fn_97_22EC(p + 0x3AEC, -1);
                                                            if (p + 0x3AD8 != 0) fn_27_C7770(p + 0x3AD8, -1);
                                                        }
                                                        if (p + 0x39AC != 0) {
                                                            fn_97_2210(p + 0x3A88, -1);
                                                            fn_97_22AC(p + 0x3A6C, -1);
                                                            fn_97_22EC(p + 0x39C0, -1);
                                                            if (p + 0x39AC != 0) fn_27_C7770(p + 0x39AC, -1);
                                                        }
                                                        if (p + 0x3880 != 0) {
                                                            fn_97_2210(p + 0x395C, -1);
                                                            fn_97_22AC(p + 0x3940, -1);
                                                            fn_97_22EC(p + 0x3894, -1);
                                                            if (p + 0x3880 != 0) fn_27_C7770(p + 0x3880, -1);
                                                        }
                                                        fn_97_3A48(p + 0x3754, -1);
                                                    }
                                                    if (p + 0x1F54 != 0) {
                                                        fn_97_4D20(p + 0x3710, -1);
                                                        fn_97_3AD4(p + 0x36F8, -1);
                                                        fn_97_3B30(p + 0x355C, -1);
                                                        fn_97_3BBC(p + 0x34FC, -1);
                                                        fn_97_4D7C(p + 0x3448, -1);
                                                        fn_97_3CB8(p + 0x3288, -1);
                                                        fn_97_3FC8(p + 0x31E4, -1);
                                                        fn_97_40FC(p + 0x31B0, -1);
                                                        fn_97_4158(p + 0x3198, -1);
                                                        fn_97_41B4(p + 0x3034, -1);
                                                        fn_97_4220(p + 0x2FCC, -1);
                                                        fn_97_4280(p + 0x2FC0, -1);
                                                        fn_97_42E0(p + 0x2F98, -1);
                                                        fn_97_5648(p + 0x2DC8, -1);
                                                        fn_97_433C(p + 0x2D64, -1);
                                                        fn_97_4408(p + 0x2D28, -1);
                                                        fn_97_4464(p + 0x2C70, -1);
                                                        if (p + 0x2A64 != 0) {
                                                            fn_27_13C90(p + 0x2B00, -1);
                                                            fn_27_21038(p + 0x2AEC, -1);
                                                            fn_97_4534(p + 0x2A64, -1);
                                                        }
                                                        fn_97_45BC(p + 0x2884, -1);
                                                        fn_97_4628(p + 0x2854, -1);
                                                        fn_97_46E0(p + 0x2844, -1);
                                                        fn_97_4720(p + 0x282C, -1);
                                                        __dt__16soModuleAccesserFv(p + 0x274C, -1);
                                                        fn_97_4FA8(p + 0x1F54, -1);
                                                    }
                                                }
                                                fn_27_1D81C8(p + 0x1E88, 0);
                                            }
                                        }
                                    }
                                }
                                fn_97_6208(p + 0x1E70, 0);
                            }
                        }
                        fn_27_19EFFC(p + 0x1E44, -1);
                        fn_27_1A51A0(p + 0x1E30, -1);
                    }
                    if (p + 0x1DA4 != 0) fn_97_3C1C(p + 0x1E0C, -1);
                    if (p + 0x1C5C != 0) {
                        if (p + 0x1D3C != 0) {
                            if (p + 0x1D40 != 0 && p + 0x1D40 != 0) {
                                if (p + 0x1D84 != 0 && p + 0x1D8C != 0 && p + 0x1D90 != 0) fn_97_4C84(p + 0x1D90, 0);
                                if (p + 0x1D40 != 0) {
                                    if (p + 0x1D40 != 0) {
                                        if (p + 0x1D44 != 0 && p + 0x1D4C != 0 && p + 0x1D50 != 0) fn_97_4C84(p + 0x1D50, 0);
                                    }
                                }
                            }
                        }
                        fn_97_62C8(p + 0x1C8C, -1);
                        fn_97_6338(p + 0x1C5C, -1);
                    }
                    if (p + 0x1A30 != 0) {
                        fn_97_3D5C(p + 0x1BAC, -1);
                        fn_97_3DE0(p + 0x1B98, -1);
                        if (p + 0x1B64 != 0) fn_27_1A2E14(p + 0x1B64, -1);
                        fn_97_63A4(p + 0x1AA0, -1);
                        if (p + 0x1A40 != 0) fn_97_3C1C(p + 0x1A7C, -1);
                        fn_27_C74E8(p + 0x1A30, -1);
                    }
                    if (p + 0x197C != 0) {
                        if (p + 0x19A0 != 0) {
                            fn_27_D2C18(p + 0x19B0, -1);
                            fn_97_4050(p + 0x19A0, 0);
                        }
                        fn_97_4090(p + 0x197C, -1);
                    }
                    fn_97_40FC(p + 0x1948, -1);
                    if (p + 0x1924 != 0) {
                        if (p + 0x1928 != 0) __dt__22soControllerModuleImplFv(p + 0x1928, 0);
                    }
                    if (p + 0x18F4 != 0) fn_27_5B39C(p + 0x18F4, -1);
                    fn_97_41B4(p + 0x1790, -1);
                    fn_97_4220(p + 0x1728, -1);
                    if (p + 0x16E4 != 0) {
                        fn_27_689B0(p + 0x170C, -1);
                        if (p + 0x16E4 != 0) fn_27_C9A14(p + 0x16E4, -1);
                    }
                    fn_97_42E0(p + 0x16BC, -1);
                    if (p + 0x13D8 != 0) {
                        __dt__24soCollisionHitModuleImplFv(p + 0x164C, -1);
                        fn_27_CC984(p + 0x1608, -1);
                        fn_27_4CAA0(p + 0x1584, -1);
                        fn_27_19B94C(p + 0x13D8, -1);
                    }
                    fn_97_4EB8(p + 0x1064, -1);
                    fn_97_433C(p + 0x1000, -1);
                    fn_97_4408(p + 0xFC4, -1);
                    if (p + 0xF18 != 0) {
                        fn_27_319E9C(p + 0xF68, -1);
                        fn_27_CC0F0(p + 0xF18, -1);
                    }
                    fn_97_4464(p + 0xE64, -1);
                    if (p + 0xC1C != 0) {
                        fn_27_13C90(p + 0xCF4, -1);
                        fn_27_21038(p + 0xCE0, -1);
                        fn_97_44D8(p + 0xCA4, -1);
                        fn_97_4534(p + 0xC1C, -1);
                    }
                    if (p + 0xA20 != 0) {
                        __dt__17soModelModuleImplFv(p + 0xB50, -1);
                        if (p + 0xB30 != 0) fn_27_19BC9C(p + 0xB30, -1);
                        fn_27_CBDE8(p + 0xA20, -1);
                    }
                    fn_97_4628(p + 0x9F0, -1);
                    fn_97_46E0(p + 0x9E0, -1);
                    fn_97_4720(p + 0x9C8, -1);
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
