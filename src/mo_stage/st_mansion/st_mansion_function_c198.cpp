#pragma force_active on
#pragma fp_contract off

extern "C" float randf__Fv();
extern const float lbl_47_rodata_110[];

struct Mansion;

struct MotionParameters {
    char pad[0x3C];
    float acceleration;
    float maxSpeed;
};

struct MansionBase {
    char pad[0x3C];
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
    virtual MotionParameters* getParameters();
};

struct Mansion : MansionBase {
    char pad40[0x118];
    unsigned char state;
    char pad159[3];
    float timer;
    char pad160[8];
    float* position;
    float origin;
    char pad170[0x14];
    float speed;
};

extern "C" void fn_47_C198(Mansion* self, float delta) {
    const float* constants = lbl_47_rodata_110;
    MotionParameters* params = self->getParameters();
    if (!params) return;

    self->timer -= delta;
    if (self->timer < constants[0]) {
        self->timer = constants[0];
    }

    switch (self->state) {
    case 0:
        self->state = 2;
        self->timer = constants[2];
        break;

    case 2:
        if (constants[0] == self->timer) {
            float random = randf__Fv();
            self->state = 9;
            self->timer = constants[3] + constants[4] * random;
        }
        break;

    case 9:
        if (constants[0] == self->timer || *self->position < self->origin) {
            float random = randf__Fv();
            self->state = 10;
            self->timer = constants[4] + constants[4] * random;
        } else {
            self->speed -= params->acceleration * delta;
            if (self->speed < -params->maxSpeed) {
                self->speed = -params->maxSpeed;
            }
            *self->position += self->speed * delta;
        }
        break;

    case 10:
        if (constants[0] == self->timer ||
            *self->position > constants[5] + self->origin) {
            float random = randf__Fv();
            self->state = 9;
            self->timer = constants[4] + constants[4] * random;
        } else {
            self->speed += params->acceleration * delta;
            if (self->speed > params->maxSpeed) {
                self->speed = params->maxSpeed;
            }
            *self->position += self->speed * delta;
        }
        break;
    }
}
