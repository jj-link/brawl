#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern "C" {
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, int, int, void*);
}
extern "C" void fn_31_1C74(u8* self, u8* data, s32 count) {
    s32 limit = count;
    u8* base = self;
    self = (u8*)getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2a);
    for (count = 0; count < limit; count++, data += 4) {
        s32 n = 1;
        if ((u32)data[0] < (u32)data[1]) {
            n = (s32)((u32)data[1] - (u32)data[0] + 1);
        }
        for (s32 j = 0; j < n; j++) {
            void* entry = *(void**)(base + (((u32)data[2] + (u32)j) << 2) + 0x1c4);
            void* r = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(self, 0, (s32)data[3], *(void**)((u8*)entry + 0x10));
            *(void**)(base + (((u32)data[0] + (u32)j) << 2) + 0x48c) = r;
        }
    }
}