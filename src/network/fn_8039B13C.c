#pragma force_active on
typedef unsigned int u32;

struct Fn39Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

int fn_8039B13C(struct Fn39Obj *self, u32 *out) {
    if (!(self->unk4 & 0x200)) {
        return -7;
    }
    *out = self->unk8;
    return 0;
}
