#pragma force_active on
extern "C" void* getBuffer__14gfFileIOHandleCFv(const void*);
extern "C" void getPrintIndexData__7MessageFPvUlPPcPUl(void*, unsigned long, char**, unsigned long*);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);

extern "C" void fn_5_13008(char* self, char* obj) {
    unsigned long size;
    char* data;
    void* buf = getBuffer__14gfFileIOHandleCFv(*(char**)(self + 0x1ac) + 0x1c90);
    getPrintIndexData__7MessageFPvUlPPcPUl(buf, 6, &data, &size);
    unsigned long len = size;
    unsigned int offset = *(unsigned int*)(obj + 0x80);
    memcpy(obj + offset, data, len);
    *(unsigned int*)(obj + 0x80) = offset + len;
}
