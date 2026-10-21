#pragma force_active on

struct Params {
    unsigned char pad0[0x0c];
    float x;
    float y;
    unsigned char pad14[0x31];
    unsigned char unused : 6;
    unsigned char flag : 1;
    unsigned char last : 1;
};

struct GetterBase {
    unsigned char pad[8];
};

struct Getter : GetterBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual Params* get();
};

struct Work {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual float get(unsigned long);
};

struct Modules {
    unsigned char pad0[0x38];
    Getter* getter;
    unsigned char pad3c[0x28];
    Work* work;
};

struct Accesser {
    unsigned char pad[0xd8];
    Modules* modules;
};

struct Object {
    unsigned char pad[0x178];
    unsigned char flag;
};

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

extern "C" const float lbl_27_rodata_1FC0;
extern "C" void fn_27_89D08(int, Accesser*, int, Vec2*, Vec3*);

extern "C" void fn_27_162ED4(void*, Object* self, void*, Accesser* accesser) {
    Getter* getter = accesser->modules->getter;
    Params* params = getter->get();

    Work* work = accesser->modules->work;
    float y = params->y + work->get(0x11000010);

    work = accesser->modules->work;
    float x = params->x + work->get(0x1100000f);

    Vec3 rotation;
    Vec2 speed = {x, y};
    rotation.x = lbl_27_rodata_1FC0;
    rotation.y = lbl_27_rodata_1FC0;
    rotation.z = lbl_27_rodata_1FC0;

    fn_27_89D08(4, accesser, 1, &speed, &rotation);

    if (params->flag)
        self->flag = 1;
}
