#pragma force_active on
typedef struct {
    char pad0[0x14];
    int unk14;
    char pad18[4];
    int unk1C;
    char pad20[0x10];
    int (*unk30)(void *, void *, void *, int, int);
} Obj;

extern void fn_80378018(void *);

int fn_803740D8(Obj *self, void *arg1, void *arg2, int arg3, int arg4, int *out) {
    *out = 0;
    if (self == 0) {
        return 1;
    }
    if (self->unk30 == 0) {
        return 1;
    }
    if (arg4 == 0 || arg3 == 0) {
        arg3 = 0;
        arg4 = 0;
    }
    self->unk1C++;
    *out = self->unk30(self, arg1, arg2, arg3, arg4);
    self->unk1C--;
    if (self->unk14 != 0 && self->unk1C == 0) {
        fn_80378018(self);
        return 0;
    }
    return 1;
}