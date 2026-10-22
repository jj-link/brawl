#pragma force_active on
extern "C" {
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void fn_8004B060(void*, int);
void* memset(void* s, int c, unsigned long n);

void* fn_8004AFB4(void* arg0, int arg1, unsigned long arg2) {
    char* base = (char*)arg0;
    *(unsigned long*)(base + 0x34) = arg2;
    *(void**)(base + 0x24) = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(arg1, arg2);
    memset(*(void**)(base + 0x24), 0, *(unsigned long*)(base + 0x34));
    memset(base + 0x4c, 0, 0x34);
    *(short*)(base + 0x30) = 0;
    *(short*)(base + 0x38) = 0;
    *(int*)(base + 0x28) = 0;
    *(int*)(base + 0x2c) = (int)((char*)*(void**)(base + 0x24) + *(unsigned long*)(base + 0x34));
    memset(base + 4, 0, 0x20);
    *(int*)(base + 0) = 0;
    *(int*)(base + 0x3c) = 0;
    *(int*)(base + 0x40) = 0;
    fn_8004B060(arg0, 3);
    return arg0;
}
}
