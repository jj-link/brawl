#pragma force_active on
struct Data {
    unsigned char padding[8];
    int value;
};

extern "C" int fn_62_EFB8(const Data* self) {
    return self->value >> 30;
}
