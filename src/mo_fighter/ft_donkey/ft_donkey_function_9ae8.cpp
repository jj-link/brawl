#pragma force_active on
typedef struct WorkBase {
    unsigned int pad[3];
    int *intWorks;
} WorkBase;

extern "C" void fn_92_9AE8(WorkBase *work, unsigned int index) {
    work->intWorks[index]++;
}
