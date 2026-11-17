#include <mt/mt_vector.h>
#include <so/so_enable.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Accesser;

struct V2 {
    float x;
    float y;
};

struct Pair {
    int a;
    int b;
};

class Work {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(unsigned long);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

class Self {
public:
    virtual void s0();
    virtual void s1(Accesser*);
    virtual V2 s2();

    unsigned char pad4;
    soEnable flags;
    unsigned char suspended;
    unsigned char pad7;
    float x;
    float y;
};

extern "C" int fn_27_1922CC(Accesser*, unsigned long);
extern "C" float fn_27_192278(Accesser*, unsigned long);
extern "C" float rsqrtf__Ff(float);
extern "C" void fn_8003DBA8(V2*);
extern "C" const float lbl_27_rodata_8048;
extern "C" const float lbl_27_rodata_8064;

extern "C" void fn_27_3BD698(Self* self, void*, Accesser* a) {
    Work* work = a->modules->work;
    int timer = fn_27_1922CC(a, 0x5dc5);
    V2 v;
    if (work->s4(0x20000002) <= timer) {
        V2 p = self->s2();
        float mag2 = p.x * p.x + p.y * p.y;
        float len;
        if ((float)(double)nw4r::ut::Abs(mag2) <= lbl_27_rodata_8064) {
            len = lbl_27_rodata_8048;
        } else {
            len = mag2 * rsqrtf__Ff(mag2);
        }
        if (len <= fn_27_192278(a, 0xfb1)) {
            Vec2f zero(lbl_27_rodata_8048, lbl_27_rodata_8048);
            self->x = zero.m_x;
            self->y = zero.m_y;
        } else {
            float d = len - fn_27_192278(a, 0xfb1);
            V2 q = self->s2();
            *(Pair*)&v = *(Pair*)&q;
            fn_8003DBA8(&v);
            v.x *= d;
            v.y *= d;
            self->x = v.x;
            self->y = v.y;
        }
    }
    if (self->flags.isEnable() == true && self->suspended == 0) {
        self->s1(a);
    }
}
