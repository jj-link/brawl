#include <types.h>
#pragma force_active on

extern "C" int fn_801BEC18(void* self, const char* name);
extern "C" void check__12gfErrorCheckFv();
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int heapType, unsigned long size);
extern "C" s32 fn_801BEF40(void* obj, void* dst, u32 size);
extern "C" const char lbl_804543F0[];

struct sndSystem {
    u8 pad0[0x124];
    u32 field_124;
    u8 pad128[0x5C8];
    void* field_6f0;
};

extern "C" s32 loadArchiveHeader__9sndSystemFv(sndSystem* self) {
    if (fn_801BEC18(self, lbl_804543F0) == 0) {
        check__12gfErrorCheckFv();
        return 0;
    }
    u32 size = self->field_124;
    void* buf = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(5, size);
    self->field_6f0 = buf;
    if (fn_801BEF40(self, buf, size) == 0) {
        check__12gfErrorCheckFv();
        return 0;
    }
    return 1;
}
