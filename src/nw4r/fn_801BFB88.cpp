#pragma force_active on
extern "C" int fn_80204A70(int a, int b, int c);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

extern "C" char* fn_801BFB88(char* self, unsigned int size, unsigned int a2, unsigned int a3) {
    unsigned int aligned = (size + 0x1F) & ~0x1F;
    char* p = (char*)fn_80204A70(*(int*)self, aligned + 0x20, 0x20);
    char* list;
    void* it;
    if (p == 0) {
        return 0;
    }
    if (p != 0) {
        *(int*)(p + 0x0) = 0;
        *(int*)(p + 0x4) = 0;
        *(unsigned int*)(p + 0x8) = size;
        *(unsigned int*)(p + 0xC) = a2;
        *(unsigned int*)(p + 0x10) = a3;
    }
    list = *(char**)(self + 0xC);
    it = list + 0xC;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(list + 0x8, &it, p);
    return p + 0x20;
}
