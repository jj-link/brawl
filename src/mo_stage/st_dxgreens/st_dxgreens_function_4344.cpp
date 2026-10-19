#pragma force_active on
struct Data {
    unsigned char padding[8];
    int value;
};

extern "C" int fn_79_4344(const Data* self) {
    return self->value >> 26;
}
