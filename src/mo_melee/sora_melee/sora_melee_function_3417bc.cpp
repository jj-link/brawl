#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void* __memcpy(void*, const void*, unsigned long);

inline float multiply(float a, float b) {
    return a * b;
}

struct Vec2 {
    float m_x, m_y;
    Vec2() {}
    Vec2(float x, float y) : m_x(x), m_y(y) {}

    static void copy(Vec2& dest, const Vec2& src) {
        __memcpy(&dest, &src, sizeof(Vec2));
    }
};

extern "C" {
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
extern char lbl_27_data_137B8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int randi__Fl(long);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Vec2 slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
};

struct Kin : Object_vptr_0 {
    int pad;
    Vec2 speed, accel, limit, unused, extra;

    void setSpeed(const Vec2& v) {
        speed.m_x = v.m_x;
        speed.m_y = v.m_y;
    }

    void setAccel(const Vec2& v) {
        accel.m_x = v.m_x;
        accel.m_y = v.m_y;
    }

    void setLimit(const Vec2& v) {
        limit.m_x = v.m_x;
        limit.m_y = v.m_y;
    }

    void setExtra(const Vec2& v) {
        extra.m_x = v.m_x;
        extra.m_y = v.m_y;
    }
};

struct Kine2 {
    char pad[8];
    Vec3f value;
};

struct Modules {
    char pad[0x7c];
    Object_vptr_0* energy;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_3417BC(void*, Accesser* arg) {
    float a[8] = {
        -2.0f, -2.1f, -2.2f, -2.3f,
        -2.4f, -2.5f, -2.6f, -2.7f
    };
    float b[8] = {
        -0.1f, -0.12f, -0.14f, -0.18f,
        -0.2f, -0.22f, -0.24f, -0.26f
    };
    float c[8] = {
        12.0f, 14.0f, 16.0f, 18.0f,
        20.0f, 22.0f, 24.0f, 26.0f
    };

    Object_vptr_0* energy = arg->modules->energy;
    Kin* kin = (Kin*)__dynamic_cast(
        energy->slot6(0), 0,
        lbl_27_data_457C0, lbl_27_data_CDF8, 1);
    Kine2* k2 = (Kine2*)__dynamic_cast(
        energy->slot6(1), 0,
        lbl_27_data_137B8, lbl_27_data_CDF8, 1);

    float scale = randi__Fl(2) == 0 ? 1.0f : -1.0f;
    scale = multiply(c[randi__Fl(8)], scale);
    float x = scale;
    float zero = 0.0f;
    float y = a[randi__Fl(8)];
    float z = b[randi__Fl(8)];

    Vec3f v(x, 0.0f, 0.0f);
    Vec2 q;
    Vec2::copy(q, kin->slot2());
    q.m_x = zero;
    q.m_y = nw4r::math::FAbs(a[randi__Fl(8)]);

    Vec2 t;
    Vec2::copy(t, kin->accel);
    k2->value = v;
    kin->setSpeed(q);

    t.m_y = z;
    kin->setAccel(t);

    Vec2 l(zero, y);
    kin->setLimit(l);
    kin->setExtra(l);
}
