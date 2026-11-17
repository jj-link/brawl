#pragma use_simple_stdpnew on
#include <new>
#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#pragma force_active on

typedef unsigned char Byte;
class PikachuEventStorage { public: PikachuEventStorage(); };
struct Big { Byte flags[12]; short values[11]; void* ptrs[22]; };
struct Small { Byte bo[0x30]; void* arrC[14]; };

#pragma always_inline on
static inline Byte* pAt(void* base, int offset) {
    return *reinterpret_cast<Byte**>(static_cast<Byte*>(base) + offset);
}
class PikachuBuildDataView : public soModuleAccesserBuildData {
public:
    virtual void* getEffectNodeData() const = 0;
    virtual soEffectScreenData* getEffectScreenData() const = 0;
    virtual void* getTerritoryParam() const = 0;
    virtual s32* getTerritoryRect() const = 0;
    virtual void* getTargetSearchParam() const = 0;
    virtual soIkData* getIkData() const = 0;
    virtual float getModelScale() const = 0;
    virtual void* getModelExtendNodeTable() const = 0;
    virtual soPreCheckAnimCmdData* getPreCheckAnimCmdData() const = 0;
    virtual s32 getHeapSlotNo() const = 0;
    virtual soSoundIdExchanger* getSoundIdExchanger() const = 0;
    virtual float getSlopeAngleLimit() const = 0;
};
static inline PikachuBuildDataView* bdOf(void* p) {
    return reinterpret_cast<PikachuBuildDataView*>(p);
}
class NullableObj { public: virtual int isNull(); };
class Receiver {
public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void add(int, void*);
};
class Registry { public: virtual void v0(); virtual void insert(void*, void*); };
class ListSink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void set(void*, int);
};
class LongSink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void set(void*);
};
class ValueSink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void set(void*);
};
class CallOne { public: virtual void v0(); virtual void apply(void*); };
class ShortGetter {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual short get();
};
static inline short subShort24(Byte* ev) {
    ShortGetter* x = reinterpret_cast<ShortGetter*>(pAt(pAt(ev, 0xAA8), 0x80) + 8);
    return x->get();
}
extern "C" {
extern Byte lbl_98_data_608[];
extern Byte lbl_98_data_120[];
extern Byte lbl_98_data_2300[];
extern Byte lbl_98_data_23A8[];
extern Byte lbl_98_data_2178[];
extern Byte lbl_98_data_21F8[];
extern Byte lbl_27_data_2F9F8[];
extern Byte lbl_27_data_2FAA0[];
extern Byte lbl_27_data_2FB48[];
extern Byte lbl_27_data_2FBF0[];
extern Byte lbl_27_data_2FC98[];
extern Byte lbl_27_data_2FD40[];
extern Byte lbl_27_data_2FDE8[];
extern Byte lbl_27_bss_A48[];
extern Byte lbl_27_bss_D8C[];
extern Byte lbl_27_bss_8C4[];
extern Byte lbl_27_bss_7C64[];
extern Byte lbl_27_bss_3AC[];
extern Byte lbl_27_bss_3CC[];
extern Byte lbl_27_bss_4BC[];
extern Byte lbl_27_bss_46C0[];
extern Byte lbl_27_bss_46D8[];
extern Byte lbl_27_bss_5B0[];
extern Byte lbl_27_bss_5D8[];
extern Byte lbl_27_bss_69C[];
extern Byte lbl_98_bss_22C[];
extern Byte lbl_98_bss_23C[];
extern Byte lbl_98_bss_24C[];
extern Byte lbl_98_bss_25C[];
extern Byte lbl_98_bss_26C[];
extern Byte lbl_98_bss_27C[];
extern Byte lbl_98_bss_28C[];
extern Byte lbl_98_bss_29C[];
extern Byte lbl_98_bss_2AC[];
extern Byte lbl_98_bss_2BC[];
extern Byte lbl_98_bss_2CC[];
extern Byte lbl_98_bss_2DC[];
extern Byte lbl_98_bss_2EC[];
extern const float lbl_98_rodata_0;
extern const float lbl_98_rodata_4;
void fn_27_1257EC(void*, int, int, int, void*);
void fn_98_77A8(void*, unsigned int, unsigned int, unsigned char, void*);
void fn_98_7810(void*, void*, float, void*, void*);
void fn_98_7898(void*, void*, void*);
void fn_98_7A6C(void*, void*, void*);
void fn_98_7ADC(void*, void*, void*);
void fn_27_3513C(void*, short, void*, void*);
void fn_98_7388(void*, int, void*);
void fn_98_7B40(void*, void*, int, unsigned int, void*);
void fn_98_7C04(void*, void*, int, unsigned int, void*);
void fn_98_7CC8(void*, void*, int, unsigned int);
void fn_98_7D9C(void*, void*, int, unsigned int);
void fn_98_7E70(void*, void*, int, unsigned int, void*);
void fn_98_7F08(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_98_7F74(void*, void*, void*);
void fn_98_7FD0(void*, void*, void*, void*);
void fn_98_8060(void*, void*);
void fn_27_5B248(void*, void*, void*, int);
void fn_98_80B4(void*, void*, short);
void fn_98_8124(void*, void*, void*, void*, void*);
void fn_27_A1DA4(void*, void*, void*);
void fn_98_8190(void*, short);
void fn_98_81D4(void*, void*, void*, void*);
void fn_98_868C(void*, void*);
void fn_98_8A5C(void*);
void fn_98_8ABC(void*, void*);
void fn_98_8E8C(void*, void*, void*, void*, void*, void*, void*);
void fn_27_14FBD8(void*, void*);
void fn_98_8F58(void*, void*, unsigned char, void*);
void fn_98_8FF0(void*, void*, void*);
void fn_27_ACAC4(void*, void*, int, int, bool, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_98_9050(void*, void*, void*);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, void*);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A60B8(void*, int);
void fn_27_D22D0(void*, int);
void* fn_98_9278();
void fn_98_90CC(void*, void*, void*, void*);
void fn_98_90E8(void*, short, void*, int, int, float, unsigned char*);
void fn_98_92E8(void*, void*, int);
void* fn_98_9364(void*, int);
void fn_98_93A0(void*, int, void*);
void fn_27_C7744(void*, void*, int);
void fn_27_1A079C(void*, int);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_98_7374(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void fn_27_14B5F8(void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
class PikachuSlopeStorage {
public:
    PikachuSlopeStorage(void* acc, int a, int b, bool flag, float angle) {
        fn_27_ACAC4(this, acc, a, b, flag, angle);
    }
};
class PikachuShadowStorage {
public:
    PikachuShadowStorage(void* acc, int value, float scale) {
        fn_27_B62E4(this, acc, scale, value);
    }
};

class PikachuColorStorage {
public:
    PikachuColorStorage(void* acc, int count, int flag) {
        fn_27_BEBB4(this, acc, count, flag);
    }
};

class PikachuJostleStorage {
public:
    PikachuJostleStorage(void* acc, int value, int count, void* data) {
        fn_27_C20D8(this, acc, value, count, data);
    }
};

template <Byte* Table>
class PikachuActionLeafStorage {
public:
    PikachuActionLeafStorage(void* acc) {
        fn_27_17437C(this, acc);
        *reinterpret_cast<Byte**>(this) = Table;
        *reinterpret_cast<Byte**>(reinterpret_cast<Byte*>(this) + 4) = Table + 0x40;
    }
};
class PikachuStateStorage {
public:
    PikachuStateStorage() {
        fn_98_7374(this, 0);
        *reinterpret_cast<Byte**>(this) = lbl_98_data_2178;
    }
};
class PikachuActionStorage {
public:
    PikachuActionStorage(void* acc) {
        fn_98_7374(this, 0);
        *reinterpret_cast<Byte**>(this) = lbl_98_data_21F8;
        new (reinterpret_cast<Byte*>(this) + 0x8) PikachuActionLeafStorage<lbl_27_data_2F9F8>(acc);
        new (reinterpret_cast<Byte*>(this) + 0x20) PikachuActionLeafStorage<lbl_27_data_2FAA0>(acc);
        new (reinterpret_cast<Byte*>(this) + 0x34) PikachuActionLeafStorage<lbl_27_data_2FB48>(acc);
        new (reinterpret_cast<Byte*>(this) + 0x48) PikachuActionLeafStorage<lbl_27_data_2FBF0>(acc);
        new (reinterpret_cast<Byte*>(this) + 0x5C) PikachuActionLeafStorage<lbl_27_data_2FC98>(acc);
        new (reinterpret_cast<Byte*>(this) + 0x70) PikachuActionLeafStorage<lbl_27_data_2FD40>(acc);
        new (reinterpret_cast<Byte*>(this) + 0x84) PikachuActionLeafStorage<lbl_27_data_2FDE8>(acc);
    }
};

extern "C" void* fn_98_70(Byte* self, int a, int b, int c, int d)
{
    Small sm;
    Big bg;
    Byte* r26;
    Byte* ev;
    Byte* q10;
    void* q00;
    void* q01;
    void* r23c;
    fn_27_1257EC(self, a, 7, b, self + 0xB64);
    *(Byte**)(self + 0x3C) = lbl_98_data_608;
    *(Byte**)(self + 0x40) = lbl_98_data_608 + 0x64;
    *(Byte**)(self + 0x48) = lbl_98_data_608 + 0x70;
    *(Byte**)(self + 0x54) = lbl_98_data_608 + 0x84;
    *(Byte**)(self + 0x64) = lbl_98_data_608 + 0xDC;
    *(Byte**)(self + 0x70) = lbl_98_data_608 + 0xEC;
    *(Byte**)(self + 0x7C) = lbl_98_data_608 + 0xFC;
    *(Byte**)(self + 0x88) = lbl_98_data_608 + 0x110;
    *(Byte**)(self + 0x94) = lbl_98_data_608 + 0x128;
    *(Byte**)(self + 0xA0) = lbl_98_data_608 + 0x140;
    *(Byte**)(self + 0xAC) = lbl_98_data_608 + 0x158;
    *(Byte**)(self + 0xB8) = lbl_98_data_608 + 0x16C;
    *(Byte**)(self + 0xC4) = lbl_98_data_608 + 0x180;
    *(Byte**)(self + 0xD0) = lbl_98_data_608 + 0x190;
    *(Byte**)(self + 0xDC) = lbl_98_data_608 + 0x1C4;
    *(Byte**)(self + 0xE8) = lbl_98_data_608 + 0x1D4;
    *(Byte**)(self + 0xF4) = lbl_98_data_608 + 0x1E8;
    *(Byte**)(self + 0x100) = lbl_98_data_608 + 0x254;
    new (sm.bo) ftFighterBuildData(
        a, static_cast<ftKind>(7), static_cast<Heaps::HeapType>(b),
        static_cast<Heaps::HeapType>(c), static_cast<Heaps::HeapType>(d),
        0, reinterpret_cast<soModuleAccesser*>(pAt(self, 0x60)), -1,
        self + 0x2AE24, self + 0x2AE2C);
    ev = self + 0x194;
    new (ev) PikachuEventStorage();
    new (ev + 0x9D0) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(ev + 0x1168),
        reinterpret_cast<soModelModule*>(ev + 0x1374),
        reinterpret_cast<soMotionModule*>(ev + 0x1664),
        reinterpret_cast<soPostureModule*>(ev + 0x1810),
        reinterpret_cast<soGroundModule*>(ev + 0x18D8),
        reinterpret_cast<soSituationModule*>(ev + 0x1930),
        ev + 0x199C,
        reinterpret_cast<soCollisionAttackModule*>(ev + 0x1FFC),
        reinterpret_cast<soCollisionHitModule*>(ev + 0x2990),
        reinterpret_cast<soCollisionShieldModule*>(ev + 0x2BBC),
        reinterpret_cast<soCollisionShieldModule*>(ev + 0x3624),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        ev + 0x37F8,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(ev + 0x398C),
        ev + 0x3A90, ev + 0x3AF4,
        reinterpret_cast<soStopModule*>(ev + 0x3B28),
        ev + 0x3B4C, ev + 0x3C00,
        reinterpret_cast<soSoundModule*>(ev + 0x3C30),
        reinterpret_cast<soLinkModule*>(ev + 0x3DD0),
        reinterpret_cast<soVisibilityModule*>(ev + 0x3E24),
        reinterpret_cast<soControllerModule*>(ev + 0x440C),
        reinterpret_cast<soCameraModule*>(ev + 0x45C8),
        reinterpret_cast<soWorkManageModule*>(ev + 0x45EC),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(ev + 0x4620),
        reinterpret_cast<soStatusModule*>(ev + 0x54E4),
        lbl_27_bss_46C0, lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(ev + 0x5594),
        reinterpret_cast<soEventManageModule*>(ev + 0xB8),
        ev + 0x2852C,
        reinterpret_cast<soEffectModule*>(ev + 0x285D4),
        ev + 0x2870C,
        reinterpret_cast<soAreaModule*>(ev + 0x2874C),
        lbl_27_bss_5B0, lbl_27_bss_5D8, ev + 0x28B2C, ev + 0x28B74,
        reinterpret_cast<soShadowModule*>(ev + 0x28BF4),
        reinterpret_cast<soItemManageModule*>(ev + 0x28CE0),
        reinterpret_cast<soColorBlendModule*>(ev + 0x28D4C),
        ev + 0x28EA0, ev + 0x28EEC,
        reinterpret_cast<soSlowModule*>(ev + 0x28F54),
        lbl_27_bss_69C, ev + 0xAB0,
        reinterpret_cast<soParamCustomizeModule*>(ev + 0xAC8),
        ev + 0x28F90);
    Byte* q8;
    long hSlot;
    Byte* q1;
    hSlot = bdOf(sm.bo)->getHeapSlotNo();
    q8 = reinterpret_cast<Byte*>(bdOf(sm.bo)->getNWMotionInstanceHeap());
    q1 = reinterpret_cast<Byte*>(bdOf(sm.bo)->getNWModelInstanceHeap());
    Heaps::HeapType hInst = bdOf(sm.bo)->getInstanceHeap();
    new (ev + 0xAB0) soHeapModuleImpl(hInst, static_cast<Heaps::HeapType>(reinterpret_cast<long>(q1)), static_cast<Heaps::HeapType>(reinterpret_cast<long>(q8)), hSlot);
    fn_27_14B5F8(ev + 0xAC8, ev + 0x9D0);
    fn_98_77A8(ev + 0x115C, bdOf(sm.bo)->getMdlResId(),
                 bdOf(sm.bo)->getAnmResId(), bdOf(sm.bo)->getResGroupNo(), ev + 0x9D0);
    fn_98_7810(ev + 0x1180, ev + 0x9D0, bdOf(sm.bo)->getModelScale(),
                 bdOf(sm.bo)->getModelExtendNodeTable(), lbl_27_bss_A48);
    void* t18 = bdOf(sm.bo)->getMotionData();
    fn_98_7898(ev + 0x1440, ev + 0x9D0, t18);
    fn_98_7A6C(ev + 0x17D4, ev + 0x9D0, lbl_27_bss_A48);
    void* t28 = bdOf(sm.bo)->getGroundConditionChecker();
    fn_98_7ADC(ev + 0x1888, ev + 0x9D0, t28);
    short t24a = subShort24(ev);
    fn_27_3513C(ev + 0x1930, t24a, ev + 0x9D0, lbl_27_bss_A48);
    long t14 = bdOf(sm.bo)->getTeam();
    fn_98_7388(ev + 0x196C, t14, ev + 0x9D0);
    fn_98_7B40(ev + 0x19E0, ev + 0x9D0, *(int*)(self + 0x28), (*(unsigned int*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_98_7C04(ev + 0x209C, ev + 0x9D0, *(int*)(self + 0x28), (*(unsigned int*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_98_7CC8(ev + 0x29F8, ev + 0x9D0, *(int*)(self + 0x28), (*(unsigned int*)(self + 0x2C) >> 7) & 0xFF);
    fn_98_7D9C(ev + 0x2C10, ev + 0x9D0, *(int*)(self + 0x28), (*(unsigned int*)(self + 0x2C) >> 7) & 0xFF);
    fn_98_7E70(ev + 0x367C, ev + 0x9D0, *(int*)(self + 0x28), (*(unsigned int*)(self + 0x2C) >> 7) & 0xFF, lbl_27_bss_A48);
    fn_98_7F08(ev + 0x38E0, ev + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(ev + 0x3A90, ev + 0x9D0, 1);
    fn_27_65EE4(ev + 0x3AF4, ev + 0x9D0);
    fn_27_154088(ev + 0x3B28, ev + 0x9D0);
    fn_27_693F4(ev + 0x3B4C, ev + 0x9D0);
    void* t1c = bdOf(sm.bo)->getShakeData();
    fn_98_7F74(ev + 0x3B84, ev + 0x9D0, t1c);
    void* t84 = bdOf(sm.bo)->getSoundIdExchanger();
    fn_98_7FD0(ev + 0x3C1C, ev + 0x9D0, t84, lbl_27_bss_A48);
    fn_98_8060(ev + 0x3C8C, ev + 0x9D0);
    void* t20 = bdOf(sm.bo)->getVisibilityData();
    fn_27_5B248(ev + 0x3E24, ev + 0x9D0, t20, 2);
    short t24b = subShort24(ev);
    fn_98_80B4(ev + 0x3E54, ev + 0x9D0, t24b);
    fn_98_8124(ev + 0x4578, ev + 0x9D0, bdOf(sm.bo)->getCameraRangeSet(),
                 bdOf(sm.bo)->getCameraClipSphereSet(), lbl_27_bss_A48);
    void* t54 = bdOf(sm.bo)->getParamAccesser();
    fn_27_A1DA4(ev + 0x45EC, ev + 0x9D0, t54);
    short t24c = subShort24(ev);
    fn_98_8190(ev + 0x4620, t24c);
    fn_98_81D4(ev + 0x4714, ev + 0x9D0, bdOf(sm.bo)->getStatusData(),
                 bdOf(sm.bo)->getPreCheckAnimCmdData());
    fn_98_868C(ev + 0x5594, ev + 0x9D0);
    fn_98_8A5C(ev + 0x589C);
    fn_98_8ABC(ev + 0x5A80, ev + 0x9D0);
    fn_98_8E8C(ev + 0x28568, ev + 0x9D0, bdOf(sm.bo)->getEffectNodeData(),
                 bdOf(sm.bo)->getEffectEmitData(), bdOf(sm.bo)->getEffectCommonData(),
                 bdOf(sm.bo)->getEffectScreenData(), lbl_27_bss_A48);
    fn_27_14FBD8(ev + 0x2870C, ev + 0x9D0);
    long t58 = bdOf(sm.bo)->getAreaCategory();
    fn_98_8F58(ev + 0x2873C, ev + 0x9D0, static_cast<unsigned char>(t58), lbl_27_bss_A48);
    bdOf(sm.bo)->getTerritoryRect();
    bdOf(sm.bo)->getTerritoryParam();
    bdOf(sm.bo)->getTargetSearchParam();
    void* t48 = bdOf(sm.bo)->getIkData();
    fn_98_8FF0(ev + 0x28AB0, ev + 0x9D0, t48);
    new (ev + 0x28B74) PikachuSlopeStorage(ev + 0x9D0, 0, 1, false, bdOf(sm.bo)->getSlopeAngleLimit());
    new (ev + 0x28BF4) PikachuShadowStorage(ev + 0x9D0, 0, lbl_98_rodata_0);
    void* t64 = bdOf(sm.bo)->getItemNodeData();
    fn_98_9050(ev + 0x28C3C, ev + 0x9D0, t64);
    new (ev + 0x28D4C) PikachuColorStorage(ev + 0x9D0, 10, 1);
    void* t6c = bdOf(sm.bo)->getJostleData();
    new (ev + 0x28EA0) PikachuJostleStorage(ev + 0x9D0, 0, 8, t6c);
    fn_27_196664(ev + 0x28EEC, ev + 0x9D0);
    fn_27_5BED0(ev + 0x28F54, ev + 0x9D0);
    fn_27_14CCEC(ev + 0x28F90, ev + 0x9D0);
    if (reinterpret_cast<NullableObj*>(ev + 0x5A5C)->isNull() == 0) {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x64);
        reinterpret_cast<Receiver*>(o)->add(1, ev + 0x5A5C);
    }
    fn_27_C74BC(ev + 0x29110, *(void**)(*(Byte**)(sm.bo + 0xC) + 0x18), 0xE);
    r26 = ev + 0x29120;
    fn_27_1A60B8(r26, 0);
    fn_27_1A60B8(r26 + 0x48C, 0);
    fn_27_D22D0(r26 + 0x91C, 0);
    void* q9278 = fn_98_9278();
    fn_98_90CC(r26 + 0x9C8, r26, r26 + 0x48C, q9278);
    bg.flags[0] = 0;
    short tP = subShort24(ev);
    fn_98_90E8(r26 + 0x9E4, tP, r26 + 0x91C, 0, 1, lbl_98_rodata_4, &bg.flags[0]);
    fn_98_92E8(r26, 0, 0x120);
    fn_98_92E8(r26 + 0x48C, 0, 0x120);
    fn_98_92E8(fn_98_9278(), 0, 0);
    bg.values[0] = 1;
    bg.ptrs[0] = r26 + 0x9E4;
    bg.ptrs[1] = r26 + 0x9C8;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[0], &bg.values[0]);
    }
    bdOf(sm.bo)->getAnimCmdData(1, 2);
    bdOf(sm.bo)->getAnimCmdData(1, 1);
    void* a1 = bdOf(sm.bo)->getAnimCmdData(1, 0);
    q1 = r26 + 0xA34;
    fn_27_C7744(q1, a1, 0x1E6);
    fn_27_D22D0(q1 + 0x14, 0);
    fn_98_90CC(q1 + 0xC0, q1, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[1] = 0;
    short t1 = subShort24(ev);
    fn_98_90E8(q1 + 0xDC, t1, q1 + 0x14, 1, 1, lbl_98_rodata_4, &bg.flags[1]);
    bg.values[1] = 0x2;
    bg.ptrs[2] = q1 + 0xDC;
    bg.ptrs[3] = q1 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[2], &bg.values[1]);
    }
    bdOf(sm.bo)->getAnimCmdData(2, 2);
    bdOf(sm.bo)->getAnimCmdData(2, 1);
    void* a2 = bdOf(sm.bo)->getAnimCmdData(2, 0);
    Byte* q2 = r26 + 0xB60;
    fn_27_C7744(q2, a2, 0x1E6);
    fn_27_D22D0(q2 + 0x14, 0);
    fn_98_90CC(q2 + 0xC0, q2, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[2] = 0;
    short t2 = subShort24(ev);
    fn_98_90E8(q2 + 0xDC, t2, q2 + 0x14, 2, 1, lbl_98_rodata_4, &bg.flags[2]);
    bg.values[2] = 0x40;
    bg.ptrs[4] = q2 + 0xDC;
    bg.ptrs[5] = q2 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[4], &bg.values[2]);
    }
    bdOf(sm.bo)->getAnimCmdData(3, 2);
    bdOf(sm.bo)->getAnimCmdData(3, 1);
    void* a3 = bdOf(sm.bo)->getAnimCmdData(3, 0);
    Byte* q3 = r26 + 0xC8C;
    fn_27_C7744(q3, a3, 0x1E6);
    fn_27_D22D0(q3 + 0x14, 0);
    fn_98_90CC(q3 + 0xC0, q3, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[3] = 0;
    short t3 = subShort24(ev);
    fn_98_90E8(q3 + 0xDC, t3, q3 + 0x14, 3, 1, lbl_98_rodata_4, &bg.flags[3]);
    bg.values[3] = 0x40;
    bg.ptrs[6] = q3 + 0xDC;
    bg.ptrs[7] = q3 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[6], &bg.values[3]);
    }
    bdOf(sm.bo)->getAnimCmdData(4, 2);
    bdOf(sm.bo)->getAnimCmdData(4, 1);
    void* a4 = bdOf(sm.bo)->getAnimCmdData(4, 0);
    Byte* q4 = r26 + 0xDB8;
    fn_27_C7744(q4, a4, 0x1E6);
    fn_27_D22D0(q4 + 0x14, 0);
    fn_98_90CC(q4 + 0xC0, q4, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[4] = 0;
    short t4 = subShort24(ev);
    fn_98_90E8(q4 + 0xDC, t4, q4 + 0x14, 4, 1, lbl_98_rodata_4, &bg.flags[4]);
    bg.values[4] = 0x2;
    bg.ptrs[8] = q4 + 0xDC;
    bg.ptrs[9] = q4 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[8], &bg.values[4]);
    }
    bdOf(sm.bo)->getAnimCmdData(5, 2);
    bdOf(sm.bo)->getAnimCmdData(5, 1);
    void* a5 = bdOf(sm.bo)->getAnimCmdData(5, 0);
    Byte* q5 = r26 + 0xEE4;
    fn_27_C7744(q5, a5, 0x1E6);
    fn_27_D22D0(q5 + 0x14, 0);
    fn_98_90CC(q5 + 0xC0, q5, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[5] = 0;
    short t5 = subShort24(ev);
    fn_98_90E8(q5 + 0xDC, t5, q5 + 0x14, 5, 1, lbl_98_rodata_4, &bg.flags[5]);
    bg.values[5] = 0x20;
    bg.ptrs[10] = q5 + 0xDC;
    bg.ptrs[11] = q5 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[10], &bg.values[5]);
    }
    bdOf(sm.bo)->getAnimCmdData(6, 2);
    bdOf(sm.bo)->getAnimCmdData(6, 1);
    void* a6 = bdOf(sm.bo)->getAnimCmdData(6, 0);
    Byte* q6 = r26 + 0x1010;
    fn_27_C7744(q6, a6, 0x1E6);
    fn_27_D22D0(q6 + 0x14, 0);
    fn_98_90CC(q6 + 0xC0, q6, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[6] = 0;
    short t6 = subShort24(ev);
    fn_98_90E8(q6 + 0xDC, t6, q6 + 0x14, 6, 1, lbl_98_rodata_4, &bg.flags[6]);
    bg.values[6] = 0x80;
    bg.ptrs[12] = q6 + 0xDC;
    bg.ptrs[13] = q6 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[12], &bg.values[6]);
    }
    bdOf(sm.bo)->getAnimCmdData(7, 2);
    bdOf(sm.bo)->getAnimCmdData(7, 1);
    void* a7 = bdOf(sm.bo)->getAnimCmdData(7, 0);
    Byte* q7 = r26 + 0x113C;
    fn_27_C7744(q7, a7, 0x1E6);
    fn_27_D22D0(q7 + 0x14, 0);
    fn_98_90CC(q7 + 0xC0, q7, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[7] = 0;
    short t7 = subShort24(ev);
    fn_98_90E8(q7 + 0xDC, t7, q7 + 0x14, 7, 1, lbl_98_rodata_4, &bg.flags[7]);
    bg.values[7] = 0x80;
    bg.ptrs[14] = q7 + 0xDC;
    bg.ptrs[15] = q7 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[14], &bg.values[7]);
    }
    bdOf(sm.bo)->getAnimCmdData(8, 2);
    bdOf(sm.bo)->getAnimCmdData(8, 1);
    void* a8 = bdOf(sm.bo)->getAnimCmdData(8, 0);
    q8 = r26 + 0x1268;
    fn_27_C7744(q8, a8, 0x1E6);
    fn_27_D22D0(q8 + 0x14, 0);
    fn_98_90CC(q8 + 0xC0, q8, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[8] = 0;
    short t8 = subShort24(ev);
    fn_98_90E8(q8 + 0xDC, t8, q8 + 0x14, 8, 1, lbl_98_rodata_4, &bg.flags[8]);
    bg.values[8] = 0x20;
    bg.ptrs[16] = q8 + 0xDC;
    bg.ptrs[17] = q8 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[16], &bg.values[8]);
    }
    q8 = r26 + 0x1394;
    bg.flags[9] = 1;
    short t9 = subShort24(ev);
    fn_98_90E8(q8, t9, q8 + 0x50, 9, 1, lbl_98_rodata_4, &bg.flags[9]);
    fn_27_1A079C(q8 + 0x50, 0);
    bg.values[9] = 0x4;
    bg.ptrs[18] = q8;
    bg.ptrs[19] = lbl_27_bss_8C4;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[18], &bg.values[9]);
    }
    bdOf(sm.bo)->getAnimCmdData(10, 2);
    bdOf(sm.bo)->getAnimCmdData(10, 1);
    void* a10 = bdOf(sm.bo)->getAnimCmdData(10, 0);
    q10 = r26 + 0x14B8;
    fn_27_C7744(q10, a10, 0x29);
    fn_27_D22D0(q10 + 0x14, 0);
    fn_98_90CC(q10 + 0xC0, q10, lbl_27_bss_D8C, lbl_27_bss_D8C);
    bg.flags[10] = 0;
    short t10 = subShort24(ev);
    fn_98_90E8(q10 + 0xDC, t10, q10 + 0x14, 10, 1, lbl_98_rodata_4, &bg.flags[10]);
    bg.values[10] = 0x10;
    bg.ptrs[20] = q10 + 0xDC;
    bg.ptrs[21] = q10 + 0xC0;
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x6C);
        reinterpret_cast<Registry*>(o)->insert(&bg.ptrs[20], &bg.values[10]);
    }
    q00 = bdOf(sm.bo)->getAnimCmdData(0, 0);
    fn_98_92E8(fn_98_9364(r26, 0), q00, 0x112);
    q01 = bdOf(sm.bo)->getAnimCmdData(0, 1);
    fn_98_92E8(fn_98_9364(r26, 1), q01, 0x112);
    void* command0 = fn_98_9364(r26, 0);
    fn_98_92E8(command0, *(void**)(*(Byte**)(sm.bo + 0xC) + 0x24), 0xE);
    void* command1 = fn_98_9364(r26, 1);
    fn_98_92E8(command1, *(void**)(*(Byte**)(sm.bo + 0xC) + 0x28), 0xE);
    fn_98_93A0(r26, 0, reinterpret_cast<ftFighterBuildData*>(sm.bo)->getAnimCmdDisguiseList(false, 0));
    fn_98_93A0(r26, 1, reinterpret_cast<ftFighterBuildData*>(sm.bo)->getAnimCmdDisguiseList(false, 1));
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x70);
        reinterpret_cast<LongSink*>(o)->set(ev + 0x29110);
    }
    r23c = soValueAccesser::getConstantIndefinite(
        reinterpret_cast<soModuleAccesser*>(ev + 0x9D0), 43013, 0);
    void* dc = __dynamic_cast(
        pAt(pAt(ev, 0xAA8), 0x90), 0, lbl_98_data_2300, lbl_98_data_23A8, 0);
    if (dc != 0) {
        fn_27_14E0B8(dc, r23c);
    }
    {
        Byte* o = pAt(pAt(ev, 0xAA8), 0x90);
        reinterpret_cast<ValueSink*>(o)->set(r23c);
    }
    fn_27_1404D4(self + 0x2A898, *(void**)(self + 0x60));
    new (self + 0x2A8D4) PikachuStateStorage();
    ev = *(Byte**)(self + 0x60);
    b = reinterpret_cast<int>(self + 0x2AD8C);
    fn_98_7374(reinterpret_cast<Byte*>(b), 0);
    *reinterpret_cast<Byte**>(reinterpret_cast<Byte*>(b)) = lbl_98_data_21F8;
    new (reinterpret_cast<Byte*>(b) + 0x8) PikachuActionLeafStorage<lbl_27_data_2F9F8>(ev);
    new (reinterpret_cast<Byte*>(b) + 0x20) PikachuActionLeafStorage<lbl_27_data_2FAA0>(ev);
    new (reinterpret_cast<Byte*>(b) + 0x34) PikachuActionLeafStorage<lbl_27_data_2FB48>(ev);
    new (reinterpret_cast<Byte*>(b) + 0x48) PikachuActionLeafStorage<lbl_27_data_2FBF0>(ev);
    new (reinterpret_cast<Byte*>(b) + 0x5C) PikachuActionLeafStorage<lbl_27_data_2FC98>(ev);
    new (reinterpret_cast<Byte*>(b) + 0x70) PikachuActionLeafStorage<lbl_27_data_2FD40>(ev);
    new (reinterpret_cast<Byte*>(b) + 0x84) PikachuActionLeafStorage<lbl_27_data_2FDE8>(ev);
    void* c1 = soValueAccesser::getConstantIndefinite(
        reinterpret_cast<soModuleAccesser*>(pAt(self, 0x60)), 43001, 0);
    *(void**)(self + 0x2AE24) = c1;
    *(int*)(self + 0x2AE28) = 1;
    void* c2 = soValueAccesser::getConstantIndefinite(
        reinterpret_cast<soModuleAccesser*>(pAt(self, 0x60)), 43004, 0);
    *(void**)(self + 0x2AE2C) = c2;
    *(int*)(self + 0x2AE30) = 1;
    fn_27_126470(self);
    {
        Byte* o = self + 0x2A898;
        reinterpret_cast<CallOne*>(o)->apply(pAt(self, 0x60));
    }
    *(Byte**)(self + 0x3C) = lbl_98_data_120;
    *(Byte**)(self + 0x40) = lbl_98_data_120 + 0x64;
    *(Byte**)(self + 0x48) = lbl_98_data_120 + 0x70;
    *(Byte**)(self + 0x54) = lbl_98_data_120 + 0x84;
    *(Byte**)(self + 0x64) = lbl_98_data_120 + 0xDC;
    *(Byte**)(self + 0x70) = lbl_98_data_120 + 0xEC;
    *(Byte**)(self + 0x7C) = lbl_98_data_120 + 0xFC;
    *(Byte**)(self + 0x88) = lbl_98_data_120 + 0x110;
    *(Byte**)(self + 0x94) = lbl_98_data_120 + 0x128;
    *(Byte**)(self + 0xA0) = lbl_98_data_120 + 0x140;
    *(Byte**)(self + 0xAC) = lbl_98_data_120 + 0x158;
    *(Byte**)(self + 0xB8) = lbl_98_data_120 + 0x16C;
    *(Byte**)(self + 0xC4) = lbl_98_data_120 + 0x180;
    *(Byte**)(self + 0xD0) = lbl_98_data_120 + 0x190;
    *(Byte**)(self + 0xDC) = lbl_98_data_120 + 0x1C4;
    *(Byte**)(self + 0xE8) = lbl_98_data_120 + 0x1D4;
    *(Byte**)(self + 0xF4) = lbl_98_data_120 + 0x1E8;
    *(Byte**)(self + 0x100) = lbl_98_data_120 + 0x254;
    fn_27_C749C(self + 0x2AE34);
    *(void**)(self + 0x2AE44) = g_ftCommonDataAccesser.getData(static_cast<ftKind>(7));
    sm.arrC[0] = lbl_27_bss_7C64;
    sm.arrC[1] = lbl_98_bss_25C;
    sm.arrC[2] = lbl_98_bss_22C;
    sm.arrC[3] = lbl_98_bss_2AC;
    sm.arrC[4] = lbl_98_bss_2CC;
    sm.arrC[5] = lbl_98_bss_23C;
    sm.arrC[6] = lbl_98_bss_24C;
    sm.arrC[7] = lbl_98_bss_26C;
    sm.arrC[8] = lbl_98_bss_27C;
    sm.arrC[9] = lbl_98_bss_28C;
    sm.arrC[10] = lbl_98_bss_29C;
    sm.arrC[11] = lbl_98_bss_2BC;
    sm.arrC[12] = lbl_98_bss_2DC;
    sm.arrC[13] = lbl_98_bss_2EC;
    {
        Byte* o = pAt(pAt(pAt(self, 0x60), 0xD8), 0x70);
        reinterpret_cast<ListSink*>(o)->set(sm.arrC, 0xE);
    }
    return self;
}
