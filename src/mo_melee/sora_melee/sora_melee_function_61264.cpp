#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Effect {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void request(int, const Vec3*, const Vec3*, float, int, int);
};

struct Modules {
    char padding[0x88];
    Effect* effect;
};

struct Object {
    char padding[0xD8];
    Modules* modules;
};

struct Input {
    char padding[0x10];
    float x, y, z;
};

extern "C" const float lbl_27_rodata_890;
extern "C" const float lbl_27_rodata_8A0;

extern "C" void fn_27_61264(void*, Object* object, const Input* input) {
    Vec3 position;
    Vec3 rotation = {
        lbl_27_rodata_890,
        lbl_27_rodata_890,
        lbl_27_rodata_890
    };
    position.x = input->x;
    position.y = input->y;
    position.z = input->z;
    Effect* effect = object->modules->effect;
    effect->request(0x26, &position, &rotation, lbl_27_rodata_8A0, 0, -1);
}
