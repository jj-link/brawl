#pragma force_active on
struct Sub {
    int a;
    int b;
    int c;
};

struct Owner {
    int unk0;
    int unk4;
    int flags;
    Sub subs[4];
};

extern "C" {
Sub* fn_27_1D0880(Owner* self, int idx) {
    int i = (self->flags >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return &self->subs[i];
}
}
