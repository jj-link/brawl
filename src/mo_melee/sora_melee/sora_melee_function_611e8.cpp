#pragma force_active on
struct Vec3 {
    float x, y, z;

    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Input {
    char pad[0x10];
    Vec3 pos;
};

class Module {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void request(int, const Vec3&, const Vec3&, float, int, int);
};

struct Modules {
    char pad[0x88];
    Module* effect;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
extern const float lbl_27_rodata_890;
extern const float lbl_27_rodata_8A0;

void fn_27_611E8(void*, Object* object, const Input* input) {
    object->modules->effect->request(
        0x20,
        Vec3(input->pos),
        Vec3(lbl_27_rodata_890, lbl_27_rodata_890, lbl_27_rodata_890),
        lbl_27_rodata_8A0,
        0,
        -1);
}
}
