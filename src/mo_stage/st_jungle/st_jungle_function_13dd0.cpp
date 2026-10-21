#pragma force_active on
extern "C" const float lbl_51_rodata_238;

struct Base {
    char pad[0x3c];
};

#define SLOT(n) virtual void vf##n();

struct Object : Base {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34)
    SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    virtual float* vf40();

    char pad40[0x150 - 0x40];
    unsigned char state;
    char pad151[0x15c - 0x151];
    unsigned char* command;
    char pad160[0x164 - 0x160];
    float previousTimer;
    float timer;
};

#undef SLOT

extern "C" void fn_51_13DD0(Object* self, float delta) {
    if (!self->command)
        return;

    self->timer -= delta;
    if (self->timer < lbl_51_rodata_238)
        self->timer = lbl_51_rodata_238;

    float* result = self->vf40();
    if (!result)
        return;

    switch (self->state) {
    case 0:
        self->previousTimer = *result;
        *self->command = 1;
        self->state = 1;
        break;
    case 1:
        break;
    case 9:
        if (*self->command == 4) {
            *self->command = 0;
            self->state = 0;
        }
        break;
    }
}
