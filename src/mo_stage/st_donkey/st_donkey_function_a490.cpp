#pragma force_active on
#include <orch_helpers.h>

extern "C" const float lbl_50_rodata_158;

struct Params {
    unsigned char padding[0x44];
    float value44;
    float value48;
};

struct Base {
    unsigned char padding[0x3C];
};

struct Object : Base {
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
    virtual void slot29();
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
    virtual Params* getParams();

    unsigned char pad1[0x12C];
    Vec3f a;
    Vec3f b;
    unsigned char pad2[0xC];
    unsigned char state;
};

extern "C" void fn_50_A490(Object* self, float delta) {
    Vec3f difference;
    Vec3f temporary;
    Params* params = self->getParams();

    if (params != 0) {
        Vec3fSub_v0420ad(&temporary, &self->b, &self->a);
        difference = temporary;

        if (lbl_50_rodata_158 != difference.m_y) {
            float limit;

            switch (self->state) {
            case 0:
            case 1:
                limit = params->value44;
                break;
            case 2:
                limit = params->value48;
                break;
            }

            if (difference.m_y > lbl_50_rodata_158 &&
                difference.m_y > limit) {
                difference.m_y = limit * delta;
            }

            if (difference.m_y < lbl_50_rodata_158 &&
                difference.m_y < -limit) {
                difference.m_y = -limit * delta;
            }

            self->a.m_y = self->a.m_y + difference.m_y;
        }
    }
}