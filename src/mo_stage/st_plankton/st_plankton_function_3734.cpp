#pragma force_active on
struct PlanktonEntry {
    unsigned char padding[0x20];
    unsigned char state;
    unsigned char tail[7];
};

struct Plankton {
    unsigned char padding[0x164];
    float x;
    float y;
    float z;
    PlanktonEntry* entries;
};

extern "C" const float lbl_74_rodata_B4[];

extern "C" bool fn_74_3734(Plankton* self) {
    if (lbl_74_rodata_B4[0] == self->x &&
        lbl_74_rodata_B4[0] == self->y &&
        lbl_74_rodata_B4[0] == self->z) {
        return false;
    }

    for (unsigned char i = 0; i < 6; ++i) {
        if (self->entries[i].state != 14) {
            return false;
        }
    }

    return true;
}
