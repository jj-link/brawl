#include <mt/mt_vector.h>
#include <nw4r/math/math_types.h>
#pragma force_active on
#pragma fp_contract off

extern const float lbl_27_rodata_E28[6];

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_B71B0();
    virtual void fn_27_B75E4();
    virtual int fn_27_7FCF8();
};
struct Pad8 { char pad[8]; };
#define V(n) virtual void slot##n();
class Object_vptr_0 : public Pad8 {
public:
    V(0)
    V(1)
    V(2)
    V(3)
    V(4)
    V(5)
    V(6)
    V(7)
    V(8)
    V(9)
    V(10)
    V(11)
    V(12)
    V(13)
    V(14)
    V(15)
    V(16)
    V(17)
    V(18)
    V(19)
    V(20)
    V(21)
    V(22)
    V(23)
    V(24)
    V(25)
    V(26)
    V(27)
    V(28)
    V(29)
    V(30)
    V(31)
    V(32)
    V(33)
    V(34)
    V(35)
    V(36)
    V(37)
    V(38)
    V(39)
    V(40)
    V(41)
    V(42)
    V(43)
    V(44)
    V(45)
    V(46)
    V(47)
    V(48)
    V(49)
    V(50)
    V(51)
    V(52)
    V(53)
    V(54)
    V(55)
    V(56)
    V(57)
    V(58)
    virtual Vec2f slot59(int);
    virtual Vec2f slot60(int);
    V(61)
    V(62)
    V(63)
    V(64)
    V(65)
    V(66)
    V(67)
    V(68)
    V(69)
    V(70)
    V(71)
    V(72)
    V(73)
    V(74)
    V(75)
    V(76)
    V(77)
    V(78)
    V(79)
    V(80)
    V(81)
    V(82)
    V(83)
    V(84)
    V(85)
    V(86)
    V(87)
    virtual Vec2f slot88(int);
    V(89)
    V(90)
    V(91)
    V(92)
    V(93)
    V(94)
    V(95)
    V(96)
    V(97)
    V(98)
    V(99)
    V(100)
    V(101)
    V(102)
    V(103)
    V(104)
    V(105)
    V(106)
    V(107)
    V(108)
    V(109)
    V(110)
    V(111)
    V(112)
    V(113)
    V(114)
    virtual unsigned int slot115(int);
    V(116)
};
#undef V
struct Modules {
    char pad[0x10];
    Object_vptr_0* m10;
    soNullable* m14;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
struct Self {
    char pad[8];
    Vec2f input;
    Vec2f speed;
    float limit;
    float threshold;
    float angularInput;
    float angularSpeed;
    float angle;
    unsigned char f2C;
    unsigned char f2D;
};
extern "C" void fn_27_B71B0(Self* self, Accesser* acc) {
    const float* k = lbl_27_rodata_E28;
    int state = acc->modules->m14->fn_27_7FCF8();
    if (state == 0) {
        self->speed = self->input + acc->modules->m10->slot88(0);
        if (acc->modules->m10->slot115(0) == 1) {
            (nw4r::math::VEC2&)self->speed += (const nw4r::math::VEC2&)acc->modules->m10->slot59(0);
        }
    } else if (state == 2) {
        if (acc->modules->m10->slot115(0) == 1) {
            self->speed = self->input + acc->modules->m10->slot59(0);
        } else if (self->f2C == 1) {
            if (k[0] != self->speed.m_x || k[0] != self->speed.m_y) {
                float sq = self->speed.m_x * self->speed.m_x + self->speed.m_y * self->speed.m_y;
                float len;
                if ((float)(double)nw4r::math::FAbs(sq) <= k[3]) {
                    len = k[0];
                } else {
                    len = sq * rsqrtf(sq);
                }
                float lim = self->limit;
                if (len > self->threshold) {
                    lim = lim + (len - self->threshold);
                }
                if (len > k[4] && len > lim) {
                    float s = (len - lim) / len;
                    self->speed.m_x = self->speed.m_x * s;
                    self->speed.m_y = self->speed.m_y * s;
                } else {
                    self->speed.m_x = k[0];
                    self->speed.m_y = k[0];
                }
            }
        } else {
            self->speed.m_x = self->input.m_x;
            self->speed.m_y = self->input.m_y;
        }
    } else {
        self->speed.m_x = self->input.m_x;
        self->speed.m_y = self->input.m_y;
    }
    if (self->f2D == 1) {
        self->angularSpeed = self->angularInput;
        unsigned int found = 0;
        Vec2f w;
        if (acc->modules->m10->slot115(0) == 1) {
            w = acc->modules->m10->slot60(0);
            found = 1;
        }
        float angle = k[0];
        if (found == 1) {
            double x = w.m_x;
            double y = w.m_y;
            angle = (float)atan2(y, x);
        }
        self->angularSpeed = self->angularSpeed + k[5] * (self->angle - angle);
        self->angle = angle;
    } else {
        self->angularSpeed = k[0];
    }
    self->input.m_x = k[0];
    self->input.m_y = k[0];
    self->angularInput = k[0];
}