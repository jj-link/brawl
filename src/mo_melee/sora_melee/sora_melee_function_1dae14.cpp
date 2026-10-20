#pragma force_active on
extern "C" const float lbl_27_rodata_2754;

struct Vec3 {
    float x, y, z;

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Module {
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
    virtual void set(const Vec3*, const unsigned short*);
};

struct Modules {
    char pad[0x7c];
    Module* module;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Owner* owner;
    char pad2[0x38];
    float x;
    float y;
};

extern "C" int fn_27_1DAE14(Object* self) {
    Vec3 v(self->x, self->y, lbl_27_rodata_2754);
    unsigned short flag = 1;
    self->owner->modules->module->set(&v, &flag);
    return 0;
}
