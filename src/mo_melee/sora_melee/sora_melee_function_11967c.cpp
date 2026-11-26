#include <ft/ft_owner.h>
#include <so/event/so_event_system.h>
#include <types.h>

#pragma force_active on

extern "C" {
extern char lbl_27_data_261F0[];
extern char lbl_27_data_261B0[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
extern f32 lbl_27_rodata_FB8;
extern char* g_ftManager;

void* __dynamic_cast(void*, s32, const void*, const void*, s32);
s32 fn_27_111364(void*);
f32 fn_27_1119A0(void*);
s32 fn_27_124680(void*);
u8 fn_27_1246EC(void*);
s32 fn_27_124718(void*);
void fn_27_1246B4(void*, s8);
void fn_27_1246D4(void*, u8);
void fn_27_124700(void*, s32);
void fn_27_124830(void*, s32);
void fn_27_139730(void*, s32, s32, s32);
void fn_27_1571DC(void*, s32, s32, f32);
void fn_27_15B908(void*, s32, s32);
void fn_27_15BB18(void*, s32, s32);
}

struct Self {
    char* unk0;
};

struct Param {
    s32 idx;
    s32 a04;
    s32 a08;
    f32 f0c;
    f32 f10;
    s32 a14;
    s8 b18;
    u8 b19;
    s16 pad1a;
    s32 a1c;
};

struct Ev {
    void* vt;
    s16 manage;
    s16 unit;
    s32 value;
    s32 extra;
};

struct MgrView {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual s32 getObserverCapacity(s32);
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void* getEventUnit(s32);
};

struct UnitView {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual s32 getEventId();
    virtual void d8();
};

struct FtSub {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual s32 f21();
};

struct Object_vptr_c_base {
    char pad[0xc];
};

class Object_vptr_c : public Object_vptr_c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(s32, f32);
    virtual f32 slot3();
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void unused0(); virtual void unused1(); virtual void unused2(); virtual void unused3(); virtual void unused4();
    virtual void unused5(); virtual void unused6(); virtual void unused7(); virtual void unused8(); virtual void unused9();
    virtual void unused10(); virtual void unused11(); virtual void unused12(); virtual void unused13(); virtual void unused14();
    virtual void unused15(); virtual void unused16(); virtual void unused17(); virtual void unused18(); virtual void unused19();
    virtual void unused20(); virtual void unused21(); virtual void unused22(); virtual void unused23(); virtual void unused24();
    virtual void unused25(); virtual void unused26(); virtual void unused27(); virtual void unused28(); virtual void unused29();
    virtual void unused30(); virtual void unused31(); virtual void unused32(); virtual void unused33(); virtual void unused34();
    virtual void unused35(); virtual void unused36(); virtual void unused37(); virtual void unused38(); virtual void unused39();
    virtual void unused40(); virtual void unused41(); virtual void unused42(); virtual void unused43(); virtual void unused44();
    virtual void unused45(); virtual void unused46(); virtual void unused47(); virtual void unused48(); virtual void unused49();
    virtual void unused50(); virtual void unused51(); virtual void unused52(); virtual void unused53(); virtual void unused54();
    virtual void unused55(); virtual void unused56(); virtual void unused57(); virtual void unused58(); virtual void unused59();
    virtual void unused60(); virtual void unused61(); virtual void unused62(); virtual void unused63(); virtual void unused64();
    virtual void unused65(); virtual void unused66(); virtual void unused67(); virtual void unused68(); virtual void unused69();
    virtual void unused70(); virtual void unused71(); virtual void unused72(); virtual void unused73(); virtual void unused74();
    virtual void unused75(); virtual void unused76(); virtual void unused77(); virtual void unused78(); virtual void unused79();
    virtual void unused80(); virtual void unused81(); virtual void unused82(); virtual void unused83(); virtual void unused84();
    virtual void unused85(); virtual void unused86(); virtual void unused87(); virtual void unused88(); virtual void unused89();
    virtual void unused90(); virtual void unused91(); virtual void unused92(); virtual void unused93(); virtual void unused94();
    virtual void unused95(); virtual void unused96(); virtual void unused97(); virtual void unused98(); virtual void unused99();
    virtual void unused100(); virtual void unused101(); virtual void unused102(); virtual void unused103(); virtual void unused104();
    virtual void unused105(); virtual void unused106(); virtual void unused107(); virtual void unused108(); virtual void unused109();
    virtual void unused110(); virtual void unused111(); virtual void unused112(); virtual void unused113(); virtual void unused114();
    virtual void unused115(); virtual void unused116(); virtual void unused117(); virtual void unused118(); virtual void unused119();
    virtual void unused120(); virtual void unused121(); virtual void unused122(); virtual void unused123(); virtual void unused124();
    virtual void unused125(); virtual void unused126(); virtual void unused127(); virtual void unused128(); virtual void unused129();
    virtual void unused130(); virtual void unused131(); virtual void unused132(); virtual void unused133(); virtual void unused134();
    virtual void unused135(); virtual void unused136(); virtual void unused137(); virtual void unused138(); virtual void unused139();
    virtual void unused140(); virtual void unused141(); virtual void unused142(); virtual void unused143(); virtual void unused144();
    virtual void unused145(); virtual void unused146(); virtual void unused147(); virtual void unused148(); virtual void unused149();
    virtual void unused150(); virtual void unused151(); virtual void unused152(); virtual void unused153(); virtual void unused154();
    virtual void unused155(); virtual void unused156(); virtual void unused157(); virtual void unused158(); virtual void unused159();
    virtual void unused160(); virtual void unused161(); virtual void unused162(); virtual void unused163(); virtual void unused164();
    virtual void unused165(); virtual void unused166(); virtual void unused167(); virtual void unused168(); virtual void unused169();
    virtual void unused170(); virtual void unused171(); virtual void unused172(); virtual void unused173(); virtual void unused174();
    virtual void unused175(); virtual void unused176(); virtual void unused177(); virtual void unused178(); virtual void unused179();
    virtual void unused180(); virtual void unused181(); virtual void unused182(); virtual void unused183(); virtual void unused184();
    virtual void unused185(); virtual void unused186(); virtual void unused187(); virtual void unused188(); virtual void unused189();
    virtual void unused190(); virtual void unused191(); virtual void unused192(); virtual void unused193(); virtual void unused194();
    virtual void unused195(); virtual void unused196(); virtual void unused197(); virtual void unused198(); virtual void unused199();
    virtual void unused200(); virtual void unused201(); virtual void unused202(); virtual void unused203(); virtual void unused204();
    virtual void unused205();
    virtual void slot206(s32, s32, s32);
};

