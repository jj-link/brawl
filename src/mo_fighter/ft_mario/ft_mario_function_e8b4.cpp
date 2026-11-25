// Status: not a full match. About 98% of the disassembly lines match (139 differing lines).
// Remaining diffs: saved-register assignment for arg4/arg5/arg6 and the accessor (r22..r27),
// and the bl targets for the template constructors, which use placeholder names here.
#include <types.h>
#include <new>
#include <so/model/so_model_module_impl.h>
#include <so/event/so_event_system.h>
#pragma force_active on
#pragma use_simple_stdpnew on

// Virtual slot classes. The first declared virtual sits at vtable offset 0x8; method pNN is at offset 0xNN.
class Obj {
public:
    virtual void* p08(); virtual void* p0c(); virtual void* p10(); virtual void* p14();
    virtual void* p18(); virtual void* p1c(); virtual void* p20(); virtual short p24();
    virtual void p28(); virtual void* p2c(); virtual void* p30(); virtual void* p34();
    virtual void* p38(); virtual void* p3c(); virtual void* p40(); virtual void* p44();
    virtual void* p48(); virtual void* p4c(); virtual float p50(); virtual void* p54();
    virtual void* p58(); virtual void* p5c(); virtual void* p60(); virtual void* p64();
    virtual void* p68(); virtual void* p6c(); virtual void* p70(); virtual void* p74();
    virtual void* p78(); virtual void* p7c(); virtual void* p80(); virtual void* p84();
    virtual void* p88(); virtual void* p8c(); virtual void* p90();
};

class ObjA {
public:
    virtual void* p08(); virtual void* p0c(); virtual void* p10(); virtual void p14(int, void*);
    virtual void* p18(); virtual void* p1c(); virtual void* p20(); virtual short p24();
    virtual void p28(); virtual void* p2c(); virtual void p30(void*); virtual void* p34();
    virtual void* p38(); virtual void* p3c(); virtual void* p40(); virtual void* p44();
    virtual void* p48(); virtual void* p4c(); virtual float p50(); virtual void* p54();
    virtual void* p58(); virtual void* p5c(); virtual void* p60(); virtual void* p64();
    virtual void* p68(); virtual void* p6c(); virtual void* p70(); virtual void* p74();
    virtual void* p78(); virtual void* p7c(); virtual void* p80(); virtual void* p84();
    virtual void* p88(); virtual void* p8c(); virtual void p90(int, int);
};

class VtablePad { char pad[8]; };
class VtableAt8 : public VtablePad {
public:
    virtual void p8();
    virtual void pc();
    virtual void p10();
    virtual void p14();
    virtual void p18();
    virtual void p1c();
    virtual void p20();
    virtual void p24();
    virtual void p28();
    virtual void p2c();
    virtual void p30();
    virtual void p34();
    virtual void p38();
    virtual void p3c();
    virtual void p40();
    virtual void p44();
    virtual void p48();
    virtual void p4c();
    virtual void p50();
    virtual void p54();
    virtual void p58();
    virtual void p5c();
    virtual void p60();
    virtual void p64();
    virtual void p68();
    virtual void p6c();
};

class EvMgr {
public:
    virtual void a08(); virtual void a0c(); virtual void a10(); virtual void a14();
    virtual void a18(); virtual void a1c(); virtual void a20(); virtual void a24();
    virtual void a28(); virtual void a2c(); virtual void a30(); virtual void a34();
    virtual void a38(); virtual void a3c(); virtual void a40(); virtual void a44();
    virtual void a48(); virtual void a4c(); virtual void a50(); virtual short p54();
};

#define GETID(r) (((EvMgr*)((r) + 0xb8))->p54())

extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_91_data_78E8[], lbl_91_data_7B64[], lbl_91_data_78F8[];
extern char lbl_91_data_7DD0[], lbl_91_data_7F50[], lbl_91_data_2938[], lbl_91_data_78F4[];
extern float lbl_91_rodata_30;
extern char lbl_27_data_8E80[];
extern char lbl_27_bss_A48[], lbl_27_bss_344[], lbl_27_bss_35C[];
extern char lbl_27_bss_384[], lbl_27_bss_398[], lbl_27_bss_3AC[], lbl_27_bss_3BC[];
extern char lbl_27_bss_3CC[], lbl_27_bss_3DC[], lbl_27_bss_3F4[], lbl_27_bss_404[];
extern char lbl_27_bss_424[], lbl_27_bss_47C[], lbl_27_bss_48C[], lbl_27_bss_4BC[];
extern char lbl_27_bss_4D0[], lbl_27_bss_4E8[], lbl_27_bss_170[], lbl_27_bss_188[];
extern char lbl_27_bss_530[], lbl_27_bss_55C[], lbl_27_bss_584[], lbl_27_bss_598[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_5EC[], lbl_27_bss_604[];
extern char lbl_27_bss_614[], lbl_27_bss_628[], lbl_27_bss_640[], lbl_27_bss_654[];
extern char lbl_27_bss_66C[], lbl_27_bss_6E8[], lbl_27_bss_9BC[], lbl_27_bss_DBC[];
extern char lbl_91_bss_220[], lbl_91_bss_22C[], lbl_91_bss_238[], lbl_91_bss_244[];
extern char lbl_91_bss_250[], lbl_91_bss_25C[], lbl_91_bss_268[], lbl_91_bss_290[];
extern char lbl_91_bss_298[], lbl_91_bss_2A0[], lbl_91_bss_2A8[], lbl_91_bss_2B0[];
extern char lbl_91_bss_2B8[], lbl_91_bss_2C0[];
extern signed char lbl_91_bss_28C, lbl_91_bss_294, lbl_91_bss_29C, lbl_91_bss_2A4;
extern signed char lbl_91_bss_2AC, lbl_91_bss_2B4, lbl_91_bss_2BC;

void fn_27_1DC5E8(void*, int, void*, void*, void*, void*, unsigned char, int,
                  void*, int, int, void*, int, int, int, int);
void fn_27_1D7EF0(void*, void*, u32, u32, int, void*, void*, int);
void fn_27_1A9430(void*, short, short);
void fn_27_1AA1F4(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_91_1A70(void*, int);
void fn_27_CBD88(void*, int, int);
void fn_27_CD8C8(void*, int);
void fn_27_D2A38(void*, int);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_C7470(void*, void*, int);
void fn_27_197C78(void*);
void fn_27_197C9C(void*);
void fn_27_197C28(void*);
void fn_27_197C08(void*);
void fn_27_C94E0(void*);
void fn_27_197C18(void*);
void fn_27_C948C(void*);
void fn_27_82A94(void*, short);
void fn_27_82794(void*, short);
void fn_27_82754(void*, short);
void fn_27_82A14(void*, short);
void fn_27_82714(void*, short);
void fn_27_82B14(void*, short);
void fn_27_82C54(void*, short);
void __register_global_object(void*, void (*)(void*, short), void*);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, int, int, void*);
void fn_27_2520C(void*, void*, void*, void*);
void fn_91_FE04(void*, void*);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_687F8(void*, void*, void*, void*);
void fn_27_57FC8(void*);
void fn_27_561E0(void*, void*, void*, void*, int, int, void*);
void fn_27_CBAA0(void*, int, int);
void fn_27_6A244(void*, void*, void*);
void fn_27_5AD88(void*, void*, void*, int);
void fn_27_A1DA4(void*, void*, void*);
void fn_27_CBEC8(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, void*, void*, void*, void*, void*, int, int, void*, void*);
void fn_27_5C600(void*, void*);
void fn_27_63B94(void*, void*, int);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
void* __ct__16soStopModuleImplFP16soModuleAccesser(void*, void*);
void* __ct__23soEventManageModuleImplFPv(void*, void*);
void* __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(void*, int, int, int, int);
void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, u32, void*, u8);
void* __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(
    void*, void*, void*, void*, void*, void*, void*, void*,
    void*, void*, void*, void*, void*, void*, void*, void*,
    void*, void*, void*, void*, void*, void*, void*, void*,
    void*, void*, void*, void*, void*, void*, void*, void*,
    void*, void*, void*, void*, void*, void*, void*, void*,
    void*, void*, void*, void*, void*, void*, void*, void*,
    void*, void*, void*, void*, void*);
}

