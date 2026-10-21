#pragma force_active on
namespace Heaps {
enum HeapType { HEAP_DEFAULT = 0 };
}

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, Heaps::HeapType);
extern "C" void fn_801334A4(void* p, void* a, void* b);

extern "C" void fn_8013344C(Heaps::HeapType heap, void* a, void* b) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x27C, heap);
    if (p != 0) {
        fn_801334A4(p, a, b);
    }
}
