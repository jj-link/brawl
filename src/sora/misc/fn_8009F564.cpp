#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8009F5AC();
extern void* g_cmAIController;

extern "C" void* fn_8009F564() {
    if (g_cmAIController == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x198, 2);
        if (p != 0) {
            p = fn_8009F5AC();
        }
        g_cmAIController = p;
    }
    return g_cmAIController;
}
