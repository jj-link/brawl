#pragma force_active on
typedef unsigned int u32;

struct FnStub54 {
    char pad[0x75c];
    float *values;
};

extern "C" float fn_54_E3FC(const FnStub54 *self, u32 index) {
    return self->values[index];
}
