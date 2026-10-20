#pragma force_active on
struct FZero {
    unsigned char padding[0x1E2];
    unsigned char state;
};

extern "C" bool fn_61_20C0(FZero* self) {
    switch (self->state) {
    case 1:
    case 2:
        return true;
    default:
        return false;
    }
}
