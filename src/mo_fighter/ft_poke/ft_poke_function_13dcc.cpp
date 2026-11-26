#include <types.h>
#include <new>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on

inline void* operator new[](size_t, void* storage) { return storage; }

struct VT {
    virtual void* m1();
    virtual void* m2();
    virtual u8 m3();
    virtual void* m4();
    virtual void* m5();
    virtual void* m6();
    virtual void* m7();
    virtual void* m8();
    virtual void* m9();
    virtual void* m10();
    virtual void* m11();
    virtual void* m12();
    virtual void* m13();
    virtual void* m14();
    virtual void* m15();
    virtual void* m16();
    virtual void* m17();
    virtual void* m18();
    virtual f32 m19();
    virtual void* m20();
    virtual void* m21();
    virtual void* m22();
    virtual void* m23();
    virtual void* m24();
    virtual void* m25();
    virtual void* m26();
    virtual void* m27();
    virtual void* m28();
    virtual void* m29();
    virtual void* m30();
    virtual void* m31();
    virtual void* m32();
    virtual f32 m33();
    virtual void* m34(void*);
    virtual void* m35(void*, void*);
};

struct PairVT {
    virtual void first();
    virtual void add(void**, s16*);
};
struct InitVT {
    virtual void first();
    virtual void init(void*);
};
struct RegistryVT {
    virtual void first();
    virtual void second();
    virtual void third();
    virtual void add(s32, void*);
};
struct ParamVT {
    virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7(); virtual void m8(); virtual void m9();
    virtual void set(void*);
};
struct StatusVT {
    virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12();
    virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(); virtual void m20(); virtual void m21();
    virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void set(void**, s32);
};

