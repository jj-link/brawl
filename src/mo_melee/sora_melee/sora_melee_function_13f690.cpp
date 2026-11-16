#pragma force_active on
#include <so/so_heap_module_impl.h>
#include <ft/ft_common_data_accesser.h>

struct FtSelf {
    char pad[0x110];
    soHeapModuleImpl* unk110;
    void* unk114;
};

struct Local {
    int* ptr;
    soHeapModuleImpl* heap;
    int zero;
    int neg;
};

extern "C" void* fn_27_149B64(void*);
extern "C" void* fn_27_1E2560(void*, int, void*, void*);

extern "C" void fn_27_13F690(FtSelf* self, Heaps::HeapType heap, Heaps::HeapType a, Heaps::HeapType b) {
    if (self->unk110 == 0 && self->unk114 == 0) {
        self->unk110 = new (heap) soHeapModuleImpl(heap, a, b, 0);
        void* r31 = operator new(0x9ec, heap);
        if (r31 != 0) {
            Local loc;
            soHeapModuleImpl* h = self->unk110;
            loc.zero = 0;
            loc.neg = -1;
            loc.ptr = &loc.zero;
            loc.heap = h;
            r31 = fn_27_1E2560(r31, -1, &loc, fn_27_149B64(&g_ftCommonDataAccesser));
        }
        self->unk114 = r31;
    }
}