#pragma use_simple_stdpnew on
#include <new>
#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <so/so_module_accesser.h>
#pragma force_active on

inline void* operator new[](size_t, void* storage) { return storage; }

extern "C" {
void fn_27_1257EC(void*, s32, s32, Heaps::HeapType, void*);
void fn_94_6D00(void*);
void fn_27_14B5F8(void*, void*);
void fn_94_7054(void*, s32, s32, u8, void*);
void fn_94_70BC(void*, void*, s32, void*);
void fn_94_7144(void*, void*, s32);
void fn_94_7318(void*, void*, void*);
void fn_94_7388(void*, void*, s32);
void fn_27_3513C(void*, s16, void*, void*);
void fn_94_6C34(void*, s32, void*);
void fn_94_73EC(void*, void*, s32, u8, void*);
void fn_94_74B0(void*, void*, s32, u8, void*);
void fn_94_7574(void*, void*, s32, u8);
void fn_94_7648(void*, void*, s32, u8);
void fn_94_771C(void*, void*, s32, u8, void*);
void fn_94_77B4(void*, void*, void*);
void fn_27_64C8C(void*, void*, s32);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_94_7820(void*, void*, s32);
void fn_94_787C(void*, void*, s32, void*);
void fn_94_790C(void*, void*);
void fn_27_5B248(void*, void*, s32, s32);
void fn_94_7960(void*, void*, s16);
void fn_94_79D0(void*, void*, s32, s32, void*);
void fn_27_A1DA4(void*, void*, s32);
void fn_94_7A3C(void*, s16);
void fn_94_7A80(void*, void*, s32, s32);
void fn_94_7F38(void*, void*);
void fn_94_8308(void*);
void fn_94_8368(void*, void*);
void fn_94_8A30(void*, void*, s32, s32, s32, s32, void*);
void fn_27_14FBD8(void*, void*);
void fn_94_8AFC(void*, void*, u8, void*);
void fn_94_8B94(void*, void*, s32);
void fn_27_ACAC4(void*, void*, s32, s32, u8, f32);
void fn_27_B62E4(void*, void*, f32, s32);
void fn_94_8BF4(void*, void*, s32);
void fn_27_BEBB4(void*, void*, s32, s32);
void fn_27_C20D8(void*, void*, s32, s32, s32);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, s32);
void fn_27_C7744(void*, void*, s32);
void fn_27_C749C(void*);
void fn_27_1A67D4(void*, s32);
void fn_27_1A079C(void*, s32);
void fn_27_D22D0(void*, s32);
void* fn_94_8E1C();
void fn_94_8C70(void*, void*, void*, void*);
void fn_94_8C8C(void*, s16, void*, s32, s32, f32, s8*);
void fn_94_8E8C(void*, void*, s32);
void* fn_94_8F08(void*, s32);
void fn_94_8F44(void*, s32, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_94_6C20(void*, s32);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void __ct__18ftFighterBuildDataFl6ftKindQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypeUcP16soModuleAccesserlPvPv(
    void*, s32, ftKind, Heaps::HeapType, Heaps::HeapType, Heaps::HeapType,
    u8, soModuleAccesser*, s32, void*, void*);
void __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(
    void*, Heaps::HeapType, Heaps::HeapType, Heaps::HeapType, long);
void __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(soModuleAccesser*, StageObject*, soResourceModule*, soModelModule*, soMotionModule*, soPostureModule*, soGroundModule*, soSituationModule*, void*, soCollisionAttackModule*, soCollisionHitModule*, soCollisionShieldModule*, soCollisionShieldModule*, soCollisionShieldModule*, void*, soCollisionSearchModule*, soDamageModule*, void*, void*, soStopModule*, void*, void*, soSoundModule*, soLinkModule*, soVisibilityModule*, soControllerModule*, soCameraModule*, soWorkManageModule*, void*, soAnimCmdModule*, soStatusModule*, void*, void*, soKineticModule*, soEventManageModule*, void*, soEffectModule*, void*, soAreaModule*, void*, void*, void*, void*, soShadowModule*, soItemManageModule*, soColorBlendModule*, void*, void*, soSlowModule*, void*, void*, soParamCustomizeModule*, void*);

extern char lbl_94_data_528[], lbl_94_data_44[];
extern char lbl_94_data_43C0[], lbl_94_data_4468[];
extern char lbl_94_data_4238[], lbl_94_data_42B8[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[], lbl_27_data_2FC98[], lbl_27_data_2FD40[];
extern char lbl_27_data_2FDE8[];
extern char lbl_27_bss_3AC[], lbl_27_bss_3CC[], lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[], lbl_27_bss_46D8[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_69C[];
extern char lbl_27_bss_A48[], lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_94_bss_1CC[], lbl_94_bss_1DC[], lbl_94_bss_1EC[];
extern char lbl_94_bss_1FC[], lbl_94_bss_20C[];
extern char lbl_27_bss_75C4[], lbl_27_bss_75D4[], lbl_27_bss_75E4[];
extern char lbl_27_bss_75F4[], lbl_27_bss_7604[];
extern float lbl_94_rodata_0, lbl_94_rodata_4;
}
struct BuildVTable {
    virtual int f0(); virtual int f1(); virtual u8 f2(); virtual int f3();
    virtual int f4(); virtual int f5(); virtual int f6(); virtual int f7();
    virtual int f8(); virtual int f9(); virtual int f10(); virtual int f11();
    virtual int f12(); virtual int f13(); virtual int f14(); virtual int f15();
    virtual int f16(); virtual int f17(); virtual int f18(); virtual int f19();
    virtual int f20(); virtual int f21(); virtual int f22(); virtual int f23();
    virtual int f24(); virtual int f25(); virtual int f26();
    virtual Heaps::HeapType f27();
    virtual Heaps::HeapType f28();
    virtual Heaps::HeapType f29();
    virtual long f30();
    virtual int f31(); virtual float f32(); virtual int f33();
    virtual void* f34(int, int);
};
struct HeapV {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual s16 f7();
};
struct InitialEvent { virtual int isNull(); };
struct InitialEventList {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void add(int, void*);
};
struct EventManager {
    virtual void f0();
    virtual void add(void**, s16*);
};
struct ActionModule {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
    virtual void f32(); virtual void setData(void*);
};
struct ParamModule {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void setData(void*);
};
struct FighterInit {
    virtual void f0();
    virtual void init(void*);
};
struct FinalModule {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void setModules(void**, int);
};
class SlopeStorage {
public:
    SlopeStorage(void* accesser, u8 initial, int count, f32 limit) {
        fn_27_ACAC4(this, accesser, initial, count, initial, limit);
    }
};

class ShadowStorage {
public:
    ShadowStorage(void* accesser, s32 mode, const f32* opacity) {
        fn_27_B62E4(this, accesser, *opacity, mode);
    }
};

class ColorBlendStorage {
public:
    ColorBlendStorage(void* accesser, s32 count, s32 enabled) {
        fn_27_BEBB4(this, accesser, count, enabled);
    }
};

class JostleStorage {
public:
    JostleStorage(void* accesser, s32 id, s32 count, s32 data) {
        fn_27_C20D8(this, accesser, id, count, data);
    }
};

#define b (reinterpret_cast<BuildVTable*>(frame.build))
#define INIT_EVENT(index, offset, eventBits, resourceCount) \
    do { \
        b->f34(index, 2); \
        b->f34(index, 1); \
        void* eventData = b->f34(index, 0); \
        char* event = root + (offset); \
        fn_27_C7744(event, eventData, resourceCount); \
        fn_27_D22D0(event + 0x14, 0); \
        fn_94_8C70(event + 0xc0, event, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        frame.events.flags[index] = 0; \
        s16 eventValue = reinterpret_cast<HeapV*>( \
            *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x80) + 8)->f7(); \
        fn_94_8C8C(event + 0xdc, eventValue, event + 0x14, index, 1, \
                    lbl_94_rodata_4, &frame.events.flags[index]); \
        frame.events.ids[index] = eventBits; \
        frame.events.pairs[2 * index] = event + 0xdc; \
        frame.events.pairs[2 * index + 1] = event + 0xc0; \
        reinterpret_cast<EventManager*>( \
            *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x6c)) \
            ->add(&frame.events.pairs[2 * index], &frame.events.ids[index]); \
    } while (0)
template<char* Table>
class ActionListenerStorage {
public:
    ActionListenerStorage(void* accesser) {
        fn_27_17437C(this, accesser);
        *reinterpret_cast<char**>(this) = Table;
        *reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 4) = Table + 0x40;
    }
};

