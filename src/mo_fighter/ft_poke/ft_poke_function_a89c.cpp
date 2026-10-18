#pragma force_active on
struct FtPokeWork {
    char pad[0x14];
    float* m_values;
};

extern "C" void fn_116_A89C(FtPokeWork* work, unsigned int index, float value) {
    work->m_values[index] += value;
}
