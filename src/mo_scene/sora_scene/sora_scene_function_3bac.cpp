#include <types.h>
#pragma force_active on

extern "C" {

struct FileIO {
    int    pad0;      // 0x00
    void  *compressed;// 0x04
    int    pad8;      // 0x08
    int    size;      // 0x0C
    void  *dest;      // 0x10
    int    heap;      // 0x14
    void  *archive;   // 0x18
    u8     flag;      // 0x1C
};

extern FileIO *lbl_1_bss_18;
bool isReady__14gfFileIOHandleCFv(const void*);
int  CXGetUncompressedSize(const void*);
void CXUncompressLZ(const void*, void*);
void DCFlushRange(void*, int);
void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void*, void*, int, int);

int fn_1_3BAC() {
    FileIO *p = lbl_1_bss_18;
    u32 f = p->flag;
    if (!((f >> 5) & 1)) {
        return 0;
    }
    u32 bit = (f >> 7) & 1;
    if (bit == 1) {
        return 1;
    }
    if (!isReady__14gfFileIOHandleCFv(p)) {
        return 0;
    }
    p->size = CXGetUncompressedSize(p->compressed);
    CXUncompressLZ(p->compressed, p->dest);
    DCFlushRange(p->dest, p->size);
    if (p->archive) {
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(p->archive, p->dest, p->size, p->heap);
    }
    p->flag |= 0x80;
    return 1;
}

}
