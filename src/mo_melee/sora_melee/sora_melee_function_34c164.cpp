#pragma scheduling on
#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;

extern "C" float lbl_27_rodata_78DC;

class TeamInner {
public:
    virtual void s0();
    virtual void s1();
    virtual int s2();
};

class Team {
public:
    virtual void s0();
    virtual void s1();
    virtual TeamInner* s2();
    virtual void s3(int, int);
    virtual void s4();
    virtual void s5();
    virtual void s6(int);
    virtual void s7(int);
};

struct ReflectBase {
    char pad[8];
};

class Reflect : public ReflectBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual int s8();
    virtual int s9();
};

class Posture {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec3f s4();
};

class Work {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18(int, void*);
};

class Kinetic {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual _VEC2 s13(short*);
};

struct Modules {
    char pad0[0xc]; Posture* posture;
    char pad1[8]; Team* team;
    char pad2[0x48]; Work* work;
    char pad3[0x14]; Kinetic* kinetic;
    char pad4[0x3c]; Reflect* reflect;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Accesser* accesser;
};

struct Event {
    char pad[0x10];
    float x;
    float y;
    float z;
    char pad1[5];
    unsigned char kind;
};

inline float directionSign(float v) { return v < lbl_27_rodata_78DC ? -1 : 1; }

extern "C" void fn_27_34C164(Object* self, Event* event) {
    if (event != 0) {
        unsigned char kind = event->kind;
        if ((unsigned char)(kind + 0xfe) <= 1) {
            if (kind == 3) {
                int id = self->accesser->modules->reflect->s9();
                if (id == self->accesser->modules->team->s2()->s2()) {
                    return;
                }
                self->accesser->modules->team->s3(id, 1);
                self->accesser->modules->team->s6(id);
                Reflect* ref = self->accesser->modules->reflect;
                Team* team = self->accesser->modules->team;
                team->s7(ref->s8());
                self->accesser->modules->work->s18(0x12000004, self->accesser);
            } else {
                Vec3f diff;
                Vec3f target;
                Vec3f pos = self->accesser->modules->posture->s4();
                target.m_x = event->x;
                target.m_y = event->y;
                target.m_z = event->z;
                short mask = -1;
                Vec3fSub(&diff, &target, &pos);
                Vec2f delta;
                delta.m_x = diff.m_x;
                delta.m_y = diff.m_y;
                _VEC2 speed = self->accesser->modules->kinetic->s13(&mask);
                float a = speed.x < lbl_27_rodata_78DC ? -1 : 1;
                float b = directionSign(delta.m_x);
                bool match = b == a;
                if (match) {
                    self->accesser->modules->work->s18(0x12000004, self->accesser);
                }
            }
            self->accesser->modules->work->s18(0x12000005, self->accesser);
        } else if (kind != 0) {
            self->accesser->modules->work->s18(0x12000006, self->accesser);
        }
    }
}
