#pragma force_active on
struct Result {
    float values[16];
};

struct Object {
    unsigned int unused;
    void* data;
    unsigned char padding[0x14];
    float value;
};

extern "C" {
extern const float lbl_27_rodata_400;
extern const float lbl_27_rodata_404;

void fn_801341D8(void*, Result*);

float fn_27_301D8(const Object* self) {
    if (lbl_27_rodata_400 != self->value) {
        Result result;
        fn_801341D8(self->data, &result);
        return (result.values[3] - result.values[5]) / self->value;
    }
    return lbl_27_rodata_404;
}
}
