#pragma force_active on
typedef struct {
    int field0;
    int field4;
    int field8;
    int *arr;
} FtGanonWork;

extern "C" void fn_109_92CC(FtGanonWork *work, int index)
{
    work->arr[index]--;
}
