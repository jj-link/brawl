#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_80022AC8();
extern "C" void* g_gfFileIOManager;

extern "C" void* fn_80022A90() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x9c, 1);
    if (obj != 0) {
        fn_80022AC8();
    }
    return g_gfFileIOManager;
}
