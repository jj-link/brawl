#pragma force_active on
#include <types.h>
#include <so/event/so_event_system.h>
#include <mt/mt_vector.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
};

struct Vec2 {
    f32 x, y;
};

struct Vec3 {
    f32 x, y, z;
};

struct Ctl2 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec3 s4();
};

struct Anim {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7(int);
};

struct Ctl {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual int c4(int);
    virtual void c5(int, int);
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11(int, int);
};

struct Comp;

struct Model {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void c8(int, int, Vec3*, Vec3*, Vec3*, Vec3*, int, int, f32);
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void c20(int, Comp*);
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void c28(int, Vec3*, f32);
};

struct Comp {
    char p0[0xc];
    Ctl2* ctl2;
    char p1[0x48];
    Anim* anim;
    char p2[8];
    Ctl* ctl;
    char p3[0x20];
    Model* model;
};

struct Owner {
    char pad[0xd8];
    Comp* comp;
};

struct Elem;

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

struct Elem {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
};

struct Self {
    char p0[0x60];
    Owner* owner;
    char p1[0x7fa4 - 0x64];
    s16 id1;
    s16 id2;
    List* cached;
    char p2[0x60];
    f32 x;
    f32 y;
};

extern "C" {
extern void* lbl_27_bss_F0;
extern char lbl_27_bss_3188[];
extern char lbl_27_data_27038[];
extern char __RTTI__11soEventUnit[];
extern const f32 lbl_27_rodata_7C08[];

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_4AB8(void*);
void fn_27_388930(void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

inline bool checkManageId(const Self* self, s32& id) {
    id = self->id1;
    return soEventSystem::getInstance()->getInstanceManager().isContain(id);
}

inline List* selectList(Self* self, s32& id) {
    soEventManager* mgr;
    List* cur;
    Unit* unit;
    int flag;

    if (self->id1 <= -1)
        return (List*)lbl_27_bss_3188;
    if (self->cached != 0)
        goto C;
    if (self->id1 <= -1 || !checkManageId(self, id)) {
        flag = 0;
        goto CHECK;
    }
    if (soEventSystem::getInstance()->getManager(self->id1)->getObserverCapacity(self->id2) == 0) {
        self->cached = 0;
        flag = 0;
        goto CHECK;
    }
    id = self->id2;
    mgr = soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->getObserverCapacity(id) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(mgr->getEventUnit(id), 0,
                                     lbl_27_data_27038, __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = unit->u7();
    }
    self->cached = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0)
        return (List*)lbl_27_bss_3188;

C:
    mgr = soEventSystem::getInstance()->getManager(self->id1);
    if (mgr->getObserverCapacity(self->id2) == 0) {
        self->cached = 0;
        return (List*)lbl_27_bss_3188;
    }
    return self->cached;
}

inline void removeEffect(Self* self) {
    Owner* o = self->owner;
    int id2 = o->comp->ctl->c4(0x1000004a);
    if (id2 != 0) {
        o->comp->model->c20(id2, o->comp);
        o->comp->ctl->c5(0, 0x1000004a);
    }
}

inline void calculateDelta(f32& dy, f32& dx, Self* self, const Vec3& pos, f32 targetY) {
    dy = targetY - self->y;
    dx = pos.x - self->x;
}

inline f32 updatePosition(Self* self, Vec3& out, f32 x, f32 y, f32 z) {
    out.x = x;
    out.y = y;
    out.z = z;
    self->x = x;
    self->y = y;
    return y;
}

extern "C" void fn_27_381120(Self* self) {
    s32 id;
    Owner* owner = self->owner;
    const f32* k = lbl_27_rodata_7C08;

    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (p != 0)
            p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        owner->comp->ctl->c11(0x10000042, 0);
        owner->comp->ctl->c11(0x10000045, 0);
        owner->comp->ctl->c11(0x10000046, 0);

        List* sel = selectList(self, id);
        for (int i = 0; i < sel->l4(); i++) {
            Elem** p2 = sel->l2(i);
            (*p2)->e9();
        }

        Owner* o = self->owner;
        id = o->comp->ctl->c4(0x1000004a);
        if (id != 0) {
            Vec3 a, b, c, d, np;
            const Vec3& pos = o->comp->ctl2->s4();
            f32 targetY = k[0] + pos.y;
            f32 deltaY, deltaX;
            calculateDelta(deltaY, deltaX, self, pos, targetY);
            Vec2f delta(deltaX, deltaY);
            const f32& dy = delta.m_y;
            const f32& dx = delta.m_x;

            if (dx * dx + dy * dy < k[6]) {
                removeEffect(self);
                f32 zero = k[3];
                a.x = zero; a.y = zero; a.z = zero;
                b.x = zero; b.y = zero; b.z = zero;
                c.x = zero; c.y = zero; c.z = zero;
                d.x = zero; d.y = zero; d.z = zero;
                o->comp->model->c8(0x01030039, 0x12e, &d, &c, &b, &a, 0, 0, k[1]);
                o->comp->anim->a7(1);
                fn_27_388930(self->p2, o);
            } else {
                f32 ny = updatePosition(self, np, self->x + k[7] * dx,
                                        self->y + k[7] * dy, pos.z);
                o->comp->model->c28(id, &np, ny);
            }
        }
    }
    fn_27_4AB8(self);
}
