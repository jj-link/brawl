#pragma force_active on
struct PokeFloatHolder {
    char pad[0x14];
    float* m_floats;
};

extern "C" void fn_116_A86C(PokeFloatHolder* self, unsigned int index, float value) {
    self->m_floats[index] *= value;
}