struct LocalFrame {
    union {
        char scratch[0x7c];
        struct {
            s8 flags[12];
            s16 ids[12];
            void* pairs[22];
        } events;
    };
    u32 build[0x30 / sizeof(u32)];
    void* modules[27];
};
#pragma always_inline on
inline void constructArea(void* object, void* accesser, int category, void* config) {
    fn_94_8AFC(object, accesser, static_cast<u8>(category), config);
}
inline void initModel(char* m, LocalFrame& frame) {
    int v68 = b->f24();
    b->f18();
    fn_94_70BC(m + 0x11bc, m + 0xa0c, v68, lbl_27_bss_A48);
}
inline void initBase(void* self, s32 entryId, Heaps::HeapType instHeap,
                     Heaps::HeapType modelHeap, Heaps::HeapType motionHeap,
                     LocalFrame& frame) {
    char* m;
    char* p = static_cast<char*>(self);
    fn_27_1257EC(self, entryId, 3, instHeap, p + 0xba0);
    char* data = lbl_94_data_528;
    *reinterpret_cast<char**>(p + 0x3c) = data;
    *reinterpret_cast<char**>(p + 0x40) = data + 0x64;
    *reinterpret_cast<char**>(p + 0x48) = data + 0x70;
    *reinterpret_cast<char**>(p + 0x54) = data + 0x84;
    *reinterpret_cast<char**>(p + 0x64) = data + 0xdc;
    *reinterpret_cast<char**>(p + 0x70) = data + 0xec;
    *reinterpret_cast<char**>(p + 0x7c) = data + 0xfc;
    *reinterpret_cast<char**>(p + 0x88) = data + 0x110;
    *reinterpret_cast<char**>(p + 0x94) = data + 0x128;
    *reinterpret_cast<char**>(p + 0xa0) = data + 0x140;
    *reinterpret_cast<char**>(p + 0xac) = data + 0x158;
    *reinterpret_cast<char**>(p + 0xb8) = data + 0x16c;
    *reinterpret_cast<char**>(p + 0xc4) = data + 0x180;
    *reinterpret_cast<char**>(p + 0xd0) = data + 0x190;
    *reinterpret_cast<char**>(p + 0xdc) = data + 0x1c4;
    *reinterpret_cast<char**>(p + 0xe8) = data + 0x1d4;
    *reinterpret_cast<char**>(p + 0xf4) = data + 0x1e8;
    *reinterpret_cast<char**>(p + 0x100) = data + 0x254;

    __ct__18ftFighterBuildDataFl6ftKindQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypeUcP16soModuleAccesserlPvPv(
        frame.build, entryId, static_cast<ftKind>(3), instHeap, modelHeap, motionHeap,
        0, *reinterpret_cast<soModuleAccesser**>(p + 0x60), -1,
        p + 0x25be8, p + 0x25bf0);
    m = p + 0x194;
    fn_94_6D00(m);
    __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(
        reinterpret_cast<soModuleAccesser*>(m + 0xa0c),
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(m + 0x11a4),
        reinterpret_cast<soModelModule*>(m + 0x13b0),
        reinterpret_cast<soMotionModule*>(m + 0x16a0),
        reinterpret_cast<soPostureModule*>(m + 0x184c),
        reinterpret_cast<soGroundModule*>(m + 0x1914),
        reinterpret_cast<soSituationModule*>(m + 0x196c),
        m + 0x19d8,
        reinterpret_cast<soCollisionAttackModule*>(m + 0x2038),
        reinterpret_cast<soCollisionHitModule*>(m + 0x29cc),
        reinterpret_cast<soCollisionShieldModule*>(m + 0x2bf8),
        reinterpret_cast<soCollisionShieldModule*>(m + 0x3660),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        m + 0x3834,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(m + 0x39c8),
        m + 0x3acc,
        m + 0x3b30,
        reinterpret_cast<soStopModule*>(m + 0x3b64),
        m + 0x3b88,
        m + 0x3c3c,
        reinterpret_cast<soSoundModule*>(m + 0x3c6c),
        reinterpret_cast<soLinkModule*>(m + 0x3e0c),
        reinterpret_cast<soVisibilityModule*>(m + 0x3e60),
        reinterpret_cast<soControllerModule*>(m + 0x4448),
        reinterpret_cast<soCameraModule*>(m + 0x4604),
        reinterpret_cast<soWorkManageModule*>(m + 0x4628),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(m + 0x465c),
        reinterpret_cast<soStatusModule*>(m + 0x5554),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(m + 0x5604),
        reinterpret_cast<soEventManageModule*>(m + 0xb8),
        m + 0x23288,
        reinterpret_cast<soEffectModule*>(m + 0x23330),
        m + 0x23468,
        reinterpret_cast<soAreaModule*>(m + 0x234a8),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        m + 0x23888,
        m + 0x238d0,
        reinterpret_cast<soShadowModule*>(m + 0x23950),
        reinterpret_cast<soItemManageModule*>(m + 0x23a3c),
        reinterpret_cast<soColorBlendModule*>(m + 0x23aa8),
        m + 0x23bfc,
        m + 0x23c48,
        reinterpret_cast<soSlowModule*>(m + 0x23cb0),
        lbl_27_bss_69C,
        m + 0xaec,
        reinterpret_cast<soParamCustomizeModule*>(m + 0xb04),
        m + 0x23cec);
    const long entry = b->f30();
    const Heaps::HeapType motion = b->f29();
    const Heaps::HeapType model = b->f28();
    __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(
        m + 0xaec, b->f27(), model, motion, entry);
    fn_27_14B5F8(m + 0xb04, m + 0xa0c);
    fn_94_7054(m + 0x1198, b->f0(), b->f1(), b->f2(), m + 0xa0c);
    initModel(m, frame);
    fn_94_7144(m + 0x147c, m + 0xa0c, b->f4());
    fn_94_7318(m + 0x1810, m + 0xa0c, lbl_27_bss_A48);
    fn_94_7388(m + 0x18c4, m + 0xa0c, b->f8());
    s16 value = reinterpret_cast<HeapV*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x80) + 8)->f7();
    fn_27_3513C(m + 0x196c, value, m + 0xa0c, lbl_27_bss_A48);
    fn_94_6C34(m + 0x19a8, b->f3(), m + 0xa0c);
    fn_94_73EC(m + 0x1a1c, m + 0xa0c, *reinterpret_cast<s32*>(p + 0x28),
               static_cast<u8>(*reinterpret_cast<u32*>(p + 0x2c) >> 7), lbl_27_bss_A48);
    fn_94_74B0(m + 0x20d8, m + 0xa0c, *reinterpret_cast<s32*>(p + 0x28),
               static_cast<u8>(*reinterpret_cast<u32*>(p + 0x2c) >> 7), lbl_27_bss_A48);
    fn_94_7574(m + 0x2a34, m + 0xa0c, *reinterpret_cast<s32*>(p + 0x28),
               static_cast<u8>(*reinterpret_cast<u32*>(p + 0x2c) >> 7));
    fn_94_7648(m + 0x2c4c, m + 0xa0c, *reinterpret_cast<s32*>(p + 0x28),
               static_cast<u8>(*reinterpret_cast<u32*>(p + 0x2c) >> 7));
    fn_94_771C(m + 0x36b8, m + 0xa0c, *reinterpret_cast<s32*>(p + 0x28),
               static_cast<u8>(*reinterpret_cast<u32*>(p + 0x2c) >> 7), lbl_27_bss_A48);
    fn_94_77B4(m + 0x391c, m + 0xa0c, lbl_27_bss_A48);
    fn_27_64C8C(m + 0x3acc, m + 0xa0c, 1);
    fn_27_65EE4(m + 0x3b30, m + 0xa0c);
    fn_27_154088(m + 0x3b64, m + 0xa0c);
    fn_27_693F4(m + 0x3b88, m + 0xa0c);
    fn_94_7820(m + 0x3bc0, m + 0xa0c, b->f5());
    fn_94_787C(m + 0x3c58, m + 0xa0c, b->f31(), lbl_27_bss_A48);
    fn_94_790C(m + 0x3cc8, m + 0xa0c);
    fn_27_5B248(m + 0x3e60, m + 0xa0c, b->f6(), 2);
    value = reinterpret_cast<HeapV*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x80) + 8)->f7();
    fn_94_7960(m + 0x3e90, m + 0xa0c, value);
    fn_94_79D0(m + 0x45b4, m + 0xa0c, b->f21(), b->f22(), lbl_27_bss_A48);
    fn_27_A1DA4(m + 0x4628, m + 0xa0c, b->f19());
    value = reinterpret_cast<HeapV*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x80) + 8)->f7();
    fn_94_7A3C(m + 0x465c, value);
    fn_94_7A80(m + 0x4750, m + 0xa0c, b->f7(), b->f26());
    fn_94_7F38(m + 0x5604, m + 0xa0c);
    fn_94_8308(m + 0x590c);
    fn_94_8368(m + 0x5af0, m + 0xa0c);
    fn_94_8A30(m + 0x232c4, m + 0xa0c, b->f9(), b->f10(),
               b->f11(), b->f12(), lbl_27_bss_A48);
    fn_27_14FBD8(m + 0x23468, m + 0xa0c);
    constructArea(m + 0x23498, m + 0xa0c, b->f20(), lbl_27_bss_A48);
    b->f14(); b->f13(); b->f15();
    fn_94_8B94(m + 0x2380c, m + 0xa0c, b->f16());
    new (m + 0x238d0) SlopeStorage(m + 0xa0c, 0, 1, b->f32());
    new (m + 0x23950) ShadowStorage(m + 0xa0c, 0, &lbl_94_rodata_0);
    fn_94_8BF4(m + 0x23998, m + 0xa0c, b->f23());
    new (m + 0x23aa8) ColorBlendStorage(m + 0xa0c, 10, 1);
    new (m + 0x23bfc) JostleStorage(m + 0xa0c, 0, 8, b->f25());
    fn_27_196664(m + 0x23c48, m + 0xa0c);
    fn_27_5BED0(m + 0x23cb0, m + 0xa0c);
    fn_27_14CCEC(m + 0x23cec, m + 0xa0c);
    if (reinterpret_cast<InitialEvent*>(m + 0x5acc)->isNull() == 0) {
        reinterpret_cast<InitialEventList*>(
            *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x64))
            ->add(1, m + 0x5acc);
    }
    fn_27_C74BC(m + 0x23e6c,
        *reinterpret_cast<void**>(*reinterpret_cast<char**>(
            reinterpret_cast<char*>(frame.build) + 0xc) + 0x18), 0x1b);
    char* root = m + 0x23e7c;
    fn_27_1A67D4(root, 0);
    fn_27_1A67D4(root + 0x4c0, 0);
    fn_27_D22D0(root + 0x984, 0);
    fn_94_8C70(root + 0xa30, root, root + 0x4c0, fn_94_8E1C());
    frame.events.flags[0] = 0;
    value = reinterpret_cast<HeapV*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x80) + 8)->f7();
    fn_94_8C8C(root + 0xa4c, value, root + 0x984, 0, 1, lbl_94_rodata_4, &frame.events.flags[0]);
    fn_94_8E8C(root, 0, 0x12d);
    fn_94_8E8C(root + 0x4c0, 0, 0x12d);
    fn_94_8E8C(fn_94_8E1C(), 0, 0);
    frame.events.ids[0] = 1;
    frame.events.pairs[0] = root + 0xa4c;
    frame.events.pairs[1] = root + 0xa30;
    reinterpret_cast<EventManager*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x6c))
        ->add(&frame.events.pairs[0], &frame.events.ids[0]);
    INIT_EVENT(1, 0xa9c, 2, 0x1ec);
    INIT_EVENT(2, 0xbc8, 0x40, 0x1ec);
    INIT_EVENT(3, 0xcf4, 0x40, 0x1ec);
    INIT_EVENT(4, 0xe20, 2, 0x1ec);
    INIT_EVENT(5, 0xf4c, 0x20, 0x1ec);
    INIT_EVENT(6, 0x1078, 0x80, 0x1ec);
    INIT_EVENT(7, 0x11a4, 0x80, 0x1ec);
    INIT_EVENT(8, 0x12d0, 0x20, 0x1ec);
    char* event9 = root + 0x13fc;
    frame.events.flags[9] = 1;
    value = reinterpret_cast<HeapV*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x80) + 8)->f7();
    fn_94_8C8C(event9, value, event9 + 0x50, 9, 1, lbl_94_rodata_4, &frame.events.flags[9]);
    fn_27_1A079C(event9 + 0x50, 0);
    frame.events.ids[9] = 4;
    frame.events.pairs[18] = event9;
    frame.events.pairs[19] = lbl_27_bss_8C4;
    reinterpret_cast<EventManager*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x6c))
        ->add(&frame.events.pairs[18], &frame.events.ids[9]);
    INIT_EVENT(10, 0x1520, 0x10, 0x29);
    void* anim0 = b->f34(0, 0);
    fn_94_8E8C(fn_94_8F08(root, 0), anim0, 0x112);
    void* anim1 = b->f34(0, 1);
    fn_94_8E8C(fn_94_8F08(root, 1), anim1, 0x112);
    fn_94_8E8C(fn_94_8F08(root, 0),
        *reinterpret_cast<void**>(*reinterpret_cast<char**>(
            reinterpret_cast<char*>(frame.build) + 0xc) + 0x24), 0x1b);
    fn_94_8E8C(fn_94_8F08(root, 1),
        *reinterpret_cast<void**>(*reinterpret_cast<char**>(
            reinterpret_cast<char*>(frame.build) + 0xc) + 0x28), 0x1b);
    fn_94_8F44(root, 0,
        reinterpret_cast<ftFighterBuildData*>(frame.build)->getAnimCmdDisguiseList(false, 0));
    fn_94_8F44(root, 1,
        reinterpret_cast<ftFighterBuildData*>(frame.build)->getAnimCmdDisguiseList(false, 1));
    reinterpret_cast<ActionModule*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x70))
        ->setData(m + 0x23e6c);
    void* param = soValueAccesser::getConstantIndefinite(
        reinterpret_cast<soModuleAccesser*>(m + 0xa0c), 0xa805, 0);
    void* paramModule = *reinterpret_cast<void**>(
        *reinterpret_cast<char**>(m + 0xae4) + 0x90);
    void* derived = __dynamic_cast(paramModule, 0, lbl_94_data_43C0,
                                   lbl_94_data_4468, 0);
    if (derived != 0) {
        fn_27_14E0B8(derived, param);
    }
    reinterpret_cast<ParamModule*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(m + 0xae4) + 0x90))
        ->setData(param);
    fn_27_1404D4(p + 0x2565c, *reinterpret_cast<void**>(p + 0x60));
    param = p + 0x25698;
    fn_94_6C20(param, 0);
    *reinterpret_cast<char**>(param) = lbl_94_data_4238;
    m = *reinterpret_cast<char**>(p + 0x60);
    char* listeners = p + 0x25b50;
    fn_94_6C20(listeners, 0);
    *reinterpret_cast<char**>(listeners) = lbl_94_data_42B8;
    char* leaf0 = listeners + 0x08;
    fn_27_17437C(leaf0, m);
    *reinterpret_cast<char**>(leaf0) = lbl_27_data_2F9F8;
    *reinterpret_cast<char**>(static_cast<char*>(leaf0) + 4) = lbl_27_data_2F9F8 + 0x40;
    char* leaf1 = listeners + 0x20;
    fn_27_17437C(leaf1, m);
    *reinterpret_cast<char**>(leaf1) = lbl_27_data_2FAA0;
    *reinterpret_cast<char**>(static_cast<char*>(leaf1) + 4) = lbl_27_data_2FAA0 + 0x40;
    char* leaf2 = listeners + 0x34;
    fn_27_17437C(leaf2, m);
    *reinterpret_cast<char**>(leaf2) = lbl_27_data_2FB48;
    *reinterpret_cast<char**>(static_cast<char*>(leaf2) + 4) = lbl_27_data_2FB48 + 0x40;
    char* leaf3 = listeners + 0x48;
    fn_27_17437C(leaf3, m);
    *reinterpret_cast<char**>(leaf3) = lbl_27_data_2FBF0;
    *reinterpret_cast<char**>(static_cast<char*>(leaf3) + 4) = lbl_27_data_2FBF0 + 0x40;
    char* leaf4 = listeners + 0x5c;
    fn_27_17437C(leaf4, m);
    *reinterpret_cast<char**>(leaf4) = lbl_27_data_2FC98;
    *reinterpret_cast<char**>(static_cast<char*>(leaf4) + 4) = lbl_27_data_2FC98 + 0x40;
    char* leaf5 = listeners + 0x70;
    fn_27_17437C(leaf5, m);
    *reinterpret_cast<char**>(leaf5) = lbl_27_data_2FD40;
    *reinterpret_cast<char**>(static_cast<char*>(leaf5) + 4) = lbl_27_data_2FD40 + 0x40;
    char* leaf6 = listeners + 0x84;
    fn_27_17437C(leaf6, m);
    *reinterpret_cast<char**>(leaf6) = lbl_27_data_2FDE8;
    *reinterpret_cast<char**>(static_cast<char*>(leaf6) + 4) = lbl_27_data_2FDE8 + 0x40;
    *reinterpret_cast<void**>(p + 0x25be8) =
        soValueAccesser::getConstantIndefinite(
            *reinterpret_cast<soModuleAccesser**>(p + 0x60), 0xa7f9, 0);
    *reinterpret_cast<s32*>(p + 0x25bec) = 1;
    *reinterpret_cast<void**>(p + 0x25bf0) =
        soValueAccesser::getConstantIndefinite(
            *reinterpret_cast<soModuleAccesser**>(p + 0x60), 0xa7fc, 0);
    *reinterpret_cast<s32*>(p + 0x25bf4) = 1;
    fn_27_126470(self);
    reinterpret_cast<FighterInit*>(p + 0x2565c)->init(
        *reinterpret_cast<void**>(p + 0x60));
}
#pragma always_inline reset

