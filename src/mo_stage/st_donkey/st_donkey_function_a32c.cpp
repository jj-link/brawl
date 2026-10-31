#pragma force_active on
#include <orch_helpers.h>

extern "C" const float lbl_50_rodata_158;
extern "C" const float lbl_50_rodata_160;

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

    unsigned char padding1[0x12C];
    Vec3f a;
    Vec3f b;
    float value184;
    float value188;
    float value18c;
    unsigned char state;
};

extern "C" void fn_50_A32C(Object* self, float delta) {
    Vec3f difference;
    Vec3f temporary;
    Params* params = self->getParams();

    if (params != 0) {
        Vec3fSub_v905145(&temporary, &self->b, &self->a);
        difference = temporary;

        if (lbl_50_rodata_158 != difference.m_x) {
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

            if (difference.m_x > lbl_50_rodata_158 &&
                difference.m_x > limit) {
                difference.m_x = limit * delta;
            }

            if (difference.m_x < lbl_50_rodata_158 &&
                difference.m_x < -limit) {
                difference.m_x = -limit * delta;
            }

            self->a.m_x = self->a.m_x + difference.m_x;

            if (difference.m_x > lbl_50_rodata_158) {
                self->value184 = lbl_50_rodata_158;
                self->value18c = lbl_50_rodata_158;
                self->value188 = lbl_50_rodata_160;
            }

            if (difference.m_x < lbl_50_rodata_158) {
                self->value184 = lbl_50_rodata_158;
                self->value188 = lbl_50_rodata_158;
                self->value18c = lbl_50_rodata_158;
            }
        }
    }
}
