#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct ObjKinetic {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void* get(int);
};
struct ObjEnergy {
    virtual void v0(); virtual void v1();
    virtual u64 getValue();
    char pad[4]; float f8; float fC;
};
struct ObjWork {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual float getFloat(unsigned int);
    virtual void setFloat(unsigned int, float);
};
struct ObjPosture {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual float getLr();
};
struct Vec3 { Vec3() {} float x,y,z; };
struct Pad8 { char pad[8]; };
struct ObjMotion : Pad8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual Vec3 getVector(int);
    virtual void v26(); virtual void v27(); virtual void v28();
    virtual void setVector(int, Vec3*);
};

struct Modules {
    char pad0[4]; ObjMotion* model; char pad8[4]; ObjPosture* posture;
    char pad10[0x54]; ObjWork* work; char pad68[0x14]; ObjKinetic* kinetic;
};
struct Self { char pad[8]; void* castSource; char pad2[0xcc]; Modules* modules; };
struct Casted { char pad[0x34]; struct Sub34* p34; };
struct Sub34 { char pad[8]; float f8; };
union Pair { u64 bits; float f[2]; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
float rsqrtf__Ff(float);
u32 fn_27_399C84(void*);
extern char lbl_27_data_9AB98[], lbl_27_data_248[], lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern float lbl_27_rodata_7DC8[];
void fn_27_39A1D8(void*, Self* self) {
    const float* c = lbl_27_rodata_7DC8;
    void* casted = __dynamic_cast(self->castSource, 0x3c, lbl_27_data_9AB98, lbl_27_data_248, 1);
    ObjEnergy* energy = (ObjEnergy*)__dynamic_cast(
        self->modules->kinetic->get(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
    Pair b; Pair a;
    a.bits = energy->getValue(); b = a;
    float limit = self->modules->work->getFloat(0x21000000);
    self->modules->posture->getLr();
    float sq = b.f[0] * b.f[0] + b.f[1] * b.f[1];
    float length; float amount;
    if ((float)(double)nw4r::math::FAbs(sq) <= c[1]) length = c[0];
    else length = sq * rsqrtf__Ff(sq);
    if (length > limit) {
        b.f[0] = b.f[0] * (length - limit) / length;
        b.f[1] = b.f[1] * (length - limit) / length;
    } else { b.f[0] = c[0]; }
    energy->f8 = b.f[0]; energy->fC = b.f[1];
    Vec3 vec = self->modules->model->getVector(1);
    limit = self->modules->work->getFloat(0x21000002);
    float other = ((Casted*)fn_27_399C84(casted))->p34->f8;
    float angle = limit + other;
    if (angle > c[2]) angle -= c[2];
    vec.x = angle;
    self->modules->model->setVector(1, &vec);
    self->modules->work->setFloat(0x21000002, angle);
}
}