#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Actor;

struct Posture {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec3f s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual Vec3f s14(int);
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual float s22(Actor*);
};

struct Pad8 {
    s32 a;
    s32 b;
};

struct Model : Pad8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
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
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24(int, Vec3f*);
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29(int, Vec3f*);
    virtual void m30();
    virtual void m31(int, Vec3f*);
};

struct Modules {
    char pad0[4];
    Model* model;
    char pad8[4];
    Posture* posture;
};

struct Actor {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Actor* actor;
};

extern "C" void fn_27_3B0760(Object* obj) {
    Vec3f scale;
    scale.m_z = scale.m_y = scale.m_x = obj->actor->modules->posture->s22(obj->actor);
    Vec3f rot = obj->actor->modules->posture->s4();
    Vec3f p20 = obj->actor->modules->posture->s14(1);
    Vec3f p14 = obj->actor->modules->posture->s14(0);
    Vec3f p8 = obj->actor->modules->posture->s14(2);
    obj->actor->modules->model->m29(2, &p14);
    obj->actor->modules->model->m29(1, &p20);
    obj->actor->modules->model->m29(0, &p8);
    obj->actor->modules->model->m24(0, &scale);
    obj->actor->modules->model->m31(0, &rot);
}
