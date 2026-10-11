#include <sr/sr_common.h>

extern "C" void* fn_111_70(void* object, int entry, Heaps::HeapType heap, void* parameter, void* context);

extern "C" void* fn_111_C540(void*, int entry, Heaps::HeapType heap, void* parameter, void* context) {
    void* object = operator new(0xA610, heap);
    if (object) {
        return fn_111_70(object, entry, heap, parameter, context);
    }
    return object;
}
