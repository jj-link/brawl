#pragma force_active on
typedef unsigned int u32;

struct FnWork0x520 {
    char pad[0x520];
    float *values;
};

extern "C" float fn_63_10A44(const FnWork0x520 *self, u32 index) {
    return self->values[index];
}
