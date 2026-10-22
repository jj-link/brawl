#pragma force_active on

extern "C" void fn_8002BBA4(void* self, void* p);
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int heap, unsigned long size);
extern "C" void free__13gfHeapManagerFPv(void* p);
extern "C" void fn_8002C8C0(void* self, int size, void* buf);
extern char lbl_80422EA8[];

extern "C" void fn_8002BB1C(void* arg0, int arg1, int arg2) {
    int size;
    *(int*)((char*)arg0 + 0x80) = arg1;
    fn_8002BBA4(arg0, lbl_80422EA8);
    size = arg2 * 8;
    if (*(void**)((char*)arg0 + 0xEC) != 0) {
        free__13gfHeapManagerFPv(*(void**)((char*)arg0 + 0xEC));
        *(void**)((char*)arg0 + 0xEC) = 0;
    }
    if (size != 0) {
        *(void**)((char*)arg0 + 0xEC) = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(7, (unsigned long)size << 5);
    }
    fn_8002C8C0(arg0, size, *(void**)((char*)arg0 + 0xEC));
}
