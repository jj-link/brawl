#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_8005D5C8();
extern "C" void* g_efScreen;

extern "C" void fn_8005D558() {
    if (g_efScreen == 0) {
        void* result = __nw__FUlQ25Heaps8HeapType(0x1ec, 2);
        if (result != 0) {
            fn_8005D5C8();
        }
        g_efScreen = result;
    }
}
