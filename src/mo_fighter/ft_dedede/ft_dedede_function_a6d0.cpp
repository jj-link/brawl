#pragma force_active on
struct DededeFlags {
    unsigned char padding[0x1C];
    unsigned int* words;
};

extern "C" bool fn_117_A6D0(DededeFlags* self, unsigned int mask, unsigned int index) {
    return (mask & self->words[index]) != 0;
}
