#include <types.h>
#include <new>
#pragma use_simple_stdpnew on
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#pragma force_active on

extern "C" {
extern char lbl_112_data_600[], lbl_112_data_11C[];
extern char lbl_112_data_19B4[], lbl_112_data_1A34[];
extern char lbl_112_data_1B3C[], lbl_112_data_1BE4[];
extern char lbl_112_rodata_0[];
extern char lbl_27_bss_3AC[], lbl_27_bss_3CC[], lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[], lbl_27_bss_46D8[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_69C[];
extern char lbl_27_bss_A48[], lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_112_bss_1AC[], lbl_112_bss_1BC[], lbl_112_bss_1CC[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[], lbl_27_data_2FC98[];
extern char lbl_27_data_2FD40[], lbl_27_data_2FDE8[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1257EC(void*, long, int, int, void*);
void fn_112_7754(void*);
void fn_112_7AA8(void*, u32, u32, u8, void*);
void* fn_112_7B10(void*, soModuleAccesser*, float, void*,
                 soEventObserverRegistrationDesc*);
void fn_112_7B98(void*, void*, void*);
void fn_112_7D6C(void*, void*, void*);
void fn_112_7DDC(void*, void*, void*);
void fn_27_3513C(void*, short, void*, void*);
void fn_112_7688(void*, long, void*);
void fn_112_7E40(void*, void*, int, u8, void*);
void fn_112_7F04(void*, void*, int, u8, void*);
void fn_112_7FC8(void*, void*, int, u8);
void fn_112_809C(void*, void*, int, u8);
void fn_112_8170(void*, void*, int, u8, void*);
void fn_112_8208(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_112_8274(void*, void*, void*);
void fn_112_82D0(void*, void*, void*, void*);
void fn_112_8360(void*, void*);
void fn_27_5B248(void*, void*, void*, int);
void fn_112_83B4(void*, void*, short);
void fn_112_8424(void*, void*, void*, void*, void*);
void fn_27_A1DA4(void*, void*, void*);
void fn_112_8490(void*, short);
void fn_112_84D4(void*, void*, void*, void*);
void fn_112_898C(void*, void*);
void fn_112_8D5C(void*);
void fn_112_8DBC(void*, void*);
void fn_112_905C(void*, void*, void*, void*, void*, void*, void*);
void fn_27_14FBD8(void*, void*);
void fn_112_9128(void*, void*, u8, void*);
void fn_112_91C0(void*, void*, void*);
void fn_27_ACAC4(void*, void*, bool, int, bool);
void fn_27_B62E4(void*, void*, float, int);
void fn_112_9220(void*, void*, void*);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, void*);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A61BC(void*, int);
void fn_27_D22D0(void*, int);
void fn_112_929C(void*, void*, void*, void*);
void fn_112_92B8(void*, short, void*, int, int, float, signed char*);
void fn_112_94B8(void*, void*, int);
void fn_27_C7744(void*, void*, int);
void fn_27_1A079C(void*, int);
void fn_112_9570(void*, int, void*);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_112_7674(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void fn_27_195B34(void*, void*, void*);
void fn_27_14B5F8(void*, void*);
void* fn_112_9448();
void* fn_112_9534(void*, int);
}

class AreaInit {
public:
    AreaInit(void* acc) { fn_27_ACAC4(this, acc, 0, 1, 0); }
};
class ShadowInit {
public:
    ShadowInit(void* acc, float* values) {
        fn_27_B62E4(this, acc, values[0], 0);
    }
};
class ColorInit {
public:
    ColorInit(void* acc) { fn_27_BEBB4(this, acc, 10, 1); }
};
class JostleInit {
public:
    JostleInit(void* acc, void* data) {
        fn_27_C20D8(this, acc, 0, 8, data);
    }
};

class BuildCalls {
public:
    virtual u32 getMdlResId() const;
    virtual u32 getAnmResId() const;
    virtual u8 getResGroupNo() const;
    virtual s32 getTeam() const;
    virtual void* getMotionData() const;
    virtual void* getShakeData() const;
    virtual void* getVisibilityData() const;
    virtual void* getStatusData() const;
    virtual void* getGroundConditionChecker() const;
    virtual void* getEffectNodeData() const;
    virtual void* getEffectEmitData() const;
    virtual void* getEffectCommonData() const;
    virtual void* getEffectScreenData() const;
    virtual void* getTerritoryParam() const;
    virtual void* getTerritoryRect() const;
    virtual void* getTargetSearchParam() const;
    virtual void* getIkData() const;
    virtual int getModelLayerType() const;
    virtual float getModelScale() const;
    virtual void* getParamAccesser() const;
    virtual s32 getAreaCategory() const;
    virtual void* getCameraRangeSet() const;
    virtual void* getCameraClipSphereSet() const;
    virtual void* getItemNodeData() const;
    virtual void* getModelExtendNodeTable() const;
    virtual void* getJostleData() const;
    virtual void* getPreCheckAnimCmdData() const;
    virtual Heaps::HeapType getInstanceHeap() const;
    virtual Heaps::HeapType getNWModelInstanceHeap() const;
    virtual Heaps::HeapType getNWMotionInstanceHeap() const;
    virtual s32 getHeapSlotNo() const;
    virtual void* getSoundIdExchanger() const;
    virtual float getSlopeAngleLimit() const;
    virtual void destroy() const;
    virtual void* getAnimCmdData(u32, s32) const;
};

class BlendCalls {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void*, int);
};
class LateCalls {
public:
    virtual void v1();
    virtual void init(void*);
};
class V {
public:
    virtual void* v1();
    virtual void* v2(void*, void*);
    virtual void* v3();
    virtual void* v4(void*, int);
    virtual void* v5();
    virtual void* v6(void*, int);
    virtual void* v7(void*, int);
    virtual int v8();
    void* apply8(void*, int);
    virtual void* v9();
    virtual void* v10(void*);
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14(void*, int, int);
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29(void*, int);
    virtual void* v30(void*, int);
    virtual void* v31();
    virtual void* v32();
    virtual void* v33();
    virtual void* v34(void*);
    virtual void* v35(void*);
};

#define P(p, o) (*(char**)((char*)(p) + (o)))
#define OBJ(p) ((V*)(p))
#define MOD(o) P(P(a, 0xAA8), o)
#define END(o) P(P(P(s, 0x60), 0xD8), o)

class TailInit {
public:
    TailInit(void* acc) {
        char* self = (char*)this;
        fn_112_7674(self, 0);
        P(self, 0) = lbl_112_data_1A34;
        {
            char* x = self + 0x8;
            fn_27_17437C(x, acc);
            P(x, 0) = lbl_27_data_2F9F8;
            P(x, 4) = lbl_27_data_2F9F8 + 0x40;
        }
        {
            char* x = self + 0x20;
            fn_27_17437C(x, acc);
            P(x, 0) = lbl_27_data_2FAA0;
            P(x, 4) = lbl_27_data_2FAA0 + 0x40;
        }
        {
            char* x = self + 0x34;
            fn_27_17437C(x, acc);
            P(x, 0) = lbl_27_data_2FB48;
            P(x, 4) = lbl_27_data_2FB48 + 0x40;
        }
        {
            char* x = self + 0x48;
            fn_27_17437C(x, acc);
            P(x, 0) = lbl_27_data_2FBF0;
            P(x, 4) = lbl_27_data_2FBF0 + 0x40;
        }
        {
            char* x = self + 0x5C;
            fn_27_17437C(x, acc);
            P(x, 0) = lbl_27_data_2FC98;
            P(x, 4) = lbl_27_data_2FC98 + 0x40;
        }
        {
            char* x = self + 0x70;
            fn_27_17437C(x, acc);
            P(x, 0) = lbl_27_data_2FD40;
            P(x, 4) = lbl_27_data_2FD40 + 0x40;
        }
        {
            char* x = self + 0x84;
            fn_27_17437C(x, acc);
            P(x, 0) = lbl_27_data_2FDE8;
            P(x, 4) = lbl_27_data_2FDE8 + 0x40;
        }
    }
};

struct ListInit {
    void* values[15];

    ListInit() : values() {}
};

struct PitCommonState {
    char prefix[0x297AC];
    char* data;
    char reserved[4];
    char flagA;
    char flagB;
};

struct Local {
    signed char flags[11];
    char pad;
    short values[11];
    char pad2[2];
    void* ptrs[22];
    int blend[7];
    char out[0x20];
    char build[0x30];
    void* list[15];
};

extern "C" void* fn_112_70(char* s, long id, char* q, int h2, char* a) {
    Local l;
    float* k = (float*)lbl_112_rodata_0;
    Heaps::HeapType motionHeap;
    char* late;
    char* finalBlock;
    void* commandData;
    void* secondCommandData;
    void* constant;
    char* t;
    char* early;
    int heapValue;

    fn_27_1257EC(s, id, 0x17, (int)q, s + 0xB64);
    P(s, 0x3C) = lbl_112_data_600;
    P(s, 0x40) = lbl_112_data_600 + 0x64;
    P(s, 0x48) = lbl_112_data_600 + 0x70;
    P(s, 0x54) = lbl_112_data_600 + 0x84;
    P(s, 0x64) = lbl_112_data_600 + 0xDC;
    P(s, 0x70) = lbl_112_data_600 + 0xEC;
    P(s, 0x7C) = lbl_112_data_600 + 0xFC;
    P(s, 0x88) = lbl_112_data_600 + 0x110;
    P(s, 0x94) = lbl_112_data_600 + 0x128;
    P(s, 0xA0) = lbl_112_data_600 + 0x140;
    P(s, 0xAC) = lbl_112_data_600 + 0x158;
    P(s, 0xB8) = lbl_112_data_600 + 0x16C;
    P(s, 0xC4) = lbl_112_data_600 + 0x180;
    P(s, 0xD0) = lbl_112_data_600 + 0x190;
    P(s, 0xDC) = lbl_112_data_600 + 0x1C4;
    P(s, 0xE8) = lbl_112_data_600 + 0x1D4;
    P(s, 0xF4) = lbl_112_data_600 + 0x1E8;
    P(s, 0x100) = lbl_112_data_600 + 0x254;

    new (l.build) ftFighterBuildData(
        id, (ftKind)23, (Heaps::HeapType)(int)q,
        (Heaps::HeapType)h2, (Heaps::HeapType)(int)a, 0,
        (soModuleAccesser*)P(s, 0x60), -1, s + 0x2978C, s + 0x29794);

#define b ((BuildCalls*)l.build)

    a = s + 0x194;
    fn_112_7754(a);
    new (a + 0x9D0) soModuleAccesser(
        (StageObject*)s,
        (soResourceModule*)(a + 0x1168),
        (soModelModule*)(a + 0x1374),
        (soMotionModule*)(a + 0x1664),
        (soPostureModule*)(a + 0x1810),
        (soGroundModule*)(a + 0x18D8),
        (soSituationModule*)(a + 0x1930),
        a + 0x199C,
        (soCollisionAttackModule*)(a + 0x1FFC),
        (soCollisionHitModule*)(a + 0x25E8),
        (soCollisionShieldModule*)(a + 0x29A4),
        (soCollisionShieldModule*)(a + 0x342C),
        (soCollisionShieldModule*)lbl_27_bss_3AC,
        a + 0x3600,
        (soCollisionSearchModule*)lbl_27_bss_3CC,
        (soDamageModule*)(a + 0x3794),
        a + 0x3898, a + 0x38FC,
        (soStopModule*)(a + 0x3930),
        a + 0x3954, a + 0x3A08,
        (soSoundModule*)(a + 0x3A38),
        (soLinkModule*)(a + 0x3BD8),
        (soVisibilityModule*)(a + 0x3C2C),
        (soControllerModule*)(a + 0x4214),
        (soCameraModule*)(a + 0x43D0),
        (soWorkManageModule*)(a + 0x43F4),
        lbl_27_bss_4BC,
        (soAnimCmdModule*)(a + 0x4428),
        (soStatusModule*)(a + 0x52F0),
        lbl_27_bss_46C0, lbl_27_bss_46D8,
        (soKineticModule*)(a + 0x53A0),
        (soEventManageModule*)(a + 0xB8),
        a + 0x26E8C,
        (soEffectModule*)(a + 0x26F34),
        a + 0x2706C,
        (soAreaModule*)(a + 0x270AC),
        lbl_27_bss_5B0, lbl_27_bss_5D8,
        a + 0x2748C, a + 0x274D4,
        (soShadowModule*)(a + 0x27554),
        (soItemManageModule*)(a + 0x27640),
        (soColorBlendModule*)(a + 0x276AC),
        a + 0x27800, a + 0x2784C,
        (soSlowModule*)(a + 0x278B4),
        lbl_27_bss_69C,
        a + 0xAB0,
        (soParamCustomizeModule*)(a + 0xAC8),
        a + 0x278F0);

    h2 = b->getHeapSlotNo();
    motionHeap = b->getNWMotionInstanceHeap();
    Heaps::HeapType instHeap;
    {
        early = (char*)b->getNWModelInstanceHeap();
        instHeap = b->getInstanceHeap();
        new (a + 0xAB0) soHeapModuleImpl(
            instHeap, (Heaps::HeapType)(long)early, motionHeap, h2);
    }

    fn_27_14B5F8(a + 0xAC8, a + 0x9D0);
    fn_112_7AA8(a + 0x115C, b->getMdlResId(), b->getAnmResId(),
                 b->getResGroupNo(), a + 0x9D0);
    fn_112_7B10(a + 0x1180, (soModuleAccesser*)(a + 0x9D0),
                b->getModelScale(), b->getModelExtendNodeTable(),
                (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    fn_112_7B98(a + 0x1440, a + 0x9D0, b->getMotionData());
    fn_112_7D6C(a + 0x17D4, a + 0x9D0, lbl_27_bss_A48);
    fn_112_7DDC(a + 0x1888, a + 0x9D0, b->getGroundConditionChecker());
    heapValue = OBJ(MOD(0x80) + 8)->v8();
    fn_27_3513C(a + 0x1930, (short)heapValue, a + 0x9D0, lbl_27_bss_A48);
    fn_112_7688(a + 0x196C, b->getTeam(), a + 0x9D0);
    fn_112_7E40(a + 0x19E0, a + 0x9D0, *(int*)(s + 0x28),
                 (*(u32*)(s + 0x2C) >> 7) & 255, lbl_27_bss_A48);
    fn_112_7F04(a + 0x209C, a + 0x9D0, *(int*)(s + 0x28),
                 (*(u32*)(s + 0x2C) >> 7) & 255, lbl_27_bss_A48);
    fn_112_7FC8(a + 0x2650, a + 0x9D0, *(int*)(s + 0x28),
                 (*(u32*)(s + 0x2C) >> 7) & 255);
    fn_112_809C(a + 0x29F8, a + 0x9D0, *(int*)(s + 0x28),
                 (*(u32*)(s + 0x2C) >> 7) & 255);
    fn_112_8170(a + 0x3484, a + 0x9D0, *(int*)(s + 0x28),
                 (*(u32*)(s + 0x2C) >> 7) & 255, lbl_27_bss_A48);
    fn_112_8208(a + 0x36E8, a + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(a + 0x3898, a + 0x9D0, 1);
    fn_27_65EE4(a + 0x38FC, a + 0x9D0);
    fn_27_154088(a + 0x3930, a + 0x9D0);
    fn_27_693F4(a + 0x3954, a + 0x9D0);
    fn_112_8274(a + 0x398C, a + 0x9D0, b->getShakeData());
    fn_112_82D0(a + 0x3A24, a + 0x9D0, b->getSoundIdExchanger(), lbl_27_bss_A48);
    fn_112_8360(a + 0x3A94, a + 0x9D0);
    fn_27_5B248(a + 0x3C2C, a + 0x9D0, b->getVisibilityData(), 2);
    heapValue = OBJ(MOD(0x80) + 8)->v8();
    fn_112_83B4(a + 0x3C5C, a + 0x9D0, (short)heapValue);
    fn_112_8424(a + 0x4380, a + 0x9D0, b->getCameraRangeSet(),
                 b->getCameraClipSphereSet(), lbl_27_bss_A48);
    fn_27_A1DA4(a + 0x43F4, a + 0x9D0, b->getParamAccesser());
    heapValue = OBJ(MOD(0x80) + 8)->v8();
    fn_112_8490(a + 0x4428, (short)heapValue);
    fn_112_84D4(a + 0x451C, a + 0x9D0, b->getStatusData(),
                 b->getPreCheckAnimCmdData());
    fn_112_898C(a + 0x53A0, a + 0x9D0);
    fn_112_8D5C(a + 0x56A8);
    fn_112_8DBC(a + 0x588C, a + 0x9D0);
    fn_112_905C(a + 0x26EC8, a + 0x9D0, b->getEffectNodeData(),
                 b->getEffectEmitData(), b->getEffectCommonData(),
                 b->getEffectScreenData(), lbl_27_bss_A48);
    fn_27_14FBD8(a + 0x2706C, a + 0x9D0);
    heapValue = b->getAreaCategory();
    fn_112_9128(a + 0x2709C, a + 0x9D0, (u8)heapValue, lbl_27_bss_A48);
    b->getTerritoryRect();
    b->getTerritoryParam();
    b->getTargetSearchParam();
    fn_112_91C0(a + 0x27410, a + 0x9D0, b->getIkData());
    b->getSlopeAngleLimit();
    new (a + 0x274D4) AreaInit(a + 0x9D0);
    new (a + 0x27554) ShadowInit(a + 0x9D0, k);
    fn_112_9220(a + 0x2759C, a + 0x9D0, b->getItemNodeData());
    new (a + 0x276AC) ColorInit(a + 0x9D0);
    new (a + 0x27800) JostleInit(a + 0x9D0, b->getJostleData());
    fn_27_196664(a + 0x2784C, a + 0x9D0);
    fn_27_5BED0(a + 0x278B4, a + 0x9D0);
    fn_27_14CCEC(a + 0x278F0, a + 0x9D0);

    if (OBJ(a + 0x5868)->v1() == 0)
        OBJ(MOD(0x64))->v4((void*)1, (int)(a + 0x5868));

    fn_27_C74BC(a + 0x27A70, P(P(l.build, 0xC), 0x18), 15);
    char* ac = a + 0x27A80;
    fn_27_1A61BC(ac, 0);
    fn_27_1A61BC(ac + 0x490, 0);
    fn_27_D22D0(ac + 0x924, 0);
    fn_112_929C(ac + 0x9D0, ac, ac + 0x490, fn_112_9448());
    l.flags[0] = 0;
    heapValue = OBJ(MOD(0x80) + 8)->v8();
    fn_112_92B8(ac + 0x9EC, (short)heapValue, ac + 0x924,
                 0, 1, k[1], &l.flags[0]);
    fn_112_94B8(ac, 0, 0x121);
    fn_112_94B8(ac + 0x490, 0, 0x121);
    fn_112_94B8(fn_112_9448(), 0, 0);
    l.values[0] = 1;
    l.ptrs[0] = ac + 0x9EC;
    l.ptrs[1] = ac + 0x9D0;
    OBJ(MOD(0x6C))->v2(&l.ptrs[0], &l.values[0]);



    b->getAnimCmdData(1, 2);
    b->getAnimCmdData(1, 1);
    {
        void* data = b->getAnimCmdData(1, 0);
        early = ac + 0xA3C;
        fn_27_C7744(early, data, 500);
        fn_27_D22D0(early + 0x14, 0);
        fn_112_929C(early + 0xC0, early, lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[1] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(early + 0xDC, (short)heapValue, early + 0x14,
                     1, 1, k[1], &l.flags[1]);
        l.values[1] = 2;
        l.ptrs[2] = early + 0xDC;
        l.ptrs[3] = early + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[2], &l.values[1]);
    }
    b->getAnimCmdData(2, 2);
    b->getAnimCmdData(2, 1);
    {
        void* data = b->getAnimCmdData(2, 0);
        char* t = ac + 0xB68;
        fn_27_C7744(t, data, 500);
        fn_27_D22D0(t + 0x14, 0);
        fn_112_929C(t + 0xC0, t, lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[2] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(t + 0xDC, (short)heapValue, t + 0x14,
                     2, 1, k[1], &l.flags[2]);
        l.values[2] = 64;
        l.ptrs[4] = t + 0xDC;
        l.ptrs[5] = t + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[4], &l.values[2]);
    }
    b->getAnimCmdData(3, 2);
    b->getAnimCmdData(3, 1);
    {
        void* data = b->getAnimCmdData(3, 0);
        char* t = ac + 0xC94;
        fn_27_C7744(t, data, 500);
        fn_27_D22D0(t + 0x14, 0);
        fn_112_929C(t + 0xC0, t, lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[3] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(t + 0xDC, (short)heapValue, t + 0x14,
                     3, 1, k[1], &l.flags[3]);
        l.values[3] = 64;
        l.ptrs[6] = t + 0xDC;
        l.ptrs[7] = t + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[6], &l.values[3]);
    }
    b->getAnimCmdData(4, 2);
    b->getAnimCmdData(4, 1);
    {
        void* data = b->getAnimCmdData(4, 0);
        char* t = ac + 0xDC0;
        fn_27_C7744(t, data, 500);
        fn_27_D22D0(t + 0x14, 0);
        fn_112_929C(t + 0xC0, t, lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[4] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(t + 0xDC, (short)heapValue, t + 0x14,
                     4, 1, k[1], &l.flags[4]);
        l.values[4] = 2;
        l.ptrs[8] = t + 0xDC;
        l.ptrs[9] = t + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[8], &l.values[4]);
    }
    b->getAnimCmdData(5, 2);
    b->getAnimCmdData(5, 1);
    {
        void* data = b->getAnimCmdData(5, 0);
        char* t = ac + 0xEEC;
        fn_27_C7744(t, data, 500);
        fn_27_D22D0(t + 0x14, 0);
        fn_112_929C(t + 0xC0, t, lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[5] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(t + 0xDC, (short)heapValue, t + 0x14,
                     5, 1, k[1], &l.flags[5]);
        l.values[5] = 32;
        l.ptrs[10] = t + 0xDC;
        l.ptrs[11] = t + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[10], &l.values[5]);
    }
    b->getAnimCmdData(6, 2);
    b->getAnimCmdData(6, 1);
    {
        void* data = b->getAnimCmdData(6, 0);
        char* t = ac + 0x1018;
        fn_27_C7744(t, data, 500);
        fn_27_D22D0(t + 0x14, 0);
        fn_112_929C(t + 0xC0, t, lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[6] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(t + 0xDC, (short)heapValue, t + 0x14,
                     6, 1, k[1], &l.flags[6]);
        l.values[6] = 128;
        l.ptrs[12] = t + 0xDC;
        l.ptrs[13] = t + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[12], &l.values[6]);
    }
    b->getAnimCmdData(7, 2);
    b->getAnimCmdData(7, 1);
    {
        void* data = b->getAnimCmdData(7, 0);
        char* t = ac + 0x1144;
        fn_27_C7744(t, data, 500);
        fn_27_D22D0(t + 0x14, 0);
        fn_112_929C(t + 0xC0, t, lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[7] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(t + 0xDC, (short)heapValue, t + 0x14,
                     7, 1, k[1], &l.flags[7]);
        l.values[7] = 128;
        l.ptrs[14] = t + 0xDC;
        l.ptrs[15] = t + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[14], &l.values[7]);
    }
    b->getAnimCmdData(8, 2);
    b->getAnimCmdData(8, 1);
    {
        void* data = b->getAnimCmdData(8, 0);
        late = ac + 0x1270;
        fn_27_C7744(late, data, 500);
        fn_27_D22D0(late + 0x14, 0);
        fn_112_929C(late + 0xC0, late, lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[8] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(late + 0xDC, (short)heapValue, late + 0x14,
                     8, 1, k[1], &l.flags[8]);
        l.values[8] = 32;
        l.ptrs[16] = late + 0xDC;
        l.ptrs[17] = late + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[16], &l.values[8]);
    }
    {
        late = ac + 0x139C;
        l.flags[9] = 1;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(late, (short)heapValue, late + 0x50,
                     9, 1, k[1], &l.flags[9]);
        fn_27_1A079C(late + 0x50, 0);
        l.values[9] = 4;
        l.ptrs[18] = late;
        l.ptrs[19] = lbl_27_bss_8C4;
        OBJ(MOD(0x6C))->v2(&l.ptrs[18], &l.values[9]);
    }
    b->getAnimCmdData(10, 2);
    b->getAnimCmdData(10, 1);
    {
        void* data = b->getAnimCmdData(10, 0);
        finalBlock = ac + 0x14C0;
        fn_27_C7744(finalBlock, data, 41);
        fn_27_D22D0(finalBlock + 0x14, 0);
        fn_112_929C(finalBlock + 0xC0, finalBlock,
                     lbl_27_bss_D8C, lbl_27_bss_D8C);
        l.flags[10] = 0;
        heapValue = OBJ(MOD(0x80) + 8)->v8();
        fn_112_92B8(finalBlock + 0xDC, (short)heapValue,
                     finalBlock + 0x14, 10, 1, k[1], &l.flags[10]);
        l.values[10] = 16;
        l.ptrs[20] = finalBlock + 0xDC;
        l.ptrs[21] = finalBlock + 0xC0;
        OBJ(MOD(0x6C))->v2(&l.ptrs[20], &l.values[10]);
    }
    {
        commandData = b->getAnimCmdData(0, 0);
        fn_112_94B8(fn_112_9534(ac, 0), commandData, 0x112);
    }
    {
        secondCommandData = b->getAnimCmdData(0, 1);
        fn_112_94B8(fn_112_9534(ac, 1), secondCommandData, 0x112);
    }
    fn_112_94B8(fn_112_9534(ac, 0), P(P(l.build, 0xC), 36), 15);
    fn_112_94B8(fn_112_9534(ac, 1), P(P(l.build, 0xC), 40), 15);
    fn_112_9570(ac, 0,
        ((ftFighterBuildData*)b)->getAnimCmdDisguiseList(false, 0));
    fn_112_9570(ac, 1,
        ((ftFighterBuildData*)b)->getAnimCmdDisguiseList(false, 1));
    OBJ(MOD(0x70))->v34(a + 0x27A70);

    constant = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(a + 0x9D0), 0xA805, 0);
    void* casted = __dynamic_cast(MOD(0x90), 0,
        lbl_112_data_1B3C, lbl_112_data_1BE4, 0);
    if (casted)
        fn_27_14E0B8(casted, constant);
    OBJ(MOD(0x90))->v10(constant);
    fn_27_1404D4(s + 0x29200, P(s, 0x60));
    t = s + 0x2923C;
    fn_112_7674(t, 0);
    P(t, 0) = lbl_112_data_19B4;

    a = P(s, 0x60);
    q = s + 0x296F4;
    new (q) TailInit(a);

    P(s, 0x2978C) = (char*)soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)P(s, 0x60), 0xA7F9, 0);
    *(int*)(s + 0x29790) = 1;
    P(s, 0x29794) = (char*)soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)P(s, 0x60), 0xA7FC, 0);
    *(int*)(s + 0x29798) = 1;
    fn_27_126470(s);
    ((LateCalls*)(s + 0x29200))->init(P(s, 0x60));

    P(s, 0x3C) = lbl_112_data_11C;
    P(s, 0x40) = lbl_112_data_11C + 0x64;
    P(s, 0x48) = lbl_112_data_11C + 0x70;
    P(s, 0x54) = lbl_112_data_11C + 0x84;
    P(s, 0x64) = lbl_112_data_11C + 0xDC;
    P(s, 0x70) = lbl_112_data_11C + 0xEC;
    P(s, 0x7C) = lbl_112_data_11C + 0xFC;
    P(s, 0x88) = lbl_112_data_11C + 0x110;
    P(s, 0x94) = lbl_112_data_11C + 0x128;
    P(s, 0xA0) = lbl_112_data_11C + 0x140;
    P(s, 0xAC) = lbl_112_data_11C + 0x158;
    P(s, 0xB8) = lbl_112_data_11C + 0x16C;
    P(s, 0xC4) = lbl_112_data_11C + 0x180;
    P(s, 0xD0) = lbl_112_data_11C + 0x190;
    P(s, 0xDC) = lbl_112_data_11C + 0x1C4;
    P(s, 0xE8) = lbl_112_data_11C + 0x1D4;
    P(s, 0xF4) = lbl_112_data_11C + 0x1E8;
    P(s, 0x100) = lbl_112_data_11C + 0x254;

    fn_27_C749C(s + 0x2979C);
    char* commonData = (char*)g_ftCommonDataAccesser.getData((ftKind)23);
    PitCommonState* state = (PitCommonState*)s;
    state->data = commonData;
    state->flagA = 0;
    state->flagB = 0;
    new (l.list) ListInit();
    l.list[9] = lbl_112_bss_1AC;
    l.list[11] = lbl_112_bss_1BC;
    l.list[13] = lbl_112_bss_1CC;
    OBJ(END(0x70))->v29(l.list, 15);
    OBJ(END(0x24))->v7(state->data + 0x8C, 1);
    ((BlendCalls*)END(0x28))->v8(P(state->data, 0x98), 3);
    OBJ(END(0x28))->v14(0, 0, 3);
    l.blend[0] = 0;
    l.blend[1] = 0;
    ((float*)l.blend)[2] = k[2];
    ((float*)l.blend)[3] = k[2];
    ((float*)l.blend)[4] = k[2];
    ((float*)l.blend)[5] = k[2];
    l.blend[6] &= 0x7FFFFFFF;
    fn_27_195B34(P(state->data, 0x9C), l.out, l.blend);
    ((BlendCalls*)END(0x28))->v8(l.blend, 2);
    OBJ(END(0x28))->v14(0, 0, 2);
    return s;
}
