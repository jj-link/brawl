#include <nw4r/math/math_arithmetic.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual int slot8(int, int, int);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13(unsigned long, float);
    virtual void slot14(int, int, float);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual float slot18(unsigned long = 0);
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29(int, void*);
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55(int, int, int, int);
};

class Control {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual int slot8(int, int, int);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13(unsigned long, float);
    virtual void slot14(int, int, float);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual float slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29(int, void*);
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55(int, int, int, int);
};

struct OtherBase {
    char pad[8];
};

class Other : public OtherBase {
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29(int, void*);
};

struct Modules {
    char pad0[4];
    Other* other;
    char pad1[0x48];
    Object_vptr_0* anim;
    char pad2[8];
    Control* control;
    char pad3[4];
    Object_vptr_0* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Vector {
    float x;
    float y;
    float z;
};

extern "C" {
float fn_27_192278(void*, unsigned long);
int fn_27_1922CC(void*, unsigned long);
extern const float lbl_27_rodata_7650;
extern const float lbl_27_rodata_7654;
}

inline float clampValue(float v, float lo, float hi) {
    float t = nw4r::math::FSelect(v - lo, v, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_27_32EB38(void*, Accesser* a) {
    int state = a->modules->work->slot4(0x20000002);
    if (state != a->modules->work->slot4(0x20000003)) {
        a->modules->work->slot5(state, 0x20000003);
        if (state == 2)
            a->modules->anim->slot9();
    }

    switch (state) {
    case 1: {
        float low = fn_27_192278(a, 0xfa9);
        float high = fn_27_192278(a, 0xfa8);
        float ratio = (a->modules->work->slot12(0x11000013) - low) / (high - low);
        int count = a->modules->work->slot4(0x20000000);

        if (count >= 3 && a->modules->work->slot4(0x20000008) == -1) {
            int id = a->modules->work->slot4(0x20000006);
            int result = a->modules->anim->slot8(id, 0, 0);
            a->modules->work->slot5(result, 0x20000008);
        } else if (count >= 11 && a->modules->work->slot4(0x20000009) == -1) {
            int id = a->modules->work->slot4(0x20000007);
            int result = a->modules->anim->slot8(id, 0, 0);
            a->modules->work->slot5(result, 0x20000009);
        }

        int timer = a->modules->work->slot4(0x20000004);
        if (timer == 0) {
            a->modules->work->slot18(0x22000013);
            int id = a->modules->work->slot4(0x20000009);
            if (id != -1) {
                float value = ratio;
                float min = fn_27_192278(a, 0xfb0);
                if (ratio < min)
                    value = min;
                a->modules->anim->slot14(id, 0, value);
            }
            a->modules->control->slot55(
                (int)(ratio > lbl_27_rodata_7650 ? (void*)0 : (void*)1),
                0, 1, -1);
        }

        int next = timer + 1;
        if (next >= fn_27_1922CC(a, 0x5dc2))
            next = 0;
        a->modules->work->slot5(next, 0x20000004);
        a->modules->work->slot5(count + 1, 0x20000000);

        float value = a->modules->work->slot12(0x21000004);
        float stick = a->modules->control->slot18();
        if ((float)(double)nw4r::math::FAbs(stick) > lbl_27_rodata_7650) {
            float max = fn_27_192278(a, 0xfa2);
            float min = fn_27_192278(a, 0xfa3);
            float factor = fn_27_192278(a, 0xfa4);
            value += factor * stick;
            value = clampValue(value, -min, max);
            a->modules->work->slot13(0x21000004, value);
        }

        int target = a->modules->work->slot4(0x2000000a);
        if (target != 0) {
            Vector v;
            v.x = -value * fn_27_192278(a, 0xfa5);
            v.y = lbl_27_rodata_7654;
            v.z = lbl_27_rodata_7654;
            a->modules->other->slot29(target, &v);
        }
        break;
    }
    }
}