extern "C" {
extern char lbl_116_data_82F8[], lbl_116_data_7DFC[], lbl_116_data_1DFC[], lbl_116_data_1E7C[];
extern char lbl_116_data_1F84[], lbl_116_data_217C[], lbl_116_data_1FF4[], lbl_116_data_209C[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[], lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[], lbl_27_data_2FD40[], lbl_27_data_2FDE8[];
extern char lbl_27_bss_3AC[], lbl_27_bss_3CC[], lbl_27_bss_4BC[], lbl_27_bss_46C0[], lbl_27_bss_46D8[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_69C[], lbl_27_bss_83CC[], lbl_27_bss_8C4[];
extern char lbl_27_bss_A48[], lbl_27_bss_D8C[], lbl_116_bss_4CC[];
extern float lbl_116_rodata_50, lbl_116_rodata_54;

void fn_27_1257EC(void*, void*, s32, void*, void*);
void fn_116_738C(void*);
void fn_116_76E0(void*, void*, void*, u8, void*);
void fn_116_7748(void*, soModuleAccesser*, f32, void*, soEventObserverRegistrationDesc*);
void fn_116_17020(void*, void*, void*);
void fn_116_79A4(void*, void*, void*);
void fn_116_7A14(void*, void*, void*);
void fn_116_7A78(void*, void*, s32, u8, void*);
void fn_116_171BC(void*, void*, s32, u8, void*);
void fn_116_7C00(void*, void*, s32, u8);
void fn_116_7CD4(void*, void*, s32, u8);
void fn_116_7DA8(void*, void*, s32, u8, void*);
void fn_116_7E40(void*, void*, void*);
void fn_27_64C8C(void*, void*, s32);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_116_7EAC(void*, void*, void*);
void fn_116_7F08(void*, void*, void*, void*);
void fn_116_7F98(void*, void*);
void fn_27_5B248(void*, void*, void*, s32);
void fn_116_7FEC(void*, void*, s16);
void fn_116_805C(void*, void*, void*, void*, void*);
void fn_27_A1DA4(void*, void*, void*);
void fn_116_80C8(void*, s16);
void fn_116_17280(void*, void*, void*, void*);
void fn_116_17608(void*, void*);
void fn_116_8994(void*);
void fn_116_179D8(void*, void*);
void fn_116_8D8C(void*, void*, void*, void*, void*, void*, void*);
void fn_27_14FBD8(void*, void*);
void fn_116_17C2C(void*, void*, u8, void*);
void fn_116_8EF0(void*, void*, void*);
void fn_27_ACAC4(void*, void*, s32, s32, bool, f32);
void fn_27_B62E4(void*, void*, f32, s32);
void fn_116_8F50(void*, void*, void*);
void fn_27_BEBB4(void*, void*, s32, s32);
void fn_27_C20D8(void*, void*, s32, s32, void*);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, s32);
void fn_27_C7744(void*, void*, s32);
void fn_27_D22D0(void*, s32);
void fn_27_1A5FB4(void*, s32);
void fn_27_1A079C(void*, s32);
void* fn_116_9178(void);
void fn_116_8FCC(void*, void*, void*, void*);
void fn_116_8FE8(void*, s16, void*, s32, s32, f32, s8*);
void fn_116_91E8(void*, s32, s32);
void* fn_116_17CC4(void*, s32);
void fn_116_17D00(void*, s32, void*);
void fn_116_72AC(void*, s32);
void fn_116_72C0(void*, void*, void*);
void fn_27_14B5F8(void*, void*);
void fn_27_3513C(void*, s16, void*, void*);
void fn_27_1404D4(void*, void*);
void fn_27_14E0B8(void*, void*);
void fn_27_126470(void*);
void fn_27_17437C(void*, void*);
void fn_27_368968(void*, void*, void*);
void fn_27_376848(void*, void*, void*, void*);
void fn_27_C749C(void*);



void* __dynamic_cast(void*, s32, void*, void*, s16);



}

template<char* Table> struct HandleBuilder {
    HandleBuilder(void* accesser) {
        fn_27_17437C(this, accesser);
        *(char**)this = Table;
        *(char**)((char*)this + 4) = Table + 0x40;
    }
};

struct StackLocals {
    s8 flags[11];
    char pad0;
    s16 sv[11];
    char pad1[2];
    void* pr[22];
    char fbd[0x30];
    void* av[13];
};
#define fbd local.fbd
#define flags local.flags
#define sv local.sv
#define pr local.pr
#define av local.av
extern "C" void* fn_116_13DCC(char* self, void* a1, void* a2, void* a3, void* a4) {
    StackLocals local;
    s32 i;
    void* vt;
    void* v5;
    void* v4;
    void* v22;
    char* p;

    fn_27_1257EC(self, a1, 30, a2, self + 0xb64);

    *(char**)(self + 0x3c) = lbl_116_data_82F8;
    *(char**)(self + 0x40) = lbl_116_data_82F8 + 0x64;
    *(char**)(self + 0x48) = lbl_116_data_82F8 + 0x70;
    *(char**)(self + 0x54) = lbl_116_data_82F8 + 0x84;
    *(char**)(self + 0x64) = lbl_116_data_82F8 + 0xdc;
    *(char**)(self + 0x70) = lbl_116_data_82F8 + 0xec;
    *(char**)(self + 0x7c) = lbl_116_data_82F8 + 0xfc;
    *(char**)(self + 0x88) = lbl_116_data_82F8 + 0x110;
    *(char**)(self + 0x94) = lbl_116_data_82F8 + 0x128;
    *(char**)(self + 0xa0) = lbl_116_data_82F8 + 0x140;
    *(char**)(self + 0xac) = lbl_116_data_82F8 + 0x158;
    *(char**)(self + 0xb8) = lbl_116_data_82F8 + 0x16c;
    *(char**)(self + 0xc4) = lbl_116_data_82F8 + 0x180;
    *(char**)(self + 0xd0) = lbl_116_data_82F8 + 0x190;
    *(char**)(self + 0xdc) = lbl_116_data_82F8 + 0x1c4;
    *(char**)(self + 0xe8) = lbl_116_data_82F8 + 0x1d4;
    *(char**)(self + 0xf4) = lbl_116_data_82F8 + 0x1e8;
    *(char**)(self + 0x100) = lbl_116_data_82F8 + 0x254;

    new (fbd) ftFighterBuildData((s32)a1, (ftKind)30, (Heaps::HeapType)(s32)a2,
        (Heaps::HeapType)(s32)a3, (Heaps::HeapType)(s32)a4, 0,
        *(soModuleAccesser**)(self + 0x60), -1, self + 0x162d0, self + 0x162d8);

    char* mod = self + 0x194;
    void* acc;
    struct ModuleBuilder {
        static void create(char* mod, char* self, StackLocals& local, void*& acc) {
    void* vt;
    void* v5;
    void* v4;
    void* v22;
    char* p;
    fn_116_738C(mod);

    new (mod + 0x9d0) soModuleAccesser(
        (StageObject*)(self),
        (soResourceModule*)(mod + 0x1168),
        (soModelModule*)(mod + 0x1374),
        (soMotionModule*)(mod + 0x1664),
        (soPostureModule*)(mod + 0x1810),
        (soGroundModule*)(mod + 0x18d8),
        (soSituationModule*)(mod + 0x1930),
        (void*)(mod + 0x199c),
        (soCollisionAttackModule*)(mod + 0x1ffc),
        (soCollisionHitModule*)(mod + 0x2650),
        (soCollisionShieldModule*)(mod + 0x287c),
        (soCollisionShieldModule*)(mod + 0x32e4),
        (soCollisionShieldModule*)(lbl_27_bss_3AC),
        (void*)(mod + 0x34b8),
        (soCollisionSearchModule*)(lbl_27_bss_3CC),
        (soDamageModule*)(mod + 0x364c),
        (void*)(mod + 0x3750),
        (void*)(mod + 0x37b4),
        (soStopModule*)(mod + 0x37e8),
        (void*)(mod + 0x380c),
        (void*)(mod + 0x38c0),
        (soSoundModule*)(mod + 0x38f0),
        (soLinkModule*)(mod + 0x3a90),
        (soVisibilityModule*)(mod + 0x3ae4),
        (soControllerModule*)(mod + 0x40cc),
        (soCameraModule*)(mod + 0x4288),
        (soWorkManageModule*)(mod + 0x42ac),
        (void*)(lbl_27_bss_4BC),
        (soAnimCmdModule*)(mod + 0x42e0),
        (soStatusModule*)(mod + 0x51a0),
        (void*)(lbl_27_bss_46C0),
        (void*)(lbl_27_bss_46D8),
        (soKineticModule*)(mod + 0x5250),
        (soEventManageModule*)(mod + 0xb8),
        (void*)(mod + 0x139bc),
        (soEffectModule*)(mod + 0x13a64),
        (void*)(mod + 0x13b9c),
        (soAreaModule*)(mod + 0x13bdc),
        (void*)(lbl_27_bss_5B0),
        (void*)(lbl_27_bss_5D8),
        (void*)(mod + 0x13fe0),
        (void*)(mod + 0x14028),
        (soShadowModule*)(mod + 0x140a8),
        (soItemManageModule*)(mod + 0x14194),
        (soColorBlendModule*)(mod + 0x14200),
        (void*)(mod + 0x14354),
        (void*)(mod + 0x143a0),
        (soSlowModule*)(mod + 0x14408),
        (void*)(lbl_27_bss_69C),
        (void*)(mod + 0xab0),
        (soParamCustomizeModule*)(mod + 0xac8),
        (void*)(mod + 0x14444));

    void* v26 = ((VT*)fbd)->m31();
    void* heapMotion = ((VT*)fbd)->m30();
    void* v21 = ((VT*)fbd)->m29();
    v4 = ((VT*)fbd)->m28();
    new (mod + 0xab0) soHeapModuleImpl((Heaps::HeapType)(s32)v4, (Heaps::HeapType)(s32)v21, (Heaps::HeapType)(s32)heapMotion, (s32)v26);
    fn_27_14B5F8(mod + 0xac8, mod + 0x9d0);

    fn_116_76E0(mod + 0x115c, ((VT*)fbd)->m1(), ((VT*)fbd)->m2(),
        ((VT*)fbd)->m3(), mod + 0x9d0);

    fn_116_7748(mod + 0x1180, (soModuleAccesser*)(mod + 0x9d0), ((VT*)fbd)->m19(),
        ((VT*)fbd)->m25(), (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    v5 = ((VT*)fbd)->m5();
    fn_116_17020(mod + 0x1440, mod + 0x9d0, v5);
    fn_116_79A4(mod + 0x17d4, mod + 0x9d0, lbl_27_bss_A48);
    v5 = ((VT*)fbd)->m9();
    fn_116_7A14(mod + 0x1888, mod + 0x9d0, v5);
    fn_27_3513C(mod + 0x1930, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), mod + 0x9d0, lbl_27_bss_A48);
    v4 = ((VT*)fbd)->m4();
    fn_116_72C0(mod + 0x196c, v4, mod + 0x9d0);
    fn_116_7A78(mod + 0x19e0, mod + 0x9d0, *(s32*)(self + 0x28), (u8)((*(u32*)(self + 0x2c) >> 7) & 0xff), lbl_27_bss_A48);
    fn_116_171BC(mod + 0x209c, mod + 0x9d0, *(s32*)(self + 0x28), (u8)((*(u32*)(self + 0x2c) >> 7) & 0xff), lbl_27_bss_A48);
    fn_116_7C00(mod + 0x26b8, mod + 0x9d0, *(s32*)(self + 0x28), (u8)((*(u32*)(self + 0x2c) >> 7) & 0xff));
    fn_116_7CD4(mod + 0x28d0, mod + 0x9d0, *(s32*)(self + 0x28), (u8)((*(u32*)(self + 0x2c) >> 7) & 0xff));
    fn_116_7DA8(mod + 0x333c, mod + 0x9d0, *(s32*)(self + 0x28), (u8)((*(u32*)(self + 0x2c) >> 7) & 0xff), lbl_27_bss_A48);
    fn_116_7E40(mod + 0x35a0, mod + 0x9d0, lbl_27_bss_A48);
    fn_27_64C8C(mod + 0x3750, mod + 0x9d0, 1);
    fn_27_65EE4(mod + 0x37b4, mod + 0x9d0);
    fn_27_154088(mod + 0x37e8, mod + 0x9d0);
    fn_27_693F4(mod + 0x380c, mod + 0x9d0);
    v5 = ((VT*)fbd)->m6();
    fn_116_7EAC(mod + 0x3844, mod + 0x9d0, v5);
    v5 = ((VT*)fbd)->m32();
    fn_116_7F08(mod + 0x38dc, mod + 0x9d0, v5, lbl_27_bss_A48);
    fn_116_7F98(mod + 0x394c, mod + 0x9d0);
    v5 = ((VT*)fbd)->m7();
    fn_27_5B248(mod + 0x3ae4, mod + 0x9d0, v5, 2);
    fn_116_7FEC(mod + 0x3b14, mod + 0x9d0, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId());
    fn_116_805C(mod + 0x4238, mod + 0x9d0, ((VT*)fbd)->m22(),
        ((VT*)fbd)->m23(), lbl_27_bss_A48);
    v5 = ((VT*)fbd)->m20();
    fn_27_A1DA4(mod + 0x42ac, mod + 0x9d0, v5);
    fn_116_80C8(mod + 0x42e0, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId());
    fn_116_17280(mod + 0x43d4, mod + 0x9d0, ((VT*)fbd)->m8(), ((VT*)fbd)->m27());
    fn_116_17608(mod + 0x5250, mod + 0x9d0);
    fn_116_8994(mod + 0x5558);
    fn_116_179D8(mod + 0x573c, mod + 0x9d0);
    fn_116_8D8C(mod + 0x139f8, mod + 0x9d0, ((VT*)fbd)->m10(),
        ((VT*)fbd)->m11(), ((VT*)fbd)->m12(), ((VT*)fbd)->m13(), lbl_27_bss_A48);
    fn_27_14FBD8(mod + 0x13b9c, mod + 0x9d0);
    vt = ((VT*)fbd)->m21();
    fn_116_17C2C(mod + 0x13bcc, mod + 0x9d0, (u8)(u32)vt, lbl_27_bss_A48);
    ((VT*)fbd)->m15();
    ((VT*)fbd)->m14();
    ((VT*)fbd)->m16();
    v5 = ((VT*)fbd)->m17();
    fn_116_8EF0(mod + 0x13f64, mod + 0x9d0, v5);
    struct SlopeBuilder {
        SlopeBuilder(void* accesser, s32 first, s32 second, bool flag, f32 limit) {
            fn_27_ACAC4(this, accesser, first, second, flag, limit);
        }
    };
    new (mod + 0x14028) SlopeBuilder(mod + 0x9d0, 0, 1, false, ((VT*)fbd)->m33());
    struct ShadowBuilder {
        ShadowBuilder(void* accesser, const f32& size, s32 value) {
            fn_27_B62E4(this, accesser, size, value);
        }
    };
    new (mod + 0x140a8) ShadowBuilder(mod + 0x9d0, lbl_116_rodata_50, 0);
    v5 = ((VT*)fbd)->m24();
    fn_116_8F50(mod + 0x140f0, mod + 0x9d0, v5);
    struct ColorBuilder {
        ColorBuilder(void* accesser, s32 value, s32 flag) {
            fn_27_BEBB4(this, accesser, value, flag);
        }
    };
    new (mod + 0x14200) ColorBuilder(mod + 0x9d0, 0xa, 1);
    struct JostleBuilder {
        JostleBuilder(void* accesser, s32 first, s32 second, void* data) {
            fn_27_C20D8(this, accesser, first, second, data);
        }
    };
    new (mod + 0x14354) JostleBuilder(mod + 0x9d0, 0, 8, ((VT*)fbd)->m26());
    fn_27_196664(mod + 0x143a0, mod + 0x9d0);
    fn_27_5BED0(mod + 0x14408, mod + 0x9d0);
    fn_27_14CCEC(mod + 0x14444, mod + 0x9d0);

    {
        s32 hv = (s32)((VT*)(mod + 0x5718))->m1();
        if (hv == 0) {
            ((RegistryVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x64)))->add(1, mod + 0x5718);
        }
    }
    fn_27_C74BC(mod + 0x145c4, *(void**)(*(char**)(fbd + 0xc) + 0x18), 0xd);

    p = mod + 0x145d4;
    fn_27_1A5FB4(p, 0);
    fn_27_1A5FB4(p + 0x488, 0);
    fn_27_D22D0(p + 0x914, 0);
    vt = fn_116_9178();
    fn_116_8FCC(p + 0x9c0, p, p + 0x488, vt);

    flags[0] = 0;
    fn_116_8FE8(p + 0x9dc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), p + 0x914, 0, 1, lbl_116_rodata_54, &flags[0]);
    fn_116_91E8(p, 0, 0x11f);
    fn_116_91E8(p + 0x488, 0, 0x11f);
    vt = fn_116_9178();
    fn_116_91E8(vt, 0, 0);
    sv[0] = 1;
    pr[0] = p + 0x9dc;
    pr[1] = p + 0x9c0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[0], &sv[0]);

    {
    ((VT*)fbd)->m35((void*)1, (void*)2);
    ((VT*)fbd)->m35((void*)1, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)1, (void*)0);
    char* b = p + 0xa2c;
    fn_27_C7744(b, v4, 0x1e4);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[1] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 1, 1, lbl_116_rodata_54, &flags[1]);
    sv[1] = 2;
    pr[2] = b + 0xdc;
    pr[3] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[2], &sv[1]);
    }

    {
    ((VT*)fbd)->m35((void*)2, (void*)2);
    ((VT*)fbd)->m35((void*)2, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)2, (void*)0);
    char* b = p + 0xb58;
    fn_27_C7744(b, v4, 0x1e4);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[2] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 2, 1, lbl_116_rodata_54, &flags[2]);
    sv[2] = 0x40;
    pr[4] = b + 0xdc;
    pr[5] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[4], &sv[2]);
    }

    {
    ((VT*)fbd)->m35((void*)3, (void*)2);
    ((VT*)fbd)->m35((void*)3, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)3, (void*)0);
    char* b = p + 0xc84;
    fn_27_C7744(b, v4, 0x1e4);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[3] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 3, 1, lbl_116_rodata_54, &flags[3]);
    sv[3] = 0x40;
    pr[6] = b + 0xdc;
    pr[7] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[6], &sv[3]);
    }

    {
    ((VT*)fbd)->m35((void*)4, (void*)2);
    ((VT*)fbd)->m35((void*)4, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)4, (void*)0);
    char* b = p + 0xdb0;
    fn_27_C7744(b, v4, 0x1e4);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[4] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 4, 1, lbl_116_rodata_54, &flags[4]);
    sv[4] = 2;
    pr[8] = b + 0xdc;
    pr[9] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[8], &sv[4]);
    }

    {
    ((VT*)fbd)->m35((void*)5, (void*)2);
    ((VT*)fbd)->m35((void*)5, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)5, (void*)0);
    char* b = p + 0xedc;
    fn_27_C7744(b, v4, 0x1e4);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[5] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 5, 1, lbl_116_rodata_54, &flags[5]);
    sv[5] = 0x20;
    pr[10] = b + 0xdc;
    pr[11] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[10], &sv[5]);
    }

    {
    ((VT*)fbd)->m35((void*)6, (void*)2);
    ((VT*)fbd)->m35((void*)6, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)6, (void*)0);
    char* b = p + 0x1008;
    fn_27_C7744(b, v4, 0x1e4);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[6] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 6, 1, lbl_116_rodata_54, &flags[6]);
    sv[6] = 0x80;
    pr[12] = b + 0xdc;
    pr[13] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[12], &sv[6]);
    }

    {
    ((VT*)fbd)->m35((void*)7, (void*)2);
    ((VT*)fbd)->m35((void*)7, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)7, (void*)0);
    char* b = p + 0x1134;
    fn_27_C7744(b, v4, 0x1e4);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[7] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 7, 1, lbl_116_rodata_54, &flags[7]);
    sv[7] = 0x80;
    pr[14] = b + 0xdc;
    pr[15] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[14], &sv[7]);
    }

    {
    ((VT*)fbd)->m35((void*)8, (void*)2);
    ((VT*)fbd)->m35((void*)8, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)8, (void*)0);
    char* b = p + 0x1260;
    fn_27_C7744(b, v4, 0x1e4);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[8] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 8, 1, lbl_116_rodata_54, &flags[8]);
    sv[8] = 0x20;
    pr[16] = b + 0xdc;
    pr[17] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[16], &sv[8]);
    }

    {
    char* b = p + 0x138c;
    flags[9] = 1;
    fn_116_8FE8(b, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x50, 9, 1, lbl_116_rodata_54, &flags[9]);
    fn_27_1A079C(b + 0x50, 0);
    sv[9] = 4;
    pr[18] = b;
    pr[19] = lbl_27_bss_8C4;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[18], &sv[9]);
    }

    {
    ((VT*)fbd)->m35((void*)10, (void*)2);
    ((VT*)fbd)->m35((void*)10, (void*)1);
    v4 = ((VT*)fbd)->m35((void*)10, (void*)0);
    char* b = p + 0x14b0;
    fn_27_C7744(b, v4, 0x29);
    fn_27_D22D0(b + 0x14, 0);
    fn_116_8FCC(b + 0xc0, b, lbl_27_bss_D8C, lbl_27_bss_D8C);
    flags[10] = 0;
    fn_116_8FE8(b + 0xdc, static_cast<soEventManager&>(*(soEventManageModule*)*(void**)(*(char**)(mod + 0xaa8) + 0x80)).getManageId(), b + 0x14, 0xa, 1, lbl_116_rodata_54, &flags[10]);
    sv[10] = 0x10;
    pr[20] = b + 0xdc;
    pr[21] = b + 0xc0;
    ((PairVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x6c)))->add(&pr[20], &sv[10]);
    }

    struct AnimBinder {
        void bind(s32 index, void* script, s32 length) {
            fn_116_91E8(fn_116_17CC4(this, index), (s32)script, length);
        }
    };
    ((AnimBinder*)p)->bind(0, ((VT*)fbd)->m35((void*)0, (void*)0), 0x112);
    ((AnimBinder*)p)->bind(1, ((VT*)fbd)->m35((void*)0, (void*)1), 0x112);
    vt = fn_116_17CC4(p, 0);
    fn_116_91E8(vt, *(s32*)(*(char**)(fbd + 0xc) + 0x24), 0xd);
    vt = fn_116_17CC4(p, 1);
    fn_116_91E8(vt, *(s32*)(*(char**)(fbd + 0xc) + 0x28), 0xd);

    v5 = ((ftFighterBuildData*)fbd)->getAnimCmdDisguiseList(false, 0);
    fn_116_17D00(p, 0, v5);
    v5 = ((ftFighterBuildData*)fbd)->getAnimCmdDisguiseList(false, 1);
    fn_116_17D00(p, 1, v5);

    ((VT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x70)))->m34(mod + 0x145c4);

    struct ParamInitializer {
        void init(void* constant) {
            char* mod = (char*)this;
            void* param = __dynamic_cast(*(void**)(*(char**)(mod + 0xaa8) + 0x90), 0, lbl_116_data_1FF4, lbl_116_data_209C, 0);
            if (param != 0) {
                fn_27_14E0B8(param, constant);
            }
            ((ParamVT*)(*(char**)(*(char**)(mod + 0xaa8) + 0x90)))->set(constant);
        }
    };
    ((ParamInitializer*)mod)->init(soValueAccesser::getConstantIndefinite((soModuleAccesser*)(mod + 0x9d0), 0xa805, 0));
    fn_27_1404D4(self + 0x15d44, *(void**)(self + 0x60));

    {
        char* part = self + 0x15d80;
        fn_116_72AC(part, 0);
        *(char**)part = lbl_116_data_1DFC;
    }
    acc = *(void**)(self + 0x60);
    char* r27p = self + 0x16238;
    fn_116_72AC(r27p, 0);
    *(char**)r27p = lbl_116_data_1E7C;
    {
    char* part = r27p + 0x8;
    fn_27_17437C(part, acc);
    *(char**)part = lbl_27_data_2F9F8;
    *(char**)(part + 4) = lbl_27_data_2F9F8 + 0x40;
    }
    {
    char* part = r27p + 0x20;
    fn_27_17437C(part, acc);
    *(char**)part = lbl_27_data_2FAA0;
    *(char**)(part + 4) = lbl_27_data_2FAA0 + 0x40;
    }
    {
    char* part = r27p + 0x34;
    fn_27_17437C(part, acc);
    *(char**)part = lbl_27_data_2FB48;
    *(char**)(part + 4) = lbl_27_data_2FB48 + 0x40;
    }
    {
    char* part = r27p + 0x48;
    fn_27_17437C(part, acc);
    *(char**)part = lbl_27_data_2FBF0;
    *(char**)(part + 4) = lbl_27_data_2FBF0 + 0x40;
    }
    {
    char* part = r27p + 0x5c;
    fn_27_17437C(part, acc);
    *(char**)part = lbl_27_data_2FC98;
    *(char**)(part + 4) = lbl_27_data_2FC98 + 0x40;
    }
    {
    char* part = r27p + 0x70;
    fn_27_17437C(part, acc);
    *(char**)part = lbl_27_data_2FD40;
    *(char**)(part + 4) = lbl_27_data_2FD40 + 0x40;
    }
    {
    char* part = r27p + 0x84;
    fn_27_17437C(part, acc);
    *(char**)part = lbl_27_data_2FDE8;
    *(char**)(part + 4) = lbl_27_data_2FDE8 + 0x40;
    }
        }
    };
    ModuleBuilder::create(mod, self, local, acc);

    *(void**)(self + 0x162d0) = soValueAccesser::getConstantIndefinite(*(soModuleAccesser**)(self + 0x60), 0xa7f9, 0);
    *(s32*)(self + 0x162d4) = 1;
    *(void**)(self + 0x162d8) = soValueAccesser::getConstantIndefinite(*(soModuleAccesser**)(self + 0x60), 0xa7fc, 0);
    *(s32*)(self + 0x162dc) = 1;

    fn_27_126470(self);
    ((InitVT*)(self + 0x15d44))->init(*(void**)(self + 0x60));

    *(char**)(self + 0x3c) = lbl_116_data_7DFC;
    *(char**)(self + 0x40) = lbl_116_data_7DFC + 0x64;
    *(char**)(self + 0x48) = lbl_116_data_7DFC + 0x70;
    *(char**)(self + 0x54) = lbl_116_data_7DFC + 0x84;
    *(char**)(self + 0x64) = lbl_116_data_7DFC + 0xdc;
    *(char**)(self + 0x70) = lbl_116_data_7DFC + 0xec;
    *(char**)(self + 0x7c) = lbl_116_data_7DFC + 0xfc;
    *(char**)(self + 0x88) = lbl_116_data_7DFC + 0x110;
    *(char**)(self + 0x94) = lbl_116_data_7DFC + 0x128;
    *(char**)(self + 0xa0) = lbl_116_data_7DFC + 0x140;
    *(char**)(self + 0xac) = lbl_116_data_7DFC + 0x158;
    *(char**)(self + 0xb8) = lbl_116_data_7DFC + 0x16c;
    *(char**)(self + 0xc4) = lbl_116_data_7DFC + 0x180;
    *(char**)(self + 0xd0) = lbl_116_data_7DFC + 0x190;
    *(char**)(self + 0xdc) = lbl_116_data_7DFC + 0x1c4;
    *(char**)(self + 0xe8) = lbl_116_data_7DFC + 0x1d4;
    *(char**)(self + 0xf4) = lbl_116_data_7DFC + 0x1e8;
    *(char**)(self + 0x100) = lbl_116_data_7DFC + 0x254;

    fn_27_C749C(self + 0x162e0);
    void* gd = g_ftCommonDataAccesser.getData((ftKind)0x1e);
    *(void**)(self + 0x162f0) = gd;
    fn_27_368968(self + 0x162f4, *(void**)((char*)gd + 0x7c), *(void**)(self + 0x60));
    fn_27_376848(self + 0x1630c, a1, *(void**)(self + 0x60), self + 0x162f4);

    typedef void* StatusPointer;
    new (av) StatusPointer[13]();
    av[0] = lbl_27_bss_83CC;
    av[1] = lbl_116_bss_4CC;
    av[5] = lbl_27_bss_83CC;
    av[6] = lbl_27_bss_83CC;
    av[7] = lbl_116_bss_4CC;
    av[8] = lbl_116_bss_4CC;
    av[9] = lbl_116_bss_4CC;
    av[10] = lbl_116_bss_4CC;

    ((StatusVT*)(*(char**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70)))->set(av, 0xd);

    char* q2 = (char*)__dynamic_cast(*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x38), 8, lbl_116_data_1F84, lbl_116_data_217C, 1);
    float fa = *(float*)(*(char**)(*(char**)(self + 0x162f0) + 0x7c) + 0x1c);
    *(s32*)(q2 + 0xac) = 0x11;
    *(float*)(q2 + 0xb0) = fa;
    float fb = *(float*)(*(char**)(*(char**)(self + 0x162f0) + 0x7c) + 0x20);
    *(s32*)(q2 + 0xb4) = 5;
    *(float*)(q2 + 0xb8) = fb;

    ((ParamVT*)(*(char**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x90)))->set((char*)*(void**)(self + 0x162f0) + 0x94);

    return self;
}
