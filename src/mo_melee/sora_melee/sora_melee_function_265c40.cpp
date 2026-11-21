#include <types.h>
#include <new>

class soCollisionAttackModule;
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/event/so_event_system.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_56058[], lbl_27_bss_384[], lbl_27_bss_444[];
extern char lbl_27_data_2F978[], lbl_27_data_558D8[];
extern char lbl_27_data_39430[], lbl_27_data_46F8[], lbl_27_data_1E0A0[];
extern char lbl_27_data_B620[], lbl_27_data_12DD0[], lbl_27_data_1A108[];
extern char lbl_27_data_55F48[], lbl_27_data_3A338[], lbl_27_data_44A68[];
extern char lbl_27_data_40418[], lbl_27_data_40508[], lbl_27_data_32FD0[];
extern char lbl_27_bss_5FF4[], lbl_27_bss_5BF4[], lbl_27_bss_5C0C[];
extern char __RTTI__11soEventUnit[];
extern s8 lbl_27_bss_1088;
extern s8 lbl_27_bss_5C68;
extern void* lbl_27_bss_108C;
extern void* lbl_27_bss_5C6C;
extern f32 lbl_27_rodata_42C8;
extern f32 lbl_27_rodata_42CC;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;

void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, s32, f32, f32);
void fn_27_26F06C(void*, void*, void*, void*, void*, soEventObserverRegistrationDesc*);
void fn_27_A34D4(void*, void*, s32, void*, void*, void*, void*,
                 soEventObserverRegistrationDesc*, int);
void fn_27_A78C0(void*);
void fn_27_A6948(void*);
void fn_27_A6978(void*);
void fn_27_1BA438(void*);
void fn_27_84118(void*);
void fn_27_D3188(void*);
void fn_27_86D4C(void*);
void fn_27_37D3C(void*);
void fn_27_7DC10(void*);
void fn_27_82C14(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__18soCollisionHitPartFv(void*);
void __dt__18soCollisionHitPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void __ct__19soCollisionHitGroupFv(void*);
void __dt__19soCollisionHitGroupFv(void*);
void __register_global_object(void*, void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getInstance__13soEventSystemFv(void);
void* getManager__13soEventSystemFl(void*, s32);
}

class soGimmickEventObserver;
template <typename T> class soEventUnitWrapper;
template <> class soEventUnitWrapper<soGimmickEventObserver> {
public:
    static unsigned char __RTTI[];
};

struct GlobalObject {
    void* vt;
    GlobalObject() {
        vt = 0;
        vt = lbl_27_data_B620;
    }
};

struct GlobalObject2 {
    void* vt;
    GlobalObject2() {
        vt = 0;
        vt = lbl_27_data_12DD0;
    }
};

struct Bits {
    unsigned int a : 4, b : 2, c : 1, rest : 25;
};

class Class_364 {
public:
    virtual void fn_27_93100();
    virtual void fn_27_9329C();
    virtual void fn_27_932A0();
    virtual void fn_27_93778();
    virtual bool fn_27_95264();
    virtual void fn_27_93860();
    virtual void fn_27_94198();
    virtual void fn_27_942B4();
    virtual void fn_27_943C4();
    virtual void fn_27_944D4();
    virtual void fn_27_94748(const soCollisionHitPart&);
    virtual void fn_27_9483C();
    virtual void fn_27_94930();
    virtual int fn_27_94E00();
    virtual bool fn_27_94C38();
    virtual void fn_27_93B80();
    virtual void fn_27_93F8C();
    virtual void fn_27_94A40();
    virtual void fn_27_94AA0();
    virtual void fn_27_94AD0();
    virtual void fn_27_94B00();
    virtual void fn_27_94B30();
    virtual void fn_27_94B60();
    virtual void fn_27_94B90();
    virtual void fn_27_94BC0();
    virtual void fn_27_94BF0();
    virtual void fn_27_94C20();
    virtual int fn_27_973EC();
    virtual int fn_27_973F4();

    void* calc;
    unsigned int flags;
    char parts[0x68];
    void* vt2;
    void* calc2;
    Bits bits2;
    char groups[0x78];
    void* vt3;
    void* calc3;
    Bits bits3;
    char hitgroups[0x38];
    char impl[0x68];
};

struct Storage {
    void* vt;
    void* calc;
    Bits bits;
    char elements[0xa0];
};

class Obj358 {
public:
    virtual void m0(s16, s16);
    s16 a, b, c;

    Obj358() : a(-1), b(3), c(-1) {
        *(void**)this = lbl_27_data_2F978;
        m0(-1, -1);
    }
};

class Obj664 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9(void*);
};

class Sub24 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

class EvSys {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual u32 m6(s16);
};

class EvMgr {
public:
    virtual s32 m0(void*);
    virtual void m1();
    virtual u32 m2(s16);
    virtual void m3(s16, s16);
    virtual u32 m4(s16);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void* m8(s16);
};

