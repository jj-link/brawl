#pragma force_active on
extern "C" {
void fn_8006271C(void*);
void renderXlu__10ecTraceMgrFv(void*);
void* getHeap__13gfHeapManagerFQ25Heaps8HeapType(int);

void fn_8005F668(void* self) {
    char* p = (char*)self;
    renderXlu__10ecTraceMgrFv(p + 0x98);

    if (*(int*)(p + 0x6C)) {
        unsigned i = (unsigned)*(int*)(p + 0x70);
        char* ptr = (char*)(*(int*)(p + 0x60)) + i * 0x84;
        for (; i <= (unsigned)*(int*)(p + 0x74); i++, ptr += 0x84) {
            if (*(int*)(ptr + 0x7C)) {
                fn_8006271C(ptr);
            }
        }
    }

    if (*(unsigned char*)(p + 0x40)) {
        getHeap__13gfHeapManagerFQ25Heaps8HeapType(3);
    }
}
}
