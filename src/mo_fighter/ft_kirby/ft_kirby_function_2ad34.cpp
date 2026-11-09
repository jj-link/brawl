#include <types.h>
#pragma force_active on

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" void fn_96_14960(Vec3* dst, const Vec3* src);

class PostureObj {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14();
    virtual Vec3 getPos();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28();
    virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C();
    virtual Vec3 getRot(int);
    virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual f32 getScale();
};

struct ModelBase { int a; int b; };

class ModelObj : public ModelBase {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void setSRT(int, Vec3*, Vec3*, Vec3*);
};

struct Modules {
    char pad0[4];
    ModelObj* model;
    char pad8[4];
    PostureObj* posture;
};

struct Obj {
    char pad[0xD8];
    Modules* modules;
};

struct Owner {
    char pad[0x60];
    Obj* obj;
};

inline void copyVec(Vec3* dst, const Vec3& src) { fn_96_14960(dst, &src); }

extern "C" {
void fn_96_2AD34(Owner* arg0) {
    Obj* obj = arg0->obj;
    f32 s = obj->modules->posture->getScale();
    Vec3 scale;
    scale.z = s;
    scale.y = s;
    scale.x = s;
    Vec3 rot;
    Vec3 pos;
    copyVec(&pos, obj->modules->posture->getPos());
    copyVec(&rot, obj->modules->posture->getRot(0));
    rot.x = 0.0f;
    rot.y = 0.0f;
    rot.z = 0.0f;
    obj->modules->model->setSRT(0, &scale, &rot, &pos);
}
}
