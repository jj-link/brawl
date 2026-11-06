#pragma force_active on
extern void fn_80378018(void *);

typedef struct Inner {
    char pad0[0x14];
    int unk14;
    char pad1[4];
    int unk1C;
} Inner;

typedef struct Outer {
    char pad0[8];
    Inner *unk8;
    char pad1[0x18];
    int unk24;
    char pad2[4];
    void (*unk2C)(void *, int, int, int);
} Outer;

int fn_80373B7C(Outer *self, int arg1, int arg2, int arg4) {
    int tmp;

    if (self == 0) {
        return 1;
    }
    if (self->unk2C == 0) {
        return 1;
    }
    if (arg2 == 0 || arg1 == 0) {
        arg1 = 0;
        arg2 = 0;
    }
    tmp = self->unk24;
    self->unk24 = tmp + 1;
    tmp = self->unk8->unk1C;
    self->unk8->unk1C = tmp + 1;
    self->unk2C(self, arg1, arg2, arg4);
    self->unk24--;
    self->unk8->unk1C--;
    if (self->unk8->unk14 != 0 && self->unk8->unk1C == 0) {
        fn_80378018(self->unk8);
        return 0;
    }
    return 1;
}
