#pragma force_active on

struct Timing {
    float delay;
    float first;
    float second;
};

struct Target {
    unsigned char pad[0x2C];
    unsigned char state;
};

struct Object {
    unsigned char pad[0xC];
    float elapsed;
    unsigned char active;
    Timing* timing;
    Target* target;
};

extern "C" {
extern const float lbl_27_rodata_3920;
extern float lbl_27_data_547E0;
void fn_27_2346EC(void*, unsigned char);
}

extern "C" void fn_27_2371C0(Object* self) {
    Timing* timing = self->timing;
    float delay = timing->delay;
    if (delay > lbl_27_rodata_3920) {
        float step = lbl_27_data_547E0;
        timing->delay = delay - step;
        return;
    }
    if (self->active != 0) {
        if (self->target->state == 1) {
            if (self->elapsed >= timing->first) {
                if (lbl_27_rodata_3920 == timing->second) {
                    self->active = 0;
                }
                fn_27_2346EC(self->target, 0);
                self->elapsed = lbl_27_rodata_3920;
            }
        } else {
            if (self->elapsed >= timing->second) {
                if (lbl_27_rodata_3920 == timing->first) {
                    self->active = 0;
                }
                fn_27_2346EC(self->target, 1);
                self->elapsed = lbl_27_rodata_3920;
            }
        }
        float elapsed = self->elapsed;
        float step = lbl_27_data_547E0;
        self->elapsed = elapsed + step;
    }
}
