#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value;
};

extern "C" int fn_27_CF824(const Data* self) {
    return static_cast<int>((self->value << 6) & 0xFE000000u) >> 26;
}
