#pragma force_active on
extern const float lbl_41_rodata_18;

struct Fn41Obj {
    char pad[0x14];
    float *arr;
};

extern "C" {
void fn_41_C1A4(Fn41Obj *self, int idx, float divisor)
{
    if (lbl_41_rodata_18 == divisor) {
        return;
    }
    float *p = self->arr;
    p[idx] = p[idx] / divisor;
}
}
