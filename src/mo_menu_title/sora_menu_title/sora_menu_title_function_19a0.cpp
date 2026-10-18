#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);

extern const char lbl_24_data_628[];
extern const char lbl_24_data_714[];

extern "C" void* fn_24_19A0() {
    void* task = __nw__FUlQ25Heaps8HeapType(0x80, 0x2a);
    if (task != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
            task, lbl_24_data_628, 8, 0x0f, 8, true);
        *(void**)((char*)task + 0x3c) = (void*)lbl_24_data_714;
        *(int*)((char*)task + 0x40) = 0;
        *(int*)((char*)task + 0x44) = 0;
        *(int*)((char*)task + 0x48) = 0;
        *(int*)((char*)task + 0x4c) = 0;
        *(int*)((char*)task + 0x5c) = 0;
    }
    return task;
}
