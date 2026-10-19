#include <types.h>
#pragma force_active on

namespace Heaps {
    enum HeapType { };
}

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, Heaps::HeapType);
extern "C" void fn_27_22C3B0();

extern "C" void fn_27_22C37C() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1c94, (Heaps::HeapType)0xf);
    if (p != 0) {
        fn_27_22C3B0();
    }
}
