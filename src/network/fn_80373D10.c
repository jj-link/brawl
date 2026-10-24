#pragma force_active on
typedef struct Inner {
    char pad0[0x14];
    int unk14;
    int unk18;
    int unk1C;
} Inner;

typedef struct Outer {
    char pad0[0x8];
    Inner *unk8;
    char pad1[0x18];
    int unk24;
    char pad2[0xC];
    void (*unk34)(void *, void *);
} Outer;

extern void fn_80378018(void *);

int fn_80373D10(Outer *self, void *arg1) {
    Inner *inner;
    int tmp;

    if (self == 0) {
        return 1;
    }
    if (self->unk34 == 0) {
        return 1;
    }

    tmp = self->unk24;
    inner = self->unk8;
    self->unk24 = tmp + 1;
    tmp = inner->unk1C;
    inner->unk1C = tmp + 1;
    self->unk34(self, arg1);

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
