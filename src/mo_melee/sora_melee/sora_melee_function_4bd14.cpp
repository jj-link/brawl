#include <nw4r/math/math_arithmetic.h>
#include <types.h>
#include <so/event/so_event_system.h>

#pragma force_active on

struct Inst {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual int i6(int);
};

struct Mgr {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual int m4(int);
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void* m8(int);
};

struct Node {
    char pad0[0xC];
    u32 id;
    char pad10[0x12];
    u8 cat;
    u8 sub;
};

struct Elem {
    virtual void e0();
    virtual void e1(float, Node*, int);
};

struct List {
    virtual void l0();
    virtual void l1();
    virtual Elem** l2(int);
    virtual void l3();
    virtual int l4();
};

struct Unit {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual List* u7();
};

struct Obj {
    virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3(); virtual void o4();
    virtual void o5(); virtual void o6(); virtual void o7(); virtual void o8(); virtual void o9();
    virtual void o10(); virtual void o11(); virtual void o12(); virtual void o13(); virtual void o14();
    virtual void o15(); virtual void o16(); virtual void o17(); virtual void o18(); virtual void o19();
    virtual void o20(); virtual void o21(); virtual void o22(); virtual void o23(); virtual void o24();
    virtual void o25(); virtual void o26(); virtual void o27(); virtual void o28(); virtual void o29();
    virtual void o30(); virtual void o31(); virtual void o32(); virtual void o33(); virtual void o34();
    virtual void o35(); virtual void o36(); virtual void o37(); virtual void o38(); virtual void o39();
    virtual void o40(); virtual void o41(); virtual void o42(); virtual void o43(); virtual void o44();
    virtual void o45(); virtual void o46(); virtual void o47(); virtual void o48(); virtual void o49();
    virtual float o50(u8);
};

class Sub3C {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};

struct Self {
    char pad0[0x20];
    s16 a;
    s16 b;
    List* cache;
    s32 c;
    char pad2C[0xC];
    f32 f38;
    Sub3C sub3c;
    char pad40[0x80];
    char padC0[0x21];
    u8 e1;
};

extern "C" {
extern char lbl_27_bss_AE0[];
extern char lbl_27_data_4558[];
extern char lbl_27_data_248[];
extern char __RTTI__11soEventUnit[];
extern char __RTTI__6gfTask[];
extern const float lbl_27_rodata_50C;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Inst* getInstance__13soEventSystemFv();
Mgr* getManager__13soEventSystemFl(Inst*, long);
void* getInstance__15gfTaskSchedulerFv();
void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, u32);
void* fn_8015C1B0(void*, void*);
void* fn_27_36A58(void*, int);
float fn_27_379A0(void*, int);
Obj* fn_27_8CD54(void*);

inline bool checkManageId(const Self* self) {
    s32 id = self->a;
    return soEventSystem::getInstance()->getInstanceManager().isContain(id);
}

inline List* getList(Self* self) {
    s16 id = self->b;
    Mgr* mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->m4(id) == 0) return 0;
    Unit* unit = (Unit*)__dynamic_cast(mgr->m8(id), 0, lbl_27_data_4558, __RTTI__11soEventUnit, 0);
    if (unit == 0) return 0;
    return unit->u7();
}

void fn_27_4BD14(Self* self) {
    Mgr* mgr;
    List* sel;
    s16 id1;
    s16 id2;
    List* cur;
    Unit* unit;
    int flag;
    int n;
    int i;
    void* list;

    if (self->a <= -1) {
        sel = (List*)lbl_27_bss_AE0;
        goto LOOP;
    }
    if (self->cache != 0) {
        goto C;
    }
    if (self->a <= -1 || !checkManageId(self)) {
        flag = 0;
        goto CHECK;
    }
    if (getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a)->m4(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    cur = getList(self);
    self->cache = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) {
        sel = (List*)lbl_27_bss_AE0;
        goto LOOP;
    }
C:
    mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->a);
    if (mgr->m4(self->b) == 0) {
        self->cache = 0;
        sel = (List*)lbl_27_bss_AE0;
    } else {
        sel = self->cache;
    }
LOOP:
    n = self->sub3c.s3();
    for (i = 0; i < n; i++) {
        list = fn_27_36A58(self->padC0, i);
        Node* node = 0;
        while ((node = (Node*)fn_8015C1B0(list, node)) != 0) {
            void* task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(), node->cat, node->id);
            if (task == 0) {
                continue;
            }
            Obj* obj = fn_27_8CD54(__dynamic_cast(task, 0x3C, lbl_27_data_248, __RTTI__6gfTask, 0));
            float pos = fn_27_379A0(self->padC0, i);
            float d = obj->o50(node->sub) - pos;
            if (self->e1 == 1 && d * self->f38 < lbl_27_rodata_50C) {
                continue;
            }
            float absd = (float)(double)nw4r::math::FAbs(d);
            for (int j = 0; j < sel->l4(); j++) {
                Elem** p = sel->l2(j);
                (*p)->e1(absd, node, self->c);
            }
        }
    }
}
}
