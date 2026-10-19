#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" const char lbl_1_data_99AC[];
extern "C" const char lbl_1_data_9A20[];

extern "C" void* fn_1_3C1A4() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x18, 0x2E);
    if (obj) {
        *reinterpret_cast<const char**>(obj) = lbl_1_data_99AC;
        *reinterpret_cast<const char**>(static_cast<char*>(obj) + 4) = lbl_1_data_9A20;
        *reinterpret_cast<unsigned long*>(static_cast<char*>(obj) + 8) = 0;
    }
    return obj;
}
