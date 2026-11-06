#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
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
    virtual float slot12(unsigned long);
};

struct Modules {
    char pad0[0xc];
    Object_vptr_0* posture;
    char pad1[0x54];
    Object_vptr_0* work;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
struct Self {
    char pad[8];
    float x;
    float y;
};
extern "C" void fn_8003DBA8(Vec2f*);
extern "C" float lbl_27_rodata_78A8;
extern "C" float lbl_27_rodata_78C8;

inline float deltaY(Accesser* accesser) {
    Object_vptr_0* workY = accesser->modules->work;
    return workY->slot12(0x21000005) - accesser->modules->posture->slot4().m_y;
}

extern "C" void fn_27_3482C8(Self* self, void*, Accesser* accesser) {
    float y = deltaY(accesser);
    Object_vptr_0* workX = accesser->modules->work;
    float x = workX->slot12(0x21000004) - accesser->modules->posture->slot4().m_x;
    Vec2f delta(x, y);
    float square = x * x + y * y;
    float length;
    if ((float)(double)nw4r::ut::Abs(square) <= lbl_27_rodata_78C8)
        length = lbl_27_rodata_78A8;
    else
        length = square * rsqrtf(square);
    if (length > soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xfcb, 0)) {
        fn_8003DBA8(&delta);
        float scale = soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xfcb, 0);
        delta.m_x *= scale;
        delta.m_y *= scale;
    }
    self->x = delta.m_x;
    self->y = delta.m_y;
}
