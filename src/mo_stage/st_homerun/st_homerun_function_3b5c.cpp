#pragma force_active on
extern "C" const float lbl_88_rodata_0[];

struct HomeRun {
    unsigned char pad[0x1D8];
    unsigned char state;
    unsigned char pad2[0xF];
    float value;
};

extern "C" bool fn_88_3B5C(HomeRun* self) {
    switch (self->state) {
    case 10:
        if (lbl_88_rodata_0[0] == self->value)
            return true;
        break;
    }
    return false;
}
