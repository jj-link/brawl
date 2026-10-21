#pragma force_active on
typedef unsigned int u32;

class Check {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int f5();
};

class Sub {
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
    virtual float get(u32 id);
    virtual void set(u32 id, float v);
};

struct Modules {
    char pad[0x14];
    Check* check;
    char pad2[0x4C];
    Sub* sub;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_193378(void* obj, float f);

extern "C" void fn_27_180A7C(void* a, Object* self) {
    float f31 = self->modules->sub->get(0x21000004);
    if (self->modules->check->f5() == 2) {
        f31 += self->modules->sub->get(0x21000005);
        self->modules->sub->set(0x21000004, f31);
    }
    fn_27_193378(self, f31);
}
