#pragma force_active on
typedef unsigned char u8;

struct Node {
    void* prev;
    void* next;
    u8 type;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, Node* node);

extern "C" {
void fn_81_3CFC(int unused, u8 type, char* list) {
    Node* node = (Node*)__nw__FUlQ25Heaps8HeapType(0xC, 0x11);
    if (node) {
        node->prev = 0;
        node->next = 0;
    }
    if (node) {
        node->type = type;
        void* it = list + 4;
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(list, &it, node);
    }
}
}
