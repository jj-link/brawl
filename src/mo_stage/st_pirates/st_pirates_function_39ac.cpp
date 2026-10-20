#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Params {
    u8 pad[0x24];
    float initial;
    float low0, high0;
    float low1, high1;
};

struct Base {
    u8 pad0[0x3C];
};

struct Stage : Base {
    virtual void unusedA0();
    virtual void unusedA1();
    virtual void unusedA2();
    virtual void unusedA3();
    virtual void unusedA4();
    virtual void unusedA5();
    virtual void unusedA6();
    virtual void unusedA7();
    virtual void unusedA8();
    virtual void unusedA9();
    virtual void unusedA10();
    virtual void unusedA11();
    virtual void unusedA12();
    virtual void unusedA13();
    virtual void unusedA14();
    virtual void unusedA15();
    virtual void unusedA16();
    virtual void unusedA17();
    virtual void unusedA18();
    virtual void unusedA19();
    virtual void unusedA20();
    virtual void unusedA21();
    virtual void unusedA22();
    virtual void unusedA23();
    virtual void unusedA24();
    virtual void unusedA25();
    virtual void unusedA26();
    virtual void unusedA27();
    virtual void unusedA28();
    virtual void unusedA29();
    virtual void unusedA30();
    virtual void unusedA31();
    virtual void unusedA32();
    virtual void unusedA33();
    virtual void unusedA34();
    virtual void unusedA35();
    virtual void unusedA36();
    virtual void unusedA37();
    virtual void unusedA38();
    virtual void unusedA39();
    virtual Params* getParams();
    virtual void unusedB0();
    virtual void unusedB1();
    virtual void unusedB2();
    virtual void unusedB3();
    virtual void unusedB4();
    virtual void unusedB5();
    virtual void unusedB6();
    virtual void unusedB7();
    virtual void unusedB8();
    virtual void unusedB9();
    virtual void unusedB10();
    virtual void unusedB11();
    virtual void unusedB12();
    virtual void unusedB13();
    virtual void unusedB14();
    virtual void unusedB15();
    virtual void unusedB16();
    virtual void unusedB17();
    virtual void unusedB18();
    virtual void unusedB19();
    virtual void unusedB20();
    virtual void unusedB21();
    virtual void unusedB22();
    virtual void unusedB23();
    virtual void unusedB24();
    virtual void setValue(int, float);
    virtual void unusedC0();
    virtual void unusedC1();
    virtual void unusedC2();
    virtual void unusedC3();
    virtual void unusedC4();
    virtual void unusedC5();
    virtual void unusedC6();
    virtual void unusedC7();
    virtual void unusedC8();
    virtual void unusedC9();
    virtual void unusedC10();
    virtual void unusedC11();
    virtual void unusedC12();
    virtual void unusedC13();
    virtual void unusedC14();
    virtual void unusedC15();
    virtual void unusedC16();
    virtual void unusedC17();
    virtual void unusedC18();
    virtual void unusedC19();
    virtual void unusedC20();
    virtual void unusedC21();
    virtual void unusedC22();
    virtual void unusedC23();
    virtual void unusedC24();
    virtual void unusedC25();
    virtual void unusedC26();
    virtual void unusedC27();
    virtual void unusedC28();
    virtual void unusedC29();
    virtual void unusedC30();
    virtual void unusedC31();
    virtual void unusedC32();
    virtual void unusedC33();
    virtual void unusedC34();
    virtual void unusedC35();
    virtual void unusedC36();
    virtual void unusedC37();
    virtual void unusedC38();
    virtual void unusedC39();
    virtual void unusedC40();
    virtual void unusedC41();
    virtual void unusedC42();
    virtual void unusedC43();
    virtual void unusedC44();
    virtual void unusedC45();
    virtual void unusedC46();
    virtual void unusedC47();
    virtual void setMotion(u32, bool, bool, float*);

    u8 pad1[0x150 - 0x40];
    u8 state;
    u8 pad2[7];
    float* value;
    u8 pad3[4];
    u8 enabled;
    u8 count;
    u8 pad4[6];
    u8* event;
    u8* action;
    u8* active;
    u8 previousEvent;
    u8 pad5[3];
    float timer;
    u8 motion;
    u8 pad6[3];
    float frame;
};

extern "C" float randf__Fv();
extern "C" const float lbl_52_rodata_B8;
extern "C" const float lbl_52_rodata_BC;

extern "C" void fn_52_39AC(Stage* self, float delta) {
    Params* params = self->getParams();
    if (!params) return;

    self->timer -= delta;
    if (self->timer < lbl_52_rodata_B8)
        self->timer = lbl_52_rodata_B8;

    self->frame -= delta;
    if (self->frame < lbl_52_rodata_B8)
        self->frame = lbl_52_rodata_B8;

    switch (self->state) {
    case 0:
        self->setMotion(0, true, true, &self->frame);
        self->timer = params->initial;
        self->state = 1;
        break;

    case 1:
        if (self->enabled != 1) return;

        u32 next = 5;
        bool keep = true;

        switch (self->motion) {
        case 0:
            if (lbl_52_rodata_B8 == self->timer) {
                if (*self->event == 9) return;
                if (*self->event == 7) return;
                next = 1;
                keep = false;
            }
            break;

        case 2:
            if (lbl_52_rodata_B8 == self->timer) {
                next = 3;
                keep = false;
            }
            break;

        case 1:
            next = 2;
            self->timer = params->low1
                + (params->high1 - params->low1) * randf__Fv();
            break;

        case 3:
            next = 0;
            self->timer = params->low0
                + (params->high0 - params->low0) * randf__Fv();
            break;

        case 4:
            if (--self->count == 0) {
                next = 0;
                self->timer = params->low0
                    + (params->high0 - params->low0) * randf__Fv();
            }
            break;
        }

        if (*self->event != self->previousEvent) {
            u8 old = next;

            switch (*self->event) {
            case 6:
                self->count = 3;
                next = 4;
                break;

            case 7:
            case 9:
                if (*self->active && *self->action != 5)
                    next = 3;
                break;
            }

            if (next != old)
                keep = false;

            self->previousEvent = *self->event;
        }

        if (next == 5) return;

        self->setMotion(next, keep, true, &self->frame);
        self->setValue(0, lbl_52_rodata_BC - *self->value);

        switch (self->motion) {
        case 0:
            *self->active = 0;
            *self->action = 7;
            break;

        case 1:
            *self->active = 1;
            *self->action = 3;
            break;

        case 2:
            *self->active = 1;
            *self->action = 4;
            break;

        case 3:
            *self->active = 1;
            *self->action = 5;
            break;

        case 4:
            if (!*self->active) {
                *self->active = 0;
                *self->action = 7;
            } else if (*self->action != 3 && *self->action != 4) {
                *self->active = 0;
                *self->action = 7;
            } else {
                *self->active = 1;
                *self->action = 6;
            }
            break;
        }
        break;
    }
}
