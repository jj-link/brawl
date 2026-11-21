#include <types.h>
#include <new>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#include <so/event/so_event_presenter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_20878[], lbl_27_data_46658[], lbl_27_data_81A0[], lbl_27_data_466B8[], lbl_27_data_128[];
extern char lbl_27_data_15218[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[], __RTTI__11soEventUnit[];
extern const float lbl_27_rodata_7934;
extern const float lbl_27_rodata_7938;
}

struct Pair {
    void* a;
    void* b;
};

struct FlagSlot {
    u8 v;
    u8 pad[3];
};

struct KindSlot {
    s16 v;
    s16 pad;
};

class Mgr {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33();
    virtual s32 get(s32, s32);
};

class Reg {
public:
    virtual void v0();
    virtual void regist(Pair&, s16&);
};

class Q {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6();
    virtual s16 get();
};

class U {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6();
    virtual void* getList();
};

struct Pres {
    char pad[0x34];
    void* vt;
    s16 id;
    s16 unit;
    void* list;
    s32 v40;
    s32 v44;
    s32 v48;
    s32 v4c;
};

inline void* getList(Pres* p) {
    s16 unit = p->unit;
    soEventManager* mgr = soEventSystem::getInstance()->getManager(p->id);
    if (mgr->getObserverCapacity(unit) == 0) return 0;
    U* u = (U*)__dynamic_cast(mgr->getEventUnit(unit), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
    if (u == 0) return 0;
    return u->getList();
}

typedef soArrayVector<acCmdInterpreterStackData, 8> Stk;

struct Elem {
    s32 kind;
    s32 intData;
    u8 boolData;
    const void* addr;
    float f;
    Elem() : kind(-1), intData(0), boolData(0), addr(0), f(lbl_27_rodata_7934) { }
};

// Same layout/initialisation as soArrayVector<acCmdInterpreterStackData, 8>, without instantiating its vtable.
struct StkVec {
    void* vt0;
    void* vt1;
    s32 m_topIndex : 5;
    s32 m_lastIndex : 5;
    s32 m_size : 5;
    u32 m_isFull : 1;
    Elem m_elements[8];

    StkVec() : vt0(lbl_27_data_15218), vt1(lbl_27_data_15218 + 0x48),
               m_topIndex(0), m_lastIndex(0), m_size(0), m_isFull(false) { }
};

extern "C" u8* fn_27_34FEE8(u8* self, u8* arg1, Mgr* arg2)
{
    s32 e0;
    KindSlot k0, k1, k2, k3, k4;
    FlagSlot fl0, fl1, fl2, fl3, fl4;
    Pair pr0, pr1, pr2, pr3, pr4;

    // section 0
    arg2->get(0, 2);
    arg2->get(0, 1);
    s32 r0v = arg2->get(0, 0);
    *(s32*)(self + 4) = 0;
    *(void**)self = lbl_27_data_20878;
    *(s32*)(self + 8) = r0v;
    *(s32*)(self + 0xC) = 2;
    if (r0v == 0) *(s32*)(self + 0xC) = 0;
    new (self + 0x14) StkVec();
    *(void**)(self + 0xD0) = self;
    *(void**)(self + 0xC0) = lbl_27_data_46658;
    *(void**)(self + 0xD4) = lbl_27_bss_D8C;
    *(void**)(self + 0xD8) = lbl_27_bss_D8C;
    void* list0 = 0;
    fl0.v = 0;
    s16 eid0 = ((Q*)(*(u8**)(*(u8**)(arg1 + 0xD8) + 0x80) + 8))->get();
    u8* i0 = self + 0xDC;
    new (i0) acCmdInterpreter((Stk*)(self + 0x14), 0, 0, &fl0.v, lbl_27_rodata_7938);
    Pres* p0 = (Pres*)i0;
    p0->vt = lbl_27_data_466B8;
    p0->id = eid0;
    p0->unit = 5;
    p0->list = list0;
    e0 = eid0;
    if (e0 > 0 && e0 > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(e0)) {
            if (soEventSystem::getInstance()->getManager(p0->id)->getObserverCapacity(p0->unit) == 0) {
                p0->list = list0;
            } else {
                list0 = getList(p0);
                p0->list = list0;
            }
        }
    }
    s32 z0 = 0;
    p0->v40 = z0;
    *(void**)p0 = lbl_27_data_81A0;
    p0->vt = lbl_27_data_81A0 + 0x20;
    p0->v44 = z0;
    p0->v48 = z0;
    p0->v4c = z0;
    k0.v = 1;
    pr0.a = self + 0xDC;
    pr0.b = self + 0xC0;
    (*(Reg**)(*(u8**)(arg1 + 0xD8) + 0x6C))->regist(pr0, k0.v);

    // section 1
    arg2->get(1, 2);
    arg2->get(1, 1);
    s32 r1v = arg2->get(1, 0);
    u8* b1 = self + 0x12C;
    *(s32*)(b1 + 4) = z0;
    *(void**)b1 = lbl_27_data_20878;
    *(s32*)(b1 + 8) = r1v;
    *(s32*)(b1 + 0xC) = 6;
    if (r1v == 0) *(s32*)(b1 + 0xC) = 0;
    new (b1 + 0x14) StkVec();
    *(void**)(b1 + 0xD0) = b1;
    *(void**)(b1 + 0xC0) = lbl_27_data_46658;
    Stk* stack1 = (Stk*)(b1 + 0x14);
    *(void**)((u8*)stack1 + 0xC0) = lbl_27_bss_D8C;
    *(void**)((u8*)stack1 + 0xC4) = lbl_27_bss_D8C;
    void* list1 = 0;
    fl1.v = 0;
    s16 eid1 = ((Q*)(*(u8**)(*(u8**)(arg1 + 0xD8) + 0x80) + 8))->get();
    u8* i1 = b1 + 0xDC;
    new (i1) acCmdInterpreter(stack1, 1, 0, &fl1.v, lbl_27_rodata_7938);
    Pres* p1 = (Pres*)i1;
    p1->vt = lbl_27_data_466B8;
    p1->id = eid1;
    p1->unit = 5;
    p1->list = list1;
    s32 e1 = eid1;
    if (e1 > 0 && e1 > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(e1)) {
            if (soEventSystem::getInstance()->getManager(p1->id)->getObserverCapacity(p1->unit) == 0) {
                p1->list = list1;
            } else {
                list1 = getList(p1);
                p1->list = list1;
            }
        }
    }
    s32 z1 = 0;
    *(void**)p1 = lbl_27_data_81A0;
    p1->vt = lbl_27_data_81A0 + 0x20;
    p1->v40 = 1;
    p1->v44 = z1;
    p1->v48 = z1;
    p1->v4c = z1;
    k1.v = 2;
    pr1.a = b1 + 0xDC;
    pr1.b = b1 + 0xC0;
    (*(Reg**)(*(u8**)(arg1 + 0xD8) + 0x6C))->regist(pr1, k1.v);

    // section 2
    arg2->get(2, 2);
    arg2->get(2, 1);
    s32 r2v = arg2->get(2, 0);
    u8* b2 = self + 0x258;
    *(s32*)(b2 + 4) = z1;
    *(void**)b2 = lbl_27_data_20878;
    *(s32*)(b2 + 8) = r2v;
    *(s32*)(b2 + 0xC) = 6;
    if (r2v == 0) *(s32*)(b2 + 0xC) = 0;
    new (b2 + 0x14) StkVec();
    *(void**)(b2 + 0xD0) = b2;
    *(void**)(b2 + 0xC0) = lbl_27_data_46658;
    Stk* stack2 = (Stk*)(b2 + 0x14);
    *(void**)((u8*)stack2 + 0xC0) = lbl_27_bss_D8C;
    *(void**)((u8*)stack2 + 0xC4) = lbl_27_bss_D8C;
    void* list2 = 0;
    fl2.v = 0;
    s16 eid2 = ((Q*)(*(u8**)(*(u8**)(arg1 + 0xD8) + 0x80) + 8))->get();
    u8* i2 = b2 + 0xDC;
    new (i2) acCmdInterpreter(stack2, 1, 0, &fl2.v, lbl_27_rodata_7938);
    Pres* p2 = (Pres*)i2;
    p2->vt = lbl_27_data_466B8;
    p2->id = eid2;
    p2->unit = 5;
    p2->list = list2;
    s32 e2 = eid2;
    if (e2 > 0 && e2 > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(e2)) {
            if (soEventSystem::getInstance()->getManager(p2->id)->getObserverCapacity(p2->unit) == 0) {
                p2->list = list2;
            } else {
                s16 unit2 = p2->unit;
                soEventManager* mgr2 = soEventSystem::getInstance()->getManager(p2->id);
                if (mgr2->getObserverCapacity(unit2) == 0) {
                    list2 = 0;
                } else {
                    U* u2 = (U*)__dynamic_cast(mgr2->getEventUnit(unit2), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (u2 == 0) list2 = 0;
                    else list2 = u2->getList();
                }
                p2->list = list2;
            }
        }
    }
    s32 z2 = 0;
    *(void**)p2 = lbl_27_data_81A0;
    p2->vt = lbl_27_data_81A0 + 0x20;
    p2->v40 = 2;
    p2->v44 = z2;
    p2->v48 = z2;
    p2->v4c = z2;
    k2.v = 2;
    pr2.a = b2 + 0xDC;
    pr2.b = b2 + 0xC0;
    (*(Reg**)(*(u8**)(arg1 + 0xD8) + 0x6C))->regist(pr2, k2.v);

    // section 3
    arg2->get(3, 2);
    arg2->get(3, 1);
    s32 r3v = arg2->get(3, 0);
    u8* b3 = self + 0x384;
    *(s32*)(b3 + 4) = z2;
    *(void**)b3 = lbl_27_data_20878;
    *(s32*)(b3 + 8) = r3v;
    *(s32*)(b3 + 0xC) = 6;
    if (r3v == 0) *(s32*)(b3 + 0xC) = 0;
    new (b3 + 0x14) StkVec();
    *(void**)(b3 + 0xD0) = b3;
    *(void**)(b3 + 0xC0) = lbl_27_data_46658;
    Stk* stack3 = (Stk*)(b3 + 0x14);
    *(void**)((u8*)stack3 + 0xC0) = lbl_27_bss_D8C;
    *(void**)((u8*)stack3 + 0xC4) = lbl_27_bss_D8C;
    void* list3 = 0;
    fl3.v = 0;
    s16 eid3 = ((Q*)(*(u8**)(*(u8**)(arg1 + 0xD8) + 0x80) + 8))->get();
    u8* i3 = b3 + 0xDC;
    new (i3) acCmdInterpreter(stack3, 1, 0, &fl3.v, lbl_27_rodata_7938);
    Pres* p3 = (Pres*)i3;
    p3->vt = lbl_27_data_466B8;
    p3->id = eid3;
    p3->unit = 5;
    p3->list = list3;
    s32 e3 = eid3;
    if (e3 > 0 && e3 > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(e3)) {
            if (soEventSystem::getInstance()->getManager(p3->id)->getObserverCapacity(p3->unit) == 0) {
                p3->list = list3;
            } else {
                s16 unit3 = p3->unit;
                soEventManager* mgr3 = soEventSystem::getInstance()->getManager(p3->id);
                if (mgr3->getObserverCapacity(unit3) == 0) {
                    list3 = 0;
                } else {
                    U* u3 = (U*)__dynamic_cast(mgr3->getEventUnit(unit3), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (u3 == 0) list3 = 0;
                    else list3 = u3->getList();
                }
                p3->list = list3;
            }
        }
    }
    s32 z3 = 0;
    *(void**)p3 = lbl_27_data_81A0;
    p3->vt = lbl_27_data_81A0 + 0x20;
    p3->v40 = 3;
    p3->v44 = z3;
    p3->v48 = z3;
    p3->v4c = z3;
    k3.v = 2;
    pr3.a = b3 + 0xDC;
    pr3.b = b3 + 0xC0;
    (*(Reg**)(*(u8**)(arg1 + 0xD8) + 0x6C))->regist(pr3, k3.v);

    // section 4
    u8* i4 = self + 0x4B0;
    fl4.v = 1;
    void* list4 = 0;
    s16 eid4 = ((Q*)(*(u8**)(*(u8**)(arg1 + 0xD8) + 0x80) + 8))->get();
    new (i4) acCmdInterpreter((Stk*)(i4 + 0x50), 1, 0, &fl4.v, lbl_27_rodata_7938);
    Pres* p4 = (Pres*)i4;
    p4->vt = lbl_27_data_466B8;
    p4->id = eid4;
    p4->unit = 5;
    p4->list = list4;
    s32 e4 = eid4;
    if (e4 > 0 && e4 > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(e4)) {
            if (soEventSystem::getInstance()->getManager(p4->id)->getObserverCapacity(p4->unit) == 0) {
                p4->list = list4;
            } else {
                s16 unit4 = p4->unit;
                soEventManager* mgr4 = soEventSystem::getInstance()->getManager(p4->id);
                if (mgr4->getObserverCapacity(unit4) == 0) {
                    list4 = 0;
                } else {
                    U* u4 = (U*)__dynamic_cast(mgr4->getEventUnit(unit4), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (u4 == 0) list4 = 0;
                    else list4 = u4->getList();
                }
                p4->list = list4;
            }
        }
    }
    *(void**)p4 = lbl_27_data_81A0;
    p4->vt = lbl_27_data_81A0 + 0x20;
    p4->v40 = 4;
    p4->v44 = 0;
    p4->v48 = 0;
    p4->v4c = 0;
    new (i4 + 0x50) StkVec();
    k4.v = 4;
    pr4.a = i4;
    pr4.b = lbl_27_bss_8C4;
    (*(Reg**)(*(u8**)(arg1 + 0xD8) + 0x6C))->regist(pr4, k4.v);

    arg2->get(5, 2);
    arg2->get(5, 1);
    arg2->get(5, 0);
    return self;
}
