#pragma force_active on
typedef unsigned char u8;

struct Obj {
    void* prev;
    void* next;
    u8 kind;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

extern "C" void fn_79_15A0(void* unused, u8 kind, char* list) {
    void* it;
    Obj* p = (Obj*)__nw__FUlQ25Heaps8HeapType(0xc, 0x11);
    if (p) {
        p->prev = 0;
        p->next = 0;
    }
    if (p) {
        p->kind = kind;
        it = list + 4;
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(list, &it, p);
    }
}
