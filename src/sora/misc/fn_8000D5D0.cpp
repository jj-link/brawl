#include <types.h>
#pragma force_active on

struct Obj {
    u8 pad0[0x40];
    void* field40;
    u8 pad44[0x10];
    void* field54;
    u8 pad58[8];
    void* field60;
    u8 pad64[0x40];
};

extern "C" void fn_801AC6EC(void*);
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
extern "C" void* fn_8019CA18(void*, int*, int*, int);
extern "C" void fn_8000D3EC(Obj*, void*);

extern "C" void fn_8000D5D0(Obj* self, int* resource) {
    if (self->field60 != 0) {
        if (self->field60 != 0) {
            fn_801AC6EC(self->field40);
            Destroy__Q34nw4r3g3d6G3dObjFv(self->field60);
        }
        self->field60 = 0;
        if (self->field54 != 0) {
            fn_8000D3EC(self, self->field54);
        }
    }
    if (*resource != 0) {
        void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x1f);
        int size;
        int res = *resource;
        void* obj = fn_8019CA18(allocator, &size, &res, 0);
        self->field60 = obj;
        fn_8000D3EC(self, obj);
    }
}
