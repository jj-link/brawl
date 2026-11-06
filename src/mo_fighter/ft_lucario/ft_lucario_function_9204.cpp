#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

class StatusObj {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44();
    virtual int getStatus();
};

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
    virtual float getRotYLr();
    virtual void v54(); virtual void v58(); virtual void v5C();
    virtual float getScale();
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
    char padC[0x60];
    StatusObj* status;
};

struct Obj {
    char pad[0xD8];
    Modules* modules;
};

struct Owner {
    char pad[0x60];
    Obj* obj;
};

extern "C" void fn_118_FCD0(Obj* arg0);
extern "C" void fn_118_1135C(Obj* arg0);
extern "C" void fn_118_933C(Vec3* dst, const Vec3* src);

inline void copyVec(Vec3* dst, const Vec3& src) { fn_118_933C(dst, &src); }

extern "C" void fn_118_9204(Owner* arg0) {
    Obj* obj = arg0->obj;
    switch (obj->modules->status->getStatus()) {
    case 0x11B:
        fn_118_FCD0(obj);
        break;
    case 0x122:
    case 0x123:
    case 0x124:
        fn_118_1135C(obj);
        break;
    }
    float s = obj->modules->posture->getScale();
    Vec3 scale;
    scale.z = s;
    scale.y = s;
    scale.x = s;
    Vec3 rot;
    Vec3 pos;
    copyVec(&pos, obj->modules->posture->getPos());
    copyVec(&rot, obj->modules->posture->getRot(0));
    rot.y += obj->modules->posture->getRotYLr();
    obj->modules->model->setSRT(0, &scale, &rot, &pos);
}