extern "C" void* fn_94_70(void* self, s32 entryId,
                           Heaps::HeapType instHeap,
                           Heaps::HeapType modelHeap,
                           Heaps::HeapType motionHeap) {
    LocalFrame frame;
    initBase(self, entryId, instHeap, modelHeap, motionHeap, frame);
    char* p = static_cast<char*>(self);
    char* data = lbl_94_data_44;
    *reinterpret_cast<char**>(p + 0x3c) = data;
    *reinterpret_cast<char**>(p + 0x40) = data + 0x64;
    *reinterpret_cast<char**>(p + 0x48) = data + 0x70;
    *reinterpret_cast<char**>(p + 0x54) = data + 0x84;
    *reinterpret_cast<char**>(p + 0x64) = data + 0xdc;
    *reinterpret_cast<char**>(p + 0x70) = data + 0xec;
    *reinterpret_cast<char**>(p + 0x7c) = data + 0xfc;
    *reinterpret_cast<char**>(p + 0x88) = data + 0x110;
    *reinterpret_cast<char**>(p + 0x94) = data + 0x128;
    *reinterpret_cast<char**>(p + 0xa0) = data + 0x140;
    *reinterpret_cast<char**>(p + 0xac) = data + 0x158;
    *reinterpret_cast<char**>(p + 0xb8) = data + 0x16c;
    *reinterpret_cast<char**>(p + 0xc4) = data + 0x180;
    *reinterpret_cast<char**>(p + 0xd0) = data + 0x190;
    *reinterpret_cast<char**>(p + 0xdc) = data + 0x1c4;
    *reinterpret_cast<char**>(p + 0xe8) = data + 0x1d4;
    *reinterpret_cast<char**>(p + 0xf4) = data + 0x1e8;
    *reinterpret_cast<char**>(p + 0x100) = data + 0x254;
    fn_27_C749C(p + 0x25bf8);
    *reinterpret_cast<ftData**>(p + 0x25c08) =
        g_ftCommonDataAccesser.getData(static_cast<ftKind>(3));
    typedef void* StatusPointer;
    new (frame.modules) StatusPointer[27]();
    frame.modules[1] = lbl_94_bss_1FC;
    frame.modules[2] = lbl_94_bss_1CC;
    frame.modules[4] = lbl_94_bss_20C;
    frame.modules[5] = lbl_27_bss_75C4;
    frame.modules[6] = lbl_27_bss_75E4;
    frame.modules[8] = lbl_27_bss_75F4;
    frame.modules[9] = lbl_27_bss_75D4;
    frame.modules[10] = lbl_27_bss_7604;
    frame.modules[11] = lbl_94_bss_1DC;
    frame.modules[12] = lbl_94_bss_1EC;
    frame.modules[14] = lbl_94_bss_1DC;
    frame.modules[15] = lbl_94_bss_1EC;
    frame.modules[16] = lbl_94_bss_1FC;
    frame.modules[17] = lbl_94_bss_1FC;
    frame.modules[18] = lbl_94_bss_1FC;
    frame.modules[19] = lbl_94_bss_1FC;
    frame.modules[21] = lbl_94_bss_20C;
    frame.modules[22] = lbl_94_bss_20C;
    frame.modules[23] = lbl_94_bss_20C;
    frame.modules[24] = lbl_94_bss_20C;
    frame.modules[25] = lbl_94_bss_20C;
    frame.modules[26] = lbl_94_bss_20C;
    reinterpret_cast<FinalModule*>(
        *reinterpret_cast<char**>(
            *reinterpret_cast<char**>(
                *reinterpret_cast<char**>(p + 0x60) + 0xd8) + 0x70))
        ->setModules(frame.modules, 0x1b);
    return self;
}
#undef b
