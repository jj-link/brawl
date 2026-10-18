#pragma force_active on
extern const float lbl_62_rodata_0;
extern "C" float randf__Fv();

struct Params {
    char pad[0x28];
    float a, b, c, d, e;
};

struct Ice {
    char pad[0x9c];
    Params* params;
    char pad2[0x426];
    unsigned char state;
    char pad3;
    float timer;
    unsigned char motion;
    char pad4[3];
    float count;
};

extern "C" void fn_62_1A74(Ice* self, float delta) {
    Params* p = self->params;
    if (p) {
        self->timer -= delta;
        if (self->timer < lbl_62_rodata_0)
            self->timer = lbl_62_rodata_0;

        switch (self->state) {
        case 0:
            self->timer = p->a + (p->b - p->a) * randf__Fv();
            self->count = p->e;
            self->state = 1;
            break;
        case 1:
            if (lbl_62_rodata_0 == self->count) {
                self->motion = 14;
                self->state = 0;
            } else if (lbl_62_rodata_0 == self->timer) {
                switch (self->motion) {
                case 14:
                    self->motion = 8;
                    break;
                case 8:
                    self->motion = 9;
                    break;
                case 9:
                    self->motion = 10;
                    break;
                case 10:
                    self->motion = 11;
                    self->state = 3;
                    break;
                }
                self->timer = p->c + (p->d - p->c) * randf__Fv();
            }
            break;
        case 2:
            break;
        case 3:
            if (self->motion == 14)
                self->state = 0;
            break;
        }
    }
}