static inline f32 vcallFOwner(void* owner) {
    return ((Object_vptr_c*)owner)->slot3();
}

static inline void vcallOwnerSet(void* owner, f32 f) {
    ((Object_vptr_c*)owner)->slot2(0, f);
}

static inline void vcall340(void* obj, s32 a, s32 b, s32 c) {
    ((Object_vptr_3c*)obj)->slot206(a, b, c);
}

inline s32 getUnit(MgrView* mgr, s16 unit) {
    UnitView* u = (UnitView*)__dynamic_cast(
        mgr->getEventUnit(unit), 0, lbl_27_data_26440,
        __RTTI__11soEventUnit, 0);
    if (u == 0)
        return 0;
    return u->getEventId();
}

inline void evLookupFill(Ev* ev, s16& n, soEventManager*& m2) {
    s32 value;
    n = (s16)((FtSub*)(g_ftManager + 0xb4))->f21();
    value = 0;
    ev->vt = lbl_27_data_261F0;
    ev->manage = n;
    ev->unit = 0;
    ev->value = 0;

    if (n > 0 && n > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(n)) {
            soEventManager* m1 =
                soEventSystem::getInstance()->getManager(ev->manage);
            if (m1->getObserverCapacity(ev->unit) == 0) {
                ev->value = value;
            } else {
                s16 id = ev->unit;
                m2 = soEventSystem::getInstance()->getManager(ev->manage);
                if (m2->getObserverCapacity(id) == 0)
                    value = 0;
                else
                    value = getUnit((MgrView*)m2, id);
                ev->value = value;
            }
        }
    }
}

