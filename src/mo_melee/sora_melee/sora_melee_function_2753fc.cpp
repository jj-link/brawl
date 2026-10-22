#pragma force_active on

typedef unsigned char u8;

struct Node {
    Node* next;
    Node* prev;
};

struct Collision {
    char pad[0x2C];
    u8 enabled : 1;
    u8 b40 : 1;
    u8 b20 : 1;
    u8 b10 : 1;
    u8 b08 : 1;
    u8 b04 : 1;
    u8 active : 1;
    u8 b01 : 1;
    u8 flag2D : 1;
    u8 p2D : 7;
    char padding[2];
    Node node;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_275534(Collision*, void*);
extern "C" void fn_27_275628(void*, void*, void*, void*);
extern "C" char g_grCollisionList[12];
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char*, void**, Node*);

extern "C" Collision* fn_27_2753FC(void* a, void* data, void* c, bool d, int heap) {
    Collision* obj = (Collision*)__nw__FUlQ25Heaps8HeapType(0x38, heap);
    if (obj != 0) {
        obj->enabled = d;
        obj->active = 0;
        obj->node.next = 0;
        obj->node.prev = 0;
        fn_27_275534(obj, data);
        fn_27_275628(obj, a, c, data);
        void* it = g_grCollisionList + 4;
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(g_grCollisionList, &it, &obj->node);
        obj->flag2D = 0;
    }
    return obj;
}
