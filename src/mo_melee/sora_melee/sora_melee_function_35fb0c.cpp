#pragma force_active off
#pragma dont_inline on
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
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    ~soEventUnitWithWorkArea();
};
extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_A0C74(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_27_A0C34(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_27_1362C(void*, short);
void* fn_27_7700(void*, short);
void* fn_27_75E0C(void*, short);
void* fn_27_64930(void*, short);
void* fn_27_1A2B08(void*, short);
void* fn_27_1A405C(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A262C(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_CBB00(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void* fn_27_CC0F0(void*, short);
void* fn_27_19FFEC(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_C96C0(void*, short);
void* fn_27_CBDE8(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* __dt__22soControllerModuleImplFv(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* __dt__19soPostureModuleImplFv(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void __dl__FPv(void*);
}
#pragma force_active on
extern "C" void* fn_27_35FB0C(char* self, int flag) {
    if (self) {
        if (self) {
            fn_27_1DBB60(self + 0x1F08, -1);
            if (self + 0xCC) {
                if (self + 0x1958) {
                    if (self + 0x1E08) {
                        if (self + 0x1E58) fn_27_A0C74(self + 0x1E58, -1);
                        if (self + 0x1E08) __dt__16acCmdInterpreterFv(self + 0x1E08, 0);
                    }
                    if (self + 0x1cdc) {
                        if (self + 0x1db8) __dt__16acCmdInterpreterFv(self + 0x1db8, 0);
                        if (self + 0x1cf0) fn_27_A0C74(self + 0x1cf0, -1);
                        if (self + 0x1cdc) fn_27_C7770(self + 0x1cdc, -1);
                    }
                    if (self + 0x1bb0) {
                        if (self + 0x1c8c) __dt__16acCmdInterpreterFv(self + 0x1c8c, 0);
                        if (self + 0x1bc4) fn_27_A0C74(self + 0x1bc4, -1);
                        if (self + 0x1bb0) fn_27_C7770(self + 0x1bb0, -1);
                    }
                    if (self + 0x1a84) {
                        if (self + 0x1b60) __dt__16acCmdInterpreterFv(self + 0x1b60, 0);
                        if (self + 0x1a98) fn_27_A0C74(self + 0x1a98, -1);
                        if (self + 0x1a84) fn_27_C7770(self + 0x1a84, -1);
                    }
                    if (self + 0x1958) {
                        if (self + 0x1a34) __dt__16acCmdInterpreterFv(self + 0x1a34, 0);
                        if (self + 0x196c) fn_27_A0C74(self + 0x196c, -1);
                        if (self + 0x1958) fn_27_C7770(self + 0x1958, -1);
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x193C) fn_27_C31CC(self + 0x193C, -1);
                    if (self + 0x18FC) fn_27_63EBC(self + 0x18FC, -1);
                    if (self + 0x18E4) fn_27_5C674(self + 0x18E4, -1);
                    if (self + 0x1748) {
                        fn_27_97968(self + 0x17A0, -1);
                        fn_27_1CCCC(self + 0x1790, -1);
                        if (self + 0x1784) fn_27_A0C34(self + 0x1784, -1);
                        if (self + 0x1748) fn_27_CBF58(self + 0x1748, -1);
                    }
                    if (self + 0x1634) {
                        if (self + 0x1664) fn_27_1A241C(self + 0x1674, -1);
                        if (self + 0x1634) {
                            if (self + 0x1654) fn_27_1362C(self + 0x1654, 0);
                            if (self + 0x1634) {
                                if (self + 0x163C) fn_27_7700(self + 0x163C, 0);
                            }
                        }
                    }
                    if (self + 0x146C) {
                        if (self + 0x1584) {
                            fn_27_75E0C(self + 0x15D0, -1);
                            if (self + 0x15A4) fn_27_64930(self + 0x15A4, 0);
                            if (self + 0x1598) fn_27_7700(self + 0x1598, 0);
                        }
                        if (self + 0x1570) fn_27_1A2B08(self + 0x1574, -1);
                        if (self + 0x1558) fn_27_1A405C(self + 0x1558, -1);
                        if (self + 0x14B4) {
                            if (self + 0x14D4) {
                                if (self + 0x14D4) {
                                    if (self + 0x14D4) fn_27_1A1E70(self + 0x14D4, -1);
                                }
                            }
                            fn_27_CD934(self + 0x14B4, -1);
                        }
                        fn_27_C74E8(self + 0x146C, -1);
                    }
                    if (self + 0x13C8) {
                        if (self + 0x13EC) fn_27_1A262C(self + 0x13FC, -1);
                        if (self + 0x13C8) {
                            if (self + 0x13DC) fn_27_7700(self + 0x13DC, 0);
                            if (self + 0x13D0) fn_27_1362C(self + 0x13D0, 0);
                        }
                    }
                    if (self + 0x1394) fn_27_A1E80(self + 0x1394, -1);
                    if (self + 0x1370) {
                        if (self + 0x1374) __dt__22soControllerModuleImplFv(self + 0x1374, 0);
                    }
                    if (self + 0x1208) {
                        fn_27_6A3D8(self + 0x1318, -1);
                        fn_27_CBB00(self + 0x1208, -1);
                    }
                    if (self + 0x11A0) fn_27_565F0(self + 0x11AC, -1);
                    if (self + 0x1194) fn_27_6880C(self + 0x1198, -1);
                    if (self + 0x116C) __dt__16soStopModuleImplFv(self + 0x116C, -1);
                    if (self + 0xF9C) {
                        __dt__27soCollisionAttackModuleImplFv(self + 0x10C0, -1);
                        fn_27_82AD4(self + 0x10BC, -1);
                        fn_27_4CAA0(self + 0x1038, -1);
                        fn_27_19CA80(self + 0xF9C, -1);
                    }
                    if (self + 0xF38) fn_27_B5324(self + 0xF58, -1);
                    if (self + 0xEFC) fn_27_3544C(self + 0xEFC, -1);
                    if (self + 0xE54) {
                        fn_27_25740(self + 0xEA4, -1);
                        fn_27_CC0F0(self + 0xE54, -1);
                    }
                    if (self + 0xDA0) {
                        __dt__19soPostureModuleImplFv(self + 0xDDC, -1);
                        if (self + 0xDA0) fn_27_19FFEC(self + 0xDA0, -1);
                    }
                    if (self + 0xBDC) {
                        fn_27_13C90(self + 0xC30, -1);
                        fn_27_21038(self + 0xC1C, -1);
                        if (self + 0xBE0) fn_27_C96C0(self + 0xBE0, -1);
                    }
                    if (self + 0x9FC) {
                        __dt__17soModelModuleImplFv(self + 0xB10, -1);
                        fn_27_CBDE8(self + 0x9FC, -1);
                    }
                    if (self + 0x9CC) __dt__20soResourceModuleImplFv(self + 0x9E4, -1);
                    if (self + 0x9A4) __dt__16soHeapModuleImplFv(self + 0x9A4, -1);
                    __dt__16soModuleAccesserFv(self + 0x8C4, -1);
                    if (self + 0xCC) {
                        typedef soEventUnitWithWorkArea<soMotionEventObserver, 1> Unit0;
                        reinterpret_cast<Unit0*>(self + 0x888)->Unit0::~Unit0();
                        typedef soEventUnitWithWorkArea<soItemManageEventObserver, 1> Unit1;
                        reinterpret_cast<Unit1*>(self + 0x850)->Unit1::~Unit1();
                        typedef soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> Unit2;
                        reinterpret_cast<Unit2*>(self + 0x7f4)->Unit2::~Unit2();
                        typedef soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> Unit3;
                        reinterpret_cast<Unit3*>(self + 0x798)->Unit3::~Unit3();
                        typedef soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> Unit4;
                        reinterpret_cast<Unit4*>(self + 0x73c)->Unit4::~Unit4();
                        typedef soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> Unit5;
                        reinterpret_cast<Unit5*>(self + 0x6e0)->Unit5::~Unit5();
                        typedef soEventUnitWithWorkArea<soCaptureEventObserver, 4> Unit6;
                        reinterpret_cast<Unit6*>(self + 0x684)->Unit6::~Unit6();
                        fn_27_18D3DC(self + 0x640, -1);
                        typedef soEventUnitWithWorkArea<soModelEventObserver, 4> Unit7;
                        reinterpret_cast<Unit7*>(self + 0x5e4)->Unit7::~Unit7();
                        typedef soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> Unit8;
                        reinterpret_cast<Unit8*>(self + 0x588)->Unit8::~Unit8();
                        typedef soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> Unit9;
                        reinterpret_cast<Unit9*>(self + 0x52c)->Unit9::~Unit9();
                        typedef soEventUnitWithWorkArea<soSituationEventObserver, 4> Unit10;
                        reinterpret_cast<Unit10*>(self + 0x4d0)->Unit10::~Unit10();
                        fn_27_D597C(self + 0x48C, -1);
                        typedef soEventUnitWithWorkArea<soDamageEventObserver, 4> Unit11;
                        reinterpret_cast<Unit11*>(self + 0x430)->Unit11::~Unit11();
                        fn_27_18D6CC(self + 0x284, -1);
                        fn_27_18D788(self + 0x198, -1);
                        __dt__23soEventManageModuleImplFv(self + 0x184, -1);
                        typedef soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > Entity;
                        reinterpret_cast<Entity*>(self + 0xCC)->~Entity();
                    }
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
