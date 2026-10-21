#pragma force_active on
extern char lbl_8041F3B8[];

struct fn_803EE8E0_obj {
    void *unk0;
    int unk4;
};

int fn_803EE8E0(struct fn_803EE8E0_obj *self, int arg) {
    self->unk4 = arg;
    self->unk0 = lbl_8041F3B8;
    return 0;
}
