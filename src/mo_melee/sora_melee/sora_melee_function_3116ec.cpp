#include <types.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" char lbl_27_data_2E430[], lbl_27_data_CDF8[];
extern "C" const float lbl_27_rodata_7490[];

struct MyVec {
    float x, y, z;
};

struct Rect {
    Rect(float a_, float b_, float c_, float d_) { a = a_; b = b_; c = c_; d = d_; }
    float a, b, c, d;
};

struct Info {
    float a;
    float b;
    float c;
    float d;
    float e;
};

class Status {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int status();
};

struct OwnerBase {
    char pad[0x3c];
};

class Owner : public OwnerBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual int kind();
};

class Posture {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual float lr();
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void set(float val, int id);
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* get(int);
};

class Camera {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Info* get(int);
    virtual void v16();
    virtual void setVec(MyVec* v, int id);
    virtual void setRect(Rect* r, int id);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void setScale(float val, int id);
};

struct Modules {
    char p0[0xc];
    Posture* posture;
    char p10[0x50];
    Camera* camera;
    Work* work;
    char p68[8];
    Status* status;
    char p74[8];
    Kinetic* kinetic;
};

struct Object {
    char p0[8];
    Owner* owner;
    char pC[0xcc];
    Modules* modules;
};

struct Energy {
    char p0[5];
    unsigned char flags;
    char p6[6];
    float x, y;
    char p14[4];
    float z;
};

inline int adjustStatus(Object* obj, int var) {
    if (var <= 0x116)
        return var;
    switch (obj->owner->kind()) {
    case 6:
        return var;
    case 0x13:
        return var + 3;
    case 0x2c:
        return var;
    default:
        return var;
    }
}

extern "C" void fn_27_3116EC(void*, Object* obj) {
    const float* c = lbl_27_rodata_7490;
    int status = adjustStatus(obj, obj->modules->status->status());

    if (status == 0x11d) {
        float value = c[0];
        switch (obj->owner->kind()) {
        case 6:
            value = soValueAccesser::getConstantFloat(
                (soModuleAccesser*)obj, 0xfbc, 0);
            break;
        case 19:
            value = soValueAccesser::getConstantFloat(
                (soModuleAccesser*)obj, 0xfba, 0);
            break;
        case 44:
            value = soValueAccesser::getConstantFloat(
                (soModuleAccesser*)obj, 0xfbc, 0);
            break;
        }

        Energy* e = (Energy*)__dynamic_cast(
            obj->modules->kinetic->get(1), 0,
            lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        e->x = value;
        e->y = c[0];
        e->z = c[0];
        e->flags |= 0x80;
    } else if (status == 0x11e) {
        Work* w = obj->modules->work;
        w->set(c[1] * obj->modules->posture->lr(), 0x11000012);
    }

    Info* p = obj->modules->camera->get(0);
    Rect r(c[5] - p->c, c[4] - p->b, c[3] - p->d, c[2] - p->e);
    obj->modules->camera->setRect(&r, 0);

    float vy = c[1] - p->a;
    MyVec v;
    v.x = c[0];
    v.y = vy;
    v.z = c[0];
    obj->modules->camera->setVec(&v, 0);
    obj->modules->camera->setScale(c[6], 0);
}
