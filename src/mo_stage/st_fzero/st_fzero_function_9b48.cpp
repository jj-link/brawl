#pragma force_active on
typedef unsigned int u32;

struct FzeroFloatHolder {
    char pad[0x520];
    float* m_floats;
};

extern "C" float fn_61_9B48(const FzeroFloatHolder* self, u32 index) {
    return self->m_floats[index];
}
