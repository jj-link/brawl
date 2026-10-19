#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);

extern const char lbl_19_data_0[];
extern const char lbl_19_data_98[];

struct EndingTask {
    char base[0x3C];
    const char* data;
    int fields[7];
};

extern "C" void* fn_19_0() {
    EndingTask* task = (EndingTask*)__nw__FUlQ25Heaps8HeapType(0x5C, 0x2A);
    if (task != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(task, lbl_19_data_0, 8, 15, 8, true);
        task->data = lbl_19_data_98;
        task->fields[0] = 0;
        task->fields[1] = 0;
        task->fields[2] = 0;
        task->fields[3] = 0;
        task->fields[4] = 0;
        task->fields[5] = 0;
        task->fields[6] = 0;
    }
    return task;
}
