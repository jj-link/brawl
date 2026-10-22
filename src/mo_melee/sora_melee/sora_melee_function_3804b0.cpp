#pragma force_active on

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int get(int id);
    virtual void set(int value, int id);
};

class Effect {
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
    virtual void remove(int handle, void* arg);
};

struct Modules {
    char pad0[0x64];
    Work* work;
    char pad1[0x20];
    Effect* effect;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Owner* owner;
};

extern "C" void fn_27_3804B0(Self* self) {
    Owner* owner = self->owner;
    int handle = owner->modules->work->get(0x1000004A);
    if (handle != 0) {
        Modules* modules = owner->modules;
        modules->effect->remove(handle, modules);
        owner->modules->work->set(0, 0x1000004A);
    }
}
