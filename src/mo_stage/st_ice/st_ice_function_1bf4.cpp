#pragma force_active on
extern const float lbl_62_rodata_0;
extern "C" float randf__Fv();

struct Params {
    char pad[0x74];
    float a;
    float b;
};

struct Ice {
    char pad[0x9c];
    Params* params;
    char pad2[0x438 - 0xa0];
    unsigned char unk438;
    char pad3[0x4b5 - 0x439];
    unsigned char state;
    char pad4[2];
    float timer;
    unsigned char unk4BC;
    unsigned char unk4BD;
};

extern "C" void fn_62_1BF4(Ice* self, float delta) {
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
            if (self->unk438 == 1) {
                self->timer = p->a + (p->b - p->a) * randf__Fv();
                self->state = 2;
            }
            break;
        case 2:
            if (lbl_62_rodata_0 == self->timer) {
                self->unk4BC = 5;
                self->unk4BD = 5;
                self->state = 3;
            }
            break;
        case 3:
            if (self->unk4BC == 14 && self->unk4BD == 14)
                self->state = 0;
            break;
        }
    }
}