#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern "C" char lbl_22_data_278[];
extern "C" char lbl_22_data_310[];

extern "C" void* fn_22_1688() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x174, 0x2A);
    if (obj != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(obj, lbl_22_data_278, 8, 0xF, 8, true);
        *(void**)((char*)obj + 0x3C) = lbl_22_data_310;
        *(int*)((char*)obj + 0x154) = 0;
        *(int*)((char*)obj + 0x158) = 0;
        *(int*)((char*)obj + 0x40) = 0;
        *(int*)((char*)obj + 0x150) = 0;
        *(int*)((char*)obj + 0x15C) = 0;
        *(int*)((char*)obj + 0x164) = 0;
        *(int*)((char*)obj + 0x168) = 0;
        *(int*)((char*)obj + 0x16C) = 0;
    }
    return obj;
}
