// Best-effort decompilation; instruction differences remain.
#include <ft/ft_fighter_build_data.h>
#include <ft/ft_common_data_accesser.h>
#include <so/so_heap_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/stageobject.h>
#include <types.h>
#include <new>

#pragma force_active on
#pragma use_simple_stdpnew on

inline void* operator new[](size_t, void* storage) { return storage; }

extern "C" {
void fn_27_1257EC(void*, int, int, int, void*);
void fn_106_54A4(void*);
void fn_106_57F8(void*, unsigned int, unsigned int, unsigned char, void*);
void fn_106_5860(void*, void*, int, void*, float);
void fn_106_58E8(void*, void*, int);
void fn_106_5ABC(void*, void*, void*);
void fn_106_5B2C(void*, void*, int);
void fn_27_3513C(void*, s16, void*, void*);
void fn_106_53D8(void*, int, void*);
void fn_106_5B90(void*, void*, int, unsigned char, void*);
void fn_106_5C54(void*, void*, int, unsigned char, void*);
void fn_106_5D18(void*, void*, int, unsigned char);
void fn_106_5DEC(void*, void*, int, unsigned char);
void fn_106_5EC0(void*, void*, int, unsigned char, void*);
void fn_106_5F58(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_106_5FC4(void*, void*, int);
void fn_106_6020(void*, void*, int, void*);
void fn_106_60B0(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_106_6104(void*, void*, s16);
void fn_106_6174(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_106_61E0(void*, s16);
void fn_106_6224(void*, void*, int, int);
void fn_106_66DC(void*, void*);
void fn_106_6AAC(void*);
void fn_106_6B0C(void*, void*, int, int, int, int, void*);
void fn_106_6BD8(void*, void*, unsigned char, void*);
void fn_106_6C70(void*, void*, int);
void fn_106_6CD0(void*, void*, int);
void fn_106_6D4C(void*, void*, void*, void*);
void fn_106_6D68(void*, s16, void*, int, int, float, signed char*);
void* fn_106_6EF8();
void fn_106_6F68(void*, int, int);
void* fn_106_6FE4(void*, int);
void fn_106_7020(void*, int, void*);
void fn_106_53C4(void*, int);
void fn_27_14B5F8(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_14E0B8(void*, int);
void fn_27_14FBD8(void*, void*);
void fn_27_17437C(void*, soModuleAccesser*);
void fn_27_196664(void*, void*);
void fn_27_1A079C(void*, int);
void fn_27_1A61BC(void*, int);
void fn_27_5BED0(void*, void*);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_C749C(void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_C7744(void*, void*, int);
void fn_27_D22D0(void*, int);
void fn_27_126470(StageObject*);
void fn_27_1404D4(void*, soModuleAccesser*);
void* fn_800A6A78(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char lbl_106_data_65C[];
extern char lbl_106_data_144[];
extern char lbl_106_data_C08[];
extern char lbl_106_data_C88[];
extern char lbl_106_data_B58[];
extern char lbl_106_data_D90[];
extern char lbl_106_data_E38[];
extern char lbl_27_data_2F9F8[];
extern char lbl_27_data_2FAA0[];
extern char lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[];
extern char lbl_27_data_2FD40[];
extern char lbl_27_data_2FDE8[];
extern char lbl_27_bss_3AC[];
extern char lbl_27_bss_3CC[];
extern char lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[];
extern char lbl_27_bss_46D8[];
extern char lbl_27_bss_55C[];
extern char lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[];
extern char lbl_27_bss_69C[];
extern char lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_bss_8C4[];
extern char lbl_27_bss_7F34[];
extern char lbl_27_bss_7F44[];
extern char lbl_27_bss_7F54[];
extern char lbl_106_bss_1A4[];
extern char lbl_106_bss_1B4[];
extern char lbl_106_bss_1C4[];
extern char lbl_106_bss_1D4[];
extern float lbl_106_rodata_0;
extern float lbl_106_rodata_4;
}

#define MODULE(type, offset) reinterpret_cast<type*>(builder + (offset))

class SlopeStorage {
public:
    SlopeStorage(void* accesser, u8 initial, int count, float angle) {
        fn_27_ACAC4(this, accesser, initial, count, initial, angle);
    }
};

class ShadowStorage {
public:
    ShadowStorage(void* accesser, int mode, const float* opacity) {
        fn_27_B62E4(this, accesser, *opacity, mode);
    }
};

template<char* table>
class ListenerStorage {
public:
    ListenerStorage(soModuleAccesser* accesser) {
        fn_27_17437C(this, accesser);
        *(void**)this = table;
        *(void**)((char*)this + 4) = table + 0x40;
    }
};

struct BuildDataVirtual {
    virtual int m1(); virtual int m2(); virtual int m3(); virtual int m4();
    virtual int m5(); virtual int m6(); virtual int m7(); virtual int m8();
    virtual int m9(); virtual int m10(); virtual int m11(); virtual int m12();
    virtual int m13(); virtual int m14(); virtual int m15(); virtual int m16();
    virtual int m17(); virtual int m18(); virtual float m19(); virtual int m20();
    virtual int m21(); virtual int m22(); virtual int m23(); virtual int m24();
    virtual int m25(); virtual int m26(); virtual int m27(); virtual int m28();
    virtual int m29(); virtual int m30(); virtual int m31(); virtual int m32();
    virtual float m33(); virtual int m34(); virtual void* m35(int, int);
};

struct EventValueVirtual {
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual s16 value();
};

struct RegisterVirtual {
    virtual void a1();
    virtual void add(void**, s16*);
};

struct RegisterFourVirtual {
    virtual void a1(); virtual void a2(); virtual void a3();
    virtual void add(int, void*);
};

struct CheckVirtual {
    virtual int check();
};

struct InitVirtual {
    virtual void a1();
    virtual void init(soModuleAccesser*);
};

struct Config34Virtual {
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
    virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12();
    virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16();
    virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20();
    virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24();
    virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28();
    virtual void a29(); virtual void a30(); virtual void a31(); virtual void a32();
    virtual void a33(); virtual void a34(void*);
};

struct Config10Virtual {
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
    virtual void a9(); virtual void a10(int);
};

struct Config29Virtual {
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
    virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12();
    virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16();
    virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20();
    virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24();
    virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28();
    virtual void a29(void**, int);
};

extern "C" void* fn_106_70(
    StageObject* object, int entryId, Heaps::HeapType instanceHeap,
    Heaps::HeapType modelHeap, Heaps::HeapType motionHeap)
{
    char* part;
    char* self = (char*)object;

    fn_27_1257EC(object, entryId, 0x11, (int)instanceHeap,
                 (char*)object + 0xb64);

    *(void**)(self + 0x3c) = lbl_106_data_65C;
    *(void**)(self + 0x40) = lbl_106_data_65C + 0x64;
    *(void**)(self + 0x48) = lbl_106_data_65C + 0x70;
    *(void**)(self + 0x54) = lbl_106_data_65C + 0x84;
    *(void**)(self + 0x64) = lbl_106_data_65C + 0xdc;
    *(void**)(self + 0x70) = lbl_106_data_65C + 0xec;
    *(void**)(self + 0x7c) = lbl_106_data_65C + 0xfc;
    *(void**)(self + 0x88) = lbl_106_data_65C + 0x110;
    *(void**)(self + 0x94) = lbl_106_data_65C + 0x128;
    *(void**)(self + 0xa0) = lbl_106_data_65C + 0x140;
    *(void**)(self + 0xac) = lbl_106_data_65C + 0x158;
    *(void**)(self + 0xb8) = lbl_106_data_65C + 0x16c;
    *(void**)(self + 0xc4) = lbl_106_data_65C + 0x180;
    *(void**)(self + 0xd0) = lbl_106_data_65C + 0x190;
    *(void**)(self + 0xdc) = lbl_106_data_65C + 0x1c4;
    *(void**)(self + 0xe8) = lbl_106_data_65C + 0x1d4;
    *(void**)(self + 0xf4) = lbl_106_data_65C + 0x1e8;
    *(void**)(self + 0x100) = lbl_106_data_65C + 0x254;

    struct BitInfo {
        void* p;
        s32 n;
        u32 w1;
        float f[7];
        u32 value : 9;
        u32 enabled : 1;
        u32 remaining : 22;
    };
    struct Locals {
        signed char flags[11];
        s16 values[11];
        void* ptrs[22];
        BitInfo info;
        unsigned long buildDataStorage[
            sizeof(ftFighterBuildData) / sizeof(unsigned long)];
        void* refs[15];
    } local;

#define buildDataStorage local.buildDataStorage
#define flags local.flags
#define values local.values
#define ptrs local.ptrs
#define info local.info
#define refs local.refs

    new (buildDataStorage) ftFighterBuildData(
        entryId, (ftKind)0x11, instanceHeap, modelHeap, motionHeap, 0,
        *(soModuleAccesser**)(self + 0x60), -1, self + 0x8544,
        self + 0x854c);
#define buildData ((ftFighterBuildData*)buildDataStorage)
#define data (reinterpret_cast<BuildDataVirtual*>(buildData))

    char* action9;
    char* action10;
    void* list0;
    void* list1;
    int constant;
    char* p;
    char* base;
    char* builder = (char*)object + 0x194;
    fn_106_54A4(builder);

    new (builder + 0x9d0) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        MODULE(soResourceModule, 0x1168),
        MODULE(soModelModule, 0x1374),
        MODULE(soMotionModule, 0x1664),
        MODULE(soPostureModule, 0x1810),
        MODULE(soGroundModule, 0x18d8),
        MODULE(soSituationModule, 0x1930),
        builder + 0x199c,
        MODULE(soCollisionAttackModule, 0x1ffc),
        MODULE(soCollisionHitModule, 0x2990),
        MODULE(soCollisionShieldModule, 0x2d4c),
        MODULE(soCollisionShieldModule, 0x37b4),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        builder + 0x3988,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        MODULE(soDamageModule, 0x3b1c),
        builder + 0x3c20,
        builder + 0x3c84,
        MODULE(soStopModule, 0x3cb8),
        builder + 0x3cdc,
        builder + 0x3d90,
        MODULE(soSoundModule, 0x3dc0),
        MODULE(soLinkModule, 0x3f94),
        MODULE(soVisibilityModule, 0x3fe8),
        MODULE(soControllerModule, 0x45d0),
        MODULE(soCameraModule, 0x478c),
        MODULE(soWorkManageModule, 0x47b0),
        lbl_27_bss_4BC,
        MODULE(soAnimCmdModule, 0x47e4),
        MODULE(soStatusModule, 0x56e0),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        MODULE(soKineticModule, 0x5790),
        MODULE(soEventManageModule, 0xb8),
        lbl_27_bss_55C,
        MODULE(soEffectModule, 0x5cec),
        builder + 0x5e24,
        MODULE(soAreaModule, 0x5e64),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        builder + 0x6244,
        builder + 0x628c,
        MODULE(soShadowModule, 0x630c),
        MODULE(soItemManageModule, 0x63f8),
        MODULE(soColorBlendModule, 0x6464),
        builder + 0x65b8,
        builder + 0x6604,
        MODULE(soSlowModule, 0x666c),
        lbl_27_bss_69C,
        builder + 0xab0,
        MODULE(soParamCustomizeModule, 0xac8),
        builder + 0x66a8);

    modelHeap = (Heaps::HeapType)buildData->getHeapSlotNo();
    char* motionInstanceHeap =
        (char*)((soModuleAccesserBuildData*)buildDataStorage)
            ->getNWMotionInstanceHeap();
    char* modelInstanceHeap =
        (char*)((soModuleAccesserBuildData*)buildDataStorage)
            ->getNWModelInstanceHeap();
    Heaps::HeapType fighterInstanceHeap =
        ((soModuleAccesserBuildData*)buildDataStorage)->getInstanceHeap();
    new (builder + 0xab0) soHeapModuleImpl(
        fighterInstanceHeap, (Heaps::HeapType)(long)modelInstanceHeap,
        (Heaps::HeapType)(long)motionInstanceHeap, (int)modelHeap);

    fn_27_14B5F8(builder + 0xac8, builder + 0x9d0);
    fn_106_57F8(builder + 0x115c, buildData->getMdlResId(),
        buildData->getAnmResId(), buildData->getResGroupNo(),
        builder + 0x9d0);

    motionInstanceHeap = (char*)data->m25();
    float modelScale = data->m19();
    fn_106_5860(builder + 0x1180, builder + 0x9d0, (int)motionInstanceHeap,
                lbl_27_bss_A48, modelScale);
    fn_106_58E8(builder + 0x1440, builder + 0x9d0, data->m5());
    fn_106_5ABC(builder + 0x17d4, builder + 0x9d0, lbl_27_bss_A48);
    fn_106_5B2C(builder + 0x1888, builder + 0x9d0, data->m9());

    s16 shortValue = ((EventValueVirtual*)((char*)*(void**)(
        *(char**)(builder + 0xaa8) + 0x80) + 8))->value();
    fn_27_3513C(builder + 0x1930, shortValue, builder + 0x9d0,
                lbl_27_bss_A48);
    fn_106_53D8(builder + 0x196c, data->m4(), builder + 0x9d0);
    fn_106_5B90(builder + 0x19e0, builder + 0x9d0, *(int*)(self + 0x28),
        (unsigned char)(*(u32*)(self + 0x2c) >> 7), lbl_27_bss_A48);
    fn_106_5C54(builder + 0x209c, builder + 0x9d0, *(int*)(self + 0x28),
        (unsigned char)(*(u32*)(self + 0x2c) >> 7), lbl_27_bss_A48);
    fn_106_5D18(builder + 0x29f8, builder + 0x9d0, *(int*)(self + 0x28),
        (unsigned char)(*(u32*)(self + 0x2c) >> 7));
    fn_106_5DEC(builder + 0x2da0, builder + 0x9d0, *(int*)(self + 0x28),
        (unsigned char)(*(u32*)(self + 0x2c) >> 7));
    fn_106_5EC0(builder + 0x380c, builder + 0x9d0, *(int*)(self + 0x28),
        (unsigned char)(*(u32*)(self + 0x2c) >> 7), lbl_27_bss_A48);
    fn_106_5F58(builder + 0x3a70, builder + 0x9d0, lbl_27_bss_A48);
    fn_27_64C8C(builder + 0x3c20, builder + 0x9d0, 1);
    fn_27_65EE4(builder + 0x3c84, builder + 0x9d0);
    fn_27_154088(builder + 0x3cb8, builder + 0x9d0);
    fn_27_693F4(builder + 0x3cdc, builder + 0x9d0);
    fn_106_5FC4(builder + 0x3d14, builder + 0x9d0, data->m6());
    fn_106_6020(builder + 0x3dac, builder + 0x9d0, data->m32(),
                lbl_27_bss_A48);
    fn_106_60B0(builder + 0x3e1c, builder + 0x9d0);
    fn_27_5B248(builder + 0x3fe8, builder + 0x9d0, data->m7(), 2);
    fn_106_6104(builder + 0x4018, builder + 0x9d0,
        ((EventValueVirtual*)((char*)*(void**)(
            *(char**)(builder + 0xaa8) + 0x80) + 8))->value());
    fn_106_6174(builder + 0x473c, builder + 0x9d0, data->m22(),
                data->m23(), lbl_27_bss_A48);
    fn_27_A1DA4(builder + 0x47b0, builder + 0x9d0, data->m20());
    fn_106_61E0(builder + 0x47e4,
        ((EventValueVirtual*)((char*)*(void**)(
            *(char**)(builder + 0xaa8) + 0x80) + 8))->value());
    fn_106_6224(builder + 0x48d8, builder + 0x9d0, data->m8(),
                data->m27());
    fn_106_66DC(builder + 0x5790, builder + 0x9d0);
    fn_106_6AAC(builder + 0x5a98);
    fn_106_6B0C(builder + 0x5c80, builder + 0x9d0, data->m10(),
        data->m11(), data->m12(), data->m13(), lbl_27_bss_A48);
    fn_27_14FBD8(builder + 0x5e24, builder + 0x9d0);
    int statusValue = data->m21();
    fn_106_6BD8(builder + 0x5e54, builder + 0x9d0,
                (unsigned char)statusValue, lbl_27_bss_A48);
    data->m15();
    data->m14();
    data->m16();
    fn_106_6C70(builder + 0x61c8, builder + 0x9d0, data->m17());
    new (builder + 0x628c) SlopeStorage(builder + 0x9d0, 0, 1, data->m33());
    new (builder + 0x630c) ShadowStorage(builder + 0x9d0, 0, &lbl_106_rodata_0);
    fn_106_6CD0(builder + 0x6354, builder + 0x9d0, data->m24());
    fn_27_BEBB4(builder + 0x6464, builder + 0x9d0, 10, 1);
    fn_27_C20D8(builder + 0x65b8, builder + 0x9d0, 0, 8, data->m26());
    fn_27_196664(builder + 0x6604, builder + 0x9d0);
    fn_27_5BED0(builder + 0x666c, builder + 0x9d0);
    fn_27_14CCEC(builder + 0x66a8, builder + 0x9d0);

    struct CheckVirtualLocal { virtual int check(); };
    struct RegisterFourLocal {
        virtual void a1(); virtual void a2(); virtual void a3();
        virtual void add(int, void*);
    };
    if (((CheckVirtualLocal*)(builder + 0x5c58))->check() == 0)
        ((RegisterFourLocal*)*(void**)(*(char**)(builder + 0xaa8) + 0x64))
            ->add(1, builder + 0x5c58);

    fn_27_C74BC(builder + 0x6828,
        *(void**)(*(char**)((char*)buildDataStorage + 0xc) + 0x18), 0xf);
    base = builder + 0x6838;
    fn_27_1A61BC(base, 0);
    fn_27_1A61BC(base + 0x490, 0);
    fn_27_D22D0(base + 0x924, 0);
    fn_106_6D4C(base + 0x9d0, base, base + 0x490, fn_106_6EF8());

    struct InfoVirtual {
        virtual void a1(); virtual void a2(); virtual void a3();
        virtual void a4(); virtual void a5(); virtual void a6();
        virtual void a7(void*, int);
    };
#define enumStart (*(char**)(builder + 0xaa8))

    flags[0] = 0;
    s16 ev0 = ((EventValueVirtual*)((char*)*(void**)(
        enumStart + 0x80) + 8))->value();
    fn_106_6D68(base + 0x9ec, ev0, base + 0x924, 0, 1,
                lbl_106_rodata_4, &flags[0]);
    fn_106_6F68(base, 0, 0x121);
    fn_106_6F68(base + 0x490, 0, 0x121);
    fn_106_6F68(fn_106_6EF8(), 0, 0);
    values[0] = 1;
    ptrs[0] = base + 0x9ec;
    ptrs[1] = base + 0x9d0;
    ((RegisterVirtual*)*(void**)(enumStart + 0x6c))->add(
        (void**)&ptrs[0], &values[0]);

    void* cmd0 = data->m35(1, 2);
    data->m35(1, 1);
    cmd0 = data->m35(1, 0);
    modelInstanceHeap = base + 0xa3c;
    fn_27_C7744(modelInstanceHeap, cmd0, 0x1f5);
    fn_27_D22D0(modelInstanceHeap + 0x14, 0);
    fn_106_6D4C(modelInstanceHeap + 0xc0, modelInstanceHeap,
                lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[1] = 0;
    s16 ev1 = ((EventValueVirtual*)((char*)*(void**)(
        enumStart + 0x80) + 8))->value();
    fn_106_6D68(modelInstanceHeap + 0xdc, ev1, modelInstanceHeap + 0x14,
                1, 1, lbl_106_rodata_4, &flags[1]);
    values[1] = 2;
    ptrs[2] = modelInstanceHeap + 0xdc;
    ptrs[3] = modelInstanceHeap + 0xc0;
    ((RegisterVirtual*)*(void**)(enumStart + 0x6c))->add(
        (void**)&ptrs[2], &values[1]);

#define INIT_ACTION(I, OFFSET, MASK, POS, SIZE) do { \
    void* cmd = data->m35((I), 2); \
    data->m35((I), 1); \
    cmd = data->m35((I), 0); \
    char* act = base + (OFFSET); \
    fn_27_C7744(act, cmd, (SIZE)); \
    fn_27_D22D0(act + 0x14, 0); \
    fn_106_6D4C(act + 0xc0, act, lbl_27_bss_D8C, lbl_27_bss_D8C); \
    flags[(POS)] = 0; \
    s16 eventValue = ((EventValueVirtual*)((char*)*(void**)( \
        enumStart + 0x80) + 8))->value(); \
    fn_106_6D68(act + 0xdc, eventValue, act + 0x14, (I), 1, \
        lbl_106_rodata_4, &flags[(POS)]); \
    values[(POS)] = (MASK); \
    ptrs[(POS) * 2] = act + 0xdc; \
    ptrs[(POS) * 2 + 1] = act + 0xc0; \
    ((RegisterVirtual*)*(void**)(enumStart + 0x6c))->add( \
        (void**)&ptrs[(POS) * 2], &values[(POS)]); \
} while (0)

    INIT_ACTION(2, 0xb68, 0x40, 2, 0x1f5);
    INIT_ACTION(3, 0xc94, 0x40, 3, 0x1f5);
    INIT_ACTION(4, 0xdc0, 2, 4, 0x1f5);
    INIT_ACTION(5, 0xeec, 0x20, 5, 0x1f5);
    INIT_ACTION(6, 0x1018, 0x80, 6, 0x1f5);
    INIT_ACTION(7, 0x1144, 0x80, 7, 0x1f5);
    data->m35(8, 2);
    data->m35(8, 1);
    void* cmd8 = data->m35(8, 0);
    motionInstanceHeap = base + 0x1270;
    fn_27_C7744(motionInstanceHeap, cmd8, 0x1f5);
    fn_27_D22D0(motionInstanceHeap + 0x14, 0);
    fn_106_6D4C(motionInstanceHeap + 0xc0, motionInstanceHeap, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[8] = 0;
    s16 event8 = ((EventValueVirtual*)((char*)*(void**)(enumStart + 0x80) + 8))->value();
    fn_106_6D68(motionInstanceHeap + 0xdc, event8, motionInstanceHeap + 0x14, 8, 1, lbl_106_rodata_4, &flags[8]);
    values[8] = 0x20;
    ptrs[16] = motionInstanceHeap + 0xdc;
    ptrs[17] = motionInstanceHeap + 0xc0;
    ((RegisterVirtual*)*(void**)(enumStart + 0x6c))->add((void**)&ptrs[16], &values[8]);

    action9 = base + 0x139c;
    flags[9] = 1;
    s16 ev9 = ((EventValueVirtual*)((char*)*(void**)(
        enumStart + 0x80) + 8))->value();
    fn_106_6D68(action9, ev9, action9 + 0x50, 9, 1,
                lbl_106_rodata_4, &flags[9]);
    fn_27_1A079C(action9 + 0x50, 0);
    values[9] = 4;
    ptrs[18] = action9;
    ptrs[19] = lbl_27_bss_8C4;
    ((RegisterVirtual*)*(void**)(enumStart + 0x6c))->add(
        (void**)&ptrs[18], &values[9]);

    data->m35(10, 2);
    data->m35(10, 1);
    void* cmd10 = data->m35(10, 0);
    action10 = base + 0x14c0;
    fn_27_C7744(action10, cmd10, 0x29);
    fn_27_D22D0(action10 + 0x14, 0);
    fn_106_6D4C(action10 + 0xc0, action10, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[10] = 0;
    s16 event10 = ((EventValueVirtual*)((char*)*(void**)(enumStart + 0x80) + 8))->value();
    fn_106_6D68(action10 + 0xdc, event10, action10 + 0x14, 10, 1, lbl_106_rodata_4, &flags[10]);
    values[10] = 0x10;
    ptrs[20] = action10 + 0xdc;
    ptrs[21] = action10 + 0xc0;
    ((RegisterVirtual*)*(void**)(enumStart + 0x6c))->add((void**)&ptrs[20], &values[10]);
#undef INIT_ACTION

    list0 = data->m35(0, 0);
    fn_106_6F68(fn_106_6FE4(base, 0), (int)list0, 0x112);
    list1 = data->m35(0, 1);
    fn_106_6F68(fn_106_6FE4(base, 1), (int)list1, 0x112);
    fn_106_6F68(fn_106_6FE4(base, 0),
        (int)*(void**)(*(char**)((char*)buildDataStorage + 0xc) + 0x24),
        0xf);
    fn_106_6F68(fn_106_6FE4(base, 1),
        (int)*(void**)(*(char**)((char*)buildDataStorage + 0xc) + 0x28),
        0xf);
    fn_106_7020(base, 0, buildData->getAnimCmdDisguiseList(false, 0));
    fn_106_7020(base, 1, buildData->getAnimCmdDisguiseList(false, 1));

    ((Config34Virtual*)*(void**)(enumStart + 0x70))->a34(builder + 0x6828);
    constant = (int)soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(builder + 0x9d0), 0xa805, 0);
    void* casted = __dynamic_cast(*(void**)(enumStart + 0x90), 0,
        lbl_106_data_D90, lbl_106_data_E38, 0);
    if (casted)
        fn_27_14E0B8(casted, constant);
    ((Config10Virtual*)*(void**)(enumStart + 0x90))->a10(constant);

    fn_27_1404D4(self + 0x7fb8, *(soModuleAccesser**)(self + 0x60));
    part = self + 0x7ff4;
    fn_106_53C4(part, 0);
    *(void**)part = lbl_106_data_C08;

    soModuleAccesser* listenerAccesser = *(soModuleAccesser**)(self + 0x60);
    p = self + 0x84ac;
    fn_106_53C4(p, 0);
    *(void**)p = lbl_106_data_C88;

    new (p + 0x08) ListenerStorage<lbl_27_data_2F9F8>(listenerAccesser);
    new (p + 0x20) ListenerStorage<lbl_27_data_2FAA0>(listenerAccesser);
    new (p + 0x34) ListenerStorage<lbl_27_data_2FB48>(listenerAccesser);
    new (p + 0x48) ListenerStorage<lbl_27_data_2FBF0>(listenerAccesser);
    new (p + 0x5c) ListenerStorage<lbl_27_data_2FC98>(listenerAccesser);
    new (p + 0x70) ListenerStorage<lbl_27_data_2FD40>(listenerAccesser);
    new (p + 0x84) ListenerStorage<lbl_27_data_2FDE8>(listenerAccesser);

    int constant1 = (int)soValueAccesser::getConstantIndefinite(
        *(soModuleAccesser**)(self + 0x60), 0xa7f9, 0);
    *(void**)(self + 0x8544) = (void*)constant1;
    *(int*)(self + 0x8548) = 1;

    int constant2 = (int)soValueAccesser::getConstantIndefinite(
        *(soModuleAccesser**)(self + 0x60), 0xa7fc, 0);
    *(void**)(self + 0x854c) = (void*)constant2;
    *(int*)(self + 0x8550) = 1;

    fn_27_126470(reinterpret_cast<StageObject*>(self));
    ((InitVirtual*)(self + 0x7fb8))->init(
        *(soModuleAccesser**)(self + 0x60));
    char* event = self + 0x8554;
    fn_800A6A78(event);
    *(void**)(event + 8) = lbl_106_data_B58;

    *(void**)(self + 0x3c) = lbl_106_data_144;
    *(void**)(self + 0x40) = lbl_106_data_144 + 0x64;
    *(void**)(self + 0x48) = lbl_106_data_144 + 0x70;
    *(void**)(self + 0x54) = lbl_106_data_144 + 0x84;
    *(void**)(self + 0x64) = lbl_106_data_144 + 0xdc;
    *(void**)(self + 0x70) = lbl_106_data_144 + 0xec;
    *(void**)(self + 0x7c) = lbl_106_data_144 + 0xfc;
    *(void**)(self + 0x88) = lbl_106_data_144 + 0x110;
    *(void**)(self + 0x94) = lbl_106_data_144 + 0x128;
    *(void**)(self + 0xa0) = lbl_106_data_144 + 0x140;
    *(void**)(self + 0xac) = lbl_106_data_144 + 0x158;
    *(void**)(self + 0xb8) = lbl_106_data_144 + 0x16c;
    *(void**)(self + 0xc4) = lbl_106_data_144 + 0x180;
    *(void**)(self + 0xd0) = lbl_106_data_144 + 0x190;
    *(void**)(self + 0xdc) = lbl_106_data_144 + 0x1c4;
    *(void**)(self + 0xe8) = lbl_106_data_144 + 0x1d4;
    *(void**)(self + 0xf4) = lbl_106_data_144 + 0x1e8;
    *(void**)(self + 0x100) = lbl_106_data_144 + 0x254;
    *(void**)(self + 0x855c) = lbl_106_data_144 + 0x3b0;
    fn_27_C749C(self + 0x8560);

    *(void**)(self + 0x8570) =
        g_ftCommonDataAccesser.getData((ftKind)0x11);

    typedef void* StatusPointer;
    new (refs) StatusPointer[15]();
    refs[0] = lbl_27_bss_7F34;
    refs[1] = lbl_106_bss_1A4;
    refs[2] = lbl_106_bss_1B4;
    refs[3] = lbl_106_bss_1C4;
    refs[4] = lbl_106_bss_1D4;
    refs[5] = lbl_27_bss_7F44;
    refs[6] = lbl_27_bss_7F54;
    refs[8] = lbl_106_bss_1A4;
    refs[9] = lbl_106_bss_1A4;
    refs[10] = lbl_106_bss_1A4;
    refs[11] = lbl_106_bss_1C4;
    refs[12] = lbl_106_bss_1D4;
    refs[13] = lbl_106_bss_1D4;
    refs[14] = lbl_106_bss_1D4;

    ((Config29Virtual*)*(void**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70))
        ->a29((void**)refs, 0xf);

    {
        char* src = *(char**)(*(char**)(self + 0x8570) + 0x8c);
        info.f[0] = *(float*)(src + 4);
        info.f[1] = *(float*)(src + 8);
        info.f[2] = *(float*)(src + 0xc);
        info.f[3] = *(float*)(src + 4);
        info.f[4] = *(float*)(src + 8);
        info.f[5] = *(float*)(src + 0xc);
        info.f[6] = *(float*)(src + 0x10);
        info.value = *(u32*)src;
        info.enabled = 1;
        info.w1 &= 0x0fffffff;
        info.p = info.f;
        info.n = 1;
    }

    ((InfoVirtual*)*(void**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x24))->a7(&info, 1);
    return (StageObject*)self;
}

#undef enumStart
#undef data
#undef buildData
#undef refs
#undef info
#undef ptrs
#undef values
#undef flags
#undef buildDataStorage
#undef MODULE
