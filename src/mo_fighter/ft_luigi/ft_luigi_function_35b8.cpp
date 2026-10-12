void operator delete(void*);
extern "C" {
void* fn_99_3C2C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_99_21BC(void*, short);
void* fn_99_20E0(void*, short);
void* fn_99_217C(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_198E00(void*, short);
void* fn_27_19941C(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_A3704(void*, short);
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_99_3034(void*, short);
void* fn_27_CBF58(void*, short);
void* fn_99_3C6C(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_99_3D08(void*, short);
void* fn_99_1E9C(void*, short);
void* fn_99_3D48(void*, short);
void* fn_99_3DA8(void*, short);
void* fn_99_3E2C(void*, short);
void* fn_27_1A301C(void*, short);
void* fn_99_3E8C(void*, short);
void* fn_27_1A1E70(void*, short);
void* fn_27_CD934(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A262C(void*, short);
void* fn_99_3F2C(void*, short);
void* fn_99_3F6C(void*, short);
void* fn_99_3FD8(void*, short);
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
void* fn_99_4034(void*, short);
void* fn_99_4074(void*, short);
void* fn_99_40D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_D2AA4(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_CBDE8(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_99_4144(void*, short);
void* fn_99_4184(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_18D3DC(void*, short);
void* fn_27_D597C(void*, short);
void* fn_27_18D6CC(void*, short);
void* fn_27_18D788(void*, short);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Declaration-only shared destructor types preserve the imported template ABI.
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
class soEventUnit;
template <class Observer, int Capacity>
class soEventUnitWithWorkArea { public: ~soEventUnitWithWorkArea(); };
template <class Element> class soInstanceUnit;
template <class Element, int Capacity> class soArrayVector;
template <class Element, class Storage>
class soInstanceManagerSimpleEntity { public: ~soInstanceManagerSimpleEntity(); };

namespace {
// Lifetime overlays retain the null guards of the inlined destructor layers.
struct SupportLifetime {
    inline ~SupportLifetime() { fn_99_3C2C(this, static_cast<short>(0)); }
};
template <int Instance>
struct ParameterLifetime {
    inline ~ParameterLifetime() { fn_27_C7770(this, static_cast<short>(-1)); }
};
struct ControlLifetime {
    inline ~ControlLifetime() { fn_27_CBF58(this, static_cast<short>(-1)); }
};
struct CollisionBaseLifetime {
    inline ~CollisionBaseLifetime() { fn_27_1A1E70(this, static_cast<short>(-1)); }
};
struct CollisionMiddleLifetime {
    inline ~CollisionMiddleLifetime() { reinterpret_cast<CollisionBaseLifetime*>(this)->~CollisionBaseLifetime(); }
};
struct CollisionLifetime {
    inline ~CollisionLifetime() { reinterpret_cast<CollisionMiddleLifetime*>(this)->~CollisionMiddleLifetime(); }
};
struct ModelBaseLifetime {
    inline ~ModelBaseLifetime() { fn_27_D2AA4(this, static_cast<short>(-1)); }
};
struct ModelMiddleLifetime {
    inline ~ModelMiddleLifetime() { reinterpret_cast<ModelBaseLifetime*>(this)->~ModelBaseLifetime(); }
};
struct ModelLifetime {
    inline ~ModelLifetime() { reinterpret_cast<ModelMiddleLifetime*>(this)->~ModelMiddleLifetime(); }
};
template <int Instance>
struct LeafLifetime {
    inline ~LeafLifetime() { fn_99_4034(this, static_cast<short>(0)); }
};
struct ResourceLifetime {
    inline ~ResourceLifetime() { fn_99_4144(this, static_cast<short>(0)); }
};
struct HierarchyLifetime {
    inline ~HierarchyLifetime() {
        unsigned char* s = reinterpret_cast<unsigned char*>(this);
        reinterpret_cast<SupportLifetime*>(s + 0x200C)->~SupportLifetime();
        short destroy = -1;
        fn_27_1DBB60(s + 0x1FD4, destroy);
        if (s + 0xCC != 0) {
            if (s + 0x1A24 != 0) {
                if (s + 0x1ED4 != 0) {
                    fn_99_21BC(s + 0x1F24, destroy);
                    fn_99_20E0(s + 0x1ED4, destroy);
                }
                if (s + 0x1DA8 != 0) {
                    short destroy = -1;
                    fn_99_20E0(s + 0x1E84, destroy);
                    fn_99_217C(s + 0x1E68, destroy);
                    fn_99_21BC(s + 0x1DBC, destroy);
                    reinterpret_cast<ParameterLifetime<3>*>(s + 0x1DA8)->~ParameterLifetime();
                }
                if (s + 0x1C7C != 0) {
                    short destroy = -1;
                    fn_99_20E0(s + 0x1D58, destroy);
                    fn_99_217C(s + 0x1D3C, destroy);
                    fn_99_21BC(s + 0x1C90, destroy);
                    reinterpret_cast<ParameterLifetime<2>*>(s + 0x1C7C)->~ParameterLifetime();
                }
                if (s + 0x1B50 != 0) {
                    short destroy = -1;
                    fn_99_20E0(s + 0x1C2C, destroy);
                    fn_99_217C(s + 0x1C10, destroy);
                    fn_99_21BC(s + 0x1B64, destroy);
                    reinterpret_cast<ParameterLifetime<1>*>(s + 0x1B50)->~ParameterLifetime();
                }
                if (s + 0x1A24 != 0) {
                    short destroy = -1;
                    fn_99_20E0(s + 0x1B00, destroy);
                    fn_99_217C(s + 0x1AE4, destroy);
                    fn_99_21BC(s + 0x1A38, destroy);
                    reinterpret_cast<ParameterLifetime<0>*>(s + 0x1A24)->~ParameterLifetime();
                }
            }
            if (s + 0xCC != 0) {
                if (s + 0x19E0 != 0) fn_27_63EBC(s + 0x19E0, static_cast<short>(-1));
                if (s + 0x19C8 != 0) fn_27_5C674(s + 0x19C8, static_cast<short>(-1));
                if (s + 0x186C != 0) {
                    short destroy = -1;
                    fn_27_198E00(s + 0x198C, destroy);
                    fn_27_19941C(s + 0x18D8, destroy);
                    fn_27_A78FC(s + 0x18BC, destroy);
                    fn_27_A3704(s + 0x1870, destroy);
                }
                if (s + 0x16D8 != 0) {
                    short destroy = -1;
                    fn_27_97968(s + 0x1730, destroy);
                    fn_27_1CCCC(s + 0x1720, destroy);
                    fn_99_3034(s + 0x1714, destroy);
                    reinterpret_cast<ControlLifetime*>(s + 0x16D8)->~ControlLifetime();
                }
                if (s + 0x1678 != 0) fn_99_3C6C(s + 0x16B0, static_cast<short>(-1));
                if (s + 0x15C4 != 0) {
                    if (s + 0x15F4 != 0) {
                        fn_27_1A241C(s + 0x1604, static_cast<short>(-1));
                        fn_99_3D08(s + 0x15F4, static_cast<short>(0));
                    }
                    if (s + 0x15C4 != 0) {
                        short destroy = 0;
                        fn_99_1E9C(s + 0x15E4, destroy);
                        fn_99_3D48(s + 0x15C4, destroy);
                    }
                }
                if (s + 0x1400 != 0) {
                    short destroy = -1;
                    fn_99_3DA8(s + 0x1514, destroy);
                    fn_99_3E2C(s + 0x1500, destroy);
                    if (s + 0x14EC != 0) fn_27_1A301C(s + 0x14EC, destroy);
                    if (s + 0x1448 != 0) {
                        short destroy = -1;
                        fn_99_3E8C(s + 0x14D4, destroy);
                        reinterpret_cast<CollisionLifetime*>(s + 0x1468)->~CollisionLifetime();
                        fn_27_CD934(s + 0x1448, static_cast<short>(-1));
                    }
                    if (s + 0x1410 != 0) fn_99_3C6C(s + 0x1424, static_cast<short>(-1));
                    fn_27_C74E8(s + 0x1400, static_cast<short>(-1));
                }
                if (s + 0x135C != 0) {
                    if (s + 0x1380 != 0) {
                        fn_27_1A262C(s + 0x1390, static_cast<short>(-1));
                        fn_99_3F2C(s + 0x1380, static_cast<short>(0));
                    }
                    fn_99_3F6C(s + 0x135C, static_cast<short>(-1));
                }
                short destroy = -1;
                fn_99_3FD8(s + 0x1328, destroy);
                if (s + 0x1310 != 0) fn_27_5AE44(s + 0x1310, destroy);
                if (s + 0x11AC != 0) {
                    short destroy = -1;
                    fn_27_6A3D8(s + 0x12BC, destroy);
                    fn_27_CBB00(s + 0x11AC, destroy);
                }
                if (s + 0x1144 != 0) fn_27_565F0(s + 0x1150, static_cast<short>(-1));
                if (s + 0x1138 != 0) fn_27_6880C(s + 0x113C, static_cast<short>(-1));
                if (s + 0x1110 != 0) __dt__16soStopModuleImplFv(s + 0x1110, static_cast<short>(-1));
                if (s + 0xF40 != 0) {
                    short destroy = -1;
                    __dt__27soCollisionAttackModuleImplFv(s + 0x1064, destroy);
                    fn_27_82AD4(s + 0x1060, destroy);
                    fn_27_4CAA0(s + 0xFDC, destroy);
                    fn_27_19CA80(s + 0xF40, destroy);
                }
                if (s + 0xEDC != 0) {
                    fn_27_B5324(s + 0xEFC, static_cast<short>(-1));
                    reinterpret_cast<LeafLifetime<1>*>(s + 0xEEC)->~LeafLifetime();
                    reinterpret_cast<LeafLifetime<0>*>(s + 0xEDC)->~LeafLifetime();
                }
                fn_99_4074(s + 0xEA0, destroy);
                fn_99_40D0(s + 0xDE8, destroy);
                if (s + 0xBDC != 0) {
                    fn_27_13C90(s + 0xC78, destroy);
                    fn_27_21038(s + 0xC64, destroy);
                    if (s + 0xBDC != 0) {
                        fn_99_3E8C(s + 0xC48, destroy);
                        reinterpret_cast<ModelLifetime*>(s + 0xBFC)->~ModelLifetime();
                        fn_27_CD934(s + 0xBDC, static_cast<short>(-1));
                    }
                }
                if (s + 0x9FC != 0) {
                    short destroy = -1;
                    __dt__17soModelModuleImplFv(s + 0xB10, destroy);
                    fn_27_CBDE8(s + 0x9FC, destroy);
                }
                if (s + 0x9CC != 0) {
                    __dt__20soResourceModuleImplFv(s + 0x9E4, static_cast<short>(-1));
                    reinterpret_cast<ResourceLifetime*>(s + 0x9CC)->~ResourceLifetime();
                }
                fn_99_4184(s + 0x9A4, destroy);
                __dt__16soModuleAccesserFv(s + 0x8C4, destroy);
                if (s + 0xCC != 0) {
                    reinterpret_cast<soEventUnitWithWorkArea<soMotionEventObserver, 1>*>(s + 0x888)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soItemManageEventObserver, 1>*>(s + 0x850)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>*>(s + 0x7F4)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>*>(s + 0x798)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>*>(s + 0x73C)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>*>(s + 0x6E0)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCaptureEventObserver, 4>*>(s + 0x684)->~soEventUnitWithWorkArea();
                    fn_27_18D3DC(s + 0x640, destroy);
                    reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver, 4>*>(s + 0x5E4)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>*>(s + 0x588)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>*>(s + 0x52C)->~soEventUnitWithWorkArea();
                    reinterpret_cast<soEventUnitWithWorkArea<soSituationEventObserver, 4>*>(s + 0x4D0)->~soEventUnitWithWorkArea();
                    fn_27_D597C(s + 0x48C, destroy);
                    reinterpret_cast<soEventUnitWithWorkArea<soDamageEventObserver, 4>*>(s + 0x430)->~soEventUnitWithWorkArea();
                    fn_27_18D6CC(s + 0x284, destroy);
                    fn_27_18D788(s + 0x198, destroy);
                    __dt__23soEventManageModuleImplFv(s + 0x184, destroy);
                    reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >*>(s + 0xCC)->~soInstanceManagerSimpleEntity();
                }
            }
        }
        fn_27_1D81C8(this, static_cast<short>(0));
    }
};
}

extern "C" void* fn_99_35B8(void* object, int deleting) {
    if (object != 0) {
        reinterpret_cast<HierarchyLifetime*>(object)->~HierarchyLifetime();
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
