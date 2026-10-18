#pragma force_active on
extern "C" {
int fn_41_1AE30(void*);
void fn_41_1AF9C(void*);
extern float lbl_41_rodata_C90;
}

struct Enemy {
    unsigned char pad0[0x08];
    void* unk08;
    unsigned char padC[0x40];
    float unk4C;
    unsigned char pad50[0x2C];
    float unk7C;
};

extern "C" void fn_41_1F060(Enemy* self) {
    self->unk7C = lbl_41_rodata_C90 * self->unk7C;
    if (fn_41_1AE30(self->unk08) == 1) {
        fn_41_1AF9C(self);
        self->unk4C = -self->unk4C;
    }
}
