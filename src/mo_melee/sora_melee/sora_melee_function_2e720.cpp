#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Resource {
    void* unknown;
    void* data;
};

struct Provider {
    virtual void unused();
    virtual Resource* get();
};

struct Receiver {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void set(const Vec3&);
};

struct Module {
    char padding[0xC];
    Receiver* receiver;
};

struct Modules {
    char padding[0xD8];
    Module* module;
};

struct ObjectBase {
    char padding[8];
};

struct Object : ObjectBase {
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
    virtual Vec3 getPosition(int);

    char padC[0x28 - 0xC];
    Provider* provider;
    char pad2C[0x54 - 0x2C];
    Modules* modules;
};

extern "C" void fn_80134CA0(void*);

extern "C" void fn_27_2E720(Object* self) {
    fn_80134CA0(self->provider->get()->data);
    const Vec3& position = self->getPosition(0);
    self->modules->module->receiver->set(position);
}
