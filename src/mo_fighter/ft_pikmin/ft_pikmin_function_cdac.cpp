#pragma force_active on
typedef struct FtWork {
    int pad[3];
    int *values;
} FtWork;

extern "C" void fn_113_CDAC(FtWork *work, int value, unsigned int index) {
    work->values[index] += value;
}
