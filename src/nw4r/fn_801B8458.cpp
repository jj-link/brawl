#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

struct Node {
    Node* next;
    Node* prev;
};

struct Item {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    Node link;
};

struct ListEntry {
    int count;
    Node head;
};

struct Self {
    char pad[0xB4];
    ListEntry lists[3];
};

extern "C" {
void fn_8015C304(void* list);
void fn_801FFE28(int, int);
void fn_801FFE8C(int, int);
void fn_801FFEF0(int, int);
}

extern "C" void fn_801B8458(Self* self, int idx) {
    BOOL enabled = OSDisableInterrupts();
    Node* node;
    Node* head;
    ListEntry* list = &self->lists[idx];
    if (list->count == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }
    head = &list->head;
    for (node = head->next; node != head; node = node->next) {
        Item* item = (Item*)((char*)node - 4);
        item->f2();
    }
    fn_8015C304(list);
    switch (idx) {
    case 0:
        fn_801FFE28(0, 0);
        break;
    case 1:
        fn_801FFE8C(0, 0);
        break;
    case 2:
        fn_801FFEF0(0, 0);
        break;
    }
    OSRestoreInterrupts(enabled);
}
