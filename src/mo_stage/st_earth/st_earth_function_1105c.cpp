#pragma force_active on
typedef unsigned char u8;

struct EarthState {
    u8 pad[8];
    u8 mode;
    u8 pad9[3];
    float first;
    float second;
};

struct Earth {
    u8 pad[0x14c];
    void* object;
    u8 pad150[0x14];
    EarthState* state;
};

struct Update {
    u8 pad[4];
    float delta;
    u8 pad8[0x2d];
    u8 side;
};

extern "C" void fn_27_26399C(void*);
extern "C" const float lbl_66_rodata_1E0[];

extern "C" void fn_66_1105C(Earth* self, void*, Update* update) {
    if (self->state) {
        float delta = update->delta;
        fn_27_26399C(self->object);

        if (update->side == 0) {
            self->state->first -= delta;
            if (self->state->first < lbl_66_rodata_1E0[0])
                self->state->first = lbl_66_rodata_1E0[0];
        } else {
            self->state->second -= delta;
            if (self->state->second < lbl_66_rodata_1E0[0])
                self->state->second = lbl_66_rodata_1E0[0];
        }

        if (lbl_66_rodata_1E0[0] == self->state->first ||
            lbl_66_rodata_1E0[0] == self->state->second)
            self->state->mode = 4;
        else
            self->state->mode = 1;
    }
}