class EvUnit {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s16 m6(void*, s8);
};

extern "C" void* fn_27_265C40(char* self, char* arg) {
    fn_27_262728(self, arg, lbl_27_data_56058, lbl_27_bss_384,
                 self + 0x4a0, self + 0x5b4, self + 0x664, lbl_27_bss_444);

    new (self + 0x358) Obj358;

    *(void**)(self + 0x3c) = lbl_27_data_558D8;
    *(void**)(self + 0x40) = lbl_27_data_558D8 + 0x64;
    *(void**)(self + 0x48) = lbl_27_data_558D8 + 0x70;
    *(void**)(self + 0x54) = lbl_27_data_558D8 + 0x84;
    *(void**)(self + 0x64) = lbl_27_data_558D8 + 0xdc;
    *(void**)(self + 0x358) = lbl_27_data_558D8 + 0x10c;

    char* r28p;
    gfTask::Category category =
        (gfTask::Category)(unsigned char)(*(unsigned int*)(self + 0x2c) >> 7);
    Class_364* h = (Class_364*)(self + 0x364);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    s32 id = *(s32*)(self + 0x28);

    {
        soCollisionHitPart part((soCollision::Category)6, 0x3ff);
        *(void**)h = lbl_27_data_39430;
        h->calc = lbl_27_data_39430 + 0x48;
        h->flags &= 0x01ffffff;
        __construct_array(h->parts, __ct__18soCollisionHitPartFv,
                          __dt__18soCollisionHitPartFv, 0x68, 1);

        bool d;
        int c, b, a;
        a = h->fn_27_973F4();
        b = h->fn_27_973EC();
        c = h->fn_27_94E00();
        d = h->fn_27_94C38();
        bool e = h->fn_27_95264();
        int count = soArrayVectorCalculator::resize(
            *(soArrayVectorCalcInterface*)&h->calc, 1, e, d, c, b, a);
        for (int i = 0; i < count; ++i)
            h->fn_27_94748(part);
    }

    h->vt2 = lbl_27_data_46F8;
    h->calc2 = lbl_27_data_46F8 + 0x48;
    h->bits2.a = 0;
    h->bits2.b = 1;
    h->bits2.c = 0;
    __construct_array(h->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&h->calc2, 1, 1);

    h->vt3 = lbl_27_data_1E0A0;
    h->calc3 = lbl_27_data_1E0A0 + 0x48;
    h->bits3.a = 0;
    h->bits3.b = 1;
    h->bits3.c = 0;
    __construct_array(h->hitgroups, __ct__19soCollisionHitGroupFv,
                      __dt__19soCollisionHitGroupFv, 0x38, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&h->calc3, 1, 1);

    new (h->impl) soCollisionHitModuleImpl(
        (soModuleAccesser*)(self + 0xa8), id, category,
        (soArray<soCollisionHitPart>*)h,
        (soArray<soCollisionGroup>*)&h->vt2,
        (soArray<soCollisionHitGroup>*)&h->vt3, desc, true);

    Storage* s = (Storage*)(self + 0x508);
    soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
    s->vt = lbl_27_data_1A108;
    s->calc = lbl_27_data_1A108 + 0x48;
    s->bits.a = 0;
    s->bits.b = 1;
    s->bits.c = 0;
    __construct_array(s->elements, fn_27_D3188, fn_27_86D4C, 0xa0, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&s->calc, 1, 1);

    if (!lbl_27_bss_1088) {
        GlobalObject* object = new (&lbl_27_bss_108C) GlobalObject;
        __register_global_object(object, (void*)fn_27_7DC10, lbl_27_bss_5BF4);
        lbl_27_bss_1088 = 1;
    }

    fn_27_26F06C((char*)s + 0xac, self + 0xa8, s, lbl_27_bss_5FF4,
                 &lbl_27_bss_108C, desc2);

    soEventObserverRegistrationDesc* desc3 = lbl_27_data_54C60;
    if (!lbl_27_bss_5C68) {
        GlobalObject2* object = new (&lbl_27_bss_5C6C) GlobalObject2;
        __register_global_object(object, (void*)fn_27_82C14, lbl_27_bss_5C0C);
        lbl_27_bss_5C68 = 1;
    }

    fn_27_A34D4(self + 0x664, self + 0xa8, 2, self + 0x798,
                 self + 0x6cc, self + 0x6b0, &lbl_27_bss_5C6C, desc3, -1);

    fn_27_A78C0(self + 0x6b0);
    *(void**)(self + 0x6cc) = lbl_27_data_55F48;
    *(void**)(self + 0x6d0) = lbl_27_data_55F48 + 0x48;
    *(u32*)(self + 0x6d4) &= 0x0000ffff;
    *(void**)(self + 0x798) = lbl_27_data_3A338;
    *(void**)(self + 0x79c) = lbl_27_data_3A338 + 0x48;
    *(u32*)(self + 0x7a0) = *(u32*)(self + 0x7a0) & 0x01ffffff;
    __construct_array(self + 0x7a4, fn_27_A6948, fn_27_A6978, 0x24, 1);

    s16 v7cc = (s16)reinterpret_cast<Sub24*>(
        *(char**)(*(char**)(self + 0x180) + 0x80) + 8)->m7();
    char* r22p = self + 0x7c8;
    *(void**)r22p = lbl_27_data_44A68;
    *(s16*)(r22p + 4) = v7cc;
    *(s16*)(self + 0x7ce) = 3;
    if (*(s16*)(self + 0x7cc) != -1) {
        s32 ret = reinterpret_cast<EvMgr*>(getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), *(s16*)(r22p + 4)))->m0(r22p);
        if ((s16)ret > -1)
            *(s16*)(r22p + 6) = (s16)ret;
    }

    r28p = r22p + 0xc;
    *(char**)(r22p + 0x8) = r28p;
    *(void**)r22p = lbl_27_data_32FD0;
    *(u8*)(r22p + 0x10) = 0;
    *(void**)(r22p + 0xc) = lbl_27_data_40418;
    *(void**)(r22p + 0x14) = lbl_27_data_40418 + 0x34;
    *(void**)(r22p + 0x18) = lbl_27_data_40418 + 0x40;
    *(void**)(r22p + 0x1c) = lbl_27_data_40508;
    *(void**)(r22p + 0x20) = lbl_27_data_40508 + 0x48;
    *(u32*)(r28p + 0x18) = (u16)*(u32*)(r28p + 0x18);
    __construct_array(r28p + 0x1c, fn_27_1BA438, fn_27_84118, 0xc, 8);
    *(u8*)(r28p + 0x7c) = 0;

    s32 r27 = reinterpret_cast<Sub24*>(
        *(char**)(*(char**)(self + 0x180) + 0x80) + 8)->m7();
    u32 r22 = 0;
    s32 r23 = 0;
    s32 r3 = 0;
    s32 r4 = 0;
    s16 r24 = *(s16*)(self + 0x35c);

    if (r24 >= 0 && *(s16*)(self + 0x35e) >= 0)
        r4 = 1;
    if (r4 != 0 && *(s16*)(self + 0x360) > -1)
        r3 = 1;
    if (r3 != 0) {
        if (reinterpret_cast<EvSys*>(
                getInstance__13soEventSystemFv())->m6(r24) == 1)
            r23 = 1;
    }
    if (r23 != 0) {
        if (reinterpret_cast<EvMgr*>(getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(),
                *(s16*)(self + 0x35c)))->m4(*(s16*)(self + 0x35e)) == 1)
            r22 = 1;
    }
    if (r22 == 1) {
        s16 removeID = *(s16*)(self + 0x35c);
        if (soEventSystem::getInstance()->getInstanceManager().isContain(removeID) == 1) {
            reinterpret_cast<EvMgr*>(getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), *(s16*)(self + 0x35c)))->m3(
                    *(s16*)(self + 0x35e), *(s16*)(self + 0x360));
        }
        *(s16*)(self + 0x360) = -1;
        *(s16*)(self + 0x35c) = -1;
    }

    if ((s16)r27 > -1 && *(s16*)(self + 0x35e) > -1) {
        if (reinterpret_cast<EvSys*>(
                getInstance__13soEventSystemFv())->m6((s16)r27) != 0) {
            if (reinterpret_cast<EvMgr*>(getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), (s16)r27))->m2(
                        *(s16*)(self + 0x35e)) != 1) {
                EvMgr* mgr = reinterpret_cast<EvMgr*>(
                    getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), (s16)r27));
                s16 x;
                if (mgr->m4(*(s16*)(self + 0x35e)) == 0) {
                    x = -1;
                } else {
                    void* ev = mgr->m8(*(s16*)(self + 0x35e));
                    void* u = __dynamic_cast(
                        ev, 0, soEventUnitWrapper<soGimmickEventObserver>::__RTTI,
                        __RTTI__11soEventUnit, 0);
                    if (u == 0) {
                        x = -1;
                    } else {
                        x = reinterpret_cast<EvUnit*>(u)->m6(self + 0x358, -1);
                    }
                }
                *(s16*)(self + 0x360) = (s16)x;
                if (x > -1 && x > -1)
                    *(s16*)(self + 0x35c) = (s16)r27;
            }
        }
    }

    reinterpret_cast<Obj664*>(self + 0x664)->m9(
        *(void**)(*(char**)(arg + 0x10) + 8));
    fn_27_26320C(self);
    fn_27_2632F4(self, *(s32*)(arg + 0xc),
                 lbl_27_rodata_42C8, lbl_27_rodata_42CC);
    return self;
}
