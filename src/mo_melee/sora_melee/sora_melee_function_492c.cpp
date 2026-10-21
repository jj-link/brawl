#pragma force_active on

struct Vec {
    float x, y, z;
};

struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec rotation();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual Vec position(int);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual float height();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual float scale();
};

struct Pad {
    int a, b;
};

struct Model : Pad {
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
    virtual void transform(int, Vec*, Vec*, Vec*);
};

struct Modules {
    char pad[4];
    Model* model;
    char pad8[4];
    Module* module;
};

struct Actor {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Actor* actor;
};

extern "C" void fn_27_492C(Object* object) {
    Actor* actor = object->actor;
    Vec scale;
    scale.x = scale.y = scale.z = actor->modules->module->scale();
    Vec position;
    Vec rotation;
    rotation = actor->modules->module->rotation();
    position = actor->modules->module->position(0);
    position.y += actor->modules->module->height();
    actor->modules->model->transform(0, &scale, &position, &rotation);
}
