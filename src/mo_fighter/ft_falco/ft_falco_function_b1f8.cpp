#pragma force_active on
struct FloatWorkHolder {
    char pad[0x14];
    float* m_floats;
};

extern "C" void fn_108_B1F8(FloatWorkHolder* work, unsigned int index, float value) {
    work->m_floats[index] *= value;
}
