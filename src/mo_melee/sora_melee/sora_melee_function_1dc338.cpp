#include <math.h>
#pragma force_active on

extern const float lbl_27_rodata_27E0;
extern "C" float fn_27_89794(float value, float limit);

struct State {
    char pad[8];
    float value;
    float increment;
    float limit;
};

extern "C" void fn_27_1DC338(State* self) {
    self->value += self->increment;
    if (self->value < lbl_27_rodata_27E0 &&
        self->limit > lbl_27_rodata_27E0) {
        float limitMagnitude = (float)fabs(self->limit);
        float valueMagnitude = (float)fabs(self->value);
        if (valueMagnitude > limitMagnitude) {
            self->value = fn_27_89794(self->value, self->limit);
        }
    }
}
