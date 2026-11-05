#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__9gfArchiveFv(void*);
extern "C" void __dt__9gfArchiveFv(void*, int);
extern "C" void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void*, void*, int, int);
extern "C" void* getData__9gfArchiveF11ARCNodeTypeiPiUs(void*, int, int, int*, unsigned short);

extern "C" void fn_1_3F84(void* arg0, void* arg1, int arg2) {
    char* p = (char*)arg0;
    int sp8;
    void* archive;
    unsigned char flags;
    void* data;

    flags = *(unsigned char*)(p + 0x1C);
    if (!(((flags >> 5) & 1) && ((flags >> 7) & 1))) {
        return;
    }

    archive = __nw__FUlQ25Heaps8HeapType(0x80, *(int*)(p + 0x14));
    if (archive != 0) {
        archive = __ct__9gfArchiveFv(archive);
    }
    setFileImage__9gfArchiveFPviQ25Heaps8HeapType(archive, *(void**)(p + 0x10), *(int*)(p + 0x0C), *(int*)(p + 0x14));

    flags = *(unsigned char*)(p + 0x1C);
    if (((flags >> 5) & 1) && ((flags >> 7) & 1)) {
        data = getData__9gfArchiveF11ARCNodeTypeiPiUs(archive, 1, arg2, &sp8, 0xFFFE);
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(arg1, data, sp8, *(int*)(p + 0x14));
    }
    __dt__9gfArchiveFv(archive, 1);
}