class soDamageEventObserver;
class soSituationEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;
class soCaptureEventObserver;
class soCollisionShieldEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionSearchEventObserver;
class soItemManageEventObserver;
class soMotionEventObserver;

// These constructor specializations are provided by the game.
template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > {
public:
    soInstanceManagerSimpleEntity();
};
typedef soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > EventUnitManager;
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    soEventUnitWithWorkArea(s16, s16);
};

#pragma always_inline on
#pragma inline_depth(4)
static inline void constructMantleDescriptor(char* desc, void* params, Obj* ids)
{
    fn_27_1DC5E8(desc, 1, params, ids->p10(), ids->p18(), ids->p1c(), 2, -1,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
}

static inline char* getMotionInstances(char* motion)
{
    return motion + 0x6c;
}

class MarioMantle {
public:
    inline MarioMantle(int arg4, void* arg5, void* arg6);
};

inline MarioMantle::MarioMantle(int arg4, void* arg5, void* arg6)
{
    char* self = reinterpret_cast<char*>(this);
    char desc[0x40];

    Obj* acc = *(Obj**)((char*)arg5 + 4);
    constructMantleDescriptor(desc, arg6, acc);
    char* const& name = static_cast<char*>(lbl_91_data_78E8);
    fn_27_1D7EF0(self, name, *(u32*)(desc + 4), *(u32*)(desc + 8),
                 (int)arg4, arg5, self + 0x8c4, 1);

    *(char**)(self + 0x3c) = lbl_91_data_7B64;
    *(char**)(self + 0x40) = lbl_91_data_7B64 + 0x64;
    *(char**)(self + 0x48) = lbl_91_data_7B64 + 0x70;
    *(char**)(self + 0x54) = lbl_91_data_7B64 + 0x84;
    *(char**)(self + 0x64) = lbl_91_data_7B64 + 0xdc;
    *(char**)(self + 0x70) = lbl_91_data_7B64 + 0xec;
    *(char**)(self + 0x7c) = lbl_91_data_7B64 + 0x100;
    *(char**)(self + 0x88) = lbl_91_data_7B64 + 0x118;
    *(char**)(self + 0x90) = lbl_91_data_7B64 + 0x124;

    char* r29 = self + 0xcc;
    new (r29) EventUnitManager;
    __ct__23soEventManageModuleImplFPv(r29 + 0xb8, r29);

    fn_27_1A9430(r29 + 0xcc, GETID(r29), 4);
    fn_27_1AA1F4(r29 + 0x1b8, GETID(r29), 5);
    new (r29 + 0x364) soEventUnitWithWorkArea<soDamageEventObserver, 4>(GETID(r29), 6);
    fn_27_D5878(r29 + 0x3c0, GETID(r29), 7);
    new (r29 + 0x404) soEventUnitWithWorkArea<soSituationEventObserver, 4>(GETID(r29), 8);
    new (r29 + 0x460) soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>(GETID(r29), 0);
    new (r29 + 0x4bc) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(GETID(r29), 1);
    new (r29 + 0x518) soEventUnitWithWorkArea<soModelEventObserver, 4>(GETID(r29), 9);
    fn_27_1AA878(r29 + 0x574, GETID(r29), 11);
    new (r29 + 0x5b8) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(GETID(r29), 13);
    new (r29 + 0x614) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(GETID(r29), 14);
    new (r29 + 0x670) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(GETID(r29), 15);
    new (r29 + 0x6cc) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(GETID(r29), 16);
    new (r29 + 0x728) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(GETID(r29), 17);
    new (r29 + 0x784) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(GETID(r29), 12);
    new (r29 + 0x7bc) soEventUnitWithWorkArea<soMotionEventObserver, 1>(GETID(r29), 10);

    __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(
        r29 + 0x7f8, self, r29 + 0x918, r29 + 0xa44, r29 + 0xbac, r29 + 0xd20,
        lbl_27_bss_344, lbl_27_bss_35C,
        r29 + 0xd88, lbl_27_bss_384, lbl_27_bss_398, lbl_27_bss_3AC,
        lbl_27_bss_3AC, lbl_27_bss_3AC, lbl_27_bss_3BC, lbl_27_bss_3CC,
        lbl_27_bss_3DC, lbl_27_bss_3F4, lbl_27_bss_404, r29 + 0xdd8,
        lbl_27_bss_424, r29 + 0xe04, r29 + 0xe18, r29 + 0xf84,
        r29 + 0xfd8, lbl_27_bss_47C, lbl_27_bss_48C, r29 + 0xff0,
        lbl_27_bss_4BC, lbl_27_bss_4D0, lbl_27_bss_4E8, lbl_27_bss_170,
        lbl_27_bss_188, lbl_27_bss_530, r29 + 0xb8, lbl_27_bss_55C,
        r29 + 0x10e4, lbl_27_bss_584, lbl_27_bss_598, lbl_27_bss_5B0,
        lbl_27_bss_5D8, lbl_27_bss_5EC, lbl_27_bss_604, lbl_27_bss_614,
        lbl_27_bss_628, lbl_27_bss_640, lbl_27_bss_654, lbl_27_bss_66C,
        r29 + 0x1228, r29 + 0x1240, r29 + 0x8d8, r29 + 0x8f0,
        lbl_27_bss_6E8);

    void* a78;
    void* a7c;
    void* a80;
    a80 = ((Obj*)desc)->p80();
    a7c = ((Obj*)desc)->p7c();
    a78 = ((Obj*)desc)->p78();
    void* a74 = ((Obj*)desc)->p74();
    __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(
        r29 + 0x8d8, (int)a74, (int)a78, (int)a7c, (int)a80);

    char* r22 = r29 + 0x8f0;
    fn_91_1A70(r22, 0);
    *(char**)r22 = lbl_91_data_7DD0;
    const f32 zero = lbl_91_rodata_30;
    *(f32*)(r22 + 8) = zero;
    *(f32*)(r22 + 0xc) = zero;

    void* v10 = ((Obj*)desc)->p10();
    void* v0c = ((Obj*)desc)->p0c();
    void* v08 = ((Obj*)desc)->p08();

    char* r22b = r29 + 0x900;
    fn_91_1A70(r22b, 0);
    *(char**)r22b = lbl_91_data_7F50;
    *(void**)(r22b + 8) = v08;
    *(void**)(r22b + 0xc) = v08;
    *(void**)(r22b + 0x10) = v0c;
    *(short*)(r22b + 0x14) = 0;
    *(short*)(r22b + 0x16) = 0;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(r22b + 0x18, 0, r22b, (u8)(u32)v10);

    void* modelData = ((Obj*)desc)->p68();
    float scale = ((Obj*)desc)->p50();

    char* r23 = r29 + 0x930;
    fn_27_CBD88(r23, 5, 0);
    if (!lbl_91_bss_28C) {
        fn_27_197C78(lbl_91_bss_290);
        __register_global_object(lbl_91_bss_290, fn_27_82A94, lbl_91_bss_220);
        lbl_91_bss_28C = 1;
    }
    new (r23 + 0x114) soModelModuleImpl((soModuleAccesser*)(r29 + 0x7f8), (soArray<soModelNodeSetUp>*)r23, scale, modelData, (soArray<soModelVirtualNode>*)lbl_91_bss_290, (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    r23 = (char*)((Obj*)desc)->p18();

    char* r31 = r29 + 0xb10;
    fn_27_CD8C8(r31, 0);
    fn_27_D2A38(r31 + 0x20, 0);
    *(char**)(r31 + 0x6c) = lbl_27_data_8E80;
    *(char**)(r31 + 0x70) = r31;
    *(int*)(r31 + 0x74) = 0;
    u32 entry[6];
    entry[0] = 0;
    *(int*)(r31 + 0x78) = -1;
    *(int*)(r31 + 0x7c) = -1;
    *(int*)(r31 + 0x80) = 0;
    for (int i = 0; i < 1; i++) {
        fn_27_AB15C(entry + 1, i == 0 ? (void*)(r31 + 0x20) : (void*)0);
        ((ObjA*)r31)->p30(entry + 1);
        fn_27_AB18C(entry + 1, -1);
    }
    fn_27_C7470(r31 + 0x88, r23, 2);

    if (!lbl_91_bss_2A4) {
        fn_27_197C28(lbl_91_bss_2A8);
        __register_global_object(lbl_91_bss_2A8, fn_27_82794, lbl_91_bss_244);
        lbl_91_bss_2A4 = 1;
    }
    char* motionSequence = lbl_91_bss_2A8;
    if (!lbl_91_bss_29C) {
        fn_27_197C08(lbl_91_bss_2A0);
        __register_global_object(lbl_91_bss_2A0, fn_27_82754, lbl_91_bss_238);
        lbl_91_bss_29C = 1;
    }
    char* motionTranslation = lbl_91_bss_2A0;
    if (!lbl_91_bss_294) {
        fn_27_C94E0(lbl_91_bss_298);
        __register_global_object(lbl_91_bss_298, fn_27_82A14, lbl_91_bss_22C);
        lbl_91_bss_294 = 1;
    }

    char* r23d = getMotionInstances(r31);
    char* p = *(char**)(r29 + 0x8d0);
    p = *(char**)(p + 0x80);
    short v8 = ((Obj*)(p + 8))->p24();
    fn_27_13844(r31 + 0x9c, r29 + 0x7f8, r31 + 0x88, r23d,
                motionSequence, motionTranslation, lbl_27_bss_9BC, lbl_91_bss_298,
                v8, 0, lbl_27_bss_DBC);

    p = *(char**)(r29 + 0x8d0);
    p = *(char**)(p + 0x4);
    ((Obj*)p)->p08();

    if (!lbl_91_bss_2AC) {
        fn_27_197C9C(lbl_91_bss_2B0);
        __register_global_object(lbl_91_bss_2B0, fn_27_82714, lbl_91_bss_250);
        lbl_91_bss_2AC = 1;
    }
    fn_27_2520C(r29 + 0xd20, r29 + 0x7f8, lbl_91_bss_2B0, lbl_27_bss_A48);
    ((Obj*)(r29 + 0xd20))->p38();
    ((Obj*)desc)->p28();
    p = *(char**)(r29 + 0x8d0);
    p = *(char**)(p + 0x80);
    ((Obj*)(p + 8))->p24();
    char* r23g;
    void* r22e = ((Obj*)desc)->p14();
    r23g = r29 + 0xd68;
    fn_91_FE04(r23g, r22e);
    fn_91_FE04(r23g + 0x10, r22e);
    fn_27_B5048(r23g + 0x20, r23g, r23g + 0x10, r23g, r29 + 0x7f8, lbl_27_bss_A48);

    __ct__16soStopModuleImplFP16soModuleAccesser(r29 + 0xdd8, r29 + 0x7f8);
    void* r22f = ((Obj*)desc)->p1c();

    if (!lbl_91_bss_2B4) {
        fn_27_197C18(lbl_91_bss_2B8);
        __register_global_object(lbl_91_bss_2B8, fn_27_82B14, lbl_91_bss_25C);
        lbl_91_bss_2B4 = 1;
    }
    fn_27_687F8(r29 + 0xe04, r29 + 0x7f8, lbl_91_bss_2B8, r22f);

    char* r23h;
    void* r22g = ((Obj*)desc)->p84();
    r23h = r29 + 0xe0c;
    fn_27_57FC8(r23h);
    fn_27_561E0(r23h + 0xc, r29 + 0x7f8, r23h, r22g, 1, 0, lbl_27_bss_A48);

    char* r22h = r29 + 0xe74;
    fn_27_CBAA0(r22h, 5, 0);
    fn_27_6A244(r22h + 0x110, r29 + 0x7f8, r22h);

    void* v20 = ((Obj*)desc)->p20();
    fn_27_5AD88(r29 + 0xfd8, r29 + 0x7f8, v20, 1);
    p = *(char**)(r29 + 0x8d0);
    p = *(char**)(p + 0x80);
    ((Obj*)(p + 8))->p24();

    ((Obj*)desc)->p60();
    ((Obj*)desc)->p5c();
    void* v54 = ((Obj*)desc)->p54();
    fn_27_A1DA4(r29 + 0xff0, r29 + 0x7f8, v54);
    p = *(char**)(r29 + 0x8d0);
    p = *(char**)(p + 0x80);
    ((Obj*)(p + 8))->p24();
    ((Obj*)desc)->p70();
    ((Obj*)desc)->p24();

    char* r23i = r29 + 0x102c;
    char* r22i = r23i + 0x38;
    fn_91_1A70(r22i, 0);
    *(char**)(r22i + 8) = lbl_91_data_2938;
    *(char**)r22i = lbl_91_data_2938 + 8;
    *(char**)(r22i + 0xc) = r23i;
    *(int*)(r22i + 0x10) = 7;
    *(char**)(r22i + 0x14) = r23i + 0x1c;
    *(int*)(r22i + 0x18) = 6;
    *(char**)(r22i + 0x1c) = r23i + 0x34;
    *(int*)(r22i + 0x20) = 1;
    ((VtableAt8*)r22i)->p6c();

    void* v38 = ((Obj*)desc)->p38();
    void* v34 = ((Obj*)desc)->p34();
    char* r22j;
    void* v2c;
    void* v30 = ((Obj*)desc)->p30();
    v2c = ((Obj*)desc)->p2c();
    r22j = r29 + 0x108c;
    fn_27_CBEC8(r22j, 1, 0);
    fn_27_C9FE4(r22j + 0x3c, 1, 0);
    fn_27_D37BC(r22j + 0x48, 1, lbl_91_data_78F4, 0);
    if (!lbl_91_bss_2BC) {
        fn_27_C948C(lbl_91_bss_2C0);
        __register_global_object(lbl_91_bss_2C0, fn_27_82C54, lbl_91_bss_268);
        lbl_91_bss_2BC = 1;
    }
    fn_27_9747C(r22j + 0x58, r29 + 0x7f8, r22j, v2c, r22j + 0x48, lbl_91_bss_2C0,
                v30, lbl_27_bss_A48, (int)v34, -1, v38, r22j + 0x3c);

    ((Obj*)desc)->p58();
    ((Obj*)desc)->p40();
    ((Obj*)desc)->p3c();
    ((Obj*)desc)->p44();
    ((Obj*)desc)->p48();
    ((Obj*)desc)->p88();
    ((Obj*)desc)->p64();
    ((Obj*)desc)->p6c();

    fn_27_5C600(r29 + 0x1228, r29 + 0x7f8);
    fn_27_63B94(r29 + 0x1240, r29 + 0x7f8, 0);

    char* r3k = r29 + 0x1064;
    int res = (int)((Obj*)r3k)->p08();
    if (res == 0) {
        char* q = *(char**)(*(char**)(r29 + 0x8d0) + 0x64);
        ((ObjA*)q)->p14(1, r29 + 0x1064);
    }

    ((ObjA*)desc)->p90(0, 2);
    ((ObjA*)desc)->p90(0, 1);
    ((ObjA*)desc)->p90(0, 0);
    ((ObjA*)desc)->p90(1, 2);
    ((ObjA*)desc)->p90(1, 1);
    ((ObjA*)desc)->p90(1, 0);
    ((ObjA*)desc)->p90(2, 2);
    ((ObjA*)desc)->p90(2, 1);
    ((ObjA*)desc)->p90(2, 0);
    ((ObjA*)desc)->p90(3, 2);
    ((ObjA*)desc)->p90(3, 1);
    ((ObjA*)desc)->p90(3, 0);
    ((ObjA*)desc)->p90(5, 2);
    ((ObjA*)desc)->p90(5, 1);
    ((ObjA*)desc)->p90(5, 0);

    fn_27_1D90FC(self);
    *(char**)(self + 0x3c) = lbl_91_data_78F8;
    *(char**)(self + 0x40) = lbl_91_data_78F8 + 0x64;
    *(char**)(self + 0x48) = lbl_91_data_78F8 + 0x70;
    *(char**)(self + 0x54) = lbl_91_data_78F8 + 0x84;
    *(char**)(self + 0x64) = lbl_91_data_78F8 + 0xdc;
    *(char**)(self + 0x70) = lbl_91_data_78F8 + 0xec;
    *(char**)(self + 0x7c) = lbl_91_data_78F8 + 0x100;
    *(char**)(self + 0x88) = lbl_91_data_78F8 + 0x118;
    *(char**)(self + 0x90) = lbl_91_data_78F8 + 0x124;
    fn_27_1D8FC8(self, 0);
}

extern "C" void* fn_91_E8B4(char* self, int owner, void* resource, void* params)
{
    new (self) MarioMantle(owner, resource, params);
    return self;
}
