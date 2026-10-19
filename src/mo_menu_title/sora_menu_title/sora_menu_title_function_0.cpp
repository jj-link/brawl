#pragma force_active on
extern "C" {
extern unsigned char g_gfShutdownManager[];
void fn_24_44();
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

void fn_24_0() {
    g_gfShutdownManager[12] = 1;
    void* p = __nw__FUlQ25Heaps8HeapType(0x1dc, 0x2a);
    if (p) {
        fn_24_44();
    }
}
}
