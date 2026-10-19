#pragma force_active on
struct Data {
    char padding[0x50];
    float value;
};

struct Node {
    Node* prev;
    Node* next;
    unsigned char flag;
    float value;
};

struct Iterator {
    Node* node;
};

struct List {
    unsigned int size;
    Node anchor;
};

struct Base {
    char padding[0x3C];

    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual Data* getData();
};

struct Stage : Base {
    char padding2[0x1AC];
    List list;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
    List*, Iterator, Node*);

extern "C" void fn_63_1528C(Stage* self) {
    Data* data = self->getData();
    if (data) {
        Node* node = (Node*)__nw__FUlQ25Heaps8HeapType(0x10, 0xF);
        if (node) {
            node->prev = 0;
            node->next = 0;
        }
        if (node) {
            node->flag = 0;
            node->value = data->value;
            Iterator end = { &self->list.anchor };
            Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
                &self->list, end, node);
        }
    }
}
