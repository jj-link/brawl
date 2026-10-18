#pragma force_active on
extern "C" {

struct Fn115Work {
    char pad[0x14];
    float *m_floatWorks;
};

void fn_115_A3AC(Fn115Work *work, unsigned int index, float value)
{
    work->m_floatWorks[index] += value;
}

}
