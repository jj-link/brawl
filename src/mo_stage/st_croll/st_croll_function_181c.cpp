#pragma force_active on
extern "C" {
extern float lbl_90_data_282C[7];
extern float lbl_90_rodata_38;
struct Croll {
    char pad0[0x204];
    int mode;
    char pad208[0x9C];
    float speed;
    char pad2A8[0x34];
    float position;
    char pad2E0[0xC];
    float thresholds[7];
    float pad308;
    float factor;
};
void fn_90_181C(Croll* self, float delta) {
    float position = self->position;
    int index;
    for (index = 5; index > 1; --index) {
        if (position <= self->thresholds[index]) {
            break;
        }
    }
    float ratio = (self->position - self->thresholds[index]) /
        (self->thresholds[index + 1] - self->thresholds[index]);
    float value = lbl_90_data_282C[index] +
        ratio * (lbl_90_data_282C[index + 1] - lbl_90_data_282C[index]);
    self->factor = value;
    delta *= value * self->speed;
    if (self->mode != 0) {
        delta *= lbl_90_rodata_38;
    }
    self->position += delta;
}
}
