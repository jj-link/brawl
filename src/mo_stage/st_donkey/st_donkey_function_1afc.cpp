#pragma force_active on
extern "C" const float lbl_50_rodata_0;
extern "C" const double lbl_50_rodata_50;
extern "C" float randf__Fv();

struct Params {
    char pad[0x18];
    float a18, a1c, a20, a24, a28, a2c, a30, a34, a38;
};

struct Donkey {
    char pad[0x9c];
    Params* params;
    char pad2[0x3f8 - 0xa0];
    unsigned char active;
    char pad3[0x408 - 0x3f9];
    unsigned char state;
    char pad4[3];
    float t1;
    float t2;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
};

extern "C" void fn_50_1AFC(Donkey* self, float delta) {
    if (self->active == 3) {
        Params* p = self->params;
        if (p) {
            self->t1 -= delta;
            if (self->t1 < lbl_50_rodata_0)
                self->t1 = lbl_50_rodata_0;
            self->t2 -= delta;
            if (self->t2 < lbl_50_rodata_0)
                self->t2 = lbl_50_rodata_0;

            switch (self->state) {
            case 0:
                self->b14 = 6;
                self->b15 = 6;
                if (self->b16 == 1) {
                    self->t1 = p->a18 + (p->a1c - p->a18) * randf__Fv();
                    self->b16 = 0;
                } else {
                    self->t1 = p->a20 + (p->a24 - p->a20) * randf__Fv();
                }
                self->state = 1;
                break;
            case 1:
                if (lbl_50_rodata_0 == self->t1) {
                    if (randf__Fv() < p->a28) {
                        self->t1 = p->a2c + (p->a30 - p->a2c) * randf__Fv();
                        self->state = 2;
                        self->t2 = lbl_50_rodata_0;
                    } else {
                        self->state = 0;
                    }
                }
                break;
            case 2:
                if (lbl_50_rodata_0 == self->t1) {
                    self->state = 3;
                } else if (lbl_50_rodata_50 == self->t2) {
                    if (self->b14 == 6) {
                        self->b14 = 3;
                    } else if (self->b15 == 6) {
                        self->b15 = 3;
                    } else {
                        return;
                    }
                    self->t2 = p->a34 + (p->a38 - p->a34) * randf__Fv();
                }
                break;
            case 3:
                if (self->b14 == 6 && self->b15 == 6)
                    self->state = 0;
                break;
            }
        }
    }
}
