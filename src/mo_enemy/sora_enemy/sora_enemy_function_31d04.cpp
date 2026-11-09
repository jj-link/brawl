#include <types.h>

#pragma force_active on

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

struct SoraModelBase {
    int a;
    int b;
};

class SoraModel : public SoraModelBase {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void setSRT(int, Vec3f*, Vec3f*, Vec3f*);
};

class SoraPosture {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual Vec3f getPos();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual Vec3f getRot(int);
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual f32 getScale();
};

struct SoraModules {
    char pad0[4];
    SoraModel* model;
    char pad8[4];
    SoraPosture* posture;
};

struct SoraObj {
    char pad[0xD8];
    SoraModules* modules;
};

struct SoraOwner {
    char pad[0x6C];
    SoraObj* obj;
    char mid[0x21B5 - 0x70];
    unsigned char flag;
};

extern "C" void fn_27_492C(void* object);
extern "C" void fn_41_534C(Vec3f* dst, const Vec3f* src);

extern "C" void fn_41_31D04(void* arg0) {
    SoraOwner* owner = reinterpret_cast<SoraOwner*>(arg0);
    if (owner->flag != 0) {
        fn_27_492C(reinterpret_cast<u8*>(owner) + 0xC);
        return;
    }
    SoraObj* obj = owner->obj;
    f32 s = obj->modules->posture->getScale();
    Vec3f scale;
    scale.z = s;
    scale.y = s;
    scale.x = s;
    Vec3f rot;
    Vec3f pos;
    fn_41_534C(&pos, &obj->modules->posture->getPos());
    fn_41_534C(&rot, &obj->modules->posture->getRot(0));
    obj->modules->model->setSRT(0, &scale, &rot, &pos);
}
