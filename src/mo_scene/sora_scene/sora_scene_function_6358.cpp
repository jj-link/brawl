#pragma force_active on

extern "C" {
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void fn_1_3C68(void*, int, void*, void*, int);
extern char lbl_1_data_1454[];
}

struct Loader {
    unsigned int fields[7];
    bool flag1 : 1;
    bool flag2 : 1;
    bool flag3 : 1;
    unsigned char other : 5;
};

extern "C" void fn_1_6358(unsigned char* self) {
    Loader* obj;
    unsigned char* arc;

    *(void**)(self + 0x35C) =
        alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2A, 8);

    obj = (Loader*)__nw__FUlQ25Heaps8HeapType(0x20, 0x2B);
    if (obj != 0) {
        obj->fields[0] = 0;
        obj->fields[1] = 0;
        obj->fields[2] = 0;
        obj->fields[3] = 0;
        obj->fields[4] = 0;
        obj->flag1 = false;
        obj->flag2 = false;
        obj->fields[6] = 0;
        obj->fields[5] = 0xFF;
        obj->flag3 = false;
    }
    *(void**)(self + 0x380) = obj;

    arc = (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x80, 0x2B);
    if (arc != 0) {
        arc = (unsigned char*)__ct__9gfArchiveFv(arc);
    }
    *(void**)(self + 0x37C) = arc;

    fn_1_3C68(*(void**)(self + 0x380), 0x2B, lbl_1_data_1454, arc, 0);

    self[0x378] = 0;
    *(unsigned int*)(*(unsigned char**)(self + 0x35C) + 4) = 0;
}
