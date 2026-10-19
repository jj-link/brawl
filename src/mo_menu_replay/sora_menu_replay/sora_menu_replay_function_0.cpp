#pragma force_active on
typedef unsigned char u8;

struct Node {
    void* prev;
    void* next;
    void* list;
    void* vtable;
    unsigned int value;
    u8 flag;
};

struct ReplayTask {
    u8 pad0[0x3C];
    void* vtable;
    u8 pad40[0x16C];
    void* menu;
};

struct ReplayMenu {
    u8 pad0[0x1CF8];
    int count;
    u8 pad1CFC[0xC];
    void* vtable;
    void* context;
    int index1;
    int index2;
    u8 pad1D18[4];
    Node node;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_6_180(void*, void*);
void fn_6_278(void*, int, int, void*);
void addTail__6utListFP10utListNode(void*, void*);

extern u8 lbl_7_data_0[];
extern u8 lbl_7_data_278[];
extern u8 lbl_7_data_8[];
extern u8 lbl_7_data_480[];
extern u8 lbl_7_data_580[];
extern u8 lbl_8049E550[];
}

extern "C" ReplayTask* fn_7_0(void* context) {
    ReplayTask* task =
        (ReplayTask*)__nw__FUlQ25Heaps8HeapType(0x1B0, 0x2A);

    if (task) {
        fn_6_180(task, lbl_7_data_0);
        task->vtable = lbl_7_data_278;
    }

    Node* node;
    ReplayMenu* menu =
        (ReplayMenu*)__nw__FUlQ25Heaps8HeapType(0x1D34, 0x2A);

    if (menu) {
        fn_6_278(menu, 30, 5, lbl_7_data_8);
        menu->vtable = lbl_7_data_480;
        menu->context = 0;
        menu->index1 = -1;
        menu->index2 = -1;

        node = &menu->node;
        node->list = 0;
        node->prev = 0;
        node->next = 0;
        addTail__6utListFP10utListNode(lbl_8049E550, node);
        node->list = lbl_8049E550;
        node->vtable = lbl_7_data_580;
        node->value = 0;
        node->flag = 0;

        menu->count = 50;
    }

    task->menu = menu;
    menu->context = context;
    return task;
}
