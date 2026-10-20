#pragma force_active on
// st_pirates: read a float work value out of the per-stage general work block.
//
// Original assembly:
//   lwz  r3, 0x520(r3)      ; r3 = work->m_floatWorks (float* stored at +0x520)
//   slwi r0, r4, 2          ; r0 = index * 4
//   lfsx f1, r3, r0         ; f1 = m_floatWorks[index]
//   blr

struct FloatWork {
    unsigned char pad[0x520];
    float *m_floatWorks;
};

extern "C" float fn_52_13658(FloatWork *work, unsigned int index)
{
    return work->m_floatWorks[index];
}
