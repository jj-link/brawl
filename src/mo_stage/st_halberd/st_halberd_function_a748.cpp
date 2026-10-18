#pragma force_active on
struct Data {
    unsigned char padding[8];
    int value;
};

extern "C" int fn_57_A748(const Data* self) {
    return self->value >> 29;
}
