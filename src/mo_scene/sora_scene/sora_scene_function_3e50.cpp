#include <types.h>
#pragma force_active on

extern "C" bool isReady__14gfFileIOHandleCFv(const void*);
extern "C" int CXGetUncompressedSize(int);
extern "C" int CXUncompressLZ(int, void*);
extern "C" void* DCFlushRange(void*, int);
extern "C" void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void*, void*, int, int);

extern "C" int fn_1_3E50(void* arg0) {
    char* p = (char*)arg0;
    unsigned state = *(unsigned char*)(p + 0x1C);
    if (((state >> 5) & 1) == 0) return 0;
    if (((state >> 7) & 1) == 1) return 1;
    if (!isReady__14gfFileIOHandleCFv(arg0)) return 0;
    *(int*)(p + 0x0C) = CXGetUncompressedSize(*(int*)(p + 4));
    CXUncompressLZ(*(int*)(p + 4), *(void**)(p + 0x10));
    DCFlushRange(*(void**)(p + 0x10), *(int*)(p + 0x0C));
    if (*(void**)(p + 0x18)) {
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(*(void**)(p + 0x18), *(void**)(p + 0x10), *(int*)(p + 0x0C), *(int*)(p + 0x14));
    }
    *(unsigned char*)(p + 0x1C) |= 0x80;
    return 1;
}
