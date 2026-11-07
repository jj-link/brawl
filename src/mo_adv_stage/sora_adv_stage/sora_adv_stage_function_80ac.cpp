#include <types.h>
#pragma force_active on

extern "C" void* getData__9gfArchiveF11ARCNodeTypeiPiUs(void* self, int type, int id, int* size, u16 flags);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
extern "C" void* __ct__9gfArchiveFv(void* self);
extern "C" void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void* self, void* data, int size, int heap);

extern "C" void fn_40_80AC(u8* self, void** out) {
    if (*(void**)(self + 0x220) == nullptr) {
        int size;
        void* data = getData__9gfArchiveF11ARCNodeTypeiPiUs(*(void**)(self + 0x1b0), 1, 0x17, &size, 0xFFFE);
        void* arc = __nw__FUlQ25Heaps8HeapType(0x80, 0xF);
        if (arc != nullptr) {
            arc = __ct__9gfArchiveFv(arc);
        }
        *out = arc;
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(arc, data, size, 0x11);
        *(void**)(self + 0x220) = *out;
        return;
    }
    *out = *(void**)(self + 0x220);
}
