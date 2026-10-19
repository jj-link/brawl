#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern char lbl_24_data_478[];
extern char lbl_24_data_4B8[];

void* fn_24_1178() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x54, 0x2A);
    if (p != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_24_data_478, 8, 0xF, 8, true);
        *(char**)((char*)p + 0x3C) = lbl_24_data_4B8;
        *(int*)((char*)p + 0x40) = 0;
        *(int*)((char*)p + 0x4C) = 0;
    }
    return p;
}
}
