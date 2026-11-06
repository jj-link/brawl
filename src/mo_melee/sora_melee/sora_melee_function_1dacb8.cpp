#pragma force_active on
extern const float lbl_27_rodata_2758;

struct Vec {
    float x, y, z;
};

struct ID {
    short value;
    short pad;
};

struct Object_vptr_0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17(Vec*, ID*, float);
    virtual void slot18(Vec*, ID*);
};

struct Class_90D8_base {
    char pad[0x8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual float fn_27_7B0B0(void*);
    virtual void fn_27_7ABD8();
    virtual float fn_27_7ABCC(void*);
};

struct Modules {
    char pad[0x64];
    Object_vptr_0* objC;
    char pad2[0x14];
    Object_vptr_0* objB;
    char pad3[0x3C];
    Class_90D8* objA;
};

struct Actor {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Actor* actor;
};

extern "C" int fn_27_1DACB8(Self* self) {
    float f = -self->actor->modules->objA->fn_27_7ABCC(self->actor);
    Vec v = {f, lbl_27_rodata_2758, lbl_27_rodata_2758};
    ID s1;
    s1.value = 1;
    self->actor->modules->objB->slot17(&v, &s1, f);
    ID s2;
    s2.value = 1;
    self->actor->modules->objB->slot18(&v, &s2);
    Modules* mod = self->actor->modules;
    Object_vptr_0* c = mod->objC;
    float g = mod->objA->fn_27_7B0B0(mod);
    float h = (float)c->slot4(0x10000003);
    int n = (int)(h * g);
    self->actor->modules->objC->slot5(n, 0x10000004);
    return 0;
}
