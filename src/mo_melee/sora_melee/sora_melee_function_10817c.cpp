#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_1081D4(void* a, void* b, void* c);
void fn_27_10FB5C();
void fn_27_1E8590(int);
extern void* g_ftSystem[2];
extern void* g_ftManager;
}

extern "C" void fn_27_10817C() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x160, 2);
    if (p != 0) {
        p = fn_27_1081D4(p, g_ftSystem[0], g_ftSystem[1]);
    }
    g_ftManager = p;
    fn_27_10FB5C();
    fn_27_1E8590(0);
}
