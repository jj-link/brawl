#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);

extern char lbl_22_data_0[];
extern char lbl_22_data_1E0[];

void* fn_22_0() {
    char* obj = (char*)__nw__FUlQ25Heaps8HeapType(0x80, 0x2A);
    if (obj != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(obj, lbl_22_data_0, 8, 0xF, 8, true);
        *(char**)(obj + 0x3C) = lbl_22_data_1E0;
        *(int*)(obj + 0x60) = 0;
        *(int*)(obj + 0x64) = 0;
        *(int*)(obj + 0x40) = 0;
        *(int*)(obj + 0x4C) = 0;
        *(int*)(obj + 0x5C) = 0;
        *(int*)(obj + 0x68) = 0;
        *(int*)(obj + 0x6C) = 0;
        *(int*)(obj + 0x70) = 0;
    }
    return obj;
}
}
