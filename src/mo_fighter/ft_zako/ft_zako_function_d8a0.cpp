#include <types.h>
#include <new>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/stageobject.h>
#pragma force_active on
#pragma use_simple_stdpnew on

struct VZ {
    virtual int m1();
    virtual int m2();
    virtual unsigned char m3();
    virtual int m4();
    virtual int m5();
    virtual int m6();
    virtual int m7();
    virtual int m8();
    virtual int m9();
    virtual int m10();
    virtual int m11();
    virtual int m12();
    virtual int m13();
    virtual int m14();
    virtual int m15();
    virtual int m16();
    virtual int m17();
    virtual int m18();
    virtual int m19();
    virtual int m20();
    virtual int m21();
    virtual int m22();
    virtual int m23();
    virtual int m24();
    virtual int m25();
    virtual int m26();
    virtual int m27();
    virtual int m28();
    virtual int m29();
    virtual int m30();
    virtual int m31();
    virtual int m32();
    virtual float m33();
    virtual int m34();
    virtual int m35(int, int);
};
struct VA {
    virtual int m1();
    virtual int m2(void*, void*);
    virtual int m3();
    virtual int m4(int, void*);
    virtual int m5();
    virtual int m6();
    virtual int m7();
    virtual int m8();
    virtual int m9();
    virtual int m10(int);
    virtual int m11();
    virtual int m12();
    virtual int m13();
    virtual int m14();
    virtual int m15();
    virtual int m16();
    virtual int m17();
    virtual int m18();
    virtual int m19();
    virtual int m20();
    virtual int m21();
    virtual int m22();
    virtual int m23();
    virtual int m24();
    virtual int m25();
    virtual int m26();
    virtual int m27();
    virtual int m28();
    virtual int m29();
    virtual int m30();
    virtual int m31();
    virtual int m32();
    virtual int m33();
    virtual int m34(void*);
    virtual int m35(int, int);
};
struct VB {
    virtual int m1();
    virtual int m2(void*);
};
struct Pair { void* a; void* b; };
#define OBJ_AT(m, off) (*(char**)(*(char**)((m) + 0xAA8) + (off)))
inline int eventId(char* mods) {
    return ((VZ*)(OBJ_AT(mods, 0x80) + 8))->m8();
}
#define SUB8(m) eventId(m)
#define EXTR_0x2C(s) ((unsigned char)((*(unsigned int*)((s) + 0x2C) >> 7) & 0xFF))
#define BDV ((VZ*)buildStorage.bytes)
#define SET_VTABLES(s, t) \
    *(void**)((s) + 0x3c) = (t); \
    *(void**)((s) + 0x40) = (t) + 0x64; \
    *(void**)((s) + 0x48) = (t) + 0x70; \
    *(void**)((s) + 0x54) = (t) + 0x84; \
    *(void**)((s) + 0x64) = (t) + 0xdc; \
    *(void**)((s) + 0x70) = (t) + 0xec; \
    *(void**)((s) + 0x7c) = (t) + 0xfc; \
    *(void**)((s) + 0x88) = (t) + 0x110; \
    *(void**)((s) + 0x94) = (t) + 0x128; \
    *(void**)((s) + 0xa0) = (t) + 0x140; \
    *(void**)((s) + 0xac) = (t) + 0x158; \
    *(void**)((s) + 0xb8) = (t) + 0x16c; \
    *(void**)((s) + 0xc4) = (t) + 0x180; \
    *(void**)((s) + 0xd0) = (t) + 0x190; \
    *(void**)((s) + 0xdc) = (t) + 0x1c4; \
    *(void**)((s) + 0xe8) = (t) + 0x1d4; \
    *(void**)((s) + 0xf4) = (t) + 0x1e8; \
    *(void**)((s) + 0x100) = (t) + 0x254;
#define SETUP_SUB(q, lbl) \
    fn_27_17437C((q), acc); \
    *(void**)(q) = (lbl); \
    *(void**)((q) + 4) = (lbl) + 0x40;
