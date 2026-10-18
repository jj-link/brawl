#pragma force_active on
typedef struct FtKoopaWork {
    int pad[5];
    float *values;
} FtKoopaWork;

extern "C" void fn_102_9200(FtKoopaWork *work, unsigned int index, float value)
{
    work->values[index] -= value;
}
