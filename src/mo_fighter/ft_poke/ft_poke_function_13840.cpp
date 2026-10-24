#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void fn_116_10A30(Vec3f* dst, const Vec3f* src);
extern float lbl_116_rodata_38;

class PostureIface {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual Vec3f getPos();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual Vec3f getRot(int);
    virtual void v44(); virtual void v48(); virtual void v4C();
    virtual float getY();
    virtual void v54(); virtual void v58(); virtual void v5C();
    virtual float getScale();
};

struct ModelBase {
    int a;
    int b;
};

class ModelIface : public ModelBase {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void setSRT(int, Vec3f*, Vec3f*, Vec3f*);
    virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74(); virtual void v78();
    virtual void setNodeRotate(int, Vec3f*);
};

class WorkIface {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34();
    virtual float getFloat(int);
};

struct Modules {
    char pad0[4];
    ModelIface* model;
    char pad8[4];
    PostureIface* posture;
    char pad10[0x54];
    WorkIface* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;

    PostureIface* getPostureModule() {
        return modules->posture;
    }
};

struct Obj {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" void fn_116_13840(Obj* obj) {
    float s = obj->accesser->getPostureModule()->getScale();
    Vec3f scale;
    scale.m_z = s;
    scale.m_y = s;
    scale.m_x = s;
    Vec3f rot;
    Vec3f v;
    Vec3f pos;
    Vec3f p = obj->accesser->getPostureModule()->getPos();
    fn_116_10A30(&pos, &p);
    Vec3f r = obj->accesser->getPostureModule()->getRot(0);
    fn_116_10A30(&rot, &r);
    rot.m_y += obj->accesser->getPostureModule()->getY();
    obj->accesser->modules->model->setSRT(0, &scale, &rot, &pos);
    v.m_x = obj->accesser->modules->work->getFloat(0x11000001);
    v.m_y = lbl_116_rodata_38;
    v.m_z = lbl_116_rodata_38;
    obj->accesser->modules->model->setNodeRotate(1, &v);
}
