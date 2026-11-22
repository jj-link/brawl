#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

class Point2 : public Vec2f {
public:
    Point2(const Vec3f& p) { m_x = p.m_x; m_y = p.m_y; }
};
class Work {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
};
class Posture {
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
    virtual void slot12();
};
struct Modules {
    char pad[0xc];
    Posture* posture;
    char pad2[0x54];
    Work* work;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
class Energy {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Vec2f slot2();
    char pad[0xc];
    Vec2f a10, a18;
    char pad2[8];
    Vec2f a28;
};
extern "C" {
float fn_27_192278(void*, unsigned long);
void fn_27_89D08(int, void*, int, Vec2f*, Vec3f*);
void fn_8003DBA8(Vec2f*);
void fn_8003DC64(Vec2f*, float, Vec2f*);
float randf__Fv();
float rsqrtf__Ff(float);
extern const float lbl_27_rodata_8048[];

void fn_27_3BCC80(void*, void* arg1, void*, Accesser* arg3) {
    const float* c = lbl_27_rodata_8048 + 1;
    float y = arg3->modules->work->slot12(0x21000005);
    float x = arg3->modules->work->slot12(0x21000004);
    Vec2f v(x, y);
    Vec3f pos = arg3->modules->posture->slot4();
    Vec2f v2;
    Vec2f delta;
    Vec2f p;
    p.m_x = pos.m_x;
    p.m_y = pos.m_y;
    v.m_x = v.m_x - p.m_x;
    v.m_y = v.m_y - p.m_y;
    fn_8003DBA8(&v);
    float s = fn_27_192278(arg3, 0xfa3) + randf__Fv() *
        (fn_27_192278(arg3, 0xfa4) - fn_27_192278(arg3, 0xfa3));
    if (v.m_x < c[-1]) s = -s;
    fn_8003DC64(&v, c[1] * s, &v);
    float scale = fn_27_192278(arg3, 0xfa5);
    Vec3f zero;
    float sx = v.m_x * scale;
    float sy = v.m_y * scale;
    zero.m_x = c[-1];
    v.m_x = sx;
    v.m_y = sy;
    zero.m_y = c[-1];
    zero.m_z = c[-1];
    fn_27_89D08(3, arg3, 6, &v, &zero);
    Energy* e = (Energy*)((char*)arg1 + 0xf8);
    e->a18.m_x = c[0];
    e->a10 = Vec2f(c[-1], c[-1]);
    e->a18.m_y = Vec2f(c[0], c[0]).m_y;
    e->a28 = Vec2f(c[0], c[0]);
    float y2 = arg3->modules->work->slot12(0x21000005);
    float x2 = arg3->modules->work->slot12(0x21000004);
    v2.m_x = x2;
    v2.m_y = y2;
    Vec3f pos2 = arg3->modules->posture->slot4();
    Vec2f::copy(delta, v2 - Point2(pos2));
    float sq = e->slot2().lengthSq();
    float len;
    if ((float)(double)nw4r::ut::Abs(sq) <= c[6])
        len = c[-1];
    else
        len = sq * rsqrtf__Ff(sq);
    float len2 = c[-1];
    float result = c[7];
    if (len > len2) {
        float sq2 = delta.lengthSq();
        if ((float)(double)nw4r::ut::Abs(sq2) <= c[6])
            len2 = c[-1];
        else
            len2 = sq2 * rsqrtf__Ff(sq2);
        result = len2 / len;
        result += c[8];
    }
    arg3->modules->work->slot5((int)result, 0x20000002);
}
}
