#pragma force_active on
typedef struct {
    int pad[3];
    int *arr;
} FtYoshiWork;

extern "C" void fn_95_B968(FtYoshiWork *work, int value, unsigned int index)
{
    work->arr[index] -= value;
}
