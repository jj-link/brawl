#include <types.h>
#pragma force_active on

extern "C" {
void* getBuffer__14gfFileIOHandleCFv(const void*);
void getPrintIndexData__7MessageFPvUlPPcPUl(void*, unsigned long, char**, unsigned long*);
void* memcpy(void*, const void*, unsigned long);

void fn_5_1307C(char* a, char* b) {
    unsigned long size;
    char* buf;
    void* data = getBuffer__14gfFileIOHandleCFv(*(char**)(a + 0x1ac) + 0x1c90);
    getPrintIndexData__7MessageFPvUlPPcPUl(data, 7, &buf, &size);
    unsigned long sz = size;
    unsigned long off = *(unsigned long*)(b + 0x80);
    memcpy(b + off, buf, sz);
    *(unsigned long*)(b + 0x80) = off + sz;
}
}
