#pragma force_active on

extern "C" {
extern int lbl_2_rodata_1700;
extern int lbl_2_rodata_1710;
extern int lbl_2_data_4B14;

void fn_800B96E8(void* p, int v);
void fn_2_38950(void* self, void* entries, int count, void* resFile, int flag, int offset);
void fn_2_38A54(void* self, void* v);
void fn_16_44C(void* a, int b, void* c, int d, void* e, int f, int g, int h, int i, int j, int k);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int heap);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void* self, int a, int b, void* c);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* self, void* a, char* b);
}

extern "C" void fn_2_38800(void* self, int arg1, void* arg2, void* arg3, int arg4, int arg5, void* arg6, int arg7)
{
    char* base = (char*)self;
    void* heap;
    void* mdl;

    *(int*)(base + 0x40) = arg1;
    *(int*)(base + 0x70) = arg4;
    *(int*)(base + 0x1E8) = arg5;
    fn_800B96E8(base + 0x78, 0xF0);
    fn_2_38950(self, &lbl_2_rodata_1700, 2, arg2, 1, arg5);
    heap = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2A);
    mdl = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, 0xA, *(void**)(*(char**)(base + 0x44) + 0x10));
    *(void**)(base + 0x6C) = mdl;
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(mdl, *(void**)(*(char**)(base + 0x48) + 0x10), (char*)&lbl_2_data_4B14);
    if (*(int*)(base + 0x40) == 0) {
        fn_2_38950(self, &lbl_2_rodata_1710, 8, arg6, 0, arg5);
        *(int*)(base + 0x1E0) = arg7;
    }
    fn_2_38A54(self, arg3);
    if (*(int*)(base + 0x40) == 0) {
        fn_16_44C(base + 0x14C, 0, *(void**)(base + 0x6C), *(int*)(base + 0x4C), base + 0x50,
                  *(int*)(base + 0x64), *(int*)(base + 0x68), 6, *(int*)(base + 0x74), 0, 0);
    }
    if (*(int*)(base + 0x40) == 0) {
        *(int*)(base + 0x138) = 0;
    } else {
        *(int*)(base + 0x138) = 2;
    }
}
