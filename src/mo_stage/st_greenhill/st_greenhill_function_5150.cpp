#pragma force_active on
struct Data {
    unsigned char padding[8];
    int value;
};

extern "C" int fn_72_5150(Data* self) {
    return self->value >> 30;
}
