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
    char pad1[12];
    int unk18;
    char pad2[8];
    int unk24;
    void (*unk28)(void *, int, int, int);
} Outer;

int fn_80373AA0(Outer *self, int arg1, int arg2, int arg3) {
    Inner *inner;
    int tmp;

    if (self == 0) {
        return 1;
    }
    self->unk18 = arg1;
    if (self->unk28 == 0) {
        return 1;
    }
    if (arg3 == 0 || arg2 == 0) {
        arg2 = 0;
        arg3 = 0;
    }
    tmp = self->unk24;
    inner = self->unk8;
    self->unk24 = tmp + 1;
    tmp = inner->unk1C;
    inner->unk1C = tmp + 1;
    self->unk28(self, arg1, arg2, arg3);
    self->unk24--;
    inner = self->unk8;
    inner->unk1C--;
    inner = self->unk8;
    if (inner->unk14 != 0 && inner->unk1C == 0) {
        fn_80378018(self->unk8);
        return 0;
    }
    return 1;
}