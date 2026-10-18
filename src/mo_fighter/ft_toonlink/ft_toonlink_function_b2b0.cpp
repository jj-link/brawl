#pragma force_active on
struct ft_toonlink_work {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" {
void fn_121_B2B0(ft_toonlink_work* work, unsigned int index, float value) {
    work->m_floatWorks[index] -= value;
}
}
