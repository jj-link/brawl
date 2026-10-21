#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value;
};

extern "C" int fn_71_9FD0(const Data* self) {
    return (int)((self->value << 4) & 0xE0000000u) >> 30;
}
