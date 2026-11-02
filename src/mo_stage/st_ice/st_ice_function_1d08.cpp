#pragma force_active on
extern const float lbl_62_rodata_0;
extern const float lbl_62_rodata_40;
extern "C" float randf__Fv();

struct Params {
    char pad[0xb8];
    float a;
    float b;
};

struct Ice {
    char pad[0x9c];
    Params* params;
    char pad2[0x438 - 0xa0];
    unsigned char unk438;
    char pad3[0x4be - 0x439];
    unsigned char state;
    char pad4;
    float timer;
    unsigned char unk4C4;
    unsigned char unk4C5;
};

extern "C" void fn_62_1D08(Ice* self, float delta) {
    Params* p = self->params;
    if (p) {
        self->timer -= delta;
        if (self->timer < lbl_62_rodata_0)
            self->timer = lbl_62_rodata_0;

        switch (self->state) {
        case 0:
            self->state = 1;
            break;
        case 1:
            if (self->unk438 == 3) {
                float t = p->a + (p->b - p->a) * randf__Fv();
                self->state = 2;
                self->timer = t;
            }
            break;
        case 2:
            if (lbl_62_rodata_0 == self->timer) {
                if (randf__Fv() < lbl_62_rodata_40)
                    self->unk4C4 = 5;
                else
                    self->unk4C5 = 5;
                self->state = 3;
            }
            break;
        case 3:
            if (self->unk4C4 == 14 && self->unk4C5 == 14)
                self->state = 0;
            break;
        }
    }
}
