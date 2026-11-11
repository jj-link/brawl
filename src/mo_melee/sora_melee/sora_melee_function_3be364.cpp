#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on

class PostureObj {
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

class WorkObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long, void*);
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
    PostureObj* posture;
    char pad1[0x54];
    WorkObj* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Output {
    char pad[8];
    float x;
    float y;
};

extern "C" float rsqrtf__Ff(float);
extern "C" void fn_8003DBA8(Vec2f*);
extern "C" const float lbl_27_rodata_8048;
extern "C" const float lbl_27_rodata_8064;

extern "C" void fn_27_3BE364(Output* out, void*, Accesser* accesser) {
    int count = accesser->modules->work->slot4(0x20000003, accesser);
    if (count <= 0)
        count = 1;

    Vec2f base(accesser->modules->posture->slot4().m_x,
               accesser->modules->posture->slot4().m_y);
    Vec2f delta;
    float val5 = accesser->modules->work->slot12(0x21000005);
    float val4 = accesser->modules->work->slot12(0x21000004);
    Vec2f::copy(delta, Vec2f(val4, val5) - base);

    float sq = delta.m_x * delta.m_x + delta.m_y * delta.m_y;
    float length;
    if ((float)(double)nw4r::ut::Abs(sq) <= lbl_27_rodata_8064)
        length = lbl_27_rodata_8048;
    else
        length = sq * rsqrtf__Ff(sq);

    if (count > 1) {
        fn_8003DBA8(&delta);
        delta.m_x *= length / (float)count;
        delta.m_y *= length / (float)count;
    }

    out->x = delta.m_x;
    out->y = delta.m_y;
}
