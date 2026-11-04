#pragma force_active on
extern "C" float randf__Fv();
extern "C" const float lbl_78_rodata_0;

struct Params {
    char pad[0x14];
    float lo;
    float hi;
};

struct Dxonett {
    char pad[0x9c];
    Params* params;
    char pad2[0x2e5 - 0xa0];
    unsigned char state;
    char pad3[0x2e8 - 0x2e6];
    float timer;
    unsigned char counter;
};

extern "C" void fn_78_1128(Dxonett* self, float delta) {
    Params* p = self->params;
    if (p) {
        switch (self->state) {
        case 0:
            self->state = 1;
        case 1:
            if (self->counter == 10) {
                self->timer = p->lo + (p->hi - p->lo) * randf__Fv();
                self->state = 3;
            }
            break;
        case 3:
            self->timer -= delta;
            if (self->timer < lbl_78_rodata_0)
                self->timer = lbl_78_rodata_0;
            if (lbl_78_rodata_0 == self->timer) {
                self->counter = 100;
                self->state = 0;
            }
            break;
        }
    }
}
