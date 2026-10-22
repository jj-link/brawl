#include <types.h>
#pragma force_active on

struct Obj {
    u8 pad0[0x40];
    void* field40;
    u8 pad44[8];
    int field4C;
    u8 pad50[4];
    void* field54;
    int field58;
    u8 pad5C[0x465 - 0x5C];
    u8 flags;
};

extern "C" void fn_801AC6EC(void*);
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
extern "C" void* fn_8019CA18(void*, int*, int*, int);
extern "C" void fn_8000D3EC(Obj*, void*);

extern "C" void fn_8000D2E0(Obj* self, int* resource, int heap) {
    if (*resource != 0) {
        if (self->field54 != 0) {
            fn_801AC6EC(self->field40);
            Destroy__Q34nw4r3g3d6G3dObjFv(self->field54);
        }
        if (self->field4C != 0) {
            self->field4C = 0;
        }
        self->field54 = 0;
        self->field58 = 0;
        self->field4C = *resource;

        void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(heap);
        int size;
        int res = *resource;
        void* obj = fn_8019CA18(allocator, &size, &res, 0);
        self->field54 = obj;
        fn_8000D3EC(self, obj);
    } else {
        if (self->field54 != 0) {
            fn_801AC6EC(self->field40);
            Destroy__Q34nw4r3g3d6G3dObjFv(self->field54);
        }
        if (self->field4C != 0) {
            self->field4C = 0;
        }
        self->field54 = 0;
        self->field58 = 0;
        self->flags &= ~0x40;
    }
}
