#pragma force_active on

extern "C" int fn_80260730(void*, void*, int, unsigned char, int,
                           unsigned int, void*);
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(void*, int,
                                                              unsigned long);
extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" void fn_801D76BC(void*, unsigned int);
extern "C" int fn_802608BC(void*, void*, unsigned int, void*, unsigned int,
                           unsigned char, int, unsigned int);
extern "C" void fn_801D7718(const void*, unsigned int);
extern "C" void fn_801F3194(void);

extern "C" void fn_800C7324(void* arg0, void* arg1, void* heap, int depth,
                            int heapType) {
    char work[0x1C00];
    unsigned int info[3];
    void* infoOut = info;
    unsigned int* output = (unsigned int*)arg0;
    void* buffer;
    void* file = *(void**)((char*)arg1 + 0x10);
    void* data;
    int size;
    data = *(void**)((char*)file + 8);
    size = *(int*)((char*)file + 4);
    unsigned int allocSize;

    fn_80260730(work, data, (unsigned int)size, 6, depth, 0, infoOut);
    allocSize = info[2];
    output[0] = 0;
    buffer = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(
        heap, (int)allocSize, 0x20);
    if (output[0] != 0) {
        free__13gfHeapManagerFPv((void*)output[0]);
    }
    output[0] = (unsigned int)buffer;
    output[1] = info[0];
    output[2] = info[1];
    fn_801D76BC(buffer, allocSize);
    fn_802608BC(work, data, size, (void*)output[0], allocSize, 6, depth, 0);
    fn_801D7718((const void*)output[0], allocSize);
    fn_801F3194();
}
