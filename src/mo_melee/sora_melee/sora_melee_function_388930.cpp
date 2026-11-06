#include <nw4r/math/math_arithmetic.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13(unsigned int, float);
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
};

struct Modules {
    char pad0[0xc];
    Object_vptr_0* posture;
    char pad1[0x54];
    Object_vptr_0* work;
};

struct Object {
    char pad0[8];
    Object_vptr_3c* owner;
    char pad1[0xcc];
    Modules* modules;
};

extern float lbl_27_rodata_7CB0;

inline float clampValue(float value, float low, float high) {
    float t = nw4r::math::FSelect(value - low, value, low);
    return nw4r::math::FSelect(t - high, high, t);
}

extern "C" void fn_27_388930(void*, Object* object) {
    Vec3f pos = object->modules->posture->slot4();
    float x = object->modules->work->slot12(0x11000013);
    float y = object->modules->work->slot12(0x11000014);
    float dy = y - pos.m_y;
    float dx = x - pos.m_x;
    float angle = lbl_27_rodata_7CB0 * (float)atan2(dx, dy);
    float limit = soValueAccesser::getConstantFloat((soModuleAccesser*)object, 0xfa3, 0);
    object->modules->work->slot13(0x11000018, clampValue(angle, -limit, limit));
    object->owner->slot43();
}
