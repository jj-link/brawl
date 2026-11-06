#include <gf/gf_task.h>
#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern "C" char lbl_38_data_0[];
extern "C" char lbl_38_data_14[];
struct Args { int a, b, c, d, e; };
struct Task { char base[0x3c]; char* vtable; int f40, f44, f48, f4c, f50, f54, f58, f5c, f60; };
extern "C" Task* fn_38_0(const Args* arg) {
    Task* task = (Task*)__nw__FUlQ25Heaps8HeapType(0x74, 0x2a);
    if (task != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(task, lbl_38_data_0, 8, 15, 8, true);
        task->vtable = lbl_38_data_14;
        task->f44 = 0; task->f48 = 0; task->f60 = 0; task->f4c = 0;
    }
    int b = arg->b;
    int c = arg->c;
    task->f54 = b;
    int d = arg->d;
    task->f58 = c;
    int a = arg->a;
    task->f5c = d;
    int e = arg->e;
    task->f50 = a;
    task->f40 = e;
    if (c == 0) task->f58 = 1;
    if (task->f5c == 0) task->f5c = 1;
    return task;
}