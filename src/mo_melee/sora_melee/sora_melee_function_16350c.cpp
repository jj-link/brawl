#include <types.h>
#include <so/so_value_accesser.h>
#include <so/ground/so_ground_module_impl.h>
#include <mt/mt_vector.h>
#pragma force_active on

class Object_vptr_0 {
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
    virtual void slot11();
    virtual void slot12();
    virtual Vec2f slot13(const unsigned short& attr);
};

extern const float lbl_27_rodata_1FC0[];

extern "C" void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);

inline float dot(const Vec2f& a, const Vec2f& b) {
    return a.m_x * b.m_x + a.m_y * b.m_y;
}

inline void reflect(Vec2f& speed, const Vec2f& normal, const float* c) {
    speed = speed - (normal * c[8]) * dot(normal, speed);
}

inline void reflect2(Vec2f& speed, const Vec2f& normal, const float* c) {
    reflect(speed, normal, c);
}

extern "C" void fn_27_16350C(int, int, int, soModuleAccesser* accesser) {
    const float* c = lbl_27_rodata_1FC0 - 1;
    unsigned short attr = 2;
    Vec2f speed;
    Vec2f::copy(speed, reinterpret_cast<Object_vptr_0*>(accesser->m_enumerationStart->m_kineticModule)->slot13(attr));

    Vec3f zero3(c[1], c[1], c[1]);
    fn_27_89D08(1, accesser, 0, &Vec2f(c[1], c[1]), &zero3);

    Vec2f normal;
    normal.m_x = c[1];
    normal.m_y = c[9];
    Vec2f n;
    if (accesser->m_enumerationStart->m_groundModule->isTouch((grCollStatus::TouchMask)1, 0) == 1) {
        Vec2f::copy(n, accesser->m_enumerationStart->m_groundModule->getTouchNormal((grCollStatus::TouchMask)1, 0));
        float nx = n.m_x;
        if (normal.m_x * nx + normal.m_y * n.m_y > c[10]) {
            normal.m_x = nx;
            normal.m_y = n.m_y;
        }
    }

    reflect2(speed, normal, c);

    float scale = soValueAccesser::getConstantFloat(accesser, 0xcd5, 0);
    float x = speed.m_x;
    float y = speed.m_y;
    float sx = x * scale;
    float sy = y * scale;
    speed.m_x = sx;
    speed.m_y = sy;

    Vec3f zero3b(c[1], c[1], c[1]);
    fn_27_89D08(4, accesser, 2, &Vec2f(speed.m_x, speed.m_y), &zero3b);
}
