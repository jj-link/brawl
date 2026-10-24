#include <types.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float c, float b, float a) : x(a), y(b), z(c) {}
};

struct Vec4 { float x, y, z, w; };
struct Matrix { float m[3][4]; };
struct Entry { void* p; float x, y, z, w; };
struct List { Entry* items; unsigned int count; };

struct Obj {
    char pad[8];
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
    virtual Vec3 get(void*, const Vec3*, int, int);
    virtual void v40();
    virtual void v41();
    virtual void matrix(void*, Matrix*, int);
};

struct Link { char pad[4]; Obj* obj; };
struct Holder { char pad[0xd8]; Link* link; };
struct Mgr {
    char pad0[0x10];
    Holder* holder;
    char pad1[0xc];
    List* list;
};

typedef Vec3 (*Fn9C)(void*, void*, const Vec3*, int, int);
typedef void (*FnA8)(void*, void*, Matrix*, int);

extern "C" {
extern const float lbl_27_rodata_DC0[];
void* getManager__15gfCameraManagerFv(Mgr*);
void* getInstance__16CameraControllerFv();
void* fn_8009CD44(void*);
void fn_8003E6DC(const Matrix*, Vec3*);
float rsqrtf__Ff(float);
unsigned int fn_80019CE4(void*, Vec4*, float, float);
}

extern "C" int fn_27_B3398(Mgr* self, int mode) {
    const float* k = lbl_27_rodata_DC0;
    Entry* e;
    int off;
    unsigned int count;
    void* mgr;
    unsigned int i;
    List* list = self->list;

    if (!list) return 1;

    count = list->count;
    if (!mode) {
        mgr = getManager__15gfCameraManagerFv(self);
    } else {
        void* cam = getInstance__16CameraControllerFv();
        mgr = fn_8009CD44(cam);
    }

    float min;
    float eps;
    eps = k[1];
    i = 0;
    min = k[2];
    off = 0;

    for (; i < count; off += 0x14, i++) {
        e = (Entry*)((char*)self->list->items + off);
        Matrix mat;
        Vec4 p;
        Vec3 d;
        float vz = e->z;
        float vy = e->y;
        float vx = e->x;
        Vec3 pos = self->holder->link->obj->get(
            e->p, &Vec3(vz, vy, vx), 0, 0);
        float radius = e->w;
        self->holder->link->obj->matrix(e->p, &mat, 0);
        fn_8003E6DC(&mat, &d);

        float len2 = d.z * d.z + (d.x * d.x + d.y * d.y);
        float len;
        if ((float)__fabs(len2) <= eps) len = k[0];
        else len = len2 * rsqrtf__Ff(len2);

        radius *= len;
        if (radius < min) radius = min;

        float z = pos.z;
        float y = pos.y;
        float x = pos.x;
        p.y = y;
        p.x = x;
        p.z = z;
        p.w = radius;

        if (fn_80019CE4(mgr, &p, z, y) == 1U) return 1;
    }

    return 0;
}
