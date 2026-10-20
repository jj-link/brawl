#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void fn_114_1C104(struct Obj* obj);
extern "C" void fn_114_1C204(Vec3f* dest, const Vec3f* src);

class PostureLike {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14();
    virtual Vec3f getPos();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28();
    virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C();
    virtual Vec3f getRot(int);
    virtual void v44(); virtual void v48(); virtual void v4C();
    virtual float getY();
    virtual void v54(); virtual void v58(); virtual void v5C();
    virtual float getScale();
};

struct ModelBase { int a; int b; };
class ModelLike : public ModelBase {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void setSRT(int, Vec3f*, Vec3f*, Vec3f*);
};

struct Modules {
    char pad0[4];
    ModelLike* model;
    char pad8[4];
    PostureLike* posture;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
    PostureLike* getPostureModule() { return modules->posture; }
    ModelLike* getModelModule() { return modules->model; }
};

struct Obj {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" void fn_114_1C104(Obj* obj) {
    float s = obj->accesser->getPostureModule()->getScale();
    Vec3f scale;
    scale.m_z = s;
    scale.m_y = s;
    scale.m_x = s;
    Vec3f rot;
    Vec3f pos;
    Vec3f p = obj->accesser->getPostureModule()->getPos();
    fn_114_1C204(&pos, &p);
    Vec3f r = obj->accesser->getPostureModule()->getRot(0);
    fn_114_1C204(&rot, &r);
    rot.m_y += obj->accesser->getPostureModule()->getY();
    obj->accesser->getModelModule()->setSRT(0, &scale, &rot, &pos);
}