inline void doBody(
    Self* self, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s16 nA1, nB1, nC1, nA2, nB2, nC2;
    soEventManager *mA1, *mB1, *mC1, *mA2, *mB2, *mC2;
    char* e2;
    char* e1;
    s32 originalA;
    e1 = (*(char**)self) + (u8)arg2 * 0x244;
    e2 = (*(char**)self) + (u8)arg3 * 0x244;
    Param blk[2] = {
        { arg2, 0, 0, 0.0f, 0.0f, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0.0f, 0.0f, 0, 0, 0, 0, 0 }
    };
    u32 i;

    blk[0].a04 = fn_27_111364(*(void**)(e1 + 0x28));
    blk[0].a08 = *(s32*)(e1 + 0x58);
    blk[0].f0c = vcallFOwner(*(void**)(e1 + 0x28));
    blk[0].f10 = fn_27_1119A0(*(void**)(e1 + 0x28));
    blk[0].a14 = *(s32*)(e1 + 0x70);
    blk[0].b18 = (s8)fn_27_124680(*(void**)(e1 + 0x2c));
    blk[0].b19 = (u8)fn_27_1246EC(*(void**)(e1 + 0x2c));
    blk[0].a1c = fn_27_124718(*(void**)(e1 + 0x2c));

    blk[1].idx = arg3;
    blk[1].a04 = fn_27_111364(*(void**)(e2 + 0x28));
    blk[1].a08 = *(s32*)(e2 + 0x58);
    blk[1].f0c = vcallFOwner(*(void**)(e2 + 0x28));
    blk[1].f10 = fn_27_1119A0(*(void**)(e2 + 0x28));
    blk[1].a14 = *(s32*)(e2 + 0x70);
    blk[1].b18 = (s8)fn_27_124680(*(void**)(e2 + 0x2c));
    blk[1].b19 = (u8)fn_27_1246EC(*(void**)(e2 + 0x2c));
    blk[1].a1c = fn_27_124718(*(void**)(e2 + 0x2c));

    Param* dat;
    Param* src = blk;
    for (i = 0; i < 2; i++) {
        dat = &blk[i == 0];
        char* e = (*(char**)self) + (u8)src->idx * 0x244;
        void* obj;

        ((ftOwner*)*(void**)(e + 0x28))->setHitPointMax(dat->f10);
        vcallOwnerSet(*(void**)(e + 0x28), dat->f0c);
        fn_27_1246B4(*(void**)(e + 0x2c), dat->b18);
        fn_27_1246D4(*(void**)(e + 0x2c), dat->b19);
        fn_27_124700(*(void**)(e + 0x2c), dat->a1c);

        if (arg1 == 1) {
            obj = *(void**)(e + (((u8)e[0xa]) << 3) + 0x34);
            fn_27_139730(obj, dat->idx, -1, arg4);
            s32 b = dat->a08;
            s32 a = dat->a04;
            obj = *(void**)(e + (((u8)e[0xa]) << 3) + 0x34);
            vcall340(obj, a, b, 0);
            if (((u8)e[0xe]) & 2)
                vcall340(*(void**)(e + 0x3c), a, b, 0);
            fn_27_124830(*(void**)(e + 0x2c), dat->a14);
            *(s32*)(e + 0x50) = dat->idx;
        } else {
            *(s32*)(e + 0x50) = -1;
            obj = *(void**)(e + (((u8)e[0xa]) << 3) + 0x34);
            fn_27_139730(obj, -1, dat->idx, arg4);
            s32 b;
            b = src->a08;
            originalA = src->a04;
            obj = *(void**)(e + (((u8)e[0xa]) << 3) + 0x34);
            vcall340(obj, originalA, b, 1);
            if (((u8)e[0xe]) & 2)
                vcall340(*(void**)(e + 0x3c), originalA, b, 1);
            fn_27_124830(*(void**)(e + 0x2c), src->a14);
        }
        src++;
    }

    Ev c2, b2, a2, c1, b1, a1;
    if (arg1 == 1) {
        evLookupFill(&a1, nA1, mA1);
        a1.extra = -1;
        a1.vt = lbl_27_data_261B0;
        fn_27_15B908(&a1, arg2, arg3);

        evLookupFill(&b1, nB1, mB1);
        b1.extra = arg2;
        b1.vt = lbl_27_data_261B0;
        fn_27_1571DC(&b1, 0, 0, lbl_27_rodata_FB8);

        evLookupFill(&c1, nC1, mC1);
        c1.extra = arg3;
        c1.vt = lbl_27_data_261B0;
        fn_27_1571DC(&c1, 0, 0, lbl_27_rodata_FB8);

        *(s32*)((char*)self + 0x44) = arg2;
        *(s32*)((char*)self + 0x48) = arg3;
    } else {
        evLookupFill(&a2, nA2, mA2);
        a2.extra = -1;
        a2.vt = lbl_27_data_261B0;
        fn_27_15BB18(&a2, arg2, arg3);

        evLookupFill(&b2, nB2, mB2);
        b2.extra = arg2;
        b2.vt = lbl_27_data_261B0;
        fn_27_1571DC(&b2, 0, 0, lbl_27_rodata_FB8);

        evLookupFill(&c2, nC2, mC2);
        c2.extra = arg3;
        c2.vt = lbl_27_data_261B0;
        fn_27_1571DC(&c2, 0, 0, lbl_27_rodata_FB8);

        *(s32*)((char*)self + 0x44) = -1;
        *(s32*)((char*)self + 0x48) = -1;
    }

    *(s32*)((char*)self + 0x40) = arg5;
    *(u8*)((char*)self + 0x3c) = (u8)arg1;
}

extern "C" void fn_27_11967C(
    Self* self, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    doBody(self, arg1, arg2, arg3, arg4, arg5);
}
