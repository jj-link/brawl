#pragma force_active on
#include <math.h>
#include <mt/mt_vector.h>

extern "C" const float lbl_27_rodata_8080[];

typedef Vec2f Vec2;

typedef Vec3f Vec3;

struct Rotation : Vec3 {
    Rotation(const float* d, float value, float angle) {
        m_x = d[1];
        m_y = (d[2] == value) ? d[9] : d[10];
        m_z = angle;
    }
};

struct P14 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct Modules;

struct P64 {
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
    virtual int v17(unsigned int, Modules*);
    virtual void v18();
    virtual void v19(unsigned int, Modules*);
};

struct P70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(unsigned int, void*);
};

struct P0C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9();
};

struct P10Base {
    char pad[8];
};

struct P10 : P10Base {
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual Vec2 v57(unsigned int, int);
};

struct P88 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int, const void*, const Vec3*, int, int, float);
};

struct Modules {
    char pad0[0x0c];
    P0C* p0c;
    P10* p10;
    P14* p14;
    char pad1[0x4c];
    P64* p64;
    char pad2[0x08];
    P70* p70;
    char pad3[0x14];
    P88* p88;
};

struct Obj08Base {
    char pad[0x3c];
};

struct Obj08 : Obj08Base {
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
    virtual int v40();
};

struct Object {
    char pad0[8];
    Obj08* obj08;
    char pad1[0xcc];
    Modules* modules;
};

inline Vec3 getpos(Object* obj, P88*& p88) {
    p88 = obj->modules->p88;
    return obj->modules->p0c->v4();
}

extern "C" double atan2(double, double);

extern "C" void fn_27_3C4730(void*, Object* obj) {
    const float* d = lbl_27_rodata_8080;

    if (obj->modules->p14->v3() != 0)
        return;

    if (obj->modules->p64->v17(0x22000016, obj->modules) == 0)
        return;

    if (obj->obj08->v40() == 5)
        obj->modules->p70->v3(0x187, obj);
    else
        obj->modules->p70->v3(0x119, obj);

    obj->modules->p64->v19(0x22000016, obj->modules);

    Vec2 v;
    Vec2::copy(v, obj->modules->p10->v57(8, 0));
    float y = v.m_y;
    float angle = (float)atan2(-v.m_x, y);

    float value = obj->modules->p0c->v9();
    P88* p88;
    p88->v6(10, &getpos(obj, p88), &Rotation(d, value, angle), 0, -1, d[2]);
}
