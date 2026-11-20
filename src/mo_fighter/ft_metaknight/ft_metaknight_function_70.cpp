#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>
#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

inline void* operator new[](size_t, void* storage) {
    return storage;
}

struct FloatObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int getValue();
};
struct Obj3 {
    virtual void v0();
    virtual void method(void**, short*);
};
struct Q1 {
    virtual int f();
};
struct Q2 {
    virtual void a();
    virtual void b(void*);
};
struct Q4 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void put(int, void*);
};
struct Q10 {
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
    virtual void a9();
    virtual void put(int);
};
struct Q29 {
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
    virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12();
    virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16();
    virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20();
    virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24();
    virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28();
    virtual void call(void*, int);
};
struct Q34 {
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
    virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12();
    virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16();
    virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20();
    virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24();
    virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28();
    virtual void a29(); virtual void a30(); virtual void a31(); virtual void a32();
    virtual void a33();
    virtual void put(void*);
};
struct BD {
    virtual int m1(); virtual int m2(); virtual int m3(); virtual int m4();
    virtual int m5(); virtual int m6(); virtual int m7(); virtual int m8();
    virtual int m9(); virtual int m10(); virtual int m11(); virtual int m12();
    virtual int m13(); virtual int m14(); virtual int m15(); virtual int m16();
    virtual int m17(); virtual int m18(); virtual f32 m19(); virtual int m20();
    virtual int m21(); virtual int m22(); virtual int m23(); virtual int m24();
    virtual int m25(); virtual int m26(); virtual int m27(); virtual int m28();
    virtual int m29(); virtual int m30(); virtual int m31(); virtual int m32();
    virtual f32 m33(); virtual int m34(); virtual int m35(int, int);
};

