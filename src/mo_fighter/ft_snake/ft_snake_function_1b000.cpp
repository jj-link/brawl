#include <so/stageobject.h>
#include <so/ground/so_ground_module_impl.h>
#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

class Class_DF18 {
public:
    virtual void fn_122_ABB4();
    virtual void fn_122_1770C();
    virtual void fn_122_18D50();
    virtual void fn_122_18D4C();
    virtual void fn_122_18D48();
    virtual void fn_122_18D44();
    virtual void fn_122_18D3C();
    virtual void fn_122_18D84();
    virtual void fn_122_18D7C();
    virtual float fn_122_18D74();
    virtual void fn_122_18D6C();
    virtual void fn_122_18D64();
    virtual void fn_122_18CFC();
    virtual void fn_122_18D30();
    virtual void fn_122_18D24();
    virtual void fn_122_18D1C(Vec3f*, unsigned int);
};

class Class_E104 {
public:
    virtual void fn_122_ABB4();
    virtual void fn_122_176B0();
    virtual void fn_122_18F4C();
    virtual void fn_122_18F44();
    virtual void fn_122_18F3C();
    virtual void fn_122_18F34();
    virtual void fn_122_18F2C();
    virtual void fn_122_18F24();
    virtual void fn_122_18F1C();
    virtual void fn_122_18F14();
    virtual void fn_122_18F0C();
    virtual void fn_122_18F04();
    virtual void fn_122_18EFC();
    virtual void fn_122_18EF4();
    virtual void fn_122_18EA4();
    virtual void fn_122_18EEC();
};

struct SnakeModules {
    char pad[0xC];
    Class_DF18* posture;
    soGroundModule* ground;
};
struct Snake {
    char pad0[8];
    StageObject* object;
    char padC[0xCC];
    SnakeModules* modules;
};

extern "C" const float lbl_122_rodata_D0[];

extern "C" void fn_122_1B000(Snake* self) {
    const float* c = lbl_122_rodata_D0;
    if (self->modules->ground->isTouch(static_cast<grCollStatus::TouchMask>(0xFF), 0)) {
        float rotationY = c[0];
        if (self->modules->posture->fn_122_18D74() > c[1]) {
            rotationY = -rotationY;
        }
        Vec2f normal;
        Vec2f::copy(normal, self->modules->ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(0xFF), 0));
        float x = normal.m_x;
        float y = normal.m_y;
        float angle = static_cast<float>(atan2(y, x));
        Vec3f rotation;
        rotation.m_x = c[2];
        rotation.m_y = rotationY;
        rotation.m_z = c[3] * (angle - c[4]);
        self->modules->posture->fn_122_18D1C(&rotation, 0);
        self->object->updateNodeSRT();
    }
}
