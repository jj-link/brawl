#pragma force_active on
extern "C" {
extern void* g_ipSwitch;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8004A670(void*);

void* getInstance__8ipSwitchFv() {
    if (g_ipSwitch == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x28, 1);
        if (p != 0) {
            p = fn_8004A670(p);
        }
        g_ipSwitch = p;
    }
    return g_ipSwitch;
}
}
