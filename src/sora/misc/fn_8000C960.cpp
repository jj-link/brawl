#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8000C9D8(void*);
extern "C" void* g_gfSceneRoot;

extern "C" void fn_8000C960() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x50C, 0x2);
    if (obj != 0) {
        obj = fn_8000C9D8(obj);
    }
    g_gfSceneRoot = obj;
}
