#pragma force_active on
extern "C" float randf__Fv();
extern "C" const float lbl_47_rodata_110[];

struct Parameters {
    char pad[0x3C];
    float acceleration;
    float maxSpeed;
};

struct MansionBase {
    char pad0[0x3C];
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual void slot26() = 0;
    virtual void slot27() = 0;
    virtual void slot28() = 0;
    virtual void slot29() = 0;
    virtual void slot30() = 0;
    virtual void slot31() = 0;
    virtual void slot32() = 0;
    virtual void slot33() = 0;
    virtual void slot34() = 0;
    virtual void slot35() = 0;
    virtual void slot36() = 0;
    virtual void slot37() = 0;
    virtual void slot38() = 0;
    virtual void slot39() = 0;
    virtual Parameters* getParameters() = 0;
};

struct MansionObject : MansionBase {
    char pad40[0x118];
    unsigned char state;
    char pad159[3];
    float timer;
    char pad160[8];
    float* position;
    float target;
    char pad170[0x14];
    float speed;
};

extern "C" void fn_47_BF8C(MansionObject* self, float delta) {
    const float* c = lbl_47_rodata_110;
    Parameters* p = self->getParameters();
    if (p) {
        self->timer -= delta;
        if (self->timer < c[0])
            self->timer = c[0];

        switch (self->state) {
        case 0:
            self->state = 2;
            self->timer = c[2];
            break;

        case 2:
            if (c[0] == self->timer) {
                float r = randf__Fv();
                self->state = 9;
                self->timer = c[3] + c[4] * r;
            }
            break;

        case 9:
            if (c[0] == self->timer ||
                *self->position < self->target - c[5]) {
                float r = randf__Fv();
                self->state = 10;
                self->timer = c[4] + c[4] * r;
            } else {
                self->speed -= p->acceleration * delta;
                if (self->speed < -p->maxSpeed)
                    self->speed = -p->maxSpeed;
                *self->position += self->speed * delta;
            }
            break;

        case 10:
            if (c[0] == self->timer ||
                *self->position > self->target) {
                float r = randf__Fv();
                self->state = 9;
                self->timer = c[4] + c[4] * r;
            } else {
                self->speed += p->acceleration * delta;
                if (self->speed > p->maxSpeed)
                    self->speed = p->maxSpeed;
                *self->position += self->speed * delta;
            }
            break;
        }
    }
}
