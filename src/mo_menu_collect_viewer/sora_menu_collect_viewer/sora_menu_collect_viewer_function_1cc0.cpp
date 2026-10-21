#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, int, int, void*);
}

extern "C" void fn_6_1CC0(u8* self, u8* data, int count) {
    void* heap = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2b);
    u8* cur = data;
    for (int i = 0; i < count; i++) {
        u8* p = *(u8**)(self + 0x1ac) + (cur[1] << 2);
        void* model = *(void**)(*(u8**)(p + 0x104) + 0x10);
        void* r = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, cur[2], model);
        u8* q = *(u8**)(self + 0x1ac) + (cur[0] << 2);
        *(void**)(q + 0x184) = r;
        cur += 3;
    }
}
