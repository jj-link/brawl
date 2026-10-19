#pragma force_active on
extern "C" float randf__Fv();
extern const float lbl_63_rodata_0[];

struct State {
    unsigned char pad[0x1E0];
    unsigned char current;
    unsigned char choice;
    unsigned char first;
    unsigned char second;
};

extern "C" void fn_63_2240(State* self) {
    const float* values = lbl_63_rodata_0;
    if (self->first == 4 && self->second == 4) {
        float value = randf__Fv();
        if (value < values[6]) {
            self->choice = 1;
        } else if (value < values[7]) {
            self->choice = 2;
        } else {
            self->choice = 3;
        }

        value = randf__Fv();
        switch (self->choice) {
        case 1:
            if (value < values[8]) {
                self->first = 2;
                self->second = 3;
            } else {
                self->first = 3;
                self->second = 2;
            }
            break;
        case 2:
            if (value < values[8]) {
                self->first = 1;
                self->second = 3;
            } else {
                self->first = 3;
                self->second = 1;
            }
            break;
        case 3:
            if (value < values[8]) {
                self->first = 1;
                self->second = 2;
            } else {
                self->first = 2;
                self->second = 1;
            }
            break;
        }
    } else {
        self->choice = self->first;
        self->first = self->second;
        self->second = 4;
    }
    self->current = self->choice;
}
