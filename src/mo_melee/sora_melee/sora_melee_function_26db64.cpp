#pragma force_active on
struct Inner {
    char pad[8];
    float a;
    float b;
    float c;
};

struct Holder {
    char pad[0xd4];
    Inner* inner;
};

extern "C" void fn_27_26DB64(Holder* self, const float* src) {
    Inner* in = self->inner;
    if (in == 0) {
        return;
    }
    in->a = src[3];
    in->b = src[7];
    in->c = src[11];
}
