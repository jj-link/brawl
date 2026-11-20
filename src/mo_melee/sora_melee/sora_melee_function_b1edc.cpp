#pragma force_active on
#include <mt/mt_vector.h>

extern const float lbl_27_rodata_DB0;

class soPostureModuleImpl {
public:
    virtual void isNull();
    virtual ~soPostureModuleImpl();
    virtual void fn_27_2362C();
    virtual void fn_27_236B0();
    virtual Vec3f fn_27_25088();
    virtual void fn_27_23E84();
    virtual void fn_27_25184();
    virtual void fn_27_2370C();
    virtual void fn_27_23728();
    virtual float fn_27_23E28();
    virtual void fn_27_23CC0();
    virtual void fn_27_25068();
    virtual void fn_27_23A9C();
    virtual void fn_27_23B18();
    virtual void fn_27_250FC();
    virtual void fn_27_250A4();
    virtual void fn_27_23BF8();
    virtual void fn_27_251B8();
    virtual void fn_27_251B0();
    virtual void fn_27_23C14();
    virtual void fn_27_25154();
    virtual void fn_27_2517C();
    virtual float fn_27_23744();
};

struct Modules {
    char pad[0xC];
    soPostureModuleImpl* posture;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct State {
    char pad[8];
    float* value;
    char padC[0xC];
    float m18, m1C, m20, m24, m28, m2C;
};

extern "C" void fn_27_B1EDC(State* self, const Rect2D* rect, Accesser* acc) {
    Vec3f pos = acc->modules->posture->fn_27_25088();
    float lr = acc->modules->posture->fn_27_23E28();
    float scale = acc->modules->posture->fn_27_23744();

    if (scale <= lbl_27_rodata_DB0)
        return;

    float* p = self->value;
    float left = rect->m_left;
    float down = rect->m_down;
    float y = self->m2C;
    float x;
    float right = rect->m_right;
    x = pos.m_x;
    float up = rect->m_up;
    float offset = self->m28 * scale;

    float a = ((right - x) - offset) / scale;
    self->m18 = a;

    float b = ((left - pos.m_x) - offset) / scale;
    self->m1C = b;

    self->m20 = ((up - pos.m_y) - (scale * (y + *p))) / scale;
    self->m24 = ((down - pos.m_y) - (scale * (y + *p))) / scale;

    if (lr < lbl_27_rodata_DB0) {
        self->m1C = -a;
        self->m18 = -b;
    }
}
