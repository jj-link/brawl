#pragma force_active on
typedef unsigned int u32;

struct FtRobotWork {
    char pad[0x14];
    float *floatWorks;
};

extern "C" void fn_120_9ABC(FtRobotWork *work, u32 index, float value) {
    work->floatWorks[index] += value;
}
