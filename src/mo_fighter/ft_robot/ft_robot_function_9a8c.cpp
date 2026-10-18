#pragma force_active on
typedef struct FtRobotWork {
    unsigned char pad[0x14];
    float *m_floatWorks;
} FtRobotWork;

extern "C" void fn_120_9A8C(FtRobotWork *work, unsigned int index, float value)
{
    work->m_floatWorks[index] *= value;
}
