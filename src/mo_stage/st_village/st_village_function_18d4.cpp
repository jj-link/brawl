#pragma force_active on

extern "C" const float lbl_70_rodata_0;
extern "C" float randf__Fv();

struct Params {
    char pad[0x30];
    float initial;
    float repeat;
    float probability;
};

struct Village {
    char pad[0x9c];
    Params* params;
    char padA0[0x265 - 0xa0];
    unsigned char state;
    char pad266[2];
    float timer;
    unsigned char motion;
};

extern "C" void fn_70_18D4(Village* self, float delta) {
    Params* p = self->params;
    if (p) {
        self->timer -= delta;
        if (self->timer < lbl_70_rodata_0)
            self->timer = lbl_70_rodata_0;

        switch (self->state) {
        case 0:
            self->timer = p->initial;
            self->state = 1;
            break;
        case 1:
            if (lbl_70_rodata_0 == self->timer) {
                if (randf__Fv() < p->probability) {
                    self->motion = 4;
                    self->state = 2;
                } else {
                    self->timer = p->repeat;
                }
            }
            break;
        case 2:
            if (self->motion == 6) {
                self->timer = p->repeat;
                self->state = 1;
            }
            break;
        }
    }
}
