#pragma force_active on

extern const float lbl_93_rodata_60[];

struct WorkModule {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned long);
};

struct PostureLike {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual float v09();
};

struct Modules {
    char pad00[0xC];
    PostureLike* obj;
    char pad10[0x54];
    WorkModule* work;
};

struct Fighter {
    char pad00[0xD8];
    Modules* modules;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_93_10BA0(Fighter* fighter, Vec3* a, Vec3* b) {
    const float* constants = lbl_93_rodata_60;
    WorkModule* work = fighter->modules->work;
    float f31 = work->getFloat(0x11000013);
    float f1 = work->getFloat(0x11000014);
    a->x = constants[1];
    a->y = f1;
    a->z = f31;
    b->x = constants[1];
    b->y = constants[1];
    b->z = constants[1];
    if (fighter->modules->obj->v09() < constants[1]) {
        b->y = constants[4];
    } else {
        b->y = constants[5];
    }
}
