#pragma force_active on

extern "C" const float lbl_70_rodata_0;
extern "C" float randf__Fv();

struct Params {
    char pad[4];
    float initial;
    float repeat;
    float probability;
};

struct Village {
    char pad[0x9c];
    Params* params;
    char padA0[0x275 - 0xa0];
    unsigned char state;
    char pad276[2];
    float timer;
    unsigned char motion;
};

extern "C" void fn_70_1AC4(Village* self, float delta) {
    switch (((unsigned char*)self)[0x1D9]) {
    case 0:
    case 1:
        return;
    default:
        break;
    }
    Params* p = self->params;
    if (p != 0) {
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
