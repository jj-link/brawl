#pragma force_active on
#include <mt/mt_vector.h>

struct PointDistance {
    int index;
    float distance;
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(const PointDistance&);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual unsigned int slot14();
};

struct gfTask_base {
    char pad[0x3c];
};

class gfTask : public gfTask_base {
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
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual int slot25();
    virtual void slot26(Vec2f*, int);
};

extern "C" {
extern gfTask* lbl_27_bss_5668;
extern const float lbl_27_rodata_7C90;
}

inline float square(float value)
{
    return value * value;
}

inline float distanceSquared(const Vec2f& a, const Vec2f& b)
{
    float x = a.m_x - b.m_x;
    float y = a.m_y - b.m_y;
    Vec2f delta(x, y);
    return delta.m_x * delta.m_x + delta.m_y * delta.m_y;
}

extern "C" void fn_27_388B04(
    void*, soNullable* output, const Vec2f* center,
    const Vec2f* lower, const Vec2f* upper, float radius)
{
    PointDistance points[64];
    int count = 0;
    int total = lbl_27_bss_5668->slot25();

    for (int i = 0; i < total; ++i) {
        Vec2f pos;
        lbl_27_bss_5668->slot26(&pos, i);

        if (lower->m_x < pos.m_x &&
            lower->m_y < pos.m_y &&
            upper->m_x > pos.m_x &&
            upper->m_y > pos.m_y)
            continue;

        float distance = distanceSquared(pos, *center);
        if (lbl_27_rodata_7C90 == radius || distance < square(radius)) {
            points[count].index = i;
            points[count].distance = distance;
            ++count;
        }
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = i; j < count; ++j) {
            if (points[i].distance > points[j].distance) {
                PointDistance tmp = points[j];
                points[j].index = points[i].index;
                points[j].distance = points[i].distance;
                points[i].index = tmp.index;
                points[i].distance = tmp.distance;
            }
        }
    }

    output->slot8();

    for (int i = 0; i < count; ++i) {
        output->slot10(points[i]);
        if (output->slot14() == 1)
            break;
    }

    output->slot3();
}
