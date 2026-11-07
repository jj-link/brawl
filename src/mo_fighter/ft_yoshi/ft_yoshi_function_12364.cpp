#include <so/so_module_accesser.h>
#include <ft/ft_common_data_accesser.h>

#pragma force_active on

struct Speed {
    union { float x; unsigned int xbits; };
    union { float y; unsigned int ybits; };
};

class KineticView {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual Speed getSumSpeed(short&);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int);
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(int);
    virtual void slot13(float, int);
};

class Class_82E0 {
public:
    virtual void fn_95_12CE8();
    virtual void fn_95_121EC();
    virtual void fn_95_12CC8();
    virtual void fn_95_12364();
    virtual void fn_95_F360();
    virtual void fn_95_F318();
    virtual void fn_95_127E0();
    virtual void fn_95_12C50();
    virtual void fn_95_F30C();
    virtual void fn_95_F304();
    virtual void fn_95_F300();
    virtual void fn_95_F2F8();
    virtual void fn_95_F35C();
    virtual void fn_95_F2F0();
};

extern "C" {
extern const float lbl_95_rodata_B8[];

void fn_95_FF04(void*);
void fn_95_100C4(void*);
void fn_95_10704(void*);
void fn_95_10374(void*);
float fn_95_A8B4(float);
int fn_95_FDD8(void*);
int fn_95_FE54(void*);

void fn_95_12364(void*, soModuleAccesser* self) {
    const float* const c = lbl_95_rodata_B8;
    const soModuleEnumeration* e = self->m_enumerationStart;
    Object_vptr_0* w = reinterpret_cast<Object_vptr_0*>(e->m_workManageModule);
    KineticView* k = reinterpret_cast<KineticView*>(e->m_kineticModule);
    soPostureModule* p = e->m_postureModule;
    soModelModule* m = e->m_modelModule;
    char* data = *(char**)((char*)g_ftCommonDataAccesser.getData((ftKind)4) + 0x7c);

    short flag = -1;
    Speed v;
    v = k->getSumSpeed(flag);
    float y = w->slot12(0x21000005);
    float x = w->slot12(0x21000004);

    fn_95_FF04(self);
    fn_95_100C4(self);
    float sum = y + c[1] * *(float*)(data + 0x58);
    w->slot13(sum, 0x21000005);
    fn_95_10704(self);

    float ax = fn_95_A8B4(x);
    float av = fn_95_A8B4(v.x);
    fn_95_A8B4(*(float*)(data + 0x9c));
    float limit = fn_95_A8B4(*(float*)(data + 0x9c));

    if (x > c[0]) {
        if (v.x <= c[0])
            ax *= c[3];
    } else {
        if (v.x >= c[0])
            ax *= c[3];
    }

    float t = c[3] * fn_95_A8B4(x);
    float magnitude = fn_95_A8B4(x);
    float denom = magnitude + t;
    float angle;

    if (x > c[0]) {
        float diff;
        if (v.x > c[0]) {
            float a = fn_95_A8B4(v.x);
            diff = fn_95_A8B4(x) - a;
        } else {
            float a = fn_95_A8B4(v.x);
            float b = fn_95_A8B4(x);
            diff = b + a;
        }
        angle = c[4] + c[2] * (diff / denom);
    } else {
        float diff;
        if (v.x < c[0]) {
            float a = fn_95_A8B4(v.x);
            diff = fn_95_A8B4(x) - a;
        } else {
            float a = fn_95_A8B4(v.x);
            float b = fn_95_A8B4(x);
            diff = b + a;
        }
        angle = c[5] + c[2] * (diff / denom);
    }

    while (angle < c[0])
        angle += c[6];
    while (angle > c[6])
        angle -= c[6];

    m->setNodeRotateY(3, c[7] * angle);
    float rotation = -*(float*)(data + 0x9c) + limit * (av / ax);
    m->setNodeRotateZ(2, c[7] * rotation);

    if (fn_95_FDD8(self) || fn_95_FE54(self)) {
        w->slot5(0x11a, 0x20000008);
    } else if ((x > c[0] && v.x < c[0]) || (x <= c[0] && v.x > c[0])) {
        ax = c[3] * fn_95_A8B4(x);
        if (fn_95_A8B4(v.x) > ax) {
            w->slot5(0x119, 0x20000008);
            fn_95_10374(self);
            float lr = w->slot12(0x21000008);
            w->slot4(0x20000003);
            if (c[0] != lr)
                p->setLr(lr);
            m->setNodeRotateY(3, c[0]);
            m->setNodeRotateZ(2, c[0]);
            fn_95_10704(self);
        }
    }
}
}
