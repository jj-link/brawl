#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800729B0(void);
extern void* g_sndSystem;

extern "C" void* fn_80072968(void) {
    if (g_sndSystem == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0xBD0, 5);
        if (p != 0) {
            p = fn_800729B0();
        }
        g_sndSystem = p;
    }
    return g_sndSystem;
}
