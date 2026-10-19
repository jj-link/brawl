#pragma force_active on
struct Data {
    int padding[2];
    int value;
};

extern "C" int fn_62_601C(const Data* self) {
    return self->value >> 30;
}
