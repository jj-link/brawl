#include <math.h>
#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
class soPostureModuleImpl {
public:
    virtual void isNull();
    virtual ~soPostureModuleImpl();
    virtual void fn_27_2362C();
    virtual void fn_27_236B0();
    virtual Vec3 fn_27_25088();
    virtual void fn_27_23E84();
    virtual void fn_27_25184();
};
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28(int, const Vec3*, const Vec3*, float, int, int);
};
struct Modules {
    char pad[0xc];
    soPostureModuleImpl* posture;
    char pad2[0x78];
    Class_1250* effect;
};
struct Object {
    char pad[0xd8];
    Modules* modules;
};
struct Vec2 { float x, y; };
extern "C" const float lbl_27_rodata_890;
extern "C" const float lbl_27_rodata_8A0;
extern "C" void fn_27_6113C(void*, Object* object, const Vec2* input) {
    Vec3 position = object->modules->posture->fn_27_25088();
    float angle = (float)atan2(-input->x, input->y);
    Vec3 rotation;
    rotation.x = lbl_27_rodata_890;
    rotation.y = lbl_27_rodata_890;
    rotation.z = angle;
    object->modules->effect->fn_27_14A28(9, &position, &rotation, lbl_27_rodata_8A0, 0, -1);
}