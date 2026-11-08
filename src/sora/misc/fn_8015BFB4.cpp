#include <types.h>
#pragma force_active on

typedef struct fn_Link {
    void* prev; // +0
    void* next; // +4
} fn_Link;

typedef struct fn_List {
    void* head; // +0
    void* tail; // +4
    u16 length; // +8
    u16 offset; // +A
} fn_List;

extern "C" void fn_8015BFB4(fn_List* list, void* node) {
    fn_Link* link;

    if (list->head == 0) {
        link = (fn_Link*)((u8*)node + list->offset);
        link->next = 0;
        link->prev = 0;
        list->head = node;
        list->tail = node;
        list->length++;
    } else {
        link = (fn_Link*)((u8*)node + list->offset);
        link->prev = list->tail;
        link->next = 0;
        ((fn_Link*)((u8*)list->tail + list->offset))->next = node;
        list->tail = node;
        list->length++;
    }
}
