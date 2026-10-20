#pragma force_active on
struct Object {
    unsigned char padding[0x24];
    int value;
};

extern "C" bool fn_41_28DC8(Object* self, int value) {
    if (value == -1)
        return false;
    if (value < 0)
        return true;
    return value >= self->value;
}
