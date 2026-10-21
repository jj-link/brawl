#pragma force_active on

namespace Heaps {
enum HeapType { HEAP_TYPE_2 = 2 };
}

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_80109654(void* self, void* a, void* b);

extern "C" void fn_80109600(void* a, void* b) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x148, 2);
    if (p != 0) {
        fn_80109654(p, a, b);
    }
}
