#pragma force_active on
struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(int);
    virtual void setFloat(float, int);
};

struct Posture {
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
    virtual Vec3 getPos(int);
    virtual void setPos(const Vec3&, int);
};

struct Modules {
    char p[0xc];
    Posture* posture;
    char q[0x54];
    Work* work;
    char r[0x14];
    Kinetic* kinetic;
};

struct Access {
    char p[8];
    void* object;
    char q[0xcc];
    Modules* modules;
};

extern "C" {
extern const char lbl_93_data_7B28[];
extern const char lbl_93_data_3BF8[];
extern const char lbl_93_data_8DD0[];
extern const char lbl_93_data_30FC[];
extern const float lbl_93_rodata_A0;
extern const float lbl_93_rodata_A4;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2* fn_93_DAEC(Vec2*, const Vec2*);

void fn_93_14C1C(void*, Access* a) {
    char* obj = static_cast<char*>(__dynamic_cast(
        a->object, 0x3c, lbl_93_data_7B28, lbl_93_data_3BF8, 1));
    char* params = *reinterpret_cast<char**>(obj + 0x20e4);

    Kinetic* k = a->modules->kinetic;
    char* energy = static_cast<char*>(__dynamic_cast(
        k->getEnergy(0), 0, lbl_93_data_8DD0, lbl_93_data_30FC, 1));

    Vec2 zero;
    zero.x = lbl_93_rodata_A0;
    zero.y = lbl_93_rodata_A0;
    fn_93_DAEC(reinterpret_cast<Vec2*>(energy + 0x10), &zero);

    Work* w = a->modules->work;
    float f = w->getFloat(0x11000001);
    if (f <= lbl_93_rodata_A0)
        f += lbl_93_rodata_A4;
    else
        f -= lbl_93_rodata_A4;

    w = a->modules->work;
    w->setFloat(f, 0x11000001);

    w = a->modules->work;
    w->setInt(*reinterpret_cast<int*>(params + 0x34), 0x20000000);

    Vec3 pos = a->modules->posture->getPos(1);
    pos.y = *reinterpret_cast<float*>(params + 0x18);
    a->modules->posture->setPos(pos, 1);
}
}