extern ftCommonDataAccesser g_ftCommonDataAccesser;
extern "C" {
extern char lbl_126_data_6E04[];
extern char lbl_126_data_691C[];
extern char lbl_126_data_B50[];
extern char lbl_126_data_BD0[];
extern char lbl_126_data_CD8[];
extern char lbl_126_data_D80[];
extern char lbl_27_bss_3AC[];
extern char lbl_27_bss_3CC[];
extern char lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[];
extern char lbl_27_bss_46D8[];
extern char lbl_27_bss_55C[];
extern char lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[];
extern char lbl_27_bss_628[];
extern char lbl_27_bss_69C[];
extern char lbl_27_bss_8C4[];
extern char lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_data_2F9F8[];
extern char lbl_27_data_2FAA0[];
extern char lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[];
extern char lbl_27_data_2FD40[];
extern char lbl_27_data_2FDE8[];
extern float lbl_126_rodata_30;
extern float lbl_126_rodata_34;
void fn_27_1257EC(void*, int, int, s32, void*);
void fn_126_51D0(void*);
void fn_27_14B5F8(void*, void*);
void fn_126_5524(void*, int, int, unsigned char, void*);
void fn_126_558C(void*, void*, int, void*);
void fn_126_5614(void*, void*, int);
void fn_126_57E8(void*, void*, void*);
void fn_126_5858(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_126_5104(void*, int, void*);
void fn_126_58BC(void*, void*, int, unsigned char, void*);
void fn_126_5980(void*, void*, int, unsigned char, void*);
void fn_126_5A44(void*, void*, int, unsigned char);
void fn_126_5B18(void*, void*, int, unsigned char);
void fn_126_5BEC(void*, void*, int, unsigned char, void*);
void fn_126_5C84(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_126_5CF0(void*, void*, int);
void fn_126_5D4C(void*, void*, int, void*);
void fn_126_5DDC(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_126_5E30(void*, void*, short);
void fn_126_5EA0(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_126_5F0C(void*, short);
void fn_126_5F50(void*, void*, int, int);
void fn_126_6408(void*, void*);
void fn_126_67D8(void*);
void fn_126_6838(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_126_6904(void*, void*, unsigned char, void*);
void fn_126_69D0(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, bool, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_126_6A30(void*, void*, void*, void*);
void fn_126_6A4C(void*, short, void*, int, int, float, signed char*);
void* fn_126_6BDC(void);
void fn_126_6C4C(void*, int, int);
void* fn_126_6CC8(void*, int);
void fn_126_6D04(void*, int, void*);
void fn_27_C7744(void*, int, int);
void fn_27_D22D0(void*, int);
void fn_27_1A599C(void*, int);
void fn_27_1A079C(void*, int);
void fn_27_C749C(void*);
void fn_27_C74BC(void*, int, int);
void fn_27_126470(void*);
void fn_27_1404D4(void*, void*);
void fn_126_50F0(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_14E0B8(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
template <char* Table>
struct CustomizeLeaf {
    char* primary;
    char* secondary;

    explicit CustomizeLeaf(void* accesser) {
        fn_27_17437C(this, accesser);
        primary = Table;
        secondary = Table + 0x40;
    }
};
inline int areaCategory(VZ* data) { return data->m21(); }
extern "C" void* fn_126_D8A0(void* object, int entryId, s32 heap,
                             Heaps::HeapType modelHeap, Heaps::HeapType motionHeap)
{
    struct {
        signed char flags[11];
        short sv[11];
        Pair pr[11];
        union {
            unsigned long alignment;
            char bytes[sizeof(ftFighterBuildData)];
        } buildStorage;
    } local;
#define flags local.flags
#define sv local.sv
#define pr local.pr
#define buildStorage local.buildStorage
    char* specialChunk;
    char* lastChunk;
    char* eighthChunk;
    char* extra;
    int c0a;
    int c0b;
    int cA;
    int h30;
    int h31;
    char* firstChunk;
    char* r26;
    char* mods;
    char* self = (char*)object;
    fn_27_1257EC(object, entryId, 0x35, heap, (char*)object + 0xB64);
    SET_VTABLES(self, lbl_126_data_6E04)
    new (buildStorage.bytes) ftFighterBuildData(
        entryId, (ftKind)0x35, (Heaps::HeapType)heap, modelHeap, motionHeap,
        0, *(soModuleAccesser**)(self + 0x60), -1,
        self + 0x811C, self + 0x8124);
    mods = self + 0x194;
    fn_126_51D0(mods);
    new (mods + 0x9D0) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(mods + 0x1168),
        reinterpret_cast<soModelModule*>(mods + 0x1374),
        reinterpret_cast<soMotionModule*>(mods + 0x1690),
        reinterpret_cast<soPostureModule*>(mods + 0x183C),
        reinterpret_cast<soGroundModule*>(mods + 0x1904),
        reinterpret_cast<soSituationModule*>(mods + 0x195C),
        mods + 0x19C8,
        reinterpret_cast<soCollisionAttackModule*>(mods + 0x2028),
        reinterpret_cast<soCollisionHitModule*>(mods + 0x29BC),
        reinterpret_cast<soCollisionShieldModule*>(mods + 0x2BE8),
        reinterpret_cast<soCollisionShieldModule*>(mods + 0x3650),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        mods + 0x3824,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(mods + 0x39B8),
        mods + 0x3ABC,
        mods + 0x3B20,
        reinterpret_cast<soStopModule*>(mods + 0x3B54),
        mods + 0x3B78,
        mods + 0x3C2C,
        reinterpret_cast<soSoundModule*>(mods + 0x3C5C),
        reinterpret_cast<soLinkModule*>(mods + 0x3DFC),
        reinterpret_cast<soVisibilityModule*>(mods + 0x3E50),
        reinterpret_cast<soControllerModule*>(mods + 0x4438),
        reinterpret_cast<soCameraModule*>(mods + 0x45F4),
        reinterpret_cast<soWorkManageModule*>(mods + 0x4618),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(mods + 0x464C),
        reinterpret_cast<soStatusModule*>(mods + 0x54F0),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        reinterpret_cast<soKineticModule*>(mods + 0x55A0),
        reinterpret_cast<soEventManageModule*>(mods + 0xB8),
        lbl_27_bss_55C,
        reinterpret_cast<soEffectModule*>(mods + 0x5AFC),
        mods + 0x5C34,
        reinterpret_cast<soAreaModule*>(mods + 0x5C68),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        mods + 0x5F70,
        mods + 0x5FB8,
        reinterpret_cast<soShadowModule*>(mods + 0x6038),
        reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
        reinterpret_cast<soColorBlendModule*>(mods + 0x6084),
        mods + 0x61D8,
        mods + 0x6224,
        reinterpret_cast<soSlowModule*>(mods + 0x628C),
        lbl_27_bss_69C,
        mods + 0xAB0,
        reinterpret_cast<soParamCustomizeModule*>(mods + 0xAC8),
        mods + 0x62C8);

    h31 = BDV->m31();
    h30 = BDV->m30();
    firstChunk = reinterpret_cast<char*>(BDV->m29());
    int h28 = BDV->m28();
    new (mods + 0xAB0) soHeapModuleImpl((Heaps::HeapType)h28, (Heaps::HeapType)reinterpret_cast<s32>(firstChunk),
                                        (Heaps::HeapType)h30, h31);
    fn_27_14B5F8(mods + 0xAC8, mods + 0x9D0);
    fn_126_5524(mods + 0x115C, BDV->m1(), BDV->m2(), BDV->m3(), mods + 0x9D0);
    h30 = BDV->m25();
    BDV->m19();
    fn_126_558C(mods + 0x1180, mods + 0x9D0, h30, lbl_27_bss_A48);
    fn_126_5614(mods + 0x1440, mods + 0x9D0, BDV->m5());
    fn_126_57E8(mods + 0x1800, mods + 0x9D0, lbl_27_bss_A48);
    fn_126_5858(mods + 0x18B4, mods + 0x9D0, BDV->m9());
    fn_27_3513C(mods + 0x195C, (short)SUB8(mods), mods + 0x9D0, lbl_27_bss_A48);
    fn_126_5104(mods + 0x1998, BDV->m4(), mods + 0x9D0);
    fn_126_58BC(mods + 0x1A0C, mods + 0x9D0, *(int*)(self + 0x28), EXTR_0x2C(self), lbl_27_bss_A48);
    fn_126_5980(mods + 0x20C8, mods + 0x9D0, *(int*)(self + 0x28), EXTR_0x2C(self), lbl_27_bss_A48);
    fn_126_5A44(mods + 0x2A24, mods + 0x9D0, *(int*)(self + 0x28), EXTR_0x2C(self));
    fn_126_5B18(mods + 0x2C3C, mods + 0x9D0, *(int*)(self + 0x28), EXTR_0x2C(self));
    fn_126_5BEC(mods + 0x36A8, mods + 0x9D0, *(int*)(self + 0x28), EXTR_0x2C(self), lbl_27_bss_A48);
    fn_126_5C84(mods + 0x390C, mods + 0x9D0, lbl_27_bss_A48);
    fn_27_64C8C(mods + 0x3ABC, mods + 0x9D0, 1);
    fn_27_65EE4(mods + 0x3B20, mods + 0x9D0);
    fn_27_154088(mods + 0x3B54, mods + 0x9D0);
    fn_27_693F4(mods + 0x3B78, mods + 0x9D0);
    fn_126_5CF0(mods + 0x3BB0, mods + 0x9D0, BDV->m6());
    fn_126_5D4C(mods + 0x3C48, mods + 0x9D0, BDV->m32(), lbl_27_bss_A48);
    fn_126_5DDC(mods + 0x3CB8, mods + 0x9D0);
    fn_27_5B248(mods + 0x3E50, mods + 0x9D0, BDV->m7(), 2);
    fn_126_5E30(mods + 0x3E80, mods + 0x9D0, (short)SUB8(mods));
    fn_126_5EA0(mods + 0x45A4, mods + 0x9D0,
        BDV->m22(), BDV->m23(), lbl_27_bss_A48);
    fn_27_A1DA4(mods + 0x4618, mods + 0x9D0, BDV->m20());
    fn_126_5F0C(mods + 0x464C, (short)SUB8(mods));
    h30 = BDV->m27();
    int m8v = BDV->m8();
    fn_126_5F50(mods + 0x4740, mods + 0x9D0, m8v, h30);
    fn_126_6408(mods + 0x55A0, mods + 0x9D0);
    fn_126_67D8(mods + 0x58A8);
    fn_126_6838(mods + 0x5A90, mods + 0x9D0,
        BDV->m10(), BDV->m11(), BDV->m12(), BDV->m13(), lbl_27_bss_A48);
    fn_27_14FBD8(mods + 0x5C34, mods + 0x9D0);
    fn_126_6904(mods + 0x5C64, mods + 0x9D0, (unsigned char)areaCategory(BDV), lbl_27_bss_A48);
    BDV->m15();
    BDV->m14();
    BDV->m16();
    fn_126_69D0(mods + 0x5EF4, mods + 0x9D0, BDV->m17());
    fn_27_ACAC4(mods + 0x5FB8, mods + 0x9D0, 0, 1, false, BDV->m33());
    fn_27_B62E4(mods + 0x6038, mods + 0x9D0, lbl_126_rodata_30, 0);
    BDV->m24();
    fn_27_BEBB4(mods + 0x6084, mods + 0x9D0, 0x0A, 1);
    int m26v = BDV->m26();
    fn_27_C20D8(mods + 0x61D8, mods + 0x9D0, 0, 8, m26v);
    fn_27_196664(mods + 0x6224, mods + 0x9D0);
    fn_27_5BED0(mods + 0x628C, mods + 0x9D0);
    fn_27_14CCEC(mods + 0x62C8, mods + 0x9D0);
    if (((VZ*)(mods + 0x5A68))->m1() == 0) {
        ((VA*)OBJ_AT(mods, 0x64))->m4(1, mods + 0x5A68);
    }
    fn_27_C74BC(mods + 0x6448, *(int*)(*(char**)((char*)buildStorage.bytes + 0xC) + 0x18), 6);
    r26 = mods + 0x6458;
    fn_27_1A599C(r26, 0);
    fn_27_1A599C(r26 + 0x46C, 0);
    fn_27_D22D0(r26 + 0x8DC, 0);
    fn_126_6A30(r26 + 0x988, r26, r26 + 0x46C, fn_126_6BDC());
    flags[0] = 0;
    fn_126_6A4C(r26 + 0x9A4, (short)SUB8(mods), r26 + 0x8DC, 0, 1, lbl_126_rodata_34, &flags[0]);
    fn_126_6C4C(r26, 0, 0x118);
    fn_126_6C4C(r26 + 0x46C, 0, 0x118);
    fn_126_6C4C(fn_126_6BDC(), 0, 0);
    sv[0] = 1;
    pr[0].a = r26 + 0x9A4;
    pr[0].b = r26 + 0x988;
    ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[0], &sv[0]);
    {
        BDV->m35(1, 2);
        BDV->m35(1, 1);
        int a4 = BDV->m35(1, 0);
        firstChunk = r26 + 0x9F4;
        fn_27_C7744(firstChunk, a4, 0x1CF);
        fn_27_D22D0(firstChunk + 0x14, 0);
        fn_126_6A30(firstChunk + 0xC0, firstChunk, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[1] = 0;
        fn_126_6A4C(firstChunk + 0xDC, (short)SUB8(mods), firstChunk + 0x14, 1, 1, lbl_126_rodata_34, &flags[1]);
        sv[1] = 2;
        pr[1].a = firstChunk + 0xDC;
        pr[1].b = firstChunk + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[1], &sv[1]);
    }
    {
        BDV->m35(2, 2);
        BDV->m35(2, 1);
        int a4 = BDV->m35(2, 0);
        char* s = r26 + 0xB20;
        fn_27_C7744(s, a4, 0x1CF);
        fn_27_D22D0(s + 0x14, 0);
        fn_126_6A30(s + 0xC0, s, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[2] = 0;
        fn_126_6A4C(s + 0xDC, (short)SUB8(mods), s + 0x14, 2, 1, lbl_126_rodata_34, &flags[2]);
        sv[2] = 0x40;
        pr[2].a = s + 0xDC;
        pr[2].b = s + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[2], &sv[2]);
    }
    {
        BDV->m35(3, 2);
        BDV->m35(3, 1);
        int a4 = BDV->m35(3, 0);
        char* s = r26 + 0xC4C;
        fn_27_C7744(s, a4, 0x1CF);
        fn_27_D22D0(s + 0x14, 0);
        fn_126_6A30(s + 0xC0, s, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[3] = 0;
        fn_126_6A4C(s + 0xDC, (short)SUB8(mods), s + 0x14, 3, 1, lbl_126_rodata_34, &flags[3]);
        sv[3] = 0x40;
        pr[3].a = s + 0xDC;
        pr[3].b = s + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[3], &sv[3]);
    }
    {
        BDV->m35(4, 2);
        BDV->m35(4, 1);
        int a4 = BDV->m35(4, 0);
        char* s = r26 + 0xD78;
        fn_27_C7744(s, a4, 0x1CF);
        fn_27_D22D0(s + 0x14, 0);
        fn_126_6A30(s + 0xC0, s, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[4] = 0;
        fn_126_6A4C(s + 0xDC, (short)SUB8(mods), s + 0x14, 4, 1, lbl_126_rodata_34, &flags[4]);
        sv[4] = 2;
        pr[4].a = s + 0xDC;
        pr[4].b = s + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[4], &sv[4]);
    }
    {
        BDV->m35(5, 2);
        BDV->m35(5, 1);
        int a4 = BDV->m35(5, 0);
        char* s = r26 + 0xEA4;
        fn_27_C7744(s, a4, 0x1CF);
        fn_27_D22D0(s + 0x14, 0);
        fn_126_6A30(s + 0xC0, s, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[5] = 0;
        fn_126_6A4C(s + 0xDC, (short)SUB8(mods), s + 0x14, 5, 1, lbl_126_rodata_34, &flags[5]);
        sv[5] = 0x20;
        pr[5].a = s + 0xDC;
        pr[5].b = s + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[5], &sv[5]);
    }
    {
        BDV->m35(6, 2);
        BDV->m35(6, 1);
        int a4 = BDV->m35(6, 0);
        char* s = r26 + 0xFD0;
        fn_27_C7744(s, a4, 0x1CF);
        fn_27_D22D0(s + 0x14, 0);
        fn_126_6A30(s + 0xC0, s, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[6] = 0;
        fn_126_6A4C(s + 0xDC, (short)SUB8(mods), s + 0x14, 6, 1, lbl_126_rodata_34, &flags[6]);
        sv[6] = 0x80;
        pr[6].a = s + 0xDC;
        pr[6].b = s + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[6], &sv[6]);
    }
    {
        BDV->m35(7, 2);
        BDV->m35(7, 1);
        int a4 = BDV->m35(7, 0);
        char* s = r26 + 0x10FC;
        fn_27_C7744(s, a4, 0x1CF);
        fn_27_D22D0(s + 0x14, 0);
        fn_126_6A30(s + 0xC0, s, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[7] = 0;
        fn_126_6A4C(s + 0xDC, (short)SUB8(mods), s + 0x14, 7, 1, lbl_126_rodata_34, &flags[7]);
        sv[7] = 0x80;
        pr[7].a = s + 0xDC;
        pr[7].b = s + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[7], &sv[7]);
    }
    {
        BDV->m35(8, 2);
        BDV->m35(8, 1);
        int a4 = BDV->m35(8, 0);
        eighthChunk = r26 + 0x1228;
        fn_27_C7744(eighthChunk, a4, 0x1CF);
        fn_27_D22D0(eighthChunk + 0x14, 0);
        fn_126_6A30(eighthChunk + 0xC0, eighthChunk, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[8] = 0;
        fn_126_6A4C(eighthChunk + 0xDC, (short)SUB8(mods), eighthChunk + 0x14, 8, 1, lbl_126_rodata_34, &flags[8]);
        sv[8] = 0x20;
        pr[8].a = eighthChunk + 0xDC;
        pr[8].b = eighthChunk + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[8], &sv[8]);
    }
    {
        specialChunk = r26 + 0x1354;
        flags[9] = 1;
        fn_126_6A4C(specialChunk, (short)SUB8(mods), specialChunk + 0x50, 9, 1, lbl_126_rodata_34, &flags[9]);
        fn_27_1A079C(specialChunk + 0x50, 0);
        sv[9] = 4;
        pr[9].a = specialChunk;
        pr[9].b = lbl_27_bss_8C4;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[9], &sv[9]);
    }
    {
        BDV->m35(10, 2);
        BDV->m35(10, 1);
        int a4 = BDV->m35(10, 0);
        lastChunk = r26 + 0x1478;
        fn_27_C7744(lastChunk, a4, 0x29);
        fn_27_D22D0(lastChunk + 0x14, 0);
        fn_126_6A30(lastChunk + 0xC0, lastChunk, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flags[10] = 0;
        fn_126_6A4C(lastChunk + 0xDC, (short)SUB8(mods), lastChunk + 0x14, 10, 1, lbl_126_rodata_34, &flags[10]);
        sv[10] = 0x10;
        pr[10].a = lastChunk + 0xDC;
        pr[10].b = lastChunk + 0xC0;
        ((VA*)OBJ_AT(mods, 0x6C))->m2(&pr[10], &sv[10]);
    }

    c0a = BDV->m35(0, 0);
    fn_126_6C4C(fn_126_6CC8(r26, 0), c0a, 0x112);
    c0b = BDV->m35(0, 1);
    fn_126_6C4C(fn_126_6CC8(r26, 1), c0b, 0x112);
    fn_126_6C4C(fn_126_6CC8(r26, 0), *(int*)(*(char**)((char*)buildStorage.bytes + 0xC) + 0x24), 6);
    fn_126_6C4C(fn_126_6CC8(r26, 1), *(int*)(*(char**)((char*)buildStorage.bytes + 0xC) + 0x28), 6);
    fn_126_6D04(r26, 0, ((ftFighterBuildData*)buildStorage.bytes)->getAnimCmdDisguiseList(false, 0));
    fn_126_6D04(r26, 1, ((ftFighterBuildData*)buildStorage.bytes)->getAnimCmdDisguiseList(false, 1));
    ((VA*)OBJ_AT(mods, 0x70))->m34(mods + 0x6448);
    cA = (int)soValueAccesser::getConstantIndefinite((soModuleAccesser*)(mods + 0x9D0), 0xA805, 0);
    void* dc = __dynamic_cast(OBJ_AT(mods, 0x90), 0, lbl_126_data_CD8, lbl_126_data_D80, 0);
    if (dc != 0) {
        fn_27_14E0B8(dc, cA);
    }
    ((VA*)OBJ_AT(mods, 0x90))->m10(cA);
    fn_27_1404D4(self + 0x7B90, *(void**)(self + 0x60));
    extra = self + 0x7BCC;
    fn_126_50F0(extra, 0);
    *(void**)extra = lbl_126_data_B50;
    mods = *(char**)(self + 0x60);
    heap = reinterpret_cast<s32>(self + 0x8084);
    fn_126_50F0(reinterpret_cast<char*>(heap), 0);
    *reinterpret_cast<void**>(heap) = lbl_126_data_BD0;
    new (reinterpret_cast<char*>(heap) + 0x08) CustomizeLeaf<lbl_27_data_2F9F8>(mods);
    new (reinterpret_cast<char*>(heap) + 0x20) CustomizeLeaf<lbl_27_data_2FAA0>(mods);
    new (reinterpret_cast<char*>(heap) + 0x34) CustomizeLeaf<lbl_27_data_2FB48>(mods);
    new (reinterpret_cast<char*>(heap) + 0x48) CustomizeLeaf<lbl_27_data_2FBF0>(mods);
    new (reinterpret_cast<char*>(heap) + 0x5C) CustomizeLeaf<lbl_27_data_2FC98>(mods);
    new (reinterpret_cast<char*>(heap) + 0x70) CustomizeLeaf<lbl_27_data_2FD40>(mods);
    new (reinterpret_cast<char*>(heap) + 0x84) CustomizeLeaf<lbl_27_data_2FDE8>(mods);
    int c1 = (int)soValueAccesser::getConstantIndefinite(*(soModuleAccesser**)(self + 0x60), 0xA7F9, 0);
    *(int*)(self + 0x811C) = c1;
    *(int*)(self + 0x8120) = 1;
    int c2 = (int)soValueAccesser::getConstantIndefinite(*(soModuleAccesser**)(self + 0x60), 0xA7FC, 0);
    *(int*)(self + 0x8124) = c2;
    *(int*)(self + 0x8128) = 1;
    fn_27_126470(self);
    ((VB*)(self + 0x7B90))->m2(*(void**)(self + 0x60));
    SET_VTABLES(self, lbl_126_data_691C)
    fn_27_C749C(self + 0x812C);
    *(void**)(self + 0x813C) = (void*)g_ftCommonDataAccesser.getData((ftKind)0x35);
    return object;
}
