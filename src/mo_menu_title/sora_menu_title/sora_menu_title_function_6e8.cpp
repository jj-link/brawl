#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern const char lbl_24_data_230[];
extern const char lbl_24_data_298[];

void* fn_24_6E8() {
    void* task = __nw__FUlQ25Heaps8HeapType(0x54, 0x2A);
    if (task != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(task, lbl_24_data_230, 8, 15, 8, true);
        *(const char**) ((char*) task + 0x3C) = lbl_24_data_298;
        *(int*) ((char*) task + 0x40) = 0;
        *(int*) ((char*) task + 0x44) = 0;
        *(int*) ((char*) task + 0x48) = 0;
        *(int*) ((char*) task + 0x4C) = 0;
    }
    return task;
}
}
