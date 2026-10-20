#pragma force_active on
struct Fn27Pair {
    float a;
    float b;
};

struct Fn27Data {
    Fn27Pair pairs[16];
    unsigned int vals[16];
    int cur;
};

extern "C" {
void fn_27_220034(Fn27Data* self, int idx, float* outPair, unsigned int* outVal)
{
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 16) {
        idx = 15;
    }

    idx = self->cur - idx;
    if (idx < 0) {
        idx += 16;
    }

    if (outPair != 0) {
        outPair[0] = self->pairs[idx].a;
        outPair[1] = self->pairs[idx].b;
    }

    if (outVal != 0) {
        *outVal = self->vals[idx];
    }
}
}
