#pragma force_active on
extern "C" {
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);

void* fn_80116E94(void* p, int arg1) {
    char* obj = (char*)p;
    unsigned long size = arg1 << 4;
    *(short*)(obj + 0x18) = arg1;
    *(short*)(obj + 0x10) = 0;
    *(unsigned char*)(obj + 0x12) = 7;
    *(unsigned char*)(obj + 0x13) = *(unsigned char*)(obj + 0x13) | 0x80;
    *(short*)(obj + 0x1a) = 0;
    *(void**)(obj + 0x1c) = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(12, size);
    gfMemFill__FPvUcUl(*(void**)(obj + 0x1c), 0, size);
    return p;
}
}
