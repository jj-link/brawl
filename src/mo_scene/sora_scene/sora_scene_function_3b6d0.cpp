#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_97F0[];
extern "C" char lbl_1_data_98FC[];

extern "C" void* fn_1_3B6D0() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x14, 0x2E);
    if (obj) {
        *(void**)obj = lbl_1_data_97F0;
        *(void**)((char*)obj + 4) = lbl_1_data_98FC;
        *(int*)((char*)obj + 8) = 0;
    }
    return obj;
}