extern "C" {
soModuleAccesser* __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(soModuleAccesser*, StageObject*, soResourceModule*, soModelModule*, soMotionModule*, soPostureModule*, soGroundModule*, soSituationModule*, void*, soCollisionAttackModule*, soCollisionHitModule*, soCollisionShieldModule*, soCollisionShieldModule*, soCollisionShieldModule*, void*, soCollisionSearchModule*, soDamageModule*, void*, void*, soStopModule*, void*, void*, soSoundModule*, soLinkModule*, soVisibilityModule*, soControllerModule*, soCameraModule*, soWorkManageModule*, void*, soAnimCmdModule*, soStatusModule*, void*, void*, soKineticModule*, soEventManageModule*, void*, soEffectModule*, void*, soAreaModule*, void*, void*, void*, void*, soShadowModule*, soItemManageModule*, soColorBlendModule*, void*, void*, soSlowModule*, void*, void*, soParamCustomizeModule*, void*);
ftFighterBuildData* __ct__18ftFighterBuildDataFl6ftKindQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypeUcP16soModuleAccesserlPvPv(ftFighterBuildData*, s32, ftKind, Heaps::HeapType, Heaps::HeapType, Heaps::HeapType, u8, soModuleAccesser*, s32, void*, void*);
void __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(void*, int, int, int, int);
int getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
int getData__20ftCommonDataAccesserCF6ftKind(void*, int);
void* __dynamic_cast(void*, long, void*, void*, short);
void fn_27_14E0B8(void*, int);
void fn_27_126470(void*);
void fn_27_14B5F8(void*, void*);
void fn_27_1257EC(void*, int, int, int, void*);
void* fn_111_5F40(void*);
void fn_27_C749C(void*);
void fn_27_C7744(void*, int, int);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_111_6B4C(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, int, int);
void fn_27_1A62C0(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_1A079C(void*, int);
void fn_111_78F8(void*, void*, void*, void*);
void fn_111_7914(void*, short, void*, int, int, float, signed char*);
void* fn_111_7AA4();
void fn_111_6294(void*, int, int, unsigned char, void*);
void* fn_111_62FC(void*, soModuleAccesser*, f32, void*, void*);
void fn_111_6384(void*, void*, int);
void fn_111_6558(void*, void*, void*);
void fn_111_65C8(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_111_5E74(void*, int, void*);
void fn_111_662C(void*, void*, int, unsigned char, void*);
void fn_111_66F0(void*, void*, int, unsigned char, void*);
void fn_111_67B4(void*, void*, int, unsigned char);
void fn_111_6888(void*, void*, int, unsigned char);
void fn_111_695C(void*, void*, int, unsigned char, void*);
void fn_111_69F4(void*, void*, void*);
void fn_111_6A60(void*, void*, int);
void fn_111_6ABC(void*, void*, int, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_111_6BA0(void*, void*, short);
void fn_111_6C10(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_111_6C7C(void*, short);
void fn_111_6CC0(void*, void*, int, int);
void fn_111_7178(void*, void*);
void fn_111_7548(void*);
void fn_111_75A8(void*, void*);
void fn_111_76B8(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_111_7784(void*, void*, unsigned char, void*);
void fn_111_781C(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8, f32);
void fn_27_B62E4(void*, void*, f32, int);
void fn_111_787C(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_111_5E60(void*, int);
void fn_27_17437C(void*, void*);
void* fn_111_7B90(void*, int);
void fn_111_7B14(void*, int, int);
void fn_111_7BCC(void*, int, int);

extern char lbl_111_data_610[];
extern char lbl_111_data_120[];
extern char lbl_111_data_F6C[];
extern char lbl_111_data_FEC[];
extern char lbl_111_data_10F4[];
extern char lbl_111_data_119C[];
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
extern char lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[];
extern char lbl_27_bss_69C[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_bss_8C4[];
extern char lbl_27_bss_A48[];
extern char lbl_27_bss_80A4[];
extern char lbl_111_bss_184[];
extern char lbl_111_bss_194[];
extern char lbl_111_bss_1A4[];
extern char lbl_111_bss_1B4[];
extern char lbl_111_bss_1C4[];
extern float lbl_111_rodata_0;
extern float lbl_111_rodata_4;
}

class SlopeStorage {
public:
    SlopeStorage(void* accesser, u8 initial, int count, f32 angle) {
        fn_27_ACAC4(this, accesser, initial, count, initial, angle);
    }
};

class ShadowStorage {
public:
    ShadowStorage(void* accesser, int mode) {
        fn_27_B62E4(this, accesser, lbl_111_rodata_0, mode);
    }
};

class ColorBlendStorage {
public:
    ColorBlendStorage(void* accesser, int count, int enabled) {
        fn_27_BEBB4(this, accesser, count, enabled);
    }
};

class JostleStorage {
public:
    JostleStorage(void* accesser, int id, int count, int data) {
        fn_27_C20D8(this, accesser, id, count, data);
    }
};

#define LO(x) (local + (x) - 0xc0)
#define BDP ((BD*)LO(0x13c))
#define bd BDP

#define ENTRY_IMPL(OFF, IDX, FLAG, SHORT, SVAL, PTR, SZ, DECL, e_) \
    { \
    BDP->m35(IDX, 2); \
    BDP->m35(IDX, 1); \
    int data_ = BDP->m35(IDX, 0); \
    DECL e_ = g + (OFF); \
    fn_27_C7744(e_, data_, SZ); \
    fn_27_D22D0(e_ + 0x14, 0); \
    fn_111_78F8(e_ + 0xc0, e_, lbl_27_bss_D8C, lbl_27_bss_D8C); \
    *LO(FLAG) = 0; \
    { \
        FloatObj* fo_ = (FloatObj*)(*(char**)(*(char**)(base + 0xaa8) + 0x80) + 8); \
        int v_ = fo_->getValue(); \
        fn_111_7914(e_ + 0xdc, (short)v_, e_ + 0x14, IDX, 1, lbl_111_rodata_4, (signed char*)LO(FLAG)); \
    } \
    *(short*)LO(SHORT) = SVAL; \
    *(void**)LO(PTR) = e_ + 0xdc; \
    *(void**)LO((PTR) + 4) = e_ + 0xc0; \
    ((Obj3*)*(char**)(*(char**)(base + 0xaa8) + 0x6c))->method((void**)LO(PTR), (short*)LO(SHORT)); \
    }

#define ENTRY(OFF, IDX, FLAG, SHORT, SVAL, PTR) \
    ENTRYN(OFF, IDX, FLAG, SHORT, SVAL, PTR, 0x1ec)

#define ENTRYN(OFF, IDX, FLAG, SHORT, SVAL, PTR, SZ) \
    ENTRY_IMPL(OFF, IDX, FLAG, SHORT, SVAL, PTR, SZ, char*, e_)

#define FV() \
    ((FloatObj*)(*(char**)(*(char**)(base + 0xaa8) + 0x80) + 8))->getValue()

template <char* Table>
class ActionLeafStorage {
public:
    ActionLeafStorage(void* accesser) {
        fn_27_17437C(this, accesser);
        char* storage = (char*)this;
        *(char**)storage = Table;
        *(char**)(storage + 4) = Table + 0x40;
    }
};

#define TAILOBJ(OFF, VT) new ((char*)heap + (OFF)) ActionLeafStorage<VT>(base);

extern "C" void* fn_111_70(char* s, int entry, int heap,
                         Heaps::HeapType param, Heaps::HeapType context) {
    __declspec(align(4)) char local[0xf0];

    fn_27_1257EC(s, entry, 0x16, (int)heap, s + 0xb64);
    *(void**)(s + 0x3c) = lbl_111_data_610;
    *(void**)(s + 0x40) = lbl_111_data_610 + 0x64;
    *(void**)(s + 0x48) = lbl_111_data_610 + 0x70;
    *(void**)(s + 0x54) = lbl_111_data_610 + 0x84;
    *(void**)(s + 0x64) = lbl_111_data_610 + 0xdc;
    *(void**)(s + 0x70) = lbl_111_data_610 + 0xec;
    *(void**)(s + 0x7c) = lbl_111_data_610 + 0xfc;
    *(void**)(s + 0x88) = lbl_111_data_610 + 0x110;
    *(void**)(s + 0x94) = lbl_111_data_610 + 0x128;
    *(void**)(s + 0xa0) = lbl_111_data_610 + 0x140;
    *(void**)(s + 0xac) = lbl_111_data_610 + 0x158;
    *(void**)(s + 0xb8) = lbl_111_data_610 + 0x16c;
    *(void**)(s + 0xc4) = lbl_111_data_610 + 0x180;
    *(void**)(s + 0xd0) = lbl_111_data_610 + 0x190;
    *(void**)(s + 0xdc) = lbl_111_data_610 + 0x1c4;
    *(void**)(s + 0xe8) = lbl_111_data_610 + 0x1d4;
    *(void**)(s + 0xf4) = lbl_111_data_610 + 0x1e8;
    *(void**)(s + 0x100) = lbl_111_data_610 + 0x254;

    __ct__18ftFighterBuildDataFl6ftKindQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypeUcP16soModuleAccesserlPvPv(
        (ftFighterBuildData*)LO(0x13c), entry, (ftKind)0x16, (Heaps::HeapType)heap,
        param, context, 0, *(soModuleAccesser**)(s + 0x60), -1,
        s + 0xa5ec, s + 0xa5f4);

    char* g;
    char* thread10;
    char* thread8;
    char* thread1;
    char* base = s + 0x194;
    fn_111_5F40(base);

    __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(
        (soModuleAccesser*)(base + 0x9d0),
        (StageObject*)s,
        (soResourceModule*)(base + 0x1168),
        (soModelModule*)(base + 0x1374),
        (soMotionModule*)(base + 0x1664),
        (soPostureModule*)(base + 0x1810),
        (soGroundModule*)(base + 0x18d8),
        (soSituationModule*)(base + 0x1930),
        (void*)(base + 0x199c),
        (soCollisionAttackModule*)(base + 0x1fbc),
        (soCollisionHitModule*)(base + 0x2950),
        (soCollisionShieldModule*)(base + 0x2b7c),
        (soCollisionShieldModule*)(base + 0x35e4),
        (soCollisionShieldModule*)lbl_27_bss_3AC,
        (void*)(base + 0x37b8),
        (soCollisionSearchModule*)lbl_27_bss_3CC,
        (soDamageModule*)(base + 0x394c),
        (void*)(base + 0x3a50),
        (void*)(base + 0x3ab4),
        (soStopModule*)(base + 0x3ae8),
        (void*)(base + 0x3b0c),
        (void*)(base + 0x3bc0),
        (soSoundModule*)(base + 0x3bf0),
        (soLinkModule*)(base + 0x3ec8),
        (soVisibilityModule*)(base + 0x3f1c),
        (soControllerModule*)(base + 0x4504),
        (soCameraModule*)(base + 0x46c0),
        (soWorkManageModule*)(base + 0x46e4),
        (void*)lbl_27_bss_4BC,
        (soAnimCmdModule*)(base + 0x4718),
        (soStatusModule*)(base + 0x560c),
        (void*)lbl_27_bss_46C0,
        (void*)lbl_27_bss_46D8,
        (soKineticModule*)(base + 0x56bc),
        (soEventManageModule*)(base + 0xb8),
        (void*)(base + 0x7ce4),
        (soEffectModule*)(base + 0x7d8c),
        (void*)(base + 0x7ec4),
        (soAreaModule*)(base + 0x7f04),
        (void*)lbl_27_bss_5B0,
        (void*)lbl_27_bss_5D8,
        (void*)(base + 0x82e4),
        (void*)(base + 0x832c),
        (soShadowModule*)(base + 0x83ac),
        (soItemManageModule*)(base + 0x8498),
        (soColorBlendModule*)(base + 0x8504),
        (void*)(base + 0x8658),
        (void*)(base + 0x86a4),
        (soSlowModule*)(base + 0x870c),
        (void*)lbl_27_bss_69C,
        (void*)(base + 0xab0),
        (soParamCustomizeModule*)(base + 0xac8),
        (void*)(base + 0x8748));

    {
        s32 a = bd->m31();
        thread8 = (char*)bd->m30();
        thread1 = (char*)bd->m29();
        int d = bd->m28();
        __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(
            base + 0xab0, d, (int)thread1, (int)thread8, a);
    }

    fn_27_14B5F8(base + 0xac8, base + 0x9d0);
    {
        int group = bd->m3();
        fn_111_6294(base + 0x115c, bd->m1(), bd->m2(),
                    (unsigned char)group, base + 0x9d0);
    }
    {
        thread8 = (char*)bd->m25();
        f32 scale = bd->m19();
        fn_111_62FC(base + 0x1180, (soModuleAccesser*)(base + 0x9d0),
                    scale, thread8, lbl_27_bss_A48);
    }
    {
        int a = bd->m5();
        fn_111_6384(base + 0x1440, base + 0x9d0, a);
    }
    fn_111_6558(base + 0x17d4, base + 0x9d0, lbl_27_bss_A48);
    {
        int a = bd->m9();
        fn_111_65C8(base + 0x1888, base + 0x9d0, a);
    }
    {
        int v = FV();
        fn_27_3513C(base + 0x1930, (short)v, base + 0x9d0, lbl_27_bss_A48);
    }
    {
        int a = bd->m4();
        fn_111_5E74(base + 0x196c, a, base + 0x9d0);
    }

    fn_111_662C(base + 0x19e0, base + 0x9d0, *(int*)(s + 0x28),
                (unsigned char)(*(unsigned int*)(s + 0x2c) >> 7), lbl_27_bss_A48);
    fn_111_66F0(base + 0x205c, base + 0x9d0, *(int*)(s + 0x28),
                (unsigned char)(*(unsigned int*)(s + 0x2c) >> 7), lbl_27_bss_A48);
    fn_111_67B4(base + 0x29b8, base + 0x9d0, *(int*)(s + 0x28),
                (unsigned char)(*(unsigned int*)(s + 0x2c) >> 7));
    fn_111_6888(base + 0x2bd0, base + 0x9d0, *(int*)(s + 0x28),
                (unsigned char)(*(unsigned int*)(s + 0x2c) >> 7));
    fn_111_695C(base + 0x363c, base + 0x9d0, *(int*)(s + 0x28),
                (unsigned char)(*(unsigned int*)(s + 0x2c) >> 7), lbl_27_bss_A48);
    fn_111_69F4(base + 0x38a0, base + 0x9d0, lbl_27_bss_A48);
    fn_27_64C8C(base + 0x3a50, base + 0x9d0, 1);
    fn_27_65EE4(base + 0x3ab4, base + 0x9d0);
    fn_27_154088(base + 0x3ae8, base + 0x9d0);
    fn_27_693F4(base + 0x3b0c, base + 0x9d0);
    {
        int a = bd->m6();
        fn_111_6A60(base + 0x3b44, base + 0x9d0, a);
    }
    {
        int a = bd->m32();
        fn_111_6ABC(base + 0x3bdc, base + 0x9d0, a, lbl_27_bss_A48);
    }
    fn_111_6B4C(base + 0x3c4c, base + 0x9d0);
    {
        int a = bd->m7();
        fn_27_5B248(base + 0x3f1c, base + 0x9d0, a, 2);
    }
    {
        int v = FV();
        fn_111_6BA0(base + 0x3f4c, base + 0x9d0, (short)v);
    }
    fn_111_6C10(base + 0x4670, base + 0x9d0, bd->m22(), bd->m23(), lbl_27_bss_A48);
    {
        int a = bd->m20();
        fn_27_A1DA4(base + 0x46e4, base + 0x9d0, a);
    }
    {
        int v = FV();
        fn_111_6C7C(base + 0x4718, (short)v);
    }
    fn_111_6CC0(base + 0x480c, base + 0x9d0, bd->m8(), bd->m27());

    fn_111_7178(base + 0x56bc, base + 0x9d0);
    fn_111_7548(base + 0x59c4);
    fn_111_75A8(base + 0x5ba8, base + 0x9d0);
    fn_111_76B8(base + 0x7d20, base + 0x9d0,
                bd->m10(), bd->m11(), bd->m12(), bd->m13(), lbl_27_bss_A48);
    fn_27_14FBD8(base + 0x7ec4, base + 0x9d0);
    {
        int a = bd->m21();
        fn_111_7784(base + 0x7ef4, base + 0x9d0, (unsigned char)a, lbl_27_bss_A48);
    }
    bd->m15();
    bd->m14();
    bd->m16();
    {
        int a = bd->m17();
        fn_111_781C(base + 0x10000 - 0x7d98, base + 0x9d0, a);
    }
    new (base + 0x832c) SlopeStorage(base + 0x9d0, 0, 1, bd->m33());
    new (base + 0x83ac) ShadowStorage(base + 0x9d0, 0);
    {
        int a = bd->m24();
        fn_111_787C(base + 0x10000 - 0x7c0c, base + 0x9d0, a);
    }
    new (base + 0x8504) ColorBlendStorage(base + 0x9d0, 10, 1);
    new (base + 0x8658) JostleStorage(base + 0x9d0, 0, 8, bd->m26());
    fn_27_196664(base + 0x10000 - 0x795c, base + 0x9d0);
    fn_27_5BED0(base + 0x10000 - 0x78f4, base + 0x9d0);
    fn_27_14CCEC(base + 0x10000 - 0x78b8, base + 0x9d0);

    if (((Q1*)(base + 0x5b84))->f() == 0) {
        ((Q4*)*(char**)(*(char**)(base + 0xaa8) + 0x64))->put(1, base + 0x5b84);
    }

    fn_27_C74BC(base + 0x10000 - 0x7738,
                 *(int*)(*(char**)(LO(0x13c) + 0xc) + 0x18), 0x10);
    g = base + 0x10000 - 0x7728;
    fn_27_1A62C0(g, 0);
    fn_27_1A62C0(g + 0x494, 0);
    fn_27_D22D0(g + 0x92c, 0);
    fn_111_78F8(g + 0x9d8, g, g + 0x494, fn_111_7AA4());

    *LO(0xc0) = 0;
    int v0 = FV();
    fn_111_7914(g + 0x9f4, (short)v0, g + 0x92c,
                 0, 1, lbl_111_rodata_4, (signed char*)LO(0xc0));
    fn_111_7B14(g, 0, 0x122);
    fn_111_7B14(g + 0x494, 0, 0x122);
    fn_111_7B14(fn_111_7AA4(), 0, 0);

    *(short*)LO(0xcc) = 1;
    *(void**)LO(0xe4) = g + 0x9f4;
    *(void**)LO(0xe8) = g + 0x9d8;
    ((Obj3*)*(char**)(*(char**)(base + 0xaa8) + 0x6c))->method(
        (void**)LO(0xe4), (short*)LO(0xcc));

    ENTRY_IMPL(0xa44, 1, 0xc1, 0xce, 2, 0xec, 0x1ec, , thread1)
    ENTRY(0xb70, 2, 0xc2, 0xd0, 0x40, 0xf4)
    ENTRY(0xc9c, 3, 0xc3, 0xd2, 0x40, 0xfc)
    ENTRY(0xdc8, 4, 0xc4, 0xd4, 2, 0x104)
    ENTRY(0xef4, 5, 0xc5, 0xd6, 0x20, 0x10c)
    ENTRY(0x1020, 6, 0xc6, 0xd8, 0x80, 0x114)
    ENTRY(0x114c, 7, 0xc7, 0xda, 0x80, 0x11c)
    ENTRY_IMPL(0x1278, 8, 0xc8, 0xdc, 0x20, 0x124, 0x1ec, , thread8)

    thread8 = g + 0x13a4;
    *LO(0xc9) = 1;
    {
        int v9 = FV();
        fn_111_7914(thread8, (short)v9, thread8 + 0x50,
                     9, 1, lbl_111_rodata_4, (signed char*)LO(0xc9));
    }
    fn_27_1A079C(thread8 + 0x50, 0);
    *(short*)LO(0xde) = 4;
    *(void**)LO(0x12c) = thread8;
    *(void**)LO(0x130) = lbl_27_bss_8C4;
    ((Obj3*)*(char**)(*(char**)(base + 0xaa8) + 0x6c))->method(
        (void**)LO(0x12c), (short*)LO(0xde));

    ENTRY_IMPL(0x14c8, 10, 0xca, 0xe0, 0x10, 0x134, 0x29, , thread10)

    {
        thread10 = (char*)BDP->m35(0, 0);
        fn_111_7B14(fn_111_7B90(g, 0), (int)thread10, 0x112);
        thread10 = (char*)BDP->m35(0, 1);
        fn_111_7B14(fn_111_7B90(g, 1), (int)thread10, 0x112);
        fn_111_7B14(fn_111_7B90(g, 0),
                    *(int*)(*(char**)(LO(0x13c) + 0xc) + 0x24), 0x10);
        fn_111_7B14(fn_111_7B90(g, 1),
                    *(int*)(*(char**)(LO(0x13c) + 0xc) + 0x28), 0x10);
        fn_111_7BCC(g, 0,
                    (int)((ftFighterBuildData*)LO(0x13c))->getAnimCmdDisguiseList(false, 0));
        fn_111_7BCC(g, 1,
                    (int)((ftFighterBuildData*)LO(0x13c))->getAnimCmdDisguiseList(false, 1));
    }

    ((Q34*)*(char**)(*(char**)(base + 0xaa8) + 0x70))->put(
        base + 0x10000 - 0x7738);

    {
        thread10 = (char*)soValueAccesser::getConstantIndefinite(
            (soModuleAccesser*)(base + 0x9d0), 0x10000 - 0x57fb, 0);
        void* o = *(void**)(*(char**)(base + 0xaa8) + 0x90);
        void* p = __dynamic_cast(o, 0, lbl_111_data_10F4, lbl_111_data_119C, 0);
        if (p) {
            fn_27_14E0B8(p, (int)thread10);
        }
        ((Q10*)*(void**)(*(char**)(base + 0xaa8) + 0x90))->put((int)thread10);
    }

    fn_27_1404D4(s + 0x10000 - 0x5fa0, *(void**)(s + 0x60));
    thread10 = s + 0xa09c;
    fn_111_5E60(thread10, 0);
    *(void**)thread10 = lbl_111_data_F6C;

    base = *(char**)(s + 0x60);
    heap = (int)(s + 0xa554);
    fn_111_5E60((char*)heap, 0);
    *(void**)heap = lbl_111_data_FEC;

    TAILOBJ(0x8, lbl_27_data_2F9F8)
    TAILOBJ(0x20, lbl_27_data_2FAA0)
    TAILOBJ(0x34, lbl_27_data_2FB48)
    TAILOBJ(0x48, lbl_27_data_2FBF0)
    TAILOBJ(0x5c, lbl_27_data_2FC98)
    TAILOBJ(0x70, lbl_27_data_2FD40)
    TAILOBJ(0x84, lbl_27_data_2FDE8)

    {
        int c1 = (int)soValueAccesser::getConstantIndefinite(
            *(soModuleAccesser**)(s + 0x60), 0x10000 - 0x5807, 0);
        *(int*)(s + 0x10000 - 0x5a14) = c1;
        *(int*)(s + 0x10000 - 0x5a10) = 1;

        int c2 = (int)soValueAccesser::getConstantIndefinite(
            *(soModuleAccesser**)(s + 0x60), 0x10000 - 0x5804, 0);
        *(int*)(s + 0x10000 - 0x5a0c) = c2;
        *(int*)(s + 0x10000 - 0x5a08) = 1;
    }

    fn_27_126470(s);
    ((Q2*)(s + 0x10000 - 0x5fa0))->b(*(void**)(s + 0x60));

    *(void**)(s + 0x3c) = lbl_111_data_120;
    *(void**)(s + 0x40) = lbl_111_data_120 + 0x64;
    *(void**)(s + 0x48) = lbl_111_data_120 + 0x70;
    *(void**)(s + 0x54) = lbl_111_data_120 + 0x84;
    *(void**)(s + 0x64) = lbl_111_data_120 + 0xdc;
    *(void**)(s + 0x70) = lbl_111_data_120 + 0xec;
    *(void**)(s + 0x7c) = lbl_111_data_120 + 0xfc;
    *(void**)(s + 0x88) = lbl_111_data_120 + 0x110;
    *(void**)(s + 0x94) = lbl_111_data_120 + 0x128;
    *(void**)(s + 0xa0) = lbl_111_data_120 + 0x140;
    *(void**)(s + 0xac) = lbl_111_data_120 + 0x158;
    *(void**)(s + 0xb8) = lbl_111_data_120 + 0x16c;
    *(void**)(s + 0xc4) = lbl_111_data_120 + 0x180;
    *(void**)(s + 0xd0) = lbl_111_data_120 + 0x190;
    *(void**)(s + 0xdc) = lbl_111_data_120 + 0x1c4;
    *(void**)(s + 0xe8) = lbl_111_data_120 + 0x1d4;
    *(void**)(s + 0xf4) = lbl_111_data_120 + 0x1e8;
    *(void**)(s + 0x100) = lbl_111_data_120 + 0x254;

    fn_27_C749C(s + 0xa5fc);
    *(ftData**)(s + 0x10000 - 0x59f4) =
        g_ftCommonDataAccesser.getData((ftKind)0x16);

    {
        typedef void* StatusPointer;
        new (LO(0x16c)) StatusPointer[16]();
        *(void**)LO(0x180) = lbl_27_bss_80A4;
        *(void**)LO(0x188) = lbl_111_bss_184;
        *(void**)LO(0x18c) = lbl_111_bss_194;
        *(void**)LO(0x1a0) = lbl_111_bss_1C4;
        *(void**)LO(0x1a4) = lbl_111_bss_1B4;
        *(void**)LO(0x1a8) = lbl_111_bss_1A4;
        ((Q29*)*(char**)(*(char**)(*(char**)(s + 0x60) + 0xd8) + 0x70))->call(LO(0x16c), 0x10);
    }

    return s;
}
