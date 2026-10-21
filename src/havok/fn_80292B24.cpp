#pragma force_active on
struct Entry {
    float x, a, b, c, d, e;
};

struct Input {
    unsigned char flags;
    unsigned char pad[3];
    Entry entries[3];
};

struct Output {
    unsigned char pad[16];
    float values[4];
};

extern "C" void fn_80292B24(int index, int channel, Input *input, Output *output) {
    float value;
    Input *in = &input[index];
    Output *out = &output[index];

    if ((((int)in->flags >> (channel * 2)) & 3) == 1)
        value = in->entries[channel].a;
    else
        value = in->entries[channel].b;

    out->values[channel] = value;
}
