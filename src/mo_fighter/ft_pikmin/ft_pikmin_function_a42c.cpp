#include <types.h>
#include <mt/mt_vector.h>
#include <cm/cm_camera_controller.h>
#include <so/so_external_value_accesser.h>

#pragma force_active on

#define V1(n) virtual void v##n();
#define V4(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3)
#define V16(n) V4(n##0) V4(n##1) V4(n##2) V4(n##3)

struct TargetBase { char pad[0x3c]; };
struct Target : TargetBase {
    V16(a) V16(b) V16(c) V16(d) V16(e) V16(f)
    V4(g0) V4(g1) V4(g2) V1(g3)
    virtual void action(int);
};
struct TargetList {
    V1(0) V1(1)
    virtual Target** get(int);
    virtual int size();
};
struct Posture {
    V4(a) V4(b) V1(c)
    virtual float lr();
};
struct Item {
    V4(a) V4(b)
    virtual int value();
};
struct Link {
    V4(a)
    virtual int check(int, int);
};
struct Article {
    V1(a) V1(b) V1(c)
    virtual Item* get(int, bool, bool);
    V4(d) V4(e) V1(f)
    virtual void set(Item*);
    V1(g) V1(h)
    virtual void enable(int, int);
};
struct Effect {
    V4(a) V1(b) V1(c) V1(d)
    virtual void create(int, Vec3f*, Vec3f*, float, int);
    V4(e0) V4(e1) V4(e2) V1(f0) V1(f1) V1(f2)
    virtual void remove(int, bool, bool);
    V16(g) V4(h) V1(i) V1(j) V1(k)
    virtual void mode(int);
};
struct Ground {
    V4(a) V4(b) V1(c) V1(d)
    virtual void set(int, Vec3f*, Vec3f*);
    virtual void enable(int);
    V1(e)
    virtual void other(int, int);
};
struct GlobalBase { char pad[0x3c]; };
struct Global : GlobalBase {
    V16(a) V16(b) V16(c) V4(d0) V4(d1) V4(d2)
    virtual void update(Vec3f*, int);
};
struct Modules {
    char pad0[0xc]; Posture* posture;
    char pad10[0x44]; Link* link;
    char pad58[8]; Ground* ground;
    char pad64[0x20]; Article* article; Effect* effect;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Fighter { char pad[0x60]; Accesser* accesser; char pad2[0x1fca4]; char manager[0x184]; char other[1]; };
#define MGR(self) ((void*)&(self)->manager)
#define MGR2(self) ((void*)&(self)->other)

extern "C" {
extern float lbl_113_rodata_C;
extern float lbl_113_rodata_4;
extern Global* lbl_27_bss_5668;
void fn_27_13138C(Fighter*, int, int, void*, void*);
void fn_113_243DC(void*, int);
int fn_113_243CC(void*);
TargetList* fn_113_24550(void*);
void fn_113_24D34(void*, Target*, float);
void fn_113_2435C(void*);
Target* fn_113_244FC(void*);
void fn_113_24558(void*, void*);
void fn_113_255CC(void*, int, int, int);
void fn_113_BB50(Fighter*);
void fn_113_B91C(Fighter*, int);
int fn_113_10E18(int);
void fn_113_1094C(void*);
Vec3f* fn_113_A1D0(Vec3f*, float, float, float);
}

static inline void setGround(Fighter* self, Vec3f a2, Vec3f a1, Vec3f a0) {
    self->accesser->modules->ground->set(0, &a2, &a1);
}
static inline void doStart(Fighter* self) {
        fn_113_243DC(MGR(self), 2);
        if (fn_113_243CC(MGR(self)) > 0) {
            TargetList* list = fn_113_24550(MGR(self));
            (*list->get(0))->action(0x12);
            Posture* p = self->accesser->modules->posture;
            Target** t = list->get(0);
            float f = p->lr();
            fn_113_24D34(MGR(self), *t, f);
            if (list->size() > 1) {
                (*list->get(1))->action(0x12);
                Posture* p = self->accesser->modules->posture;
                Target** t = list->get(1);
                float f = -p->lr();
                fn_113_24D34(MGR(self), *t, f);
            }
        }
}

extern "C" void fn_113_A42C(Fighter* self, int status, int previous, void* arg3, void* arg4) {
    fn_27_13138C(self, status, previous, arg3, arg4);
    switch (status) {
    case 0x2d:
        doStart(self);
        break;
    case 0xbd:
        fn_113_2435C(MGR(self));
        break;
    case 0x3a:
        if (fn_113_243CC(MGR(self)) > 0)
            fn_113_244FC(MGR(self))->action(0x25);
        break;
    case 0x116: {
        self->accesser->modules->article->enable(1, 0);
        Item* item = self->accesser->modules->article->get(1, 0, 0);
        Link* link = self->accesser->modules->link;
        if (!link->check(6, item->value()))
            return;
        self->accesser->modules->article->set(item);
        ((u8*)CameraController::getInstance())[0x44] |= 1;
        break;
    }
    case 0x118: {
        self->accesser->modules->effect->mode(0);
        Effect* effect = self->accesser->modules->effect;
        Vec3f t3, t2, t1;
        effect->create(0xf70001,
            fn_113_A1D0(&t2, lbl_113_rodata_C, lbl_113_rodata_C, lbl_113_rodata_C),
            fn_113_A1D0(&t1, lbl_113_rodata_C, lbl_113_rodata_C, lbl_113_rodata_C),
            lbl_113_rodata_4, 0);
        self->accesser->modules->effect->mode(1);
        Global* g = lbl_27_bss_5668;
        if (!g) return;
        fn_113_A1D0(&t3, lbl_113_rodata_C, lbl_113_rodata_C, lbl_113_rodata_C);
        g->update(&t3, 2);
        self->accesser->modules->ground->enable(1);
        setGround(self, t3, t3, t3);
        self->accesser->modules->ground->other(0, -1);
        break;
    }
    case 0x80: {
        TargetList* list = fn_113_24550(MGR(self));
        if (list->size() > 0) {
            for (int i = 0; i < list->size(); i++)
                (*list->get(i))->action(0x2f);
            fn_113_255CC(MGR(self), 1, -1, 0);
        }
        break;
    }
    case 0x7a:
        fn_113_BB50(self);
        break;
    default: break;
    }

    switch (previous) {
    case 0x2d:
    case 0x2e: {
        if (status == 0x2e) return;
        if (status == 0x2f) return;
        if (fn_113_243CC(MGR(self)) <= 0) return;
        TargetList* list = fn_113_24550(MGR(self));
        for (int i = 0; i < list->size(); i++)
            (*list->get(i))->action(0xa);
        fn_113_24558(MGR(self), MGR2(self));
        return;
    }
    case 0x39:
    case 0x3a:
        if (fn_113_243CC(MGR(self)) <= 0) return;
        if (status == 0x3b) {
            fn_113_24558(MGR(self), MGR2(self));
            return;
        }
        if (status == 0x3c) return;
        if (status == 0x3a) return;
        if (status == 0x39) return;
        if (soExternalValueAccesser::getStatusKind((StageObject*)fn_113_244FC(MGR(self))) != 0x24)
            fn_113_244FC(MGR(self))->action(0xa);
        fn_113_24558(MGR(self), MGR2(self));
        return;
    case 0x3c:
        fn_113_24558(MGR(self), MGR2(self));
        return;
    case 0x80: {
        if (status == 0x81) {
            TargetList* list = fn_113_24550(MGR(self));
            for (int i = 0; i < list->size(); i++) {
                Target* obj = *list->get(i);
                int kind = soExternalValueAccesser::getStatusKind((StageObject*)obj);
                if ((unsigned int)(kind - 0x2e) <= 1) obj->action(0x30);
            }
        } else if (fn_113_10E18(status) == 0) {
            fn_113_B91C(self, 8);
        }
        fn_113_1094C(arg4);
        return;
    }
    case 0x76: case 0x77: case 0x78: case 0x95:
        if (fn_113_10E18(status) == 0) fn_113_B91C(self, 0);
        return;
    case 0x75:
        if (status != 0x76 && status != 0x77 && status != 0x78 && status != 0x79)
            if (fn_113_10E18(status) == 0) fn_113_B91C(self, 8);
        if (status == 0xe) fn_113_BB50(self);
        return;
    case 0x79:
        if (fn_113_10E18(status) == 0) fn_113_B91C(self, 8);
        return;
    case 0x94:
        if (status != 0x95 && fn_113_10E18(status) == 0) fn_113_B91C(self, 8);
        return;
    case 0xc0: case 0xc2:
        if (fn_113_10E18(status) == 0) fn_113_B91C(self, 8);
        return;
    case 0x82:
        if (fn_113_10E18(status) == 0) fn_113_B91C(self, 8);
        return;
    case 0x81:
        if (status != 0x82 && fn_113_10E18(status) == 0) fn_113_B91C(self, 8);
        return;
    case 0x116: case 0x117:
        if (status >= 0x119 || status < 0x117)
            ((signed char*)CameraController::getInstance())[0x44] &= ~1;
        return;
    case 0x118:
        self->accesser->modules->effect->remove(0xf70001, 1, 1);
        ((signed char*)CameraController::getInstance())[0x44] &= ~1;
        return;
    default: return;
    }
}
