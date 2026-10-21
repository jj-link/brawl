#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" int fn_71_A034(const Data* self) {
    return (int)((self->flags << 2) & 0xE0000000u) >> 30;
}
