#pragma force_active on
namespace Heaps {
enum HeapType { HeapType_Dummy };
}

extern "C" {
void __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(
    void*, Heaps::HeapType, Heaps::HeapType, Heaps::HeapType, long);

void* fn_27_2DA8A4(void* p, Heaps::HeapType a, Heaps::HeapType b, Heaps::HeapType c, long d) {
    __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(p, a, b, c, d);
    return p;
}
}
