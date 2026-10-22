#pragma force_active on

typedef struct Context {
    unsigned char pad0[0x10];
    int unk10;
    unsigned char pad14[0x8];
    int unk1C;
    unsigned char pad20[0x1C];
    int unk3C;
    unsigned char pad40[0xE0];
    int unk120;
    unsigned char pad124[0x8C];
    int unk1B0;
} Context;

extern int fn_8035D560(int);
extern void fn_8037BDD4(Context *, int, int);

void fn_80380D60(Context *self) {
    unsigned int result;

    result = fn_8035D560(self->unk1B0);
    self->unk1C = result;
    if (result + 0x10000 == 0xFFFF) {
        self->unk1B0 = 0;
        self->unk120 = 1;
        self->unk3C = 4;
        return;
    }
    if (result == 0) {
        self->unk10 = 2;
        fn_8037BDD4(self, 0, 0);
        return;
    }
    self->unk1B0 = 0;
    self->unk10 = 3;
    fn_8037BDD4(self, 0, 0);
}
